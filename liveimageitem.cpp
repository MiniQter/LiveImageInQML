#include "liveimageitem.h"

#include <QPainter>

LiveImageItem::LiveImageItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setAntialiasing(true);
    setPerformanceHint(QQuickPaintedItem::FastFBOResizing);
    setMipmap(true);
    setFillColor(Qt::black);

    m_image = QImage(1920, 1080, QImage::Format_ARGB32);
    m_image.fill(Qt::cyan);
}

LiveImageItem::~LiveImageItem() {}

void LiveImageItem::paint(QPainter *painter)
{
    QImage scaledImage = m_image.scaled(boundingRect().size().toSize(), Qt::KeepAspectRatio);
    QPointF leftTop = boundingRect().center() - QRectF(scaledImage.rect()).center();
    painter->drawImage(leftTop, scaledImage);
}

QImage LiveImageItem::image() const
{
    return m_image;
}

void LiveImageItem::setImage(const QImage &image)
{
    if (m_image != image) {
        emit imageChanged();
        m_image = image;
        update();
    }
}
