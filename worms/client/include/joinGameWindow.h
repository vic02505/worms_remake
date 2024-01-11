#ifndef JOINGAMEWINDOW_H_
#define JOINGAMEWINDOW_H_

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QComboBox>
#include <QListWidget>
#include "client_juego.h"
#include "menuWindow.h"

class JoinGameWindow : public QWidget {
public:
    JoinGameWindow(QWidget *parent = 0, Juego* Juego = 0);
    Juego* m_Juego;

private:
    QPushButton buttonCreateGame;
    QLineEdit editGameName;
    QLineEdit m_EditPlayerName;
    QPushButton *backButton;
    int idGame{};
    std::unordered_map<int, GameProperty> m_GameProperties;

public slots:
    void slotJoinGame(QListWidgetItem *selectedItem);
    void slotGoBack();
};

#endif // JOINGAMEWINDOW_H_