#ifndef CHARTPROVIDER_H
#define CHARTPROVIDER_H

#include <QDeclarativeImageProvider>

class HeartRateMonitor;

class ChartProvider : public QDeclarativeImageProvider
{
public:
    ChartProvider(QDeclarativeImageProvider::ImageType type, HeartRateMonitor &m_monitor);
    virtual ~ChartProvider();
    QImage requestImage(const QString& id, QSize* size, const QSize& requestedSize);
    QPixmap requestPixmap(const QString& id, QSize* size, const QSize& requestedSize);

private:
    Q_DISABLE_COPY(ChartProvider)

    QImage createChart(int width, int height);
    void drawData(QPainter &painter, QImage &image);
    void drawAxels(QPainter &painter, QImage &image);

    HeartRateMonitor &m_monitor;
};

#endif // CHARTPROVIDER_H
