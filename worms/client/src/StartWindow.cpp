#include "StartWindow.h"

StartWindow::StartWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedSize(512, 512);
    this->setWindowTitle("Worms");
    QPixmap background(std::filesystem::current_path().concat("/resources/Fondos/worms-start-2.png").c_str());
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    startButton = new QPushButton("EMPEZAR", this);
    startButton->setStyleSheet("background-color: red");
    startButton->resize(100, 50);
    startButton->move(this->width()/2 - startButton->width()/2, this->height()/2 - startButton->height()/2);
    mainWindow = new MainWindow(nullptr);

    connect(startButton, &QPushButton::clicked, this, &StartWindow::startGame);
}

void StartWindow::startGame() {
    this->close();
    mainWindow->show();
}

Protocol *StartWindow::getProtocol() {
    return mainWindow->getProtocol();
}

int StartWindow::getIdPlayer() const {
    return mainWindow->getIdPlayer();
}

int StartWindow::getCantPlayers() const {
    return mainWindow->getCantPlayers();
}
