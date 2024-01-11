#pragma once

#include <string>

enum InitGameEnum : uint8_t {
    CREATE_GAME = 0x00,
    JOIN_GAME = 0x01,
    LIST_GAMES = 0x02,
    QUIT = 0x03,
    INVALID = 0x04,
    ID_PLAYER = 0x05
};

[[maybe_unused]] inline InitGameEnum getAction(uint8_t action) {
    switch (action) {
        case 0x00:
            return CREATE_GAME;
        case 0x01:
            return JOIN_GAME;
        case 0x02:
            return LIST_GAMES;
        case 0x03:
            return QUIT;
        default:
            return INVALID;
    }
}

[[maybe_unused]] inline InitGameEnum getAction(std::string action) {
    if (action == "create") {
        return CREATE_GAME;
    } else if (action == "join") {
        return JOIN_GAME;
    } else if (action == "list") {
        return LIST_GAMES;
    } else if (action == "quit") {
        return QUIT;
    } else {
        return INVALID;
    }
}