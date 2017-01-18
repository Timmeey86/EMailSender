#include "FileReaderServiceFactory.h"
#include "FileReaderService.h"
#include "FlatFileReader.h"
#include "XMLFileReader.h"

using namespace File;

std::shared_ptr<Core::IMessageInfoRetriever> File::FileReaderServiceFactory::createFileReaderService( const QString & filePath )
{
    auto flatFileReader = std::make_shared<File::FlatFileReader>();
    auto xmlFileReader = std::make_shared<File::XMLFileReader>();

    auto fileReaderService = std::make_shared<File::FileReaderService>( flatFileReader );
    fileReaderService->registerFormatReader( xmlFileReader );

    fileReaderService->setInputFilePath( filePath );

    return fileReaderService;
}
