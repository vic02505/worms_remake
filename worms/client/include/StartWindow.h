#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "mainWindow.h"

class StartWindow : public QMainWindow {
public:
    StartWindow(QWidget *parent = nullptr);
private slots:
    void startGame();
private:
    QPushButton *startButton;
    MainWindow *mainWindow;
public:
    Protocol* getProtocol();
    int getIdPlayer() const;
    int getCantPlayers() const;
};