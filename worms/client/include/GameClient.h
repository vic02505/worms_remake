#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <filesystem>
#include "engine/entities/worms/Worm.h"
#include "ParseMapFromFile.h"
#include "engine/entities/beams/Beam.h"
#include "engine/graphics/Texture.h"
#include "messages/server/GameUpdate.h"
#include <unordered_map>
#include <vector>
#include "../include/camara.h"
#include "engine/entities/worms/Skins.h"
#include "engine/entities/projectiles/projectile.h"
#include <chrono>
#include <SDL_ttf.h>
#include <sstream>


struct Timer {
    std::string m_PlayerTurnName{};
    int m_IdPlayerTurn{};
    double m_SecondsPerTurn{};
    SDL_Rect m_TimerDestRect = {400, 10, 100, 70};
    std::chrono::time_point<std::chrono::steady_clock> m_StartTime{};
};

class GameClient {
 private:
    int m_IdPlayer;
//    std::string m_PlayerName;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::unordered_map<int, Worm*> m_Worms;
    std::vector<Grd> m_Grd;
    std::vector<Beam*> m_Beams;
    std::vector<Worm*> m_WormsDie;
    Texture* sky;
    Texture* water;
    Texture* weapons_list;
    Projectile* projectile;

    SDL2pp::Mixer *mixer;
    SDL2pp::Chunk *chunk;
    Camara* camara;
    Timer m_Timer;

   public:
   bool se_muestra_la_lista_de_armas{false};
   bool projectile_launched{false};

 private:
    void InitSDL();

    void CreateWindowAndRender();

    void InitMixerAndChunk();

    void InitCamera();

 public:
    void Init(const std::vector<Grd>& beams, int idPlayer, std::vector<GameUpdate>& initInfo,
              const GameUpdate& turnInfo);

    void Update(double elapsedSeconds, const GameUpdate& gameUpdate);

    void Render();

    void Release();

    void resetTurn(uint8_t idPlayer, std::string playerName, double secondsPerTurn);

    ~GameClient();
};
