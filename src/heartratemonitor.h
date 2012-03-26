#ifndef HEARTRATEMONITOR_H
#define HEARTRATEMONITOR_H

#include <QObject>

class QTimer;

class HeartRateMonitor : public QObject
{
    Q_OBJECT
public:
    explicit HeartRateMonitor(QObject *parent = 0);
    virtual ~HeartRateMonitor();

    enum Constants {
        HistoryMaxCount = 24
    };
    int getHistory(int data[]);


signals:
    void heartBeat();
    void heartRate(int rate);

private slots:
#ifdef SIMULATE_HEART
    void changeRate();
#endif
    void emitHeartBeat();

private:
    Q_DISABLE_COPY(HeartRateMonitor)

    void addToHistory(int value);

    QTimer *timer;
    int m_history[HistoryMaxCount];
    int m_historyCount;
    int m_firstIndex;
    int m_curIndex;

#ifdef SIMULATE_HEART
    int timerInterval;
#endif
};

#endif // HEARTRATEMONITOR_H
