/********************************************************************************
** Form generated from reading UI file 'EMailSenderUI.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILSENDERUI_H
#define UI_EMAILSENDERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EMailSenderUIClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *filePath;
    QPushButton *sendFromFile;
    QPushButton *openFile;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *output;

    void setupUi(QMainWindow *EMailSenderUIClass)
    {
        if (EMailSenderUIClass->objectName().isEmpty())
            EMailSenderUIClass->setObjectName(QStringLiteral("EMailSenderUIClass"));
        EMailSenderUIClass->resize(591, 272);
        centralWidget = new QWidget(EMailSenderUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        filePath = new QLineEdit(centralWidget);
        filePath->setObjectName(QStringLiteral("filePath"));
        filePath->setReadOnly(true);

        gridLayout->addWidget(filePath, 0, 1, 1, 2);

        sendFromFile = new QPushButton(centralWidget);
        sendFromFile->setObjectName(QStringLiteral("sendFromFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sendFromFile->sizePolicy().hasHeightForWidth());
        sendFromFile->setSizePolicy(sizePolicy1);
        sendFromFile->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(sendFromFile, 0, 4, 1, 1);

        openFile = new QPushButton(centralWidget);
        openFile->setObjectName(QStringLiteral("openFile"));
        sizePolicy1.setHeightForWidth(openFile->sizePolicy().hasHeightForWidth());
        openFile->setSizePolicy(sizePolicy1);
        openFile->setMaximumSize(QSize(23, 16777215));

        gridLayout->addWidget(openFile, 0, 3, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        output = new QLabel(groupBox);
        output->setObjectName(QStringLiteral("output"));
        output->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        output->setWordWrap(true);

        gridLayout_2->addWidget(output, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 5);

        EMailSenderUIClass->setCentralWidget(centralWidget);

        retranslateUi(EMailSenderUIClass);

        QMetaObject::connectSlotsByName(EMailSenderUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *EMailSenderUIClass)
    {
        EMailSenderUIClass->setWindowTitle(QApplication::translate("EMailSenderUIClass", "EMailSenderUI", 0));
        label->setText(QApplication::translate("EMailSenderUIClass", "File:", 0));
        sendFromFile->setText(QApplication::translate("EMailSenderUIClass", "Send", 0));
        openFile->setText(QApplication::translate("EMailSenderUIClass", "...", 0));
        groupBox->setTitle(QApplication::translate("EMailSenderUIClass", "Output", 0));
        output->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EMailSenderUIClass: public Ui_EMailSenderUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILSENDERUI_H
