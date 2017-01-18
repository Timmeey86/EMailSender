#include "FakeEmailSender.h"
#include "File/FileReaderService.h"
#include "File/FlatFileReader.h"
#include "File/XMLFileReader.h"
#include "Database/DatabaseReaderService.h"
#include "Database/FakeDatabase.h"

using namespace Mail;

void FakeEmailSender::readFile()
{
    auto flatFileReader = std::make_shared<File::FlatFileReader>();
    auto xmlFileReader = std::make_shared<File::XMLFileReader>();

    auto fileReaderService = std::make_shared<File::FileReaderService>( flatFileReader );
    fileReaderService->registerFormatReader( xmlFileReader );

    _messageBody = fileReaderService->getMessageBodyFromFile( getFileName() );
}

void FakeEmailSender::readDatabase()
{
    Database::DatabaseReaderService service( std::make_shared<Database::FakeDatabase>() );

    _messageBody = service.getMessageBody();
}

void FakeEmailSender::sendEmail()
{
    auto messageBody = getMessageBody();

    Q_UNUSED( messageBody ); // This is a fake, it won't actually send mails.

    // In a productive class, there would be a lot of TCP and SMTP stuff here.
}