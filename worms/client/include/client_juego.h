#ifndef CLIENT_JUEGO_H
#define CLIENT_JUEGO_H

#include "../../common_libs/include/Protocol.h"
#include "../../common_libs/include/ProtectedQueue.h"
#include "EventSender.h"
#include "client_receiver.h"
#include <iostream>

class Juego{
    private:
    Protocol m_Protocol;

    EventSender* emisor_de_mensajes{NULL};
    ClientReceiver* receptor_de_mensajes{NULL};
    bool inicio_el_juego{false};
    ProtectedQueue<std::string> cola_de_mensajes;

    int m_Players{};
    int m_IdPlayer{};

    public:

    explicit Juego(const std::string& ip, const std::string& puerto);

    void joinGame(int idGame, int cantPlayers, std::string playerName);

    GameInfo getGamesInfo();

    void createGame(const std::string& mapa, const std::string& nombre, const std::string& playerName,
                    const std::string& cantidad_jugadores);

    void menu_window();

    Protocol *getProtocol();

    [[nodiscard]] int getPlayers() const;
    [[nodiscard]] int getIdPlayer() const;
};

#endif // CLIENT_JUEGO_H