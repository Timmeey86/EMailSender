#include "stdafx.h"
#include "EMailSenderUI.h"

#include <QtWidgets/qfiledialog.h>

#include <EMailSenderLib/Mail/FakeEmailSender.h>

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
    Mail::FakeEmailSender fakeSender;
    fakeSender.setFileName( ui.filePath->text() );
    fakeSender.readFile();
    fakeSender.sendEmail();

    ui.output->setText( "Sent email with body:\r\n" + fakeSender.getMessageBody() );
}
