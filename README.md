# worms_remake
Remake del juego Worms realizado durante mi cursada en Taller de programación I.

El remake fue realizado en C++ utlizando programación concurrente, y protocolos TCP para la comunicación entre cliente y servidor. A su vez se hizo uso de un motor de físicas (Box2D) del lado del servidor para manejar la físicas del juego, y de un motor gráfico (SDL) para renderizar las físicas del juego del lado del cliente. 

Cliente y servidor se comunican vía socket TCP. Cada cliente realiza una acción en el juego, la cual es enviada al servidor, y procesada en el motor físico del mismo. Luego el servidor envía a cada uno de los clientes del juego la información a rederizar por parte de SDL (Ver diagramas para entender mejor la comunicación entre cliente y servidor, y la existencia de distintos hilos).

-El trabajo fue realizado en un equipo de 4 personas:

1-Santiago Piragine - spiragine@fi.uba.ar

2-Víctor Zacarías - vzacarias@fi.uba.ar

3-Julian Morales - jlmorales@fi.uba.ar

4-Juan Cuevas - jcuevas@fi.uba.ar

-La biblioteca de Sockets y Threads usada para la simplifiación de uso de protoclos TCP y programación concurrente en clases es de autoría de la cátedra en la que se cursó la materia (Veiga, Taller de programación I, UBA-FIUBA).
