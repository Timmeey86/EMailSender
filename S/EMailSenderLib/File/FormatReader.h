#ifndef FILE_XMLFILEREADER_H
#define FILE_XMLFILEREADER_H

#include <QtCore/qstring.h>

namespace File
{
    /** \brief	This class is responsible for reading XML content. */
    class FormatReader
    {
    public:
        /** \brief	Default constructor. */
        FormatReader() = default;
        /** \brief	Destructor. */
        ~FormatReader() = default;

        /**
         * \brief   Gets the message body.
         *
         * \param   fileContents    The file contents.
         *
         * \return  The message body.
         */
        QString getMessageBody( const QString & fileContents ) const;

    private:

        /**
         * \brief   Checks if the given content is well-formed XML.
         *
         * \param   fileContents    The file contents to check.
         *
         * \return  True if the file content is well-formed XML, false if not.
         */
        bool isXmlContent( const QString& fileContents ) const;
    };
}

#endif // FILE_XMLFILEREADER_H
