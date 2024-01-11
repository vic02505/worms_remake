#include "mapEditor.h"
#include "dragAndDrop.h"
#include "backgroundItem.h"
#include <iostream>

MapEditor::MapEditor(QWidget *parent) : QMainWindow(parent), currentBackground(nullptr)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 512, 512);

    view = new QGraphicsView(scene, this);

    view->setRenderHint(QPainter::Antialiasing, true);
    view->setRenderHint(QPainter::SmoothPixmapTransform, true);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view->setSceneRect(scene->sceneRect());

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(512, 512);

    setCentralWidget(view);

    widthBeam = scene->sceneRect().width() / 2;

    QPushButton *addBeamButton = new QPushButton("Add Beam", this);
    QPushButton *addSpawnButton = new QPushButton("Add Spawn", this);
    QPushButton *generateMapButton = new QPushButton("Generate Map", this);

    QComboBox *background = new QComboBox(this);
    background->addItem("Seleccionar fondo"); 
    background->addItem(QIcon("resources/Fondos/cielo.png"), "Sky");
    background->addItem("City");
    background->addItem("Forest");

    background->setStyleSheet("QComboBox {"
                                      "border: 1px solid gray;"
                                      "border-radius: 3px;"
                                      "padding: 1px 18px 1px 3px;"
                                      "min-width: 6em;}"
                                      "QComboBox::drop-down {"
                                      "subcontrol-origin: padding;"
                                      "subcontrol-position: top right;"
                                      "width: 15px;}");

    background->setFixedWidth(150);                                  

    connect(addBeamButton, &QPushButton::clicked, this, &MapEditor::addBeam);
    connect(addSpawnButton, &QPushButton::clicked, this, &MapEditor::addSpawn);
    connect(background, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MapEditor::backgroundSelection);
    connect(generateMapButton, &QPushButton::clicked, this, &MapEditor::generarMapaClicked);


    addBeamButton->setFixedSize(100, 30);
    addSpawnButton->setFixedSize(100, 30);
    generateMapButton->setFixedSize(100, 30);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(addBeamButton);
    layout->addWidget(addSpawnButton);
    layout->addWidget(generateMapButton);
    layout->addWidget(background);
    layout->addStretch();
    layout->addWidget(view);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);

    setCentralWidget(widget);
}

void MapEditor::addBeam()
{
    QPixmap beamPixmap("resources/Weapons/grdl4.png"); 
    DragAndDrop *beamItem = new DragAndDrop(beamPixmap, 1, scene);
    beamItem->setTipoElemento(1);
    beamItem->setPixmap(beamPixmap.scaledToWidth(widthBeam));
    scene->addItem(beamItem);
}

void MapEditor::addSpawn()
{
    QPixmap spawnPixmap("resources/Worms/worm-editor.png"); 
    DragAndDrop *spawnItem = new DragAndDrop(spawnPixmap, 0.1, scene);
    spawnItem->setTipoElemento(0);
    scene->addItem(spawnItem);
}

void MapEditor::backgroundSelection(int index)
{
    QPixmap backgroundPixmap;

    switch (index) {
        case 0:
            backgroundPixmap = QPixmap();
            break;
        case 1:
            backgroundPixmap = QPixmap("resources/Fondos/cielo.png");
            break;
        case 2:
            //backgroundPixmap = QPixmap(".png");
            break;
        case 3:
            //backgroundPixmap = QPixmap(".png");
            break;
        default:
            break;
    }

    if (currentBackground) {
        currentBackground->setPixmap(backgroundPixmap);
    } else {
        currentBackground = new BackgroundItem(backgroundPixmap, 0.3);
        scene->addItem(currentBackground);
    }
}

void MapEditor::generarMapaClicked()
{
    QString nombreArchivo = obtenerNombreArchivo();
    if (!nombreArchivo.isEmpty())
    {
        generateMapFile(nombreArchivo);
    }
}

QString MapEditor::obtenerNombreArchivo()
{
    bool ok;
    QString nombreArchivo = QInputDialog::getText(this, tr("Nombre del Archivo"), tr("Ingrese el nombre del archivo:"), QLineEdit::Normal, "", &ok);

    if (ok && !nombreArchivo.isEmpty())
    {
        return nombreArchivo;
    }
    else
    {
        return QString();
    }
}

void MapEditor::generateMapFile(const QString &fileName)
{

    QString directorio = "maps/";

    QFile file(directorio + fileName + ".txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        int beamCount = 0;
        int spawnCount = 0;
        QList<QPointF> vigaPosiciones;
        QList<QPointF> spawnPosiciones;


        foreach (QGraphicsItem *item, scene->items())
        {
            if (DragAndDrop *element = dynamic_cast<DragAndDrop*>(item))
            {
                QPointF position = element->scenePos();

                float elementoWidth = (element->pixmap().width())/25.6;
                float elementoHeight = (element->pixmap().height())/25.6;

                float x_meters = WorldScale::pixelToWorldX(position.x(), elementoWidth);
                float y_meters = WorldScale::pixelToWorldY(position.y(), elementoHeight);


                qDebug() << "Ancho del elemento: " << elementoWidth << " Alto del elemento: " << elementoHeight;

                float tipoElemento = element->getTipoElemento();

                if (tipoElemento == 1)
                {
                    vigaPosiciones.append(QPointF(x_meters, y_meters));
                    beamCount++;
                }else{
                    spawnPosiciones.append(QPointF(x_meters, y_meters));
                    spawnCount++;
                }
            }
        }

        stream << beamCount << Qt::endl;

        foreach (const QPointF &vigaPos, vigaPosiciones)
        {
            stream << "1 " << vigaPos.x() << " " << vigaPos.y() << Qt::endl;
        }

        //stream << spawnCount << Qt::endl;

        //foreach (const QPointF &spawnPos, spawnPosiciones)
        //{
        //    stream << spawnPos.x() << " " << spawnPos.y() << Qt::endl;
        //}

        QRectF sceneRect = scene->sceneRect();
        qDebug() << "Ancho de la escena: " << sceneRect.width() << " Altura de la escena: " << sceneRect.height();

        file.close();
        qDebug() << "Archivo generado exitosamente.";
    }
    else
    {
        qDebug() << "Error abriendo el archivo para escritura: " << file.errorString();
    }
}
