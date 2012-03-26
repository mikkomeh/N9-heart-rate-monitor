#include "heartratemonitor.h"

#include <stdlib.h>
#include <QTimer>
#include <QDebug>

HeartRateMonitor::HeartRateMonitor(QObject *parent) :
    QObject(parent),
    m_historyCount(0),
    m_firstIndex(0),
    m_curIndex(-1),
    timerInterval(-1)
{
#ifdef SIMULATE_HEART
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(emitHeartBeat()));

    QTimer *timer2 = new QTimer(this);
    timer2->setInterval(4000);
    connect(timer2, SIGNAL(timeout()), SLOT(changeRate()));
    timer2->start();
#endif
}

HeartRateMonitor::~HeartRateMonitor()
{
}

int HeartRateMonitor::getHistory(int data[])
{
    for (int i = 0; i < m_historyCount; i++) {
        data[i] = m_history[(m_firstIndex + i) % HistoryMaxCount];
    }
    return m_historyCount;
}

#ifdef SIMULATE_HEART
void HeartRateMonitor::changeRate()
{
    const int rate = random() % 150 + 50;
    emit heartRate(rate);
    timerInterval = 60.0 / (double)rate * 1000.0;
    addToHistory(rate);
    if (!timer->isActive()) {
        timer->start();
    }
}
#endif

void HeartRateMonitor::emitHeartBeat()
{
    emit heartBeat();
#ifdef SIMULATE_HEART
    if (timerInterval != -1) {
        timer->setInterval(timerInterval);
        timer->start();
        timerInterval = -1;
    }
#endif
}

void HeartRateMonitor::addToHistory(int value)
{
    m_curIndex++;
    m_curIndex %= HistoryMaxCount;
    if (m_historyCount < HistoryMaxCount) {
        m_historyCount++;
    } else {
        m_firstIndex++;
    }
    m_history[m_curIndex] = value;
}
