#include "dragAndDrop.h"

DragAndDrop::DragAndDrop(const QPixmap &pixmap, qreal scale, QGraphicsScene* scene)
    : QGraphicsPixmapItem(pixmap), scene(scene)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setScale(scale);
}

void DragAndDrop::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        startPos = event->scenePos();
        isDragging = true;
    }
    QGraphicsPixmapItem::mousePressEvent(event);
}

void DragAndDrop::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}

void DragAndDrop::setTipoElemento(int tipo) {
    tipoElemento = tipo; // 0 = spawn, 1 = beam
}

int DragAndDrop::getTipoElemento() const {
    return tipoElemento;
}


/*
QVariant DragAndDrop::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange && scene()) {
        QRectF newRect = boundingRect();
        newRect.setWidth(newRect.width() * 1.5); 
        newRect.setHeight(newRect.height() * 1.5);
        prepareGeometryChange();
        setPos(mapToScene(newRect.center()));
    }

    return QGraphicsPixmapItem::itemChange(change, value);
}

*/

void DragAndDrop::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (isDragging) {
        QPointF newPos = mapToScene(event->pos());

        setPos(constrainToScene(newPos));

        scene->setSceneRect(scene->itemsBoundingRect());
    }
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

QPointF DragAndDrop::constrainToScene(const QPointF& newPos) {
    QRectF viewRect = scene->views().first()->viewport()->rect();
    QRectF itemRect = boundingRect();

    qreal x = qBound(viewRect.left(), newPos.x(), viewRect.right() - itemRect.width());
    qreal y = qBound(viewRect.top(), newPos.y(), viewRect.bottom() - itemRect.height());

    return QPointF(x, y);
}