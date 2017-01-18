#ifndef MAIL_FAKEEMAILSENDER_H
#define MAIL_FAKEEMAILSENDER_H

#include "../Core/IEmailService.h"

namespace Mail
{
    /** \brief   This class is responsible for pretending to send emails. */
    class FakeEmailService : public Core::IEmailService
    {
    public:
        /** \brief   Default constructor. */
        FakeEmailService();
        /** \brief   Destructor. */
        virtual ~FakeEmailService();

        /**
         * \brief Pretends sending an email.
         *
         * \param body The body.
         */
        virtual void sendEmail( const QString& body ) override;
    };
}

#endif // MAIL_FAKEEMAILSENDER_H