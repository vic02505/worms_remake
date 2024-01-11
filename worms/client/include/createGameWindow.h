#ifndef CREATEGAMEWINDOW_H
#define CREATEGAMEWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QComboBox>
#include "client_juego.h"
#include "menuWindow.h"
class CreateGameWindow : public QWidget {
public:
    CreateGameWindow(QWidget *parent = 0, Juego* Juego = 0);
    Juego* m_Juego;

private:
    QPushButton buttonCreateGame;
    QLineEdit editGameName;
    QComboBox *comboBoxMapa;
    QComboBox *comboBoxPlayers;
    QLineEdit editPlayerName;
    QPushButton *backButton;
public slots:
    void slotCreateGame();
    void slotGoBack();
};

#endif // CREATEGAMEWINDOW_H