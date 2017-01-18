#ifndef FILE_FILEREADERSERVICE_H
#define FILE_FILEREADERSERVICE_H

#include <QtCore/qvector.h>

#include <memory>

namespace File
{
    class IFileFormatReader;

    /** \brief  This class is responsible for finding out and using the proper file format reader in order to provide a file's content through the
     *          IMessageInfoRetriever interface.
     */
    class FileReaderService
    {
    public:
        /**
         * \brief   Constructor.
         *
         * \param   defaultFileFormatReader	The default file format reader.
         */
        FileReaderService( std::shared_ptr<IFileFormatReader> defaultFileFormatReader );
        /** \brief  Destructor. */
        ~FileReaderService();

        /**
         * \brief   Registers the given format reader.
         *
         * \param   formatReader    The format reader.
         */
        void registerFormatReader( std::shared_ptr<IFileFormatReader> formatReader );

        /**
         * \brief   Gets the message body.
         *
         * \param    filePath    Full pathname of the file.
         * \return  the message body.
         */
        virtual QString getMessageBodyFromFile( const QString& filePath ) const;

    private:
        /**
         * \brief   Gets the file contents.
         *
         * \param    filePath    Full pathname of the file.
         * \return  The file contents.
         */
        QString getFileContents( const QString& filePath ) const;

        /** \brief  The file format readers. */
        QVector<std::shared_ptr<IFileFormatReader>> _fileFormatReaders;
        /** \brief  The default file format reader. */
        std::shared_ptr<IFileFormatReader> _defaultFileFormatReader;
    };
}

#endif // FILE_FILEREADERSERVICE_H
