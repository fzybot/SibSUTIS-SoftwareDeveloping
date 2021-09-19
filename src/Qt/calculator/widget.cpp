#include "widget.h"
#include <QToolButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    buttonOne = new QToolButton(this);
    buttonOne->setText("1");
    buttonOne->resize(50, 20);
    buttonOne->move(50, 100);
    connect(buttonOne, SIGNAL(clicked()), this, SLOT(digitClicked()));

    buttonTwo = new QToolButton(this);
    buttonTwo->setText("2");
    buttonTwo->resize(50, 20);
    buttonTwo->move(100, 100);
    connect(buttonTwo, SIGNAL(clicked()), this, SLOT(digitClicked()));

    display = new QLineEdit("0", this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    add = new QToolButton(this);
    add->setText("+");
    add->resize(50, 20);
    add->move(50, 50);
    connect(add, SIGNAL(clicked()), this, SLOT(additiveOperatorClicked()));
}

Widget::~Widget()
{
}

void Widget::digitClicked(){
    //получение сигнала от кнопки, которую мы нажали
    QToolButton *clickedButton = qobject_cast<QToolButton *>(sender());
    // преобразование текста внутри кнопки в целочисленную переменную
    int digitValue = clickedButton->text().toInt();
    if (waitOperand) {
        display->clear();
        waitOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

void Widget::additiveOperatorClicked(){
    //получение сигнала от кнопки, которую мы нажали
    QToolButton *clickedButton = qobject_cast<QToolButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            display->setText("0");
            localSumm = 0;
            pendingAdditiveOperator.clear();
            return;
        }
        display->setText(QString::number(localSumm));
    } else {
        localSumm = operand;
    }

    pendingAdditiveOperator = clickedOperator;
    waitOperand = true;
}

bool Widget::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == "+") {
        localSumm += rightOperand;
    }
    if(pendingOperator == "-"){
        localSumm -= rightOperand;
    }
    return true;
}

