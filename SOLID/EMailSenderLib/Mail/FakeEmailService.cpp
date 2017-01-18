#include "FakeEmailService.h"

#include <QtCore/qdebug.h>

using namespace Mail;

FakeEmailService::FakeEmailService()
{
}

FakeEmailService::~FakeEmailService()
{
}

void FakeEmailService::sendEmail( const QString& body )
{
    qDebug() << "Sending message body" << body;

    // In a productive class, there would be a lot of TCP and SMTP stuff here.
}