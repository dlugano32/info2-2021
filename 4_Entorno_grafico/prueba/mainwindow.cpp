#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Etiqueta1->setText("Holanda");
    ui->Texto->setText("Ingrese valor...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

