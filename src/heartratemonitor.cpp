#include "heartratemonitor.h"

#include <QTimer>
#include <QDebug>

HeartRateMonitor::HeartRateMonitor(QObject *parent) :
    QObject(parent)
{
    QTimer *timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer, SIGNAL(timeout()), SIGNAL(heartBeat()));
    timer->start();
}
