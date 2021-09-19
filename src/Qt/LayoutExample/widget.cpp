#include "widget.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QGridLayout>
#include <QToolButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Абсолютное позиционирование
    // Виджет для редактирования текста (QTextEdit)
//    QTextEdit *example_1 = new QTextEdit(this);
//    example_1->setGeometry(0, 0, 200, 300); // Задание размеров

    ///////////////////////////////////////////////////////////////////
    // QVBoxLayout & QHBoxLayout
//    QVBoxLayout *example_box = new QVBoxLayout(this);
//    QHBoxLayout *example_box = new QHBoxLayout(this);
//    example_box->setSpacing(1); // устанавливается дистанция между виджетами [пиксель]

//    // Добавляем редактор текста
//    QTextEdit *edit_line = new QTextEdit(this);
//    edit_line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    // Добавляем 3 кнопки
//    QPushButton *one = new QPushButton("1", this);
//    one->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    QPushButton *two = new QPushButton("2", this);
//    two->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    QPushButton *equal = new QPushButton("=", this);
//    equal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    // Добавляем каждый элемент в объект QHBoxLayout по очереди
//    example_box->addWidget(edit_line);
//    example_box->addWidget(one);
//    example_box->addWidget(two);
//    example_box->addWidget(equal);

//    // Устанавливаем основной метод компановки
//    setLayout(example_box);

    ///////////////////////////////////////////////////////////////////
    // Устанавливаем базовый Layout vbox. hbox будет помещен внутрь него
//    QVBoxLayout *vbox = new QVBoxLayout(this);
//    QHBoxLayout *hbox = new QHBoxLayout();

//    QListWidget *list = new QListWidget(this);
//    list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    list->addItem("One");
//    list->addItem("Two");
//    list->addItem("Three");
//    list->addItem("Hello World!");

//    QPushButton *okBtn = new QPushButton("OK", this);
//    QPushButton* cancelBtn = new QPushButton("Cancel", this);
//    QPushButton* applyBtn = new QPushButton("Apply", this);

//    hbox->addWidget(okBtn, 1, Qt::AlignRight);
//    hbox->addWidget(cancelBtn, 0);
//    hbox->addWidget(applyBtn, 0);

//    vbox->addWidget(list);
//    vbox->addLayout(hbox);

    ///////////////////////////////////////////////////////////////////
    // Grid Layout
    QGridLayout *grid = new QGridLayout(this);
    grid->setSpacing(2);

    // Значения кнопок
    QList<QString> values(
                { "1", "2", "3", "+",
                  "4", "5", "6", "-",
                  "7", "8", "9", "*",
                  ".", "0", "=", "/"
                });
    // Массив кнопок (создание объекта кнопок для каждого значения строки values)
    QToolButton *digitButtons[16];
    for (int i=0; i<values.length(); i++){
        digitButtons[i] = new QToolButton();
        digitButtons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        digitButtons[i]->setText(values[i]);
    }

    int pos = 0;

    for (int i=0; i<4; i++) {
     for (int j=0; j<4; j++) {

       digitButtons[pos]->setFixedSize(40, 40);
       grid->addWidget(digitButtons[pos], i, j);
       pos++;
     }
    }

    setLayout(grid);

}

Widget::~Widget()
{
}

