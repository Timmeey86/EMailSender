#include "DatabaseConnectionReader.h"

using namespace Database;

bool DatabaseConnectionReader::canHandle( const QString& fileContents ) const
{
    // The file can be handled if a connect string is inside.
    return fileContents.startsWith( "server=" );
}

QString DatabaseConnectionReader::getMessageBody( const QString& fileContents ) const
{
    Q_ASSERT_X( false, "DatabaseConnectionReader::getMessageBody", "Need to read from the database! Not from this interface!" );
    return "Not Implemented";
}
