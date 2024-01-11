#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include "client_juego.h"

class MainWindow : public QWidget {
private:
    Juego* juego;
    std::atomic<bool> m_Lobby;
public:
    explicit MainWindow(QWidget *parent = 0);
    Protocol* getProtocol();
    bool isLobby();
    ~MainWindow() override;

    int getCantPlayers() const;
    int getIdPlayer() const;

private slots:
    void switchToGame();
    
private:
    QLabel labelOut;
    QPushButton buttonConnect;
    QLineEdit inputPort;
    QLineEdit inputServer;
};

#endif // MAINWINDOW_H