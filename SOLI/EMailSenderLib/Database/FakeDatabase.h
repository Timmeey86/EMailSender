#ifndef DATABASE_FAKEDATABASE_H
#define DATABASE_FAKEDATABASE_H

#include "IDatabase.h"

#include <QtCore/QHash>

namespace Database
{
    /** \brief This class is responsible for acting like a real database for testing purposes. */
    class FakeDatabase : public IDatabase
    {
    public:
        /** \brief   Default constructor. */
        FakeDatabase();
        /** \brief   Destructor. */
        ~FakeDatabase();

        // Inherited from IDatabase
        virtual bool connect() override;
        virtual QAbstractItemModel * getModel( const QString & tableName ) override;

    private:
        QAbstractItemModel* _defaultModel; ///< The default model to use.
    };
}

#endif // DATABASE_FAKEDATABASE_H
