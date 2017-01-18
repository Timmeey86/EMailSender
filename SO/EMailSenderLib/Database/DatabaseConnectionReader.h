#ifndef DATABASE_DATABASECONNECTIONREADER_H
#define DATABASE_DATABASECONNECTIONREADER_H

#include "../File/IFileFormatReader.h"

namespace Database
{
    /** \brief      This class is responsible for reading the connection info of a database. */
    class DatabaseConnectionReader : public File::IFileFormatReader
    {
    public:
        DatabaseConnectionReader() = default;
        ~DatabaseConnectionReader() = default;
        
        // Inherited from IFileFormatReader
        virtual bool canHandle( const QString& fileContents ) const override;
        virtual QString getMessageBody( const QString& fileContents ) const override;
    };
}

#endif // DATABASE_DATABASECONNECTIONREADER_H
