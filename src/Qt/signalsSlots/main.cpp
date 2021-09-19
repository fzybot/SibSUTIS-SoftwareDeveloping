#include <iostream>
#include <counter.h>
#include <QDebug>
#include <quitwidget.h>
#include <QApplication>

//using namespace std;

int main(int argc, char *argv[])
{
    // First part
//    Counter counter_one, counter_two;

//    QObject::connect(&counter_one, SIGNAL(valueChanged(int)),
//               &counter_two, SLOT(setValue(int)));

//    qDebug() << "counter_one and counter_two:";
//    qDebug() << counter_one.value() << counter_two.value();

//    counter_one.setValue(12);

//    qDebug() << "counter_one and counter_two:";
//    qDebug() << counter_one.value() << counter_two.value();

//    counter_two.setValue(45);

//    qDebug() << "counter_one and counter_two:";
//    qDebug() << counter_one.value() << counter_two.value();

    // Quit button
    QApplication a(argc, argv);
    QuitWidget quit;
    quit.resize(300, 300);
    quit.setWindowTitle("Quit");
    quit.show();

    return a.exec();
}
