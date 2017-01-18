#include "FlatFileReader.h"

using namespace File;

bool FlatFileReader::canHandle(const QString & fileContents) const
{
    return true; // any kind of file contents can be handled.
}

QString FlatFileReader::getMessageBody(const QString & fileContents) const
{
    return fileContents;
}
