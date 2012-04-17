#ifndef HEARTRATEMONITOR_H
#define HEARTRATEMONITOR_H

#include <QObject>
#include <QTimer>

#define RED_VALUE_RING_BUFFER_SIZE 8
#define HEART_RATE_UPDATE_INTERVAL 2000 // ms

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

private:
    void construct();
    void run();

public slots:

private slots:
#ifdef SIMULATE_HEART
    void changeRate();
#endif
    void emitHeartBeat();

private:
    Q_DISABLE_COPY(HeartRateMonitor)

    ushort avgRedValueBuffer[RED_VALUE_RING_BUFFER_SIZE];
    uint avgRedValueBufferIndex;
    uint avgRedValueBufferCount;
    quint64 lastHeartBeatTimestamp;
    bool isUnderAvgRedValue;

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
