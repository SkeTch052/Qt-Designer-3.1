#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connectiondialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ToDialogWindow_clicked();

private:
    Ui::MainWindow *ui;
    ConnectionDialog *connectiondialog;
};

#endif // MAINWINDOW_H
