#include "stdafx.h"
#include "EMailSenderUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EMailSenderUI w;
    w.show();
    return a.exec();
}
