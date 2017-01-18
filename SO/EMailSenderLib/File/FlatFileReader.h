#ifndef FILE_FLATFILEREADER_H
#define FILE_FLATFILEREADER_H

#include "IFileFormatReader.h"

namespace File
{
    /** \brief	This class is responsible for providing the full content of a file as a QString. */
    class FlatFileReader : public IFileFormatReader
    {
    public:
        FlatFileReader() = default;
        ~FlatFileReader() = default;

        // Inherited via IFileFormatReader
        virtual bool canHandle(const QString & fileContents) const override;
        virtual QString getMessageBody(const QString & fileContents) const override;
    };
}

#endif // #define FILE_FLATFILEREADER_H

