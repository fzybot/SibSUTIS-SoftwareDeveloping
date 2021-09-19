#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void digitClicked();
    void additiveOperatorClicked();

private:

    QLineEdit *display;
    QToolButton *buttonOne;
    QToolButton *buttonTwo;
    QToolButton *add;

    double localSumm;

    bool waitOperand;
    QString pendingAdditiveOperator;


    bool calculate(double rightOperand, const QString &pendingOperator);
};
#endif // WIDGET_H
