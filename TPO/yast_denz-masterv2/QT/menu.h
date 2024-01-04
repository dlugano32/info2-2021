#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QFileSelector>
#include <QFileDialog>

namespace Ui
{
        class menu;
}

class menu : public QMainWindow
{
        Q_OBJECT

public:
        explicit menu(QWidget *parent = nullptr);
        ~menu();

private slots:
        void game_start();
        void on_right_clicked();
        void on_left_clicked();

        void on_browse_clicked();

private:
        Ui::menu *ui;
        int dif;
};
#endif
