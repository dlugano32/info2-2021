/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditPort;
    QPushButton *conectar;
    QPlainTextEdit *plainTextEnviar;
    QLabel *label_2;
    QPushButton *Enviar;
    QPlainTextEdit *plainTextRecibir;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 301);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEditPort = new QLineEdit(centralWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(80, 20, 241, 20));
        conectar = new QPushButton(centralWidget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->setGeometry(QRect(170, 50, 75, 23));
        plainTextEnviar = new QPlainTextEdit(centralWidget);
        plainTextEnviar->setObjectName(QString::fromUtf8("plainTextEnviar"));
        plainTextEnviar->setGeometry(QRect(10, 90, 181, 161));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 20, 31, 16));
        Enviar = new QPushButton(centralWidget);
        Enviar->setObjectName(QString::fromUtf8("Enviar"));
        Enviar->setGeometry(QRect(60, 270, 75, 23));
        plainTextRecibir = new QPlainTextEdit(centralWidget);
        plainTextRecibir->setObjectName(QString::fromUtf8("plainTextRecibir"));
        plainTextRecibir->setGeometry(QRect(200, 90, 181, 161));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Servidor", nullptr));
        conectar->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port", nullptr));
        Enviar->setText(QApplication::translate("MainWindow", "Enviar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
