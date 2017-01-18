#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EMailSenderUI.h"

class EMailSenderUI : public QMainWindow
{
    Q_OBJECT

public:
    EMailSenderUI( QWidget *parent = Q_NULLPTR );

private slots:

    void on_openFile_clicked();
    void on_sendFromFile_clicked();

private:

    Ui::EMailSenderUIClass ui;
};
