#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) : QMainWindow(parent), ui(new Ui::menu)
{
        ui->setupUi(this);

        dif = 3;

        connect(ui->start, SIGNAL(clicked(bool)), this, SLOT(game_start()));
        ui->port->setInputMask("99999");
}

menu::~menu()
{
        delete ui;
}

void menu::game_start()
{
        QString aux = "./game ";

        aux += ui->resolution->currentText();
        aux += " " + ui->framerate->currentText();
        aux += " " + QString::number(dif);
        aux += " " + ((ui->file->text() == "Select Level") ? "default" : ui->file->text());
        aux += " " + ui->port->text();

        this->hide();
        system(aux.toStdString().c_str());
        this->show();
}

void menu::on_left_clicked()
{
        dif--;
        if(dif == 0) dif = 3;
        switch(dif)
        {
            case 1:
                ui->dif->setText("Hard");
                break;
            case 2:
                ui->dif->setText("Medium");
                break;
            case 3:
                ui->dif->setText("Easy");
                break;
        }
}

void menu::on_right_clicked()
{
    dif++;
    if(dif == 4) dif = 1;
    switch(dif)
    {
        case 1:
            ui->dif->setText("Hard");
            break;
        case 2:
            ui->dif->setText("Medium");
            break;
        case 3:
            ui->dif->setText("Easy");
            break;
    }

}

void menu::on_browse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select Level"), "media/", tr("Level Files (*.lvl)"));
    ui->file->setText((filename == nullptr) ? "Select Level" : filename.remove(0, (QDir::currentPath()).length() + 1));
}
