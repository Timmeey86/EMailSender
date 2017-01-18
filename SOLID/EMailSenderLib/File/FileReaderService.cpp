#include "FileReaderService.h"
#include "IFileFormatReader.h"

#include <QtCore/qfile.h>

using namespace File;


FileReaderService::FileReaderService( std::shared_ptr<IFileFormatReader> defaultFileFormatReader ) :
    _defaultFileFormatReader( defaultFileFormatReader )
{
}

FileReaderService::~FileReaderService()
{
}

void FileReaderService::setInputFilePath( const QString & filePath )
{
    _currentFilePath = filePath;
}

QString FileReaderService::getMessageBody() const
{
    auto fileContents = getFileContents();

    for( auto fileFormatReader : _fileFormatReaders )
    {
        if( fileFormatReader->canHandle( fileContents ) )
        {
            return fileFormatReader->getMessageBody( fileContents );
        }
    }

    Q_ASSERT( _defaultFileFormatReader->canHandle( fileContents ) ); // The default reader should be able to handle anything.
    return _defaultFileFormatReader->getMessageBody( fileContents );
}

QString FileReaderService::getFileContents() const
{
    if( _currentFilePath.isNull() || _currentFilePath.isEmpty() )
    {
        Q_ASSERT( false );
        return "No file path given";
    }

    QFile file( _currentFilePath );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        return file.errorString();
    }
    return file.readAll();
}

void FileReaderService::registerFormatReader( std::shared_ptr<IFileFormatReader> formatReader )
{
    if( !_fileFormatReaders.contains( formatReader ) )
    {
        _fileFormatReaders.append( formatReader );
    }
}
