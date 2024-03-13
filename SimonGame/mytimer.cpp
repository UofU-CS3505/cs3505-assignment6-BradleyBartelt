#include "mytimer.h"
#include <QDebug>

MyTimer::MyTimer()
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, &QTimer::timeout,
            this, &MyTimer::MyTimerSlot);

    // msec
    timer->start(500);
}

void MyTimer::MyTimerSlot()
{
    qDebug() << "Timer...";
}
