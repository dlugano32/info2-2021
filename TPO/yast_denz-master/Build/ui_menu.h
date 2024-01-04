/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Game;
    QPushButton *start;
    QToolButton *right;
    QToolButton *left;
    QLabel *dif;
    QLineEdit *file;
    QToolButton *browse;
    QWidget *tab_2;
    QComboBox *resolution;
    QLabel *label_res;
    QComboBox *framerate;
    QLabel *label_fr;
    QLabel *label_port;
    QLineEdit *port;

    void setupUi(QMainWindow *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->setEnabled(true);
        menu->resize(380, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy);
        menu->setMaximumSize(QSize(380, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Executable/media/icon.png"), QSize(), QIcon::Normal, QIcon::On);
        menu->setWindowIcon(icon);
        menu->setAutoFillBackground(false);
        centralwidget = new QWidget(menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(380, 300));
        centralwidget->setMaximumSize(QSize(380, 300));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 341, 281));
        Game = new QWidget();
        Game->setObjectName(QString::fromUtf8("Game"));
        start = new QPushButton(Game);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(120, 210, 101, 31));
        right = new QToolButton(Game);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(70, 70, 31, 31));
        left = new QToolButton(Game);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(240, 70, 31, 31));
        dif = new QLabel(Game);
        dif->setObjectName(QString::fromUtf8("dif"));
        dif->setGeometry(QRect(110, 70, 121, 31));
        dif->setFrameShape(QFrame::Box);
        dif->setAlignment(Qt::AlignCenter);
        dif->setWordWrap(false);
        file = new QLineEdit(Game);
        file->setObjectName(QString::fromUtf8("file"));
        file->setGeometry(QRect(70, 20, 161, 31));
        file->setReadOnly(true);
        browse = new QToolButton(Game);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(240, 20, 31, 31));
        tabWidget->addTab(Game, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        resolution = new QComboBox(tab_2);
        resolution->addItem(QString());
        resolution->addItem(QString());
        resolution->addItem(QString());
        resolution->setObjectName(QString::fromUtf8("resolution"));
        resolution->setGeometry(QRect(220, 10, 101, 31));
        label_res = new QLabel(tab_2);
        label_res->setObjectName(QString::fromUtf8("label_res"));
        label_res->setGeometry(QRect(10, 10, 201, 31));
        framerate = new QComboBox(tab_2);
        framerate->addItem(QString());
        framerate->addItem(QString());
        framerate->addItem(QString());
        framerate->addItem(QString());
        framerate->addItem(QString());
        framerate->addItem(QString());
        framerate->setObjectName(QString::fromUtf8("framerate"));
        framerate->setGeometry(QRect(220, 50, 101, 31));
        label_fr = new QLabel(tab_2);
        label_fr->setObjectName(QString::fromUtf8("label_fr"));
        label_fr->setGeometry(QRect(10, 50, 201, 31));
        label_port = new QLabel(tab_2);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(10, 90, 201, 31));
        port = new QLineEdit(tab_2);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(220, 90, 101, 25));
        port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab_2, QString());
        menu->setCentralWidget(centralwidget);

        retranslateUi(menu);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QMainWindow *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Just Dance! Menu", nullptr));
        start->setText(QApplication::translate("menu", "Start", nullptr));
        right->setText(QApplication::translate("menu", "\342\254\205", nullptr));
        left->setText(QApplication::translate("menu", "\342\236\241", nullptr));
        dif->setText(QApplication::translate("menu", "Easy", nullptr));
        file->setText(QApplication::translate("menu", "Select Level", nullptr));
        browse->setText(QApplication::translate("menu", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Game), QApplication::translate("menu", "Game", nullptr));
        resolution->setItemText(0, QApplication::translate("menu", "1280 720", nullptr));
        resolution->setItemText(1, QApplication::translate("menu", "1366 768", nullptr));
        resolution->setItemText(2, QApplication::translate("menu", "1920 1080", nullptr));

        label_res->setText(QApplication::translate("menu", "Resolution", nullptr));
        framerate->setItemText(0, QApplication::translate("menu", "0", nullptr));
        framerate->setItemText(1, QApplication::translate("menu", "60", nullptr));
        framerate->setItemText(2, QApplication::translate("menu", "75", nullptr));
        framerate->setItemText(3, QApplication::translate("menu", "120", nullptr));
        framerate->setItemText(4, QApplication::translate("menu", "144", nullptr));
        framerate->setItemText(5, QApplication::translate("menu", "240", nullptr));

        label_fr->setText(QApplication::translate("menu", "Framerate (0 = Unlimited)", nullptr));
        label_port->setText(QApplication::translate("menu", "Port", nullptr));
        port->setText(QApplication::translate("menu", "4000", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("menu", "Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
