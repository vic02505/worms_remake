#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <netinet/in.h>
#include "liberror.h"
#include "socket.h"
#include <functional>
#include "messages/server/GameInfo.h"
#include "ParseMapFromFile.h"
#include "messages/user_actions/UserAction.h"
#include "messages/server/GameUpdate.h"

class Protocol {
private:
    Socket socket;
    bool wasClosed;
private:
    /* private methods don't use them, and if you do it use wisely */
    void sendByte(uint8_t byte);
    void sendTwoBytes(uint16_t bytes);
    void sendFourBytes(uint32_t bytes);
    void sendString(const std::string& message);
    void sendFloat(float f);
    uint8_t recvByte();
    uint16_t recvTwoBytes();
    uint32_t recvFourBytes();
    float recvFloat();
    std::string recvString();
public:
    explicit Protocol(Socket socket);
    Protocol(const std::string& hostname, const std::string& servname);
    GameInfo recvGameInfo();
    std::vector<Grd> recvMap();
    GameUpdate recvGameUpdate();
    UserAction recvUserAction();

    void sendGameInfo(GameInfo& gameInfo);
    void sendMap(std::reference_wrapper<std::vector<Grd>> map);
    void sendUserAction(UserAction action);
    void sendGameUpdate(GameUpdate& update);

    bool isClosed() const;
    void close();
    void shutdown(int mode);
    ~Protocol();
    Protocol(const Protocol&) = delete;
};
