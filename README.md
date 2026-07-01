# TAREA3_ELO329_GRUPO11_ACOSTA_CASTILLO
En este repositorio se encuentra el código realizado por nuestro equipo para la tarea 3 de la asignatura de ELO329 (Diseño y programación orientada a objetos). Esta tarea está realizada en el lenguaje de programación C++ y el IDE QtCreator


## Integrantes:
1. Constanza Acosta   202330019-5
2. Josefa Castillo    202430002-4


## Descripción:
En este repositorio se encuentra el código realizado por nuestro equipo (grupo 11) para la tarea 3 de la asignatura de ELO329 (Diseño y programación orientada a objetos).

## Contexto del problema a abordar:
Esta tarea está inspirada en el producto AirTag. Un AirTag es un dispositivo localizador de objetos personales (llaves, mochilas, maletas, etc.). Un EloTelTag es un dispositivo AirTag con funcionalidades reducidas y se reporta vía cualquier celular, además el dispositivo se puede guardar en una mochila, maleta, cartera, llavero, etc. 
Cada persona poseedora (dueño/a) de un EloTelTag además debe poseer al menos un celular y también podría tener un tablet.

Cada EloTelTag, tablet y celular tiene un nombre (por ejemplo para indicar qué identifica -celular, Tablet, maleta, llaves, etc.) y un identificador de su dueño/a. Para efectos de esta tarea sólo los celulares pueden reportar su posición a una nube (tienen un GPS, Global Positioning System). 

Los EloTelTag y tablets se comunican con cualquier celular cercano, esto es si su distancia es **inferior a 10 [m]**, para reportar su localización (en realidad la del celular), su nombre y el nombre de su dueño/a. Así, mientras los **celulares pueden reportar a la ETnube** su posición, los *EloTelTag* y los *tablets* **lo hacen a través de un celular cercano** perteneciente a la misma u otra persona, así como se puede observar en la imagen a continuación.


## Objetivos:

- Modelar objetos reales como objetos de software.
- Ejercitar la creación y extensión de clases dadas para satisfacer nuevos requerimientos.
- Reconocer clases y relaciones entre ellas en código fuente C++.
- Ejercitar la compilación y ejecución de programas en lenguaje C++ desde una IDE (QtCreator).
- Ejercitar la configuración de un ambiente de trabajo para desarrollar aplicaciones en lenguaje C++. Se puede trabajar con un editor tipo “Sublime” o con un IDE (Integrated Development Environment). QtCreator es el IDE sugerido tanto para esta tarea.
- Ejercitar la entrada y salida de datos en C++.
- Ejercitar la preparación y entrega de resultados de software.
- Familiarización con desarrollos "iterativos" e "incrementales" (o crecientes).


## Diagrama de clases:

<img width="2642" height="3354" alt="diagrama de clases" src="https://github.com/user-attachments/assets/e913b248-c7cc-4f93-a048-b203475921c2" />

Figura 1: Diagrama de clases del programa.


## Resultados finales:

<img width="1710" height="1107" alt="Estado inicial programa" src="https://github.com/user-attachments/assets/6c8693b1-44df-4a15-99af-075767df7933" />

Figura 2: Se muestra el mapa de placeres con los dispositivos con sus respectivos colores y radares, junto con el menú Simulation.


<img width="1710" height="1107" alt="Muestra de menú findMy" src="https://github.com/user-attachments/assets/5610fecb-43ba-4467-8937-f9f0a0a44cac" />

Figura 3: Se ha seleccionado Play en el menú. En los celulares se presenta la opción findMy a la cual se puede acceder haciendo clic.


<img width="1710" height="1107" alt="Reporte findMy" src="https://github.com/user-attachments/assets/5167ec1a-9b00-4e40-b3e0-10f2073bcd95" />


Figura 4: Al hacer clic en la opción findMy se muestran los dispositivos cercanos reportados (en el radar).



## Compilación y ejecución del programa:

- Descargue todos los archivos del proyecto en una misma carpeta.
- Abra el IDE Qt Creator.
- Vaya a File -> Open File or Project... y seleccione el archivo CMakeLists.txt que está dentro de la carpeta del proyecto.
- Si el IDE se lo solicita, seleccione el Kit de compilación (Configure Project).
- Finalmente, presione el botón Build (icono de martillo en la esquina inferior izquierda) para compilar y luego el botón Run (icono de triángulo verde "Play") para ejecutar el programa.

Consideraciones: Si está trabajando desde un dispositivo MacOS para presionar la opción de findMy, deberá pulsar la tecla "control" y hacer clic en el celular del programa.
