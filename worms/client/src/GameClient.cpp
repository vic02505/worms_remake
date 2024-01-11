#include "../include/GameClient.h"
#include "../../common_libs/include/utils/WorldScale.h"
#include <thread>
#include <iostream>
#include <utility>


void GameClient::Init(const std::vector<Grd>& beams, int idPlayer, std::vector<GameUpdate>& initInfo,
                      const GameUpdate& turnInfo) {
    InitSDL();
    CreateWindowAndRender();
    InitMixerAndChunk();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    m_IdPlayer = idPlayer;
    for (auto& beamMap : beams) {
        auto* beam = new Beam(_renderer, beamMap);
        beam->init();
        m_Beams.push_back(beam);
    }

    for (auto& gameUpdate : initInfo) {
        auto* worm = new Worm(gameUpdate.player_id, gameUpdate.m_PlayerName, _renderer, gameUpdate.x_pos, gameUpdate.y_pos, gameUpdate.width, gameUpdate.height);
        worm->init();
        m_Worms.insert(std::make_pair(gameUpdate.player_id, worm));
    }

    //Inicializo el cielo
    const SDL_Rect m_SourceRect = {0, 0, 4096, 2034};
    sky = new Texture(std::filesystem::current_path().concat(Cloud_Sky.c_str()).c_str(), _renderer, {false, 128, 128, 192});
    sky->init();
    sky->setSourceRect(&m_SourceRect);

    
    water = new Texture(std::filesystem::current_path().concat(Water.c_str()).c_str(), _renderer, {false, 128, 128, 192});
    water->init();
    const SDL_Rect srcWaterRect = {0, 385, 1024, 46};
    water->setSourceRect(&srcWaterRect);

    const SDL_Rect weapons_list_rect = {0,0, 160, 64};
    weapons_list = new Texture(std::filesystem::current_path().concat(WeaponsList.c_str()).c_str(), _renderer, {false, 128, 128, 192}); 
    weapons_list->init();
    weapons_list->setSourceRect(&weapons_list_rect);

    projectile = new Projectile(_renderer);
    projectile->init();

    //La camara funciona con bugs.
    //InitCamera();

    //Corro el audio con el chunk.
    //mixer->PlayChannel(-1, *chunk, -1);
    m_Timer = {turnInfo.m_PlayerName, turnInfo.player_id, turnInfo.m_SecondsPerTurn, {400, 10, 100, 70}, std::chrono::steady_clock::now()};
}

void GameClient::InitCamera() {
    camara = new Camara(_renderer);
    camara->setWorm(m_Worms.at(m_IdPlayer));
}

void GameClient::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >= 0;
    //init ttf
    if (TTF_Init() == -1) {
        std::cout << "Exception" << std::endl;
        //throw SDL_Exception(SDL_GetError());
    }

    if (!isInitialized) {
        std::cout << "Exception" << std::endl;
        //throw SDL_Exception(SDL_GetError());
    }
}

void GameClient::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);
    if (_window == NULL || _renderer == NULL) {
        //throw SDL_Exception(SDL_GetError());
        std::cout << "Exception" << std::endl;
    }
    SDL_SetWindowTitle(_window, "Worms");
}

void GameClient::InitMixerAndChunk() {
    mixer = new SDL2pp::Mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    chunk = new SDL2pp::Chunk(std::filesystem::current_path().concat(Game_Music.c_str()).c_str());
}

void GameClient::Update(double elapsedSeconds, const GameUpdate& gameUpdate) {
    if (gameUpdate.m_Health != 0xFF) {
        std::cout << "Update health: " << static_cast<int>(gameUpdate.m_Health) << std::endl;
        m_Worms.at(gameUpdate.player_id)->updateHealth(gameUpdate.m_Health);
    }
    if (gameUpdate.m_CurrentSprite == SPRITE_INVALID) {
        for (auto& worm : m_Worms) {
            worm.second->update(elapsedSeconds);
        }
    } else {

        if (gameUpdate.m_Movement == GameAction::PROJECTILE_LAUNCHED || gameUpdate.m_Movement == GameAction::PROJECTILE_COLLIDED) {
            projectile->update(elapsedSeconds, gameUpdate);
        }

        for (auto& worm : m_Worms) {
            if (worm.first == gameUpdate.player_id) {
                worm.second->update(elapsedSeconds, gameUpdate);
            } else {
                worm.second->update(elapsedSeconds);
            }
        }
        if (gameUpdate.m_CurrentSprite == SPRITE_WACCUSE_GRAVE) {
            m_WormsDie.push_back(m_Worms.at(gameUpdate.player_id));
            m_Worms.erase(gameUpdate.player_id);
        }
    }

}

