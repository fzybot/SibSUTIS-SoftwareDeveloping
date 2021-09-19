#ifndef COUNTER_H
#define COUNTER_H
#include <QObject>

class Counter : public QObject
{
   Q_OBJECT

private:

   int m_value;

public:

   Counter() {
       m_value = 0;
   }

   int value() const {
       return m_value;
   }

public slots:

   void setValue(int value);

signals:

   void valueChanged(int newValue);


};

#endif // COUNTER_H
