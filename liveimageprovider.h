#ifndef LIVEIMAGEPROVIDER_H
#define LIVEIMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>

class LiveImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    LiveImageProvider(QObject *parent = nullptr);

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

public slots:
    void updateImage(const QImage &image, bool checkTheSame = false);

signals:
    void imageChanged();

private:
    QImage image;
};

#endif // LIVEIMAGEPROVIDER_H
