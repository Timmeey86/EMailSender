#ifndef CORE_IEMAILSENDER_H
#define CORE_IEMAILSENDER_H

#include <QtCore/qstring.h>

namespace Core
{
    /** \brief This is the interface for classes which send emails. */
    class IEmailService
    {
    public:
        /** \brief Destructor. */
        virtual ~IEmailService() = default;

        /**
         * \brief Sends an email with the specified body.
         *
         * \param body The body.
         */
        virtual void sendEmail( const QString& body ) = 0;

        // Interface definitions: Forbid direct construction; Disable Assign/Copy/Move
    protected:
        IEmailService() {};
        IEmailService( const IEmailService& ) = delete;
        IEmailService& operator= ( const IEmailService& ) = delete;
        IEmailService( IEmailService&& ) = delete;
        IEmailService& operator= ( IEmailService&& ) = delete;
    };
}
#endif // CORE_IEMAILSENDER_H