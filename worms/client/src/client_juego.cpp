#include "client_juego.h"

#include <utility>
#include "menuWindow.h"

GameInfo Juego::getGamesInfo(){

    GameInfo actualGameInfo;
    actualGameInfo.setIdAction(InitGameEnum::LIST_GAMES);
        
    this->m_Protocol.sendGameInfo(actualGameInfo);

    GameInfo serverResponse = this->m_Protocol.recvGameInfo();

    return serverResponse;
}


Juego::Juego(const std::string& ip, const std::string& puerto) :
m_Protocol(ip, puerto), cola_de_mensajes(100) {}

void Juego::menu_window(){
    MenuWindow *menu = new MenuWindow(nullptr, this);
    
    menu->show();
}

void Juego::createGame(const std::string& mapa, const std::string& nombre, const std::string& playerName,
                       const std::string& cantidad_jugadores) {
    m_Players = std::stoi(cantidad_jugadores);
    GameProperty gameProperty(0, nombre, mapa, 0, std::stoi(cantidad_jugadores), playerName);
    GameInfo gameInfo(InitGameEnum::CREATE_GAME, {gameProperty});
    m_Protocol.sendGameInfo(std::ref(gameInfo));
    GameInfo serverResponse = m_Protocol.recvGameInfo();
    m_IdPlayer = serverResponse.getGameProperties().at(0).m_IdPlayer;

    std::cout<<"El mapa es: "<<mapa<<std::endl;
    std::cout<<"El nombre es: "<<nombre<<std::endl;
    std::cout<<"La cantidad de jugadores es: "<<cantidad_jugadores<<std::endl;
}

void Juego::joinGame(int idGame, int players, std::string playerName) {
    m_Players = players;
    GameProperty gameProperty(idGame, "", "", 0, 0, std::move(playerName));
    GameInfo gameInfo(InitGameEnum::JOIN_GAME, {gameProperty});
    m_Protocol.sendGameInfo(std::ref(gameInfo));
    GameInfo serverResponse = m_Protocol.recvGameInfo();
    m_IdPlayer = serverResponse.getGameProperties().at(0).m_IdPlayer;

    std::cout<<"El id del juego es: "<<idGame<<std::endl;
}

Protocol *Juego::getProtocol() {
    return &m_Protocol;
}

int Juego::getPlayers() const {
    return m_Players;
}

int Juego::getIdPlayer() const {
    return m_IdPlayer;
}

