#include "joinGameWindow.h"

JoinGameWindow::JoinGameWindow(QWidget *parent, Juego* juego) : QWidget(parent), m_Juego(juego) {
    QVBoxLayout *layout = new QVBoxLayout();

    auto gamesInfo = m_Juego->getGamesInfo();
    layout->addWidget(new QLabel("Nombre del jugador:"));
    m_EditPlayerName.setPlaceholderText("Ingrese su nombre");
    layout->addWidget(&m_EditPlayerName);
        
    QListWidget *listWidget = new QListWidget();

    const std::vector<GameProperty> &partidas = gamesInfo.getGameProperties();
    for (const GameProperty &partida : partidas) {
        m_GameProperties.insert(std::make_pair(partida.m_idGame, partida));
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(partida.m_GameName) +
                                                         " - Jugadores permitidos: " + QString::number(partida.m_Players)
                                                         + " - Jugadores conectados: " +
                                                         QString::number(partida.m_PlayersConnected));
        //store in item gameId in a map
        item->setData(Qt::UserRole, partida.m_idGame);
        listWidget->addItem(item);
    }

    layout->addWidget(listWidget);

    backButton = new QPushButton("Volver al Menu");
    backButton->setCursor(QCursor(Qt::PointingHandCursor));
    backButton->setStyleSheet("QPushButton:hover { background-color: #555; }");
    connect(backButton, &QPushButton::clicked, this, &JoinGameWindow::slotGoBack);
    layout->addWidget(backButton);

    setLayout(layout);

    connect(listWidget, &QListWidget::itemClicked, this, &JoinGameWindow::slotJoinGame);
}

void JoinGameWindow::slotJoinGame(QListWidgetItem *selectedItem) {
    int id = selectedItem->data(Qt::UserRole).toInt();
    QString playerName = m_EditPlayerName.text();
    m_Juego->joinGame(id, m_GameProperties.at(id).m_Players, playerName.toStdString());

    this->close();
}

void JoinGameWindow::slotGoBack() {

    MenuWindow *menuWindow = new MenuWindow(nullptr, m_Juego);
    menuWindow->show();
    this->close();
}