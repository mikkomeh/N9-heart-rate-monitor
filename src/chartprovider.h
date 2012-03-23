#ifndef CHARTPROVIDER_H
#define CHARTPROVIDER_H

#include <QDeclarativeImageProvider>

class ChartProvider : public QDeclarativeImageProvider
{
public:
    explicit ChartProvider(QDeclarativeImageProvider::ImageType type);
    virtual ~ChartProvider();
    QImage requestImage(const QString& id, QSize* size, const QSize& requestedSize);
    QPixmap requestPixmap(const QString& id, QSize* size, const QSize& requestedSize);

private:
    Q_DISABLE_COPY(ChartProvider)

    QImage createChart(int width, int height);
    void drawData(QPainter &painter, QImage &image);
    void drawAxels(QPainter &painter, QImage &image);
};

#endif // CHARTPROVIDER_H
