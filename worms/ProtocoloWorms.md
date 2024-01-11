El protocolo del juego esta definido en dos etapas, una etapa de conexion y transferencia de datos y una segunda etapa de "juego", donde se utiliza el protocolo para actualizar el juego.

#### Conexion

En esta etapa tanto el cliente como el servidor utilizan la misma clase compuesta GameInfo:

```
class GameInfo {
private:
InitGameEnum m_IdAction;
std::vector<GameProperty> m_GameProperties;
}
```

Esta esta compuesta por un InitGameEnum que modela las acciones que puede querer realizar el cliente

```
enum InitGameEnum : uint8_t {
CREATE_GAME = 0x00,
JOIN_GAME = 0x01,
LIST_GAMES = 0x02,
QUIT = 0x03,
INVALID = 0x04,
ID_PLAYER = 0x05
};
```

y por un vector de GameProperty donde cada uno modela una partida (ya sea para crear una o para informar de la existencia):

```
struct GameProperty {
int m_idGame{};
std::string m_GameName;
std::string m_MapName;
int m_PlayersConnected{};
int m_Players{};
int m_IdPlayer = 0;
GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players);
GameProperty(int idGame, std::string gameName, std::string mapName, int playersConnected, int players, int idPlayer);
explicit GameProperty(int idPlayer) : m_IdPlayer(idPlayer) {}
};
```

#### Actualizacion de juego

Esta etapa se da posteriormente a la decision de usuario de poder crear o elegir una partida ya existente. De esta manera, cuando comienza la partida los clientes tienen la capacidad de enviar decisiones de juego y el servidor de responder mediante actualizaciones a estas decisiones.

El usuario manda sus decisiones a traves de UserAction:

```
class UserAction {
private:
ActionType m_Action;
int m_IdPlayer;
uint8_t m_Param1;
uint8_t m_Param2;
```

esta clase tiene una accion asociada ActionType:

```
enum ActionType : uint8_t {
MOVE = 0X00,
STOP_MOVE = 0X01,
JUMP = 0X02,
NONE = 0X03,
ATTACK = 0X04,
STOP_ATTACK = 0X05,
SET_WEAPON = 0X06,
UNSET_WEAPON = 0X07,
DECREASE_ANGLE = 0X08,
INCREASE_ANGLE = 0X09
};
```

y dos parametros que pueden variar dependiendo de el tipo de accion que haga el usuario. 
Por ejemplo puede ser una direccion mapeada en Direction:

```
enum Direction : uint8_t {
LEFT = 0X00,
RIGHT = 0X01
};
```

El servidor por su parte procesa de manera secuencial estas acciones y envia las correspondientes actualizaciones a los usuarios a traves de GameUpdate:

```
struct GameUpdate {
uint8_t player_id;
float x_pos;
float y_pos;
float width;
float height;
double m_TimeDuration;
GameAction m_Movement;
WeaponID m_Weapon;
bool m_IsAttacking;
uint8_t m_Health;
Direction m_Dir;
GameAction m_SelfCondition;
float m_VelocityX;
float m_VelocityY;
```

cada uno de estos GameUpdate corresponden a un objeto (gusano, proyectil, etc) que pueda existir en el juego. Ademas ampliando la informacion sobre su estado y situacion actual. A traves del GameAction, se envia al cliente la accion que puede estar realizando un gusano:

```
enum GameAction : uint8_t {
START_TURN = 0x00,
WORM_MOVE_RIGHT = 0x01,
WORM_MOVE_LEFT = 0x02,
WORM_IDLE = 0x03,
WORM_NONE = 0x04,
WORM_JUMP = 0x05,
WORM_FALL = 0x06,
HAS_WEAPON_AND_ATTACK = 0X07,
HAS_WEAPON_AND_NO_ATTACK = 0X08,
NO_HAS_WEAPON = 0X09,
WORM_ATTACKED = 0x0A,
WORM_DIE = 0x0B,
WORM_GRAVE = 0x0C,
END_TURN = 0x0D,
INVALID_ACTION = 0xFF
};
```