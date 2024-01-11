#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BackgroundItem : public QGraphicsPixmapItem
{
public:
    BackgroundItem(const QPixmap &pixmap, qreal scale = 1.0);

    QRectF boundingRect() const override;
};