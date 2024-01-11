#pragma once

#include "../../../../Box2D/include/box2d/box2d.h"
#include "messages/server/GameUpdate.h"
#include "world/entities/weapons/WeaponFactory.h"
#include "world/entities/weapons/impl/Axe.h"
#include "world/entities/weapons/impl/Bate.h"
#include "world/entities/weapons/impl/Bazooka.h"
#include "messages/user_actions/ActionType.h"
#include "world/entities/action_animations/ActionToAnimation.h"
#include "world/entities/action_animations/types/SActionWeapon.h"
#include "EntitiesType.h"
#include "WEntity.h"
#include "messages/user_actions/ToolID.h"
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>

class WProyectile;

class WWorm : public WEntity {
private:
    uint8_t m_Id;
    std::string m_PlayerName;
    b2World* m_World{};
    b2Body* m_Body{};
    float m_Width{};
    float m_Height{};
    b2Vec2 m_Position{};
    b2Vec2 m_Velocity{};
    float m_Angle{};
    float m_AngularVelocity{};
    int32 m_Health{};
    int32 m_PreviousHealth{};
    int32 m_Ammo{};
    int32 m_Score{};
    bool m_IsDead{};
    bool m_IsFacingRight{};
    bool m_IsMoving{};
    bool m_IsJumping{};
    bool m_IsFalling{};
    bool m_IsShooting{};
    bool m_WasAttacked{};
    GameAction m_SelfCondition;
    WeaponID m_Weapon;
    Direction m_Dir;
    bool m_IsAttacking{};
    uint16_t m_WormCategory{};
    EntitiesType m_EntityType;
    float m_WeaponAngle{};
    std::chrono::time_point<std::chrono::system_clock> m_TimeState; //seconds
    bool m_WasChanged;
    GameUpdate m_PreviousState;
    ActionType m_CurrentActionType = ActionType::NONE;
    bool m_IsInContactWithWWorm = false;
    Direction m_OtherDirection{};
    ActionToAnimation m_ActionToAnimation;
    ToolID m_Tool;

public:
    bool tieneProyectil{false};
    //b2Body* proyectil;
    WProyectile* proyectil;

public:
    WWorm(b2World* world, std::string playerName, uint8_t id, float posX, float posY, bool isFacingRight, uint16_t wormCategory,
          const std::vector<uint16_t>& categories);

    [[maybe_unused]] [[nodiscard]] uint8_t getId() const;
    [[nodiscard]] b2Body* getBody() const;
    [[nodiscard]] b2Vec2 getPosition() const;
    [[nodiscard]] b2Vec2 getVelocity() const;
    [[nodiscard]] float getAngle() const;
    [[nodiscard]] float getAngularVelocity() const;
    [[nodiscard]] int32 getHealth() const;
    [[nodiscard]] int32 getPreviousHealth() const;
    [[nodiscard]] int32 getAmmo() const;
    [[nodiscard]] int32 getScore() const;
    [[nodiscard]] bool getIsDead() const;
    [[nodiscard]] bool getIsFacingRight() const;
    [[nodiscard]] bool getIsMoving() const;
    [[nodiscard]] bool getIsJumping() const;
    [[nodiscard]] bool getIsFalling() const;
    [[nodiscard]] bool getIsShooting() const;
    [[nodiscard]] WeaponID getWeapon() const;
    [[nodiscard]] Direction getDirection() const;
    [[nodiscard]] bool getIsAttacking() const;
    [[nodiscard]] GameAction getSelfCondition() const;
    [[nodiscard]] float getWeaponAngle() const;
    [[nodiscard]] b2World *getWorld() const;
    EntitiesType getEntityType() override;
    [[nodiscard]] GameUpdate getPreviousState() const;
    [[nodiscard]] bool getIsInContactWithAnotherWorm() const;
    ActionToAnimation* getActionToAnimation();
    std::string getPlayerName() const;
    [[nodiscard]] ToolID getTool() const;
    bool isMoving() const;
    bool wasAttacked() const;

    void setPosition(b2Vec2 position);
    void setVelocity(b2Vec2 velocity);
    void setAngle(float angle);
    void setAngularVelocity(float angularVelocity);
    void setHealth(int32 health);
    void setAmmo(int32 ammo);
    void setScore(int32 score);
    void setIsDead();
    void setIsFacingRight(bool isFacingRight);
    void setIsMoving(bool isMoving);
    void setIsJumping(bool isJumping);
    void setIsFalling(bool isFalling);
    void setIsShooting(bool isShooting);
    void setWeapon(WeaponID weapon, ActionType actionType);
    void setDirection(Direction dir);
    void setIsAttacking(bool isAttacking);
    void setSelfCondition(GameAction selfCondition);
    void setWeaponAngle(float angle, bool isIncreasing, ActionType actionType);
    void resetWormStatus();
    void setWasChanged(bool wasChanged);
    void setIsInContactWithAnotherWorm(bool isInContactWithAnotherWorm);
    void setOtherDirection(Direction otherDirection);
    void setWasAttacked(bool wasAttacked);
    void setTool(ToolID tool);

    GameUpdate getUpdate(bool wormChanged);

    void jump();

    void stopMove();

    void attack(uint8_t force);

    void receiveDamage(int damage);

    ~WWorm() override = default;

    void increaseWeaponAngle();

    void move(Direction direction);

    GameAction getMovement();

    bool getWasChanged() const;

    float getWidth() const;

    float getHeight() const;

    void unSetWeapon();

    GameUpdate getAttackedUpdate();

    void updateHealth();

    void useTool(float param1, float param2);
};