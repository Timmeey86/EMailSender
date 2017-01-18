#include "stdafx.h"
#include "EMailSenderUI.h"

#include <QtWidgets/qfiledialog.h>

EMailSenderUI::EMailSenderUI( QWidget *parent )
    : QMainWindow( parent )
{
    ui.setupUi( this );
}


void EMailSenderUI::on_openFile_clicked()
{
    ui.filePath->setText( QFileDialog::getOpenFileName( this, tr( "Select Input File" ), "C:\\", "Text Files (*.txt *.xml *.ini);;All Files (*.*)" ) );
}

void EMailSenderUI::on_sendFromFile_clicked()
{
    QString messageBody;
    auto filePath = ui.filePath->text();

    if( filePath.isNull() || filePath.isEmpty() )
    {
        Q_ASSERT( false );
        messageBody = "No file path given";
    }
    else
    {
        QFile file( filePath );
        if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            messageBody = file.errorString();
        }
        else
        {
            messageBody = file.readAll();
        }
    }

    qDebug() << "Sending message body" << messageBody;
    // In a productive class, there would be a lot of TCP and SMTP stuff here.

    ui.output->setText( "Sent email with body:\r\n" + messageBody );
}