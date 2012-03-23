#include "chartprovider.h"

#include <QImage>
#include <QPainter>
#include <QBrush>
#include <QColor>

#include <QDebug>

ChartProvider::ChartProvider(ImageType type) :
    QDeclarativeImageProvider(type)
{
}

ChartProvider::~ChartProvider()
{
}

QImage ChartProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id)
    qDebug() << __PRETTY_FUNCTION__ << requestedSize;
    const int defaultWidth = 400;
    const int defaultHeight = 200;
    const int width = requestedSize.width() > 0 ? requestedSize.width() : defaultWidth;
    const int height = requestedSize.height() > 0 ? requestedSize.height() : defaultHeight;
    QImage image = createChart(width, height);
    if (size) {
        *size = image.size();
    }
    return image;
}

QPixmap ChartProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id)
    qDebug() << __PRETTY_FUNCTION__;
    QPixmap pixmap(requestedSize);
    *size = requestedSize;
    return pixmap;
}

QImage ChartProvider::createChart(int width, int height)
{
    QImage image(width, height, QImage::Format_ARGB32);
    QPainter painter;
    painter.begin(&image);
    drawAxels(painter, image);
    drawData(painter, image);
    painter.end();
    return image;
}

void ChartProvider::drawAxels(QPainter &painter, QImage &image)
{
    const int width = image.width();
    const int height = image.height() - 10;
    QFontMetrics fm = painter.fontMetrics();
    const int left = 50;
    const int textMargin = 8;

    QColor color(255, 255, 255);
    QPen pen(color);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    painter.drawLine(left, 1, left, height);
    painter.drawLine(left, height, width - 1, height);

    const int scale[] = {0, 40, 80, 120, 160, 200};
    const int scaleSize = 6;
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);

    const int step = height / scaleSize;
    int yPos = height;
    for (int i = 0; i < scaleSize; i++) {
        QString text = QString("%1").arg(scale[i]);
        const int textWidth = fm.width(text);
        painter.drawText(left - textWidth - textMargin, yPos + (fm.height() / 2) - 3, text);
        painter.drawLine(left - 5, yPos, width, yPos);
        yPos -= step;
    }
}

void ChartProvider::drawData(QPainter &painter, QImage &image)
{
    const int width = image.width();
    const int height = image.height() - 10;
    const int left = 50;

    const int data[] = {87, 99, 111, 118, 122, 125, 129, 128, 128, 150, 125, 118};
    const int dataCount = 12;
    const int step = (width - left) / dataCount;
    double s = height / 240.0;

    QColor color(255, 0, 0);
    QPen pen(color);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QPolygon polygon;
    int yPos = height - (s * (double)data[0]);
    int xPos = left;
    polygon.append(QPoint(xPos, yPos));
    for (int i = 1; i < dataCount; i++) {
        xPos += step;
        yPos = height - (s * (double)data[i]);
        polygon.append(QPoint(xPos, yPos));
    }
    painter.drawPolyline(polygon);
}
