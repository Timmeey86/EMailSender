#ifndef DATABASE_DATABASEREADERSERVICE_H
#define DATABASE_DATABASEREADERSERVICE_H

#include <memory>
#include <QtCore/qstring.h>

namespace Database
{
    class IDatabase;

    /** \brief      This class is responsible for providing messages from a database. */
    class DatabaseReaderService
    {
    public:
        /**
         * \brief   Creates a database reader service.
         *
         * \param   database    the database.
         */
        DatabaseReaderService( std::shared_ptr<IDatabase> database );
        /**
         * \brief   Default destructor
         */
        ~DatabaseReaderService() = default;

        /**
         * \brief   Gets the message body.
         *
         * \return  the message body.
         */
        virtual QString getMessageBody() const;

    private:
        std::shared_ptr<IDatabase> _database; ///< The database to use.
    };
}

#endif // DATABASE_DATABASEREADERSERVICE_H
