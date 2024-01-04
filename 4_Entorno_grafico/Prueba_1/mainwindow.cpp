#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->to_C, SIGNAL(clicked(bool)), this, SLOT(convertir_toC()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_to_F_clicked()
{
    float value;
    bool ok;

    value=ui->lineEdit_C->text().toFloat(&ok); //Leo un Qstring, es como un string std pero mejor

    if(ok)
    {
        value= value*(9.0/5.0)+32.0;
        ui->lineEdit_F->setText(QString::number(value,'f',2) );
    }

}

void MainWindow::convertir_toC() //Hecho a mano
{
       float value;
       bool ok;

       value=ui->lineEdit_F->text().toFloat(&ok);

       if(ok)
       {
            value=(value -32.0) *(5.0/9.0);
            ui->lineEdit_C->setText( QString::number(value, 'f', 2) );
       }
}
void MainWindow::on_exit_clicked()
{
    this->close();
}
