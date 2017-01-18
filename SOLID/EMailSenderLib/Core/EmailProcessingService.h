#ifndef CORE_EMAILPROCESSINGSERVICE_H
#define CORE_EMAILPROCESSINGSERVICE_H

#include <memory>
#include <QtCore/qstring.h>

namespace Core
{
    class IMessageInfoRetriever;
    class IEmailService;

    /**
     * \class EmailProcessingService
     *
     * \brief This class is responsible for the process of sending Emails through an IEmailService based on data retreived from an IMessageInfoRetriever.
     */
    class EmailProcessingService
    {
    public:
        /**
        /*
         * \brief Default constructor.
         *
         * \param messageInfoRetriever The message information retriever.
         * \param emailSender		   The email sender.
         */
        EmailProcessingService( std::shared_ptr<IMessageInfoRetriever> messageInfoRetriever, std::shared_ptr<IEmailService> emailSender );
        /** \brief Destructor. */
        ~EmailProcessingService();

        /**
         * \brief Retrieves the message body from the message info retriever and forwards it to the email sender.
         *
         * \return the message body which was sent.
         */
        QString sendMessage() const;

    private:
        std::shared_ptr<IMessageInfoRetriever> _messageInfoRetriever;   ///< The message information retriever
        std::shared_ptr<IEmailService> _emailSender; ///< The email sender
    };
}

#endif // CORE_EMAILPROCESSINGSERVICE_H

