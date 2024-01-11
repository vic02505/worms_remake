#include "menuWindow.h"
#include "createGameWindow.h"
#include "joinGameWindow.h"

MenuWindow::MenuWindow(QWidget *parent, Juego* juego) : QWidget(parent), m_Juego(juego), buttonCreate("Crear Partida"), buttonJoin("Unirse Partida") {
    QVBoxLayout* layout = new QVBoxLayout();

    setWindowTitle("Menú del Juego");
    buttonCreate.setStyleSheet("font-size: 12pt; spacing: 10px; margin: 10px; padding: 10px; border: 2px solid black; background-color: cyan; color: white; width: 100px; height: 50px;");
    buttonCreate.setCursor(QCursor(Qt::PointingHandCursor)); // Cambia el cursor al pasar el ratón
    buttonCreate.setStyleSheet("QPushButton:hover { background-color: #555; }"); // Cambia el color al pasar el ratón
   
    buttonJoin.setStyleSheet("font-size: 12pt; spacing: 10px; margin: 10px; padding: 10px; border: 2px solid black; background-color: cyan; color: white; width: 100px; height: 50px;");
    buttonJoin.setCursor(QCursor(Qt::PointingHandCursor)); // Cambia el cursor al pasar el ratón
    buttonJoin.setStyleSheet("QPushButton:hover { background-color: #555; }"); // Cambia el color al pasar el ratón
    resize(300, 200);

    setStyleSheet("QPushButton { font-size: 16px; background-color: #3498db; color: #ffffff; }"
              "QLabel { font-size: 14px; }");


    layout->addWidget(&buttonCreate);
    layout->addWidget(&buttonJoin);

    setLayout(layout);

    connect(&buttonCreate, &QPushButton::clicked, this, &MenuWindow::slotCrearPartida);
    connect(&buttonJoin, &QPushButton::clicked, this, &MenuWindow::slotUnirsePartida);
}

void MenuWindow::slotCrearPartida() {
    qDebug() << "Botón 'Crear Partida' presionado.";
    
    this->close();

    // Crear ventana de crear partida
    CreateGameWindow* createGameWindow = new CreateGameWindow(nullptr, m_Juego);
    createGameWindow->show();

}

void MenuWindow::slotUnirsePartida() {
    qDebug() << "Botón 'Unirse Partida' presionado.";

    this->close();

    //Crear ventana de unirse a partida

    JoinGameWindow* joinGameWindow = new JoinGameWindow(nullptr, m_Juego);
    joinGameWindow->show();
}
