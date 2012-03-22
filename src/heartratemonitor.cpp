#include "heartratemonitor.h"

#include <QTimer>

HeartRateMonitor::HeartRateMonitor(QObject *parent) :
    QObject(parent)
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), SIGNAL(heartBeat()));
    timer->start();
}
