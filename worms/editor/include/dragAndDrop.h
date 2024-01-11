#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QObject>
#include <QPointF>

class DragAndDrop : public QGraphicsPixmapItem
{
public:
    DragAndDrop(const QPixmap &pixmap, qreal scale = 1.0, QGraphicsScene* scene = nullptr);
    int getTipoElemento() const; 
    void setTipoElemento(int tipo);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

   // QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    QPointF startPos;
    bool isDragging;

    QGraphicsScene* scene;
    QMenu contextMenu;
    int tipoElemento; // 0 = spawn, 1 = beam

    QPointF constrainToScene(const QPointF& newPos);
};