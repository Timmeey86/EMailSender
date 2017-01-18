#include "stdafx.h"
#include "EMailSenderUI.h"

#include <QtWidgets/qfiledialog.h>

#include <EMailSenderLib/File/FileReaderService.h>
#include <EMailSenderLib/File/FlatFileReader.h>
#include <EMailSenderLib/File/XMLFileReader.h>
#include <EMailSenderLib/Mail/FakeEmailSender.h>
#include <EMailSenderLib/Database/DatabaseReaderService.h>
#include <EMailSenderLib/Database/FakeDatabase.h>

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
    auto flatFileReader = std::make_shared<File::FlatFileReader>();
    auto xmlFileReader = std::make_shared<File::XMLFileReader>();

    auto fileReaderService = std::make_shared<File::FileReaderService>( flatFileReader );
    fileReaderService->registerFormatReader( xmlFileReader );

    auto messageBody = fileReaderService->getMessageBodyFromFile( ui.filePath->text() );

    Mail::FakeEmailSender fakeSender;
    fakeSender.sendEmail( messageBody );

    ui.output->setText( "Sent email with body:\r\n" + messageBody );
}

void EMailSenderUI::on_sendFromDatabase_clicked()
{
    auto fakeSender = std::make_shared<Mail::FakeEmailSender>();

    Database::DatabaseReaderService service( std::make_shared<Database::FakeDatabase>() );

    auto messageBody = service.getMessageBody();
        
    ui.output->setText( "Sent email with body:\r\n" + messageBody );
}
