#ifndef MAIL_FAKEEMAILSENDER_H
#define MAIL_FAKEEMAILSENDER_H

#include <QtCore/qstring.h>

namespace Mail
{
    class FakeEmailSender
    {
    public:
        FakeEmailSender() = default;
        ~FakeEmailSender() = default;

        /** \brief Reads the message body from a file. */
        void readFile();
        /** \brief Pretends sending an email. */
        void sendEmail();
        
        /**
         * \brief   Gets the message body.
         *
         * \return  the message body.
         */
        inline QString getMessageBody() const { return _messageBody; }

        /**
         * \brief   Sets the file name.
         *
         * \param   fileName    the file name.
         */
        inline void setFileName( const QString& fileName ) { _fileName = fileName; }

        /**
         * \brief   Gets the file name.
         *
         * \return  the file name.
         */
        inline QString getFileName() const { return _fileName; }

    private:

        /**
         * \brief   Gets the contents of the file at the given path.
         *
         * \param   filePath        the full path and name of the target file.
         *
         * \return  the file contents.
         */
        QString getFileContents( const QString& filePath ) const;

        QString _messageBody; ///< The body of the message to send.
        QString _fileName;    ///< The name of the file to read from.
    };
}

#endif // MAIL_FAKEEMAILSENDER_H