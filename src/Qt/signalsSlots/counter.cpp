#include "counter.h"
#include <QDebug>

void Counter::setValue(int value)
{

   if (value != this->m_value) {
     this->m_value = value;
     qDebug() << "Value is changed: " << this->m_value;
     // emit вырабатывает сигнал valueChanged() объекта в новым значением в качестве аргумента
     emit valueChanged(value);
   }

}
