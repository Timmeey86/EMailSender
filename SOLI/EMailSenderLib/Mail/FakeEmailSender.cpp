#include "FakeEmailSender.h"

using namespace Mail;

void FakeEmailSender::sendEmail( const QString& messageBody )
{
    qDebug() << "Sending message body" << messageBody;

    // In a productive class, there would be a lot of TCP and SMTP stuff here.
}