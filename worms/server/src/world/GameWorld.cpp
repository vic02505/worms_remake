#include <algorithm>
#include "world/GameWorld.h"

GameWorld::GameWorld(const std::string &file_map_path) : players(1), width(20.0f), height(20.0f),
 timeStep(1.0f/60.0f), velocityIterations(6), positionIterations(2), gravity(0.0f,-10.0f),
 m_world(gravity), map_path(file_map_path) {}   /*TODO ESTO IRIA POR CONFIG YML*/

void GameWorld::Setup() {
    categories = {m_WormCategory};
    StartWorld();
    ParseMapFromFile parser;
    std::vector<Grd> girders = parser.parse(map_path);
    for (auto& girder : girders) {
        std::unique_ptr<WBeam> beam = std::make_unique<WBeam>(&m_world, girder);
        m_Beams.push_back(std::move(beam));
    }
    m_WWater = std::make_unique<WWater>(&m_world, categories);
    m_world.SetContactListener(&contactListener);
}

void GameWorld::StartWorld() {
    b2BodyDef myBodyDef;
    b2PolygonShape polygonShape;

    //fixture definition    
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &polygonShape;
    myFixtureDef.density = 1;

    //a static body
    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(0, 0);
    b2Body* staticBody = m_world.CreateBody(&myBodyDef);

    //add four walls to the static body
    polygonShape.SetAsBox( 10, 1, b2Vec2(10, -1), 0);//ground
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 10, 1, b2Vec2(10, 21), 0);//ceiling
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 10, b2Vec2(-1, 10), 0);//left wall
    staticBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, 10, b2Vec2(21, 10), 0);//right wall
    staticBody->CreateFixture(&myFixtureDef);
}

void GameWorld::SetWorm(const int& player_number, const std::string& playerName, const float & x_pos, const float& y_pos) {
    auto* wormEntity = new WWorm(&m_world, playerName, player_number, x_pos, y_pos, x_pos <= width/2, m_WormCategory,
                                 {m_WaterCategory});
    worms.insert(std::make_pair(player_number, wormEntity));
    wormsPositions.insert(std::make_pair(player_number, b2Vec2(x_pos, y_pos)));
    std::cout << "ID [" << player_number << "] - POS (" << x_pos << ", " << y_pos << ")" << std::endl;
}

std::vector<GameUpdate> GameWorld::getWormsUpdates(bool getAll) {
    std::vector<GameUpdate> gameUpdates;
    for (auto& worm : worms) {
        auto update = worm.second->getUpdate(getAll);
        if (update.m_CurrentSprite == SPRITE_INVALID) {
            continue;
        }
        gameUpdates.push_back(update);
    }
    return gameUpdates;
}

void GameWorld::execute(IWormInstruction *instruction, int playerId) {
    if (playerId == -1) {
        return;
    }
    WWorm* worm = worms.at(playerId);
    if (worm->getBody()->GetType() == b2_staticBody) {
        return;
    }
    instruction->execute(worm);
}

void GameWorld::step() {
    m_world.Step(timeStep,velocityIterations,positionIterations);
}

void GameWorld::removeDeadWorms(std::vector<int> &wormsRemoved) {
    for (auto& id : wormsRemoved) {
        WWorm* worm = worms.at(id);
        b2Vec2 pos = worm->getPosition();
        float widthWorm = worm->getWidth();
        float heightWorm = worm->getHeight();
        deadWorms.insert(std::make_pair(id, new WDeadWorm(&m_world, id, pos, widthWorm, heightWorm)));
        worms.erase(id);
        wormsPositions.erase(id);
        worm->getBody()->GetUserData().pointer = reinterpret_cast<uintptr_t>(nullptr);
        m_world.DestroyBody(worm->getBody());
        delete worm;
    }
}

void GameWorld::setStaticBody(std::pair<const int, WWorm *> &worm) {
    b2BodyDef bd;
    bd.position.Set(worm.second->getPosition().x, worm.second->getPosition().y);
    bd.type = b2_staticBody;
    b2Body * body = m_world.CreateBody(&bd);
    b2PolygonShape shape;
    b2FixtureDef myFixtureDef;
    shape.SetAsBox(0.8f,0.5f);
    myFixtureDef.shape = &shape;
    myFixtureDef.density = 1;
    body->CreateFixture(&myFixtureDef);
}

GameWorld::~GameWorld() {
    for (auto& worm : worms) {
        m_world.DestroyBody(worm.second->getBody());
        delete worm.second; //TODO: Revisar esto
    }
}

void GameWorld::resetWormStatus(int idPlayer, const ActionType& type) {
    WWorm* current = worms.at(idPlayer);
    if (type != ATTACK) {
        current->resetWormStatus();
        m_world.Step(0,0,0);
    }
}

bool GameWorld::isQuiet() {
    for (auto& worm : worms) {
        SpritesEnum sprite = worm.second->getActionToAnimation()->getCurrentSprite();
        if (sprite != SPRITE_WACCUSE_IDLE) {
            return false;
        }
    }
    return true;
}

void GameWorld::getDeadWormsIds(std::vector<int> &deadWormsIds) {
    for (auto& worm : worms) {
        if (worm.second->getHealth() == 0) {
            deadWormsIds.push_back(worm.first);
        }
    }
}


bool GameWorld::isAlive(int idPlayer) {
    return worms.at(idPlayer)->getHealth() > 0;
}

bool GameWorld::wormBrokeTurn(const UserAction &userAction) {
//    for (auto& worm : worms) {
//        if (worm.second->getHealth() == 0) {
//            return true;
//        }
//    }
//    if (userAction.getAction() == ATTACK) {
//        return true;
//    }
    return userAction.getAction() == ATTACK || userAction.getAction() == SELF_KILL || userAction.getAction() == USE_TOOL;
}

bool GameWorld::wormsAlive(std::vector<int> &idsDeadWorms) {
    for (auto& idWorm : idsDeadWorms) {
        if (worms.at(idWorm)->getSelfCondition() != WORM_GRAVE) {
            return true;
        }
    }
    return false;
}

bool GameWorld::isWormIDLE(int idPlayer) {
    SpritesEnum action =  worms.at(idPlayer)->getActionToAnimation()->getCurrentSprite();
    return  action == SPRITE_WACCUSE_IDLE;
}

GameUpdate GameWorld::getWormUpdate(int idPlayer, bool getAll) {
    return worms.at(idPlayer)->getUpdate(getAll);
}

bool GameWorld::allElementsIDLE() {
    bool isIDLE = std::all_of(worms.begin(), worms.end(), [](std::pair<const int, WWorm*>& worm) {

        if (worm.second->tieneProyectil){
            if (worm.second->proyectil->getBody()->GetLinearVelocity().x != 0 || worm.second->proyectil->getBody()->GetLinearVelocity().y != 0) {
                return false;
            }
        }

        return worm.second->getVelocity() == b2Vec2_zero;
    });


    return isIDLE;
}

void GameWorld::getDeathWormsUpdates(std::vector<int>& idsDeadWorms) {
    for (auto& id : idsDeadWorms) {
        worms.at(id)->getActionToAnimation()->resetAnimation();
        worms.at(id)->getActionToAnimation()->setAction(ActionType::DYING);
    }
}

void GameWorld::updateWormsMove() {
    for (auto& worm : worms) {
        if (worm.second->isMoving()) {
            worm.second->move(worm.second->getDirection());
        }
    }

}


WProyectile* GameWorld::getProjectile(){

    WProyectile* p_projectile = nullptr;

    for (auto& worm : worms) {
        if (worm.second->tieneProyectil) {
            p_projectile = worm.second->proyectil;
        }
    }

    return p_projectile;
}

void GameWorld::unsetProjectiles() {
    
    for (auto& worm : worms) {
        if (worm.second->tieneProyectil) {
            worm.second->tieneProyectil = false;
        }
    }
}

int GameWorld::getWormsAlive() const {
    int alive = 0;
    for (auto& worm : worms) {
        if (worm.second->getHealth() > 0) {
            ++alive;
        }
    }
    return alive;
}

std::vector<GameUpdate> GameWorld::getWormsMoving() {
    std::vector<GameUpdate> updates;
    for (auto& worm : worms) {
        if (worm.second->isMoving()) {
            GameUpdate gameUpdate;
            gameUpdate.player_id = worm.first;
            gameUpdate.m_Dir = worm.second->getDirection();
            gameUpdate.x_pos = worm.second->getPosition().x;
            gameUpdate.y_pos = worm.second->getPosition().y;
//    gameUpdate.m_Health = worm.second->getPreviousHealth();
            gameUpdate.m_Movement = GameAction::WORM_IDLE;
            gameUpdate.m_CurrentSprite = SPRITE_WACCUSE_IDLE;
            updates.push_back(std::move(gameUpdate));
        }
    }
    return updates;
}

void GameWorld::wormsAttacked(std::vector<int> &idWorms) {
    for (auto& worm : worms) {
        if (worm.second->wasAttacked()) {
            worm.second->setWasAttacked(false);
            worm.second->getActionToAnimation()->resetAnimation();
            worm.second->getActionToAnimation()->setAction(ActionType::ATTACKED);
            idWorms.push_back(worm.first);
        }
    }
}

GameUpdate GameWorld::getWormUpdateAttacked(int id) {
    return worms.at(id)->getAttackedUpdate();
}

GameUpdate GameWorld::getWormsHealth(int id) {
    auto* worm = worms.at(id);
    GameUpdate update;
    update.m_InfoWorm = true;
    update.player_id = worm->getId();
    update.m_Dir = worm->getDirection();
    update.m_Health = worm->getHealth();
    update.x_pos = worm->getPosition().x;
    update.y_pos = worm->getPosition().y;
    update.width = worm->getWidth() * 2;
    update.height = worm->getHeight() * 2;
    update.m_CurrentSprite =
            worm->getActionToAnimation()->getCurrentSprite() == SPRITE_INVALID ? SPRITE_WACCUSE_IDLE
            : worm->getActionToAnimation()->getCurrentSprite();
    update.m_PlayerName = worm->getPlayerName();
    worm->updateHealth();
    return update;
}

std::vector<GameUpdate> GameWorld::getWormsHealths() const {
    std::vector<GameUpdate> updates;
    for (auto& worm : worms) {
        GameUpdate update;
        update.player_id = worm.second->getId();
        update.m_Health = worm.second->getHealth();
        update.x_pos = worm.second->getPosition().x;
        update.y_pos = worm.second->getPosition().y;
        update.width = worm.second->getWidth() * 2;
        update.height = worm.second->getHeight() * 2;
        update.m_PlayerName = worm.second->getPlayerName();
        update.m_CurrentSprite =
                worm.second->getActionToAnimation()->getCurrentSprite() == SPRITE_INVALID ? SPRITE_WACCUSE_IDLE
                : worm.second->getActionToAnimation()->getCurrentSprite();
        updates.push_back(std::move(update));
    }
    return updates;
}

void GameWorld::wormSetAnimationUseTool(int id) {
    worms.at(id)->getActionToAnimation()->resetAnimation();
    worms.at(id)->getActionToAnimation()->setAction(ActionType::USE_TOOL, worms.at(id)->getTool());
}

void GameWorld::wormGraveAction(int &deadWorm) {
    worms.at(deadWorm)->getActionToAnimation()->resetAnimation();
    worms.at(deadWorm)->getActionToAnimation()->setAction(ActionType::DYING);
}

void GameWorld::getWormGraveUpdate(int &deadWorm, GameUpdate &update) {
    WWorm* worm = worms.at(deadWorm);
    SpritesEnum action = SPRITE_WACCUSE_GRAVE;
    update.player_id = worm->getId();
    update.m_Dir = worm->getDirection();
    update.x_pos = worm->getPosition().x;
    update.y_pos = worm->getPosition().y;
    update.width = worm->getWidth() * 2;
    update.height = worm->getHeight() * 2;
    update.m_Health = worm->getHealth();
    update.m_Movement = GameAction::WORM_GRAVE;
    update.m_CurrentSprite = action;
    update.m_PlayerName = worm->getPlayerName();
}


void GameWorld::getWormDieUpdate(int &deadWorm, GameUpdate &update) {
    WWorm* worm = worms.at(deadWorm);
    SpritesEnum action = SPRITE_WACCUSE_DIE;
    update.player_id = worm->getId();
    update.m_Dir = worm->getDirection();
    update.x_pos = worm->getPosition().x;
    update.y_pos = worm->getPosition().y;
    update.width = worm->getWidth() * 2;
    update.height = worm->getHeight() * 2;
    update.m_Health = worm->getHealth();
    update.m_Movement = GameAction::WORM_GRAVE;
    update.m_CurrentSprite = action;
    update.m_PlayerName = worm->getPlayerName();
}

SpritesEnum GameWorld::getWormAction(int idPlayer) {
    return worms.at(idPlayer)->getActionToAnimation()->getCurrentSprite(worms.at(idPlayer));
}

void GameWorld::getWormToolUpdate(int idPlayer, GameUpdate &update) {
    WWorm* worm = worms.at(idPlayer);
    update.player_id = worm->getId();
    update.m_Dir = worm->getDirection();
    update.x_pos = worm->getPosition().x;
    update.y_pos = worm->getPosition().y;
    update.width = worm->getWidth() * 2;
    update.height = worm->getHeight() * 2;
    update.m_Health = worm->getHealth();
    update.m_Movement = GameAction::WORM_IDLE;
    update.m_CurrentSprite = worm->getActionToAnimation()->getCurrentSprite(worms.at(idPlayer));
    update.m_PlayerName = worm->getPlayerName();
}