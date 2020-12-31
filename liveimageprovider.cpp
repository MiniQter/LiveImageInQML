#include "liveimageprovider.h"

LiveImageProvider::LiveImageProvider(QObject *parent)
    : QObject(parent)
    , QQuickImageProvider(QQuickImageProvider::Image)
{
    image = QImage(1920, 1080, QImage::Format_RGB32);
    image.fill(Qt::magenta);
}

QImage LiveImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);

    if (size) {
        *size = image.size();
    }

    if (requestedSize.width() > 0 && requestedSize.height() > 0) {
        image = image.scaled(requestedSize.width(), requestedSize.height(), Qt::KeepAspectRatio);
    }

    return image;
}

void LiveImageProvider::updateImage(const QImage &image, bool checkTheSame)
{
    if (image.isNull())
        return;

    if (checkTheSame && (this->image != image))
        return;

    this->image = image;
    emit imageChanged();
}
