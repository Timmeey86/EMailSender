#include "FormatReader.h"

#include <QtCore/qxmlstream.h>

using namespace File;

QString FormatReader::getMessageBody( const QString & fileContents ) const
{
    if( isXmlContent( fileContents ) )
    {
        QXmlStreamReader xml( fileContents );

        while( !xml.atEnd() )
        {
            xml.readNextStartElement();
            if( xml.name() == "relevantText" && !xml.atEnd() )
            {
                xml.readNext();
                return xml.text().toString();
            }
        }
        // At this point, no relevant text was found
        return "No relevant text was found";
    }
    // else: File is plain text, return everything

    return fileContents;
}

bool FormatReader::isXmlContent( const QString & fileContents ) const
{
    QXmlStreamReader xml( fileContents );

    while( !xml.atEnd() ) {
        xml.readNext();
        qDebug() << QString( "<%1>: %2" ).arg( xml.name().toString(), xml.text().toString() );
    }

    if( xml.hasError() )
    {
        return false;
    }

    return true;
}