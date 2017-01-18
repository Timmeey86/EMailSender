#include "EMailSenderLib_pch.h"
#include "FakeDatabase.h"

#include <QtGui/qstandarditemmodel.h>

using namespace Database;

FakeDatabase::FakeDatabase() :
    _defaultModel( nullptr )
{
}

FakeDatabase::~FakeDatabase()
{
    delete _defaultModel;
    _defaultModel = nullptr;
}

bool FakeDatabase::connect()
{
    // Pretend connecting to a database and create a default model.
    auto itemModel = new QStandardItemModel();
    itemModel->insertColumns( 0, 2 );
    itemModel->appendRow( QList<QStandardItem*>() << new QStandardItem( "0" ) << new QStandardItem( "This is the first log message" ) );
    itemModel->appendRow( QList<QStandardItem*>() << new QStandardItem( "1" ) << new QStandardItem( "This is the second log message" ) );
    itemModel->appendRow( QList<QStandardItem*>() << new QStandardItem( "2" ) << new QStandardItem( "This is the third log message" ) );
    _defaultModel = itemModel;

    return true; 
}

QAbstractItemModel* FakeDatabase::getModel( const QString & tableName )
{
    Q_UNUSED( tableName ); // Fake DB
    Q_ASSERT( _defaultModel );
    return _defaultModel;
}
