#ifndef LIVEIMAGEITEM_H
#define LIVEIMAGEITEM_H

#include <QImage>
#include <QQuickPaintedItem>

class LiveImageItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_DISABLE_COPY(LiveImageItem)
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)

signals:
    void imageChanged();

public:
    explicit LiveImageItem(QQuickItem *parent = nullptr);
    ~LiveImageItem() override;

    void paint(QPainter *painter) override;

    QImage image() const;
    Q_INVOKABLE void setImage(const QImage &image);

private:
    QImage m_image;
};

#endif // LIVEIMAGEITEM_H
