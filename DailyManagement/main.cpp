#include "calendarPage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calendarPage *w = new calendarPage;
    w->show();
    return a.exec();
}
