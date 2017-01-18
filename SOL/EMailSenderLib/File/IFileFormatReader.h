#ifndef FILE_IFILEFORMATREADER_H
#define FILE_IFILEFORMATREADER_H

#include <QtCore/qstring.h>

namespace File
{
    /** \brief   This is the interface for classes which extract message bodies from a certain type of file. */
    class IFileFormatReader
    {
    public:
        /** \brief Destructor. */
        virtual ~IFileFormatReader() = default;

        /**
         * \brief Determines if the given file content can be handled.
         *
         * \param fileContents The file contents.
         *
         * \return True if the file contents can be handled, false if not.
         */
        virtual bool canHandle( const QString& fileContents ) const = 0;
        /**
         * \brief Gets the message body.
         *
         * \param fileContents The file contents.
         *
         * \return The message body.
         */
        virtual QString getMessageBody( const QString& fileContents ) const = 0;

        // Interface definitions: Forbid direct construction; Disable Assign/Copy/Move
    protected:
        IFileFormatReader() {};
        IFileFormatReader( const IFileFormatReader& ) = delete;
        IFileFormatReader& operator= ( const IFileFormatReader& ) = delete;
        IFileFormatReader( IFileFormatReader&& ) = delete;
        IFileFormatReader& operator= ( IFileFormatReader&& ) = delete;

    };
}
#endif // FILE_IFILEFORMATREADER_H