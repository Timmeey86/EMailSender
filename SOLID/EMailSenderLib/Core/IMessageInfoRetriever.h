#ifndef CORE_IMESSAGEINFORETRIEVER_H
#define CORE_IMESSAGEINFORETRIEVER_H

#include <QtCore/qstring.h>

namespace Core
{
    class IMessageInfoRetriever
    {
    public:
        /** \brief Default constructor. */
        virtual ~IMessageInfoRetriever() = default;

        /**
         * \brief	Retrieves the message body.
         *
         * \return	The message body.
         */
        virtual QString getMessageBody() const = 0;

        // Interface definitions: Forbid direct construction; Disable Assign/Copy/Move
    protected:
        IMessageInfoRetriever() {};
        IMessageInfoRetriever( const IMessageInfoRetriever& ) = delete;
        IMessageInfoRetriever& operator= ( const IMessageInfoRetriever& ) = delete;
        IMessageInfoRetriever( IMessageInfoRetriever&& ) = delete;
        IMessageInfoRetriever& operator= ( IMessageInfoRetriever&& ) = delete;
    };
}

#endif // CORE_IMESSAGEINFORETRIEVER_H
