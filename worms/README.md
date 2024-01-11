# Worms
## Cosas por hacer
- Refactor parse map para que lea tambien gusanos y agua
- Colision entre gusanos, no se porque no esta funcionando al 100%. A veces se mueven los dos, a veces solo uno
- Diferentes tipos de viga con inclinacion. En WWorm hacer algo con la logica de moverse, porque cuando este en una viga inclinada va a tener velocidad en y
- Leer de archivo de mapa las posiciones de los Worms
- Animacion de set weapon y un set weapon. Porque cuando equipo el bate y lo tengo seteado hace todo el sprite de la animacion. Tendria que haber un set(setting) weapon, y has weapon.

#### Grafico - cliente
La cámara del juego está funcionando con errores. 
- El gusano al moverse hacia la derecha se sale del mapa (es decir, la cámara no lo sigue). 
- El fondo del mapa solo se mueve en una parte del mismo. También ocurre qué el fondo se mueve a una velocidad mucho mayor a la que lo hace el gusan (para recrear este problema desplazarse primero hacia la izquierda una vez iniciado el juego, a partir de ahí moverse a cualquier lado). 
- Al intentar aplicarle la cámara al gusano que se encuentra en movimiento, el mismo tiene problemas para renderizarse, se renderiza bien dependiendo de donde se encuentre el gusano.
- Cuando se conectan dos o más jugadores los gusanos de los mismos no son mostrados en pantalla.
- Al generarse la ventana de “esperando al resto de jugadores” (esto sería una ventanita de QT la cual se genera mientras esperan por una partida), se genera de manera correcta el único problema que estuve teniendo es que cuando se genera y se terminan de unir todos los jugadores la misma no se cierra automáticamente sino que uno debe cerrarla para que pueda ejecutarse la ventana de SDL y entrar al game.
- Con respecto al editor, ya está implementado una base del mismo se pueden agregar tanto vigas como gusanos y el fondo. Todavía hay un problema con que no se puedan poner cosas más allá de la ventana de escena y falta generar el archivo para que pueda ser agregado con los demás mapas ya existentes.

#### Servidor

- En el servidor, hay un bug que se genera cuando un cliente queda en estado de espera luego de crear una partida que aún no ha comenzado. También pasa con los clientes que se unen a una partida y esta luego de su adhesión tampoco empieza. Cuando en alguno de estos dos casos, el un cliente termina abruptamente (cerrando su socket) el servidor queda con 2 hilos fantasmas por cada cliente desconectado. 
- No hay testing. El protocolo esta definido, faltan implementar los scripts de generacion de salida de casos de test y comparacion de estos mismos.
- ParseMapFromFile.h: Esta clase es la encargada de leer el archivo que esta guardado dentro del package maps, y procesar el mismo segun la siguiente convencion:
```
<numero de vigas a leer>
<tipo de viga> <posicion x> <posicion y>
```
Cabe destacar que las posiciones estan basadas en el centro del cuerpo.
Aca habria que hacer un refactor para que también lea del archivo gusanos y el agua. También falta que en el archivo se estén seteando estos mismos (actualmente las posiciones iniciales del worm son aleatorias), ya que hasta el momento solo se está seteando las vigas que presenta el mapa.
- Colision entre gusanos, hay un pequeño bug, cuando un gusano colisiona con otro, se activa el ContactListener del Worm, y este ejecuta ciertos metodos del Worm (tanto del receiver o producer de la colision) para que el mismo no se mueva.
El bug que se presenta es que el gusano arrastra al otro.
- Falta que el World setee Vigas inclinadas. A como esta desarrollado hasta el momento solo permite vigas de tipo large o small verticales u horizontales.
- Animacion de Set Weapon, actualmente se esta loopeando en todo el sprite de la animación del Bate.
- TBS: Falta implementar bien el sistema de turnos, actualmente existe un Sistema de turnos que solamente habilita al jugador correspondiente después de pasados 120 segundos. Pero hay que agregar la parte de las condiciones de corte del turno, y ademas de que el las explosiones, muertes, y demas animaciones se ejecuten en un periodo de “no turno”, donde ocurren todas estas actualizaciones del Game.
- Falta que se pueda cerrar las ventanas de SDL sin tener que matar al proceso.
- De los features mas importantes del juego se implementó:
- Movimiento; salto; equipacion de Hacha y Bate; la funcion de Ataque;  la muerte de un Worm; las colisiones entre gusanos y con el Agua que instakillea al Worm; TBS (a medio terminar).

- Hay un pequeño bug que es cuando en el Mapa 1 el Worm camina hasta la mitad del mapa, queda trabado. Esto creeria que se debe a que en el World entre las vigas hay un pequeño hueco que no dejaria caminar al Worm y pasar a la segunda viga. No hizo un find de ese bug, pero se estima que viene por ese lado. Ya que cuando llega a la mitad de la viga y se queda trabado, se destraba saltando y yendo hacia delante.

## Manual de usuario

Para poder jugar el juego es necesario tener instalado de forma local los archivos del juego. El juego se encuentra alojado en un repositorio de github.
https://github.com/SantiPira/Worms

Para instalarlo basta con clonar el repositorio o descargar el .zip y descomprimirlo en donde se desee tener la carpeta de instalación.

Una vez descargado, es necesario correr el instalador del juego, para esto, hay que abrir la terminal desde la carpeta del juego y ejecutar el comando ./installer.sh. El instalador se va a encargar de crear una carpeta llamada build donde se encuentran los ejecutables del juego.

- Servidor: 
Para correr el servidor es necesario ejecutar el comando “./worms-server numero_de_puerto”. Cuál número de puerto usar es responsabilidad del jugador.

- Cliente:
El cliente se corre con “./worms-client”. Una vez ejecutado se mostrará una ventana en la cual hay que ingresar el IP y el puerto del servidor con el que se desea establecer una conexión.

Una vez establecida la conexión,  se muestra una ventana que permite decidir si unirse a un juego o crear una partida nueva. Una vez concretadas una de las dos opciones, se ingresará a un lobby hasta que la partida inicié.

#### Gameplay

Para mover al gusano se utilizan las teclas:
- A : Mueve a izquierda
- D: Mueve a Derecha
- Barra espaciadora: Salta
- H: Saca el Hacha y equipa el Hacha
- J: Guarda el arma
- B: Saca y equipa el Bate
- C: Ataca

El Worm por defecto tiene 100 de HP y el golpe del Hacha quita 50 de HP.
Para el uso del Bate se empezo a implementar el aumento del angulo de golpe, con las flechas UP y DOWN se incrementa y decrementa el angulo. Esto no esta del todo hecho.

Y para el ataque con esta arma se mantiene pulsada la tecla ‘C’, que hace cargar la potencia del golpe.
