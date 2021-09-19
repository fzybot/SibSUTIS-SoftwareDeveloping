#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget testWidget;
    testWidget.setGeometry(300, 300, 300, 300);
    testWidget.show();
    return a.exec();
}
