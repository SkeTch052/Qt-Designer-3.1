#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Подключение к БД");
    ui->sb_Port->setStyleSheet("QSpinBox::up-button, QSpinBox::down-button { width: 0; }");
    ui->pb_SaveQString->setAutoDefault(true);
    connect(ui->pb_Cancel, &QPushButton::clicked, this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_SaveQString_clicked()
{
    QString host = ui->le_Host->text();
    QString dbName = ui->le_DB->text();
    QString login = ui->le_Login->text();
    QString password = ui->le_Pass->text();
    uint port = ui->sb_Port->text().toUInt();

    QString connectionString = QString("host=%1, port=%2, dbname=%3, user=%4, password=%5;")
                                   .arg(host)
                                   .arg(port)
                                   .arg(dbName)
                                   .arg(login)
                                   .arg(password);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Строка подключения");
    msgBox.setText(connectionString);
    msgBox.setStandardButtons(QMessageBox::Ok);

    if (msgBox.exec() == QMessageBox::Ok) {
        QApplication::quit();
    }
}

