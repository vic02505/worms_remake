#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QComboBox>
#include <QString>
#include <QPointF>
#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <QInputDialog>
#include <QList>
#include "backgroundItem.h"
#include "utils/WorldScale.h"

class MapEditor : public QMainWindow
{

public:
    MapEditor(QWidget *parent = nullptr);
    void generateMapFile(const QString &nombreArchivo);
    QString obtenerNombreArchivo();
    
private slots:
    void addBeam();
    void addSpawn();
    void backgroundSelection(int index);
    void generarMapaClicked();


private:
    BackgroundItem *currentBackground;
    QGraphicsScene *scene;
    QGraphicsView *view;
    int widthBeam = 0;
};
