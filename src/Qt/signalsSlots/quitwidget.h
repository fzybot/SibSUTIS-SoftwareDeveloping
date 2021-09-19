#ifndef QUITWIDGET_H
#define QUITWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QMoveEvent>


class QuitWidget:public QWidget
{
private:
    QLabel *label;
    QString text = "Hello";

    QLabel *moveLabel;
public:
    QuitWidget(QWidget *parent = nullptr);

    ~QuitWidget();

    void keyPressEvent(QKeyEvent *e);
    void moveEvent(QMoveEvent *e);
};

#endif // QUITWIDGET_H
