#include "quitwidget.h"
#include <QPushButton>
#include <QApplication>
#include <QString>

QuitWidget::QuitWidget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton *quitBtn = new QPushButton("Quit", this);
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);


    label = new QLabel(text, this);
    label->move(10, 50);

    moveLabel = new QLabel("Move info", this);
    moveLabel->move(10, 30);

}

void QuitWidget::keyPressEvent(QKeyEvent *event){

    label->setText(event->text());
}

void QuitWidget::moveEvent(QMoveEvent *event){
    int x = event->pos().x();
    int y = event->pos().y();
    QString position = QString::number(x) + ", " + QString::number(y);
    moveLabel->setText(position);
}

QuitWidget::~QuitWidget()
{
}
