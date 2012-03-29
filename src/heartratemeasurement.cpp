#include "heartratemeasurement.h"

HeartRateMeasurement::HeartRateMeasurement(QObject *parent) :
    QObject(parent), m_time(QDateTime::currentDateTime()), m_value(-1)
{
}

HeartRateMeasurement::HeartRateMeasurement(QDateTime time, int value, QObject *parent) :
    QObject(parent), m_time(time), m_value(value)
{
}

HeartRateMeasurement::~HeartRateMeasurement()
{
}

HeartRateMeasurement::HeartRateMeasurement(const HeartRateMeasurement &other)
    : QObject(other.parent())
{
    m_time = other.m_time;
    m_value = other.m_value;
}

HeartRateMeasurement &HeartRateMeasurement::operator =(const HeartRateMeasurement &other)
{
    m_time = other.m_time;
    m_value = other.m_value;
    return *this;
}

QDateTime HeartRateMeasurement::time() const
{
    return m_time;
}

int HeartRateMeasurement::value() const
{
    return m_value;
}

void HeartRateMeasurement::setTime(const QDateTime &time)
{
    m_time = time;
}

void HeartRateMeasurement::setValue(int value)
{
    m_value = value;
}
