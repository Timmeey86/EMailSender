#ifndef DATABASE_FAKEDATABASE_H
#define DATABASE_FAKEDATABASE_H

#include <QtCore/QHash>

namespace Database
{
    /** \brief This class is responsible for acting like a real database for testing purposes. */
    class FakeDatabase
    {
    public:
        FakeDatabase();
        ~FakeDatabase();

        /**
         * \brief   Connects to the (fake) database.
         *
         * \return  True if it succeeds, false if it fails.
         */
        virtual bool connect();

        /**
         * \brief   Gets a model for the given table from the connected (fake) database.
         *
         * \param   tableName   Name of the table.
         *
         * \return  the model which was retrieved or NULL if not connected / in case of errors.
         */
        virtual QAbstractItemModel * getModel( const QString & tableName );

    private:
        QAbstractItemModel* _defaultModel; ///< The default model to use.
    };
}

#endif // DATABASE_FAKEDATABASE_H
