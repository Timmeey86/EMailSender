#ifndef FILE_XMLFILEREADER_H
#define FILE_XMLFILEREADER_H

#include "IFileFormatReader.h"
namespace File
{
    /** \brief	This class is responsible for reading XML content. */
    class XMLFileReader : public IFileFormatReader
    {
    public:
        /** \brief	Default constructor. */
        XMLFileReader() = default;
        /** \brief	Destructor. */
        ~XMLFileReader() = default;

        // Inherited via IFileFormatReader
        virtual bool canHandle(const QString & fileContents) const override;
        virtual QString getMessageBody(const QString & fileContents) const override;
    };
}

#endif // FILE_XMLFILEREADER_H
