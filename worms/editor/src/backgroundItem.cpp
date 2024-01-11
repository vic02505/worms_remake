#include "backgroundItem.h"

BackgroundItem::BackgroundItem(const QPixmap &pixmap, qreal scale)
    : QGraphicsPixmapItem(pixmap)
{
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setScale(scale);
    //setPos(0, 0);
}

QRectF BackgroundItem::boundingRect() const
{
    return QGraphicsPixmapItem::boundingRect();
}