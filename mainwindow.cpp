#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connectiondialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , connectiondialog(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Менеджер БД");
    setFixedSize(this->size());
    this->setStyleSheet("QSizeGrip { width: 0px; height: 0px; }");
}

MainWindow::~MainWindow()
{
    delete ui;
    if (connectiondialog){
        delete connectiondialog;
    }
}

void MainWindow::on_pb_ToDialogWindow_clicked()
{

    if (!connectiondialog) {
        connectiondialog = new ConnectionDialog(this);
    }

    connectiondialog->setButtonTexts();

    connectiondialog->show();
}

