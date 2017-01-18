#ifndef DATABASE_IDATABASE_H
#define DATABASE_IDATABASE_H

class QAbstractItemModel;

namespace Database
{
    /** \brief  This is the interface for databases. */
    class IDatabase
    {
    public:
        /** \brief Destructor. */
        virtual ~IDatabase() = default;

        /**
         * \brief   Tries connecting to the database.
         *
         * \return  True if the connection was established, false if not.
         */
        virtual bool connect() = 0;

        /**
         * \brief   Retrieves a model for the given table.
         *
         * \param   tableName       the table name.
         * \return  A model for the table.
         */
        virtual QAbstractItemModel* getModel( const QString& tableName ) = 0;

        // Interface definitions: Forbid direct construction; Disable Assign/Copy/Move
    protected:
        IDatabase() {};
        IDatabase( const IDatabase& ) = delete;
        IDatabase& operator= ( const IDatabase& ) = delete;
        IDatabase( IDatabase&& ) = delete;
        IDatabase& operator= ( IDatabase&& ) = delete;
    };
}
#endif // DATABASE_IDATABASE_H
