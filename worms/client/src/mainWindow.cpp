#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), m_Lobby(true), buttonConnect("Conectar"){
    QVBoxLayout* connectLayout = new QVBoxLayout();
    QVBoxLayout* inputLayout = new QVBoxLayout();

    // Establecer estilos para los campos de entrada y el botón
    setWindowTitle("Conectar al Servidor");
    resize(300, 200);
    this->inputPort.setStyleSheet("font-size: 12pt; width: 50px; height: 25px; border: 2px solid black;");
    this->inputServer.setStyleSheet("font-size: 12pt; width: 50px; height: 25px; border: 2px solid black;");
    buttonConnect.setStyleSheet("font-size: 12pt; spacing: 10px; margin: 10px; padding: 10px; border: 2px solid black; background-color: black; color: white; width: 100px; height: 50px;");
    buttonConnect.setCursor(QCursor(Qt::PointingHandCursor)); // Cambia el cursor al pasar el ratón
    buttonConnect.setStyleSheet("QPushButton:hover { background-color: #555; }"); // Cambia el color al pasar el ratón

    inputLayout->addWidget(new QLabel("Puerto:"));
    inputLayout->addWidget(&this->inputPort);
    inputLayout->addWidget(new QLabel("IP:")); 
    inputLayout->addWidget(&this->inputServer);

    connectLayout->addLayout(inputLayout);
    connectLayout->addWidget(&this->buttonConnect);

    setLayout(connectLayout);

    connect(&buttonConnect, &QPushButton::clicked, this, &MainWindow::switchToGame);
    connect(&inputServer, &QLineEdit::returnPressed, this, &MainWindow::switchToGame);
}

void MainWindow::switchToGame() {
    // Obtengo los valores de los campos de entrada
    
    QString port = this->inputPort.text();
    QString server = this->inputServer.text();

    this->close();
    this->juego = new Juego(server.toStdString(), port.toStdString());
 
    juego->menu_window();
}

Protocol *MainWindow::getProtocol() {
    return this->juego->getProtocol();
}

MainWindow::~MainWindow() {
    delete this->juego;
}

bool MainWindow::isLobby() {
    return m_Lobby.load();
}

int MainWindow::getCantPlayers() const {
    return this->juego->getPlayers();
}

int MainWindow::getIdPlayer() const {
    return this->juego->getIdPlayer();
}
