#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TaskOrganizer taskOrganizer;
    TaskOrganizerController controller(&taskOrganizer);

    MainWindow w(&controller);
    w.show();

    return a.exec();
}
