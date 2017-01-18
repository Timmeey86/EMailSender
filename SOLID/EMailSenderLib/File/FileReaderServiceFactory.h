#ifndef FILE_FILEREADERSERVICEFACTORY_H
#define FILE_FILEREADERSERVICEFACTORY_H

#include <memory>

namespace Core
{
    class IMessageInfoRetriever;
}

namespace File
{
    class FileReaderService;

    /** \brief	This class is responsible for the creation of File Reader Service objects. */
    class FileReaderServiceFactory
    {
    public:
        /** \brief	Default constructor. */
        FileReaderServiceFactory() = default;
        /** \brief	Destructor. */
        ~FileReaderServiceFactory() = default;

        /**
         * \brief	Creates a file reader service.
         *
         * \param	filePath	Full pathname of the file to read from.
         *
         * \return	The new file reader service.
         */
        virtual std::shared_ptr<Core::IMessageInfoRetriever> createFileReaderService( const QString& filePath );
    };
}

#endif // FILE_FILEREADERSERVICEFACTORY_H
