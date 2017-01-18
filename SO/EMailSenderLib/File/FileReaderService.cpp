#include "FileReaderService.h"
#include "IFileFormatReader.h"
#include "../Database/DatabaseConnectionReader.h"
#include "../Database/FakeDatabase.h"

#include <QtCore/qfile.h>

using namespace File;


FileReaderService::FileReaderService(std::shared_ptr<IFileFormatReader> defaultFileFormatReader) :
	_defaultFileFormatReader( defaultFileFormatReader )
{
}

FileReaderService::~FileReaderService()
{
}

QString FileReaderService::getMessageBodyFromFile(const QString& filePath) const
{
    auto fileContents = getFileContents(filePath);

    for (auto fileFormatReader : _fileFormatReaders)
    {
        if (fileFormatReader->canHandle(fileContents))
        {
            if (dynamic_cast<Database::DatabaseConnectionReader*>(fileFormatReader.get()) != nullptr)
            {
                auto database = std::make_shared<Database::FakeDatabase>();
                if (!database->connect())
                {
                    return "ERROR: Database connect failed";
                }
                // else:

                return database->getModel("REPORTS")->index(0, 1).data().toString();
            }
            else
            {
                return fileFormatReader->getMessageBody(fileContents);
            }
        }
    }

    Q_ASSERT(_defaultFileFormatReader->canHandle(fileContents)); // The default reader should be able to handle anything.
    return _defaultFileFormatReader->getMessageBody(fileContents);
}

QString FileReaderService::getFileContents(const QString& filePath) const
{
    if (filePath.isNull() || filePath.isEmpty())
    {
        Q_ASSERT(false);
        return "No file path given";
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return file.errorString();
    }
    return file.readAll();
}

void FileReaderService::registerFormatReader(std::shared_ptr<IFileFormatReader> formatReader)
{
    if (!_fileFormatReaders.contains(formatReader))
    {
        _fileFormatReaders.append(formatReader);
    }
}
