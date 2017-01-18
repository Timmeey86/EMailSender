#include "FakeEmailSender.h"
#include "File/FormatReader.h"

using namespace Mail;

void FakeEmailSender::readFile()
{
    auto fileContents = getFileContents( getFileName() );

    File::FormatReader formatReader;
    _messageBody = formatReader.getMessageBody( fileContents );
}

void FakeEmailSender::sendEmail()
{
    auto messageBody = getMessageBody();

    qDebug() << "Sending message body" << messageBody;
    // In a productive class, there would be a lot of TCP and SMTP stuff here.
}

QString FakeEmailSender::getFileContents( const QString& filePath ) const
{
    if( filePath.isNull() || filePath.isEmpty() )
    {
        Q_ASSERT( false );
        return "No file path given";
    }

    QFile file( filePath );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        return file.errorString();
    }
    return file.readAll();
}