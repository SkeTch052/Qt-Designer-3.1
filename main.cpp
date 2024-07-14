#include "connectiondialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnectionDialog dialog;

    dialog.setButtonTexts();

    dialog.show();

    return a.exec();
}
