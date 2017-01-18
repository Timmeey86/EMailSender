#include "stdafx.h"
#include "EMailSenderUI.h"

#include <QtWidgets/qfiledialog.h>

#include <EMailSenderLib/Core/EmailProcessingService.h>
#include <EMailSenderLib/File/FileReaderServiceFactory.h>
#include <EMailSenderLib/Mail/FakeEmailService.h>
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
    auto fakeSender = std::make_shared<Mail::FakeEmailService>();

    auto fileReaderService = File::FileReaderServiceFactory().createFileReaderService( ui.filePath->text() );

    auto emailProcessingService = std::make_shared<Core::EmailProcessingService>( fileReaderService, fakeSender );

    auto sentText = Core::EmailProcessingService( fileReaderService, fakeSender ).sendMessage();

    ui.output->setText( sentText );
}

void EMailSenderUI::on_sendFromDatabase_clicked()
{
    auto fakeSender = std::make_shared<Mail::FakeEmailService>();

    auto databaseReaderService = std::make_shared<Database::DatabaseReaderService>(
        std::make_shared<Database::FakeDatabase>()
        );

    auto sentText = Core::EmailProcessingService( databaseReaderService, fakeSender ).sendMessage();

    ui.output->setText( sentText );
}
