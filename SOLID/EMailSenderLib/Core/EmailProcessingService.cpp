#include "EmailProcessingService.h"
#include "IEmailService.h"
#include "IMessageInfoRetriever.h"

using namespace Core;

EmailProcessingService::EmailProcessingService( std::shared_ptr<IMessageInfoRetriever> messageInfoRetriever, std::shared_ptr<IEmailService> emailSender ) :
    _messageInfoRetriever( messageInfoRetriever ),
    _emailSender( emailSender )
{
}

EmailProcessingService::~EmailProcessingService()
{
    // automatic cleanup
}

QString EmailProcessingService::sendMessage() const
{
    auto messageBody = _messageInfoRetriever->getMessageBody();
    _emailSender->sendEmail( messageBody );
    return "Sent email with body:\r\n" + messageBody;
}
