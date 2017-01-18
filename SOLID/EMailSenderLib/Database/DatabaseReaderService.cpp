#include "EMailSenderLib_pch.h"
#include "DatabaseReaderService.h"
#include "IDatabase.h"

using namespace Database;

DatabaseReaderService::DatabaseReaderService( std::shared_ptr<IDatabase> database ) :
    _database( std::move( database ) )
{
}

QString DatabaseReaderService::getMessageBody() const
{
    if( !_database->connect() )
    {
        return "ERROR: Database connect failed";
    }
    // else:

    return _database->getModel( "REPORTS" )->index( 0, 1 ).data().toString();
}