void GameClient::Render() {
    SDL_RenderClear(_renderer);

    //camara->updateCamera();

    //SDL_Rect& wormRect;

    //renderizar fondo.
    SDL_Rect m_DestRect = {0 /*- camara->camara_rect.x/4*/, 0 /*- camara->camara_rect.y/4*/, 512, 512};
    sky->render(&m_DestRect, false);

    //renderizar agua.
    const SDL_Rect m_DestRect2 = {0, 461, 1024, 51};
    water->render(&m_DestRect2, false);

    //renderizar vigas.
    for (auto& beam : m_Beams) {

        //Las vigas se desplzan muy rapido respecto a la velocidad del gusano.
        
        /*
        SDL_Rect& beamRect = beam->getBeamRect();
        SDL_Rect beamRectCopy = {0,0,0,0};
        beamRectCopy.x = beamRect.x;
        beamRectCopy.y = beamRect.y;
        
        beamRect.x -= camara->camara_rect.x/4;
        beamRect.y -= camara->camara_rect.y/4;
        */

        beam->render();

        /*
        beamRect.x = beamRectCopy.x;
        beamRect.y = beamRectCopy.y;
        */


    }

    //renderizar gusanos.
    for (auto& worm : m_Worms) {
        worm.second->render();
    }


    if (projectile_launched) {
        projectile->render();
    }


    //El gusano se pinta en en una parte del mapa, pero cuando este comienza a desplazarse hacia la derecha
    //comienza a desaperecer y aparecer de forma intermitente.
    
    //Para ver esto: Apretar "A" hasta que aparezaca el gusano.
    //Luego mantener pulsado "D".

    /* 
    Worm* player_worm = this->m_Worms.at(this->m_IdPlayer);
    SDL_Rect& worm_rect = player_worm->getWormRect();
    worm_rect.x -= camara->camara_rect.x/4;
    worm_rect.y -= camara->camara_rect.y/4;
    */

    //camara->updateCamera();

    //renderizar gusanos muertos.
    for (auto& worm : m_WormsDie) {
        worm->render();
    }

    //renderizar lista de armas.
    if(se_muestra_la_lista_de_armas) {
        SDL_Rect weapons_list_dst_rect = {0, 0, 160, 64};
        weapons_list->render(&weapons_list_dst_rect, false);
    }

    auto now = std::chrono::steady_clock::now();
    auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - m_Timer.m_StartTime).count();
    auto remainingSeconds = m_Timer.m_SecondsPerTurn - elapsedSeconds;

    // Crear el texto del temporizador
    std::stringstream ss;
    ss << "Turn: " << m_Timer.m_PlayerTurnName << " " << remainingSeconds << "s";

    // Crear una textura a partir del texto
    TTF_Font* font = TTF_OpenFont(std::filesystem::current_path()
                                          .concat("/resources/Fonts/Dhurjati-Regular.ttf").c_str(), 16);
    SDL_Color textColor = {0, 0, 0, 255}; // Blanco
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, ss.str().c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);

    // Renderizar la textura en m_TimerDestRect
    SDL_RenderCopy(_renderer, textTexture, NULL, &m_Timer.m_TimerDestRect);

    // Limpiar
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);

    SDL_RenderPresent(_renderer);
}

void GameClient::Release() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void GameClient::resetTurn(uint8_t idPlayer, std::string playerName, double secondsPerTurn) {
    m_Timer.m_IdPlayerTurn = idPlayer;
    m_Timer.m_PlayerTurnName = std::move(playerName);
    m_Timer.m_SecondsPerTurn = secondsPerTurn;
    m_Timer.m_StartTime = std::chrono::steady_clock::now();
}

GameClient::~GameClient() {
    std::cout << "Destroing GameClient" << std::endl;
    for (auto& beam : m_Beams) {
        beam->release();
        delete beam;
    }

    for (auto& worm : m_Worms) {
        delete worm.second;
    }

    for (auto& worm : m_WormsDie) {
        delete worm;
    }

    sky->release();
    delete sky;

    water->release();
    delete water;

    weapons_list->release();
    delete weapons_list;

    delete projectile;
    delete mixer;
    delete chunk;
    delete camara;
}


