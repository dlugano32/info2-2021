#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    servidor = NULL;
    socket = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_conectar_clicked()
{
    if( !servidor )
    {
        servidor = new QTcpServer(this);
        connect(servidor, SIGNAL(newConnection()),this, SLOT(nuevaConexion()) );

        servidor->listen(QHostAddress::Any, ui->lineEditPort->text().toUInt());

        ui->conectar->setText("Conectado");
        ui->conectar->setStyleSheet("background-color: rgb(0,255,0);");
    }
    else
    {
        if(socket)
        {
            socket->close();
            delete socket;
            socket = NULL;
        }

        servidor->close();
        delete servidor;
        servidor = NULL;

        ui->conectar->setText("Desconectado");
        ui->conectar->setStyleSheet("background-color: rgb(255,0,0);");
    }
}

void MainWindow::on_Enviar_clicked()
{
    if(socket)
    {
        socket->write(ui->plainTextEnviar->toPlainText().toUtf8());
    }
}

void MainWindow::nuevaConexion(void)
{
    if(!socket)
    {
        socket = new QTcpSocket;
        socket = servidor->nextPendingConnection();
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    }
}




void MainWindow::readyRead()
{

    ui->plainTextRecibir->appendPlainText( socket->read(socket->bytesAvailable()) );
}

void MainWindow::disconnected()
{
    socket->close();
    delete socket;
    socket = NULL;
}
