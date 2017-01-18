#ifndef DATABASE_DATABASEREADERSERVICE_H
#define DATABASE_DATABASEREADERSERVICE_H

#include "../Core/IMessageInfoRetriever.h"
#include <memory>

namespace Database
{
    class IDatabase;

    /** \brief      This class is responsible for providing messages from a database. */
    class DatabaseReaderService : public Core::IMessageInfoRetriever
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

        // Inherited via IMessageInfoRetriever
        virtual QString getMessageBody() const override;

    private:
        std::shared_ptr<IDatabase> _database; ///< The database to use.
    };
}

#endif // DATABASE_DATABASEREADERSERVICE_H
