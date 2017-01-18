#ifndef MAIL_FAKEEMAILSENDER_H
#define MAIL_FAKEEMAILSENDER_H

#include <QtCore/QString>

namespace Mail
{
    /** \brief   This class pretends sending emails. */
    class FakeEmailSender
    {
    public:
        FakeEmailSender() = default;
        ~FakeEmailSender() = default;

        /**
         * \brief   Pretends sending an email.
         *
         * \param   messageBody     the message body.
         */
        void sendEmail( const QString& messageBody );
    };
}

#endif // MAIL_FAKEEMAILSENDER_H
