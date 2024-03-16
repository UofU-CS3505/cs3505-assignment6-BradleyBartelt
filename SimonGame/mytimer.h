#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>

///
/// \brief The MyTimer class is used for calling specific functions after a short delay, so we can display certin button colors for
/// a short time, then change them back to normal.
///
class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;

public slots:
    void MyTimerSlot();

};

#endif // MYTIMER_H
