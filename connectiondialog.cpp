#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>

ConnectionDialog::ConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    setWindowTitle("Подключение к БД");
    ui->sb_Port->setStyleSheet("QSpinBox::up-button, QSpinBox::down-button { width: 0; }");
    ui->sb_Port->setValue(5432);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::setButtonTexts()
{
    ui->dbb_Ok_Cancel->button(QDialogButtonBox::Cancel)->setText("Отмена");
}

void ConnectionDialog::on_dbb_Ok_Cancel_rejected(){
    QApplication::exit(0);
}

void ConnectionDialog::on_dbb_Ok_Cancel_accepted()
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
         QApplication::exit(0);
    }
}
