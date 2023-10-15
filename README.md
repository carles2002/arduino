# Código Arduino para un emisor BLE de CO2


## *En esta primera versión el código esta separado en proyectos diferentes ([beacon](https://github.com/carles2002/arduino/tree/main/beaconArduino) y [medición](https://github.com/carles2002/arduino/tree/main/sketch_sep22a))*




El código Arduino que se muestra a continuación es un emisor BLE de CO2. El emisor se basa en la placa Arduino Nano 33 BLE, que tiene un módulo Bluetooth Low Energy integrado.



## Descripción general



***El código funciona de la siguiente manera:***

El código inicializa la placa Arduino y el módulo Bluetooth Low Energy.
El código crea un servicio BLE con una característica para el valor de CO2.
El código mide el valor de CO2 usando un sensor de CO2.
El código publica el valor de CO2 en la característica BLE.
El código repite los pasos 3 y 4 en un bucle infinito.
Instalación

## Para instalar el código, sigue estos pasos:

Descarga el código de GitHub.
Descomprime el archivo ZIP.
Abre el archivo beaconArduino.ino en el IDE de Arduino.
Añade la carpeta de librerías a la raíz de la carpeta donde este el .ino.
Conecta la placa Arduino Nano 33 BLE a tu computadora.
Compila y carga el código en la placa Arduino.

## Configuración

El código tiene las siguientes configuraciones:

La dirección MAC del dispositivo BLE se puede configurar .
El intervalo de publicación del valor de CO2 se puede configurar.
Se pueden añadir valores a modo de "*test*" antes de enviar el beacon.

## Uso

Para usar el emisor, sigue estos pasos:

Abre la aplicación de tu teléfono inteligente para detectar dispositivos BLE.
Busca el dispositivo con la dirección MAC que configuraste en el código.
Conecta tu teléfono inteligente al dispositivo / escanea beacons cercanos.
En la aplicación de tu teléfono inteligente, deberías ver el valor de CO2.

**Explicación del código**

El código funciona de la siguiente manera:

La función `setup()` inicializa la placa Arduino y el módulo Bluetooth Low Energy. También crea el servicio BLE y la característica BLE para el valor de CO2.
La función `loop()` mide el valor de CO2 y lo publica en la característica BLE.
(*En esta versión inicial no se miden los valores de CO2, estos estan predefinidos en el código*)






**El código también incluye las siguientes funciones adicionales:**

La función `imprimirDatos()` imprime los datos del emisor en el monitor serie.
La función `led()` controla el encendido y apagado del led integrado.
Para obtener más información sobre estas funciones, consulta el código fuente.

## Librerias 
El codigo hace uso de 6 Librerias:

### LED
Esta librería se encarga de manejar el uso del led integrado en la placa ESP, permite encenderlo, apagarlo y hacerlo brillar X segundos.

### Medidor
En esta librería se encuentra todo lo que tiene que ver con **obtener lecturas de los sensores**, en el caso de esta primera versión, no se ha implementado el codigo necesario para hacerlo y simplemente se emulan los valores. (*El código que falta está en el otro proyecto sketch del repositorio*)

### Publicador
Esta librería se encarga de preparar la **emisora** para su correcto funcionamiento con diferentes configuraciones (Nombre, fabricante, potencia de emision...)y además permite emitir/publicar valores por beacon, como pueden ser un minor y un major o la temperatura y el valor de CO2.

### EmisoraBLE
En esta librería se implementa el funcionamiento de la emisora Bluetooth, haciendo uso de la libreria de codigo abierto bluefruit y de servicioEnEmisora. Esta permite encender la emisora, enviar datos, apagarla ... 

### PuertoSerie
Esta librería permite enviar mensajes de texto por el puerto serie para poder ser leidos por otros dispositivos compatibles.

### servicioEnEmisora 
Aquí es donde se implementa todo lo que permite el envio de datos mediante Bluetooth utilizando bluefruit, permite establecer una comunicacion y enviar caracteres concretos. (*En este caso no se utiliza, ya que solo se requiere el envio de dos [N]*)
