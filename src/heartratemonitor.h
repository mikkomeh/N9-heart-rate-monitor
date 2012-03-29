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
        HistoryMaxCount = 60
    };
    int getHistory(int data[]);

signals:
    void heartBeat();
    void heartRate(int rate);

public slots:

private slots:
#ifdef SIMULATE_HEART
    void changeRate();
#endif
    void emitHeartBeat();

private:
    Q_DISABLE_COPY(HeartRateMonitor)

    void addToHistory(int value);
    int m_history[HistoryMaxCount];
    int m_historyCount;
    int m_firstIndex;
    int m_curIndex;

    int m_heartRate;

#ifdef SIMULATE_HEART
    QTimer *timer;
    int timerInterval;
#endif
};

#endif // HEARTRATEMONITOR_H
