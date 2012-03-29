#ifndef HEARTRATEMEASUREMENT_H
#define HEARTRATEMEASUREMENT_H

#include <QObject>
#include <QDateTime>

class HeartRateMeasurement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QDateTime time READ time WRITE setTime)
    Q_PROPERTY(int value READ value WRITE setValue)

public:
    HeartRateMeasurement(QObject *parent = 0);
    HeartRateMeasurement(QDateTime time, int value, QObject *parent = 0);
    virtual ~HeartRateMeasurement();
    HeartRateMeasurement(const HeartRateMeasurement &other);
    HeartRateMeasurement &operator=(const HeartRateMeasurement &other);

    QDateTime time() const;
    int value() const;

public slots:
    void setTime(const QDateTime &time);
    void setValue(int value);

private:
    QDateTime m_time;
    int m_value;
};

#endif // HEARTRATEMEASUREMENT_H
