#ifndef HEARTRATEMONITOR_H
#define HEARTRATEMONITOR_H

#include <QObject>

class HeartRateMonitor : public QObject
{
    Q_OBJECT
public:
    explicit HeartRateMonitor(QObject *parent = 0);

signals:
    void heartBeat();
    void heartRate(int rate);

public slots:

private:
    Q_DISABLE_COPY(HeartRateMonitor)
};

#endif // HEARTRATEMONITOR_H
