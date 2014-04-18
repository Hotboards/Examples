Ejemplos
=======

BSP
---

**(gpios) General Pourpose Input  Outputs**

- [Ejemplo 1: Parpadeo de un led](https://github.com/Hotboards/Examples/blob/master/Microchip/gpios1.X/main.c)
- [Ejemplo 2: Escritura y lectura de un puerto](https://github.com/Hotboards/Examples/blob/master/Microchip/gpios2.X/main.c)
- [Ejemplo 3: Rotación de leds en un puerto](https://github.com/Hotboards/Examples/blob/master/Microchip/gpios3.X/main.c)


**(delays) Retardos por software**

- [Ejemplo 1: Parpadeo de un led cada 100ms](https://github.com/Hotboards/Examples/blob/master/Microchip/delays1.X/main.c)
- [Ejemplo 2: Parpadeo de un puerto completo a 500ms](https://github.com/Hotboards/Examples/blob/master/Microchip/delays2.X/main.c)
- [Ejemplo 3: Rotación de leds en un puerto cada 200ms](https://github.com/Hotboards/Examples/blob/master/Microchip/delays3.X/main.c)


**(swtimers) Timers por software**

- [Ejemplo 1: Parpadeo de un led cada 100ms](http://github.com/Hotboards/Examples/blob/master/Microchip/swtimers1.X/main.c)
- [Ejemplo 2: Parpadeo de de 3 leds a diferentes tiempos](http://github.com/Hotboards/Examples/blob/master/Microchip/swtimers2.X/main.c)
- [Ejemplo 3: Rotación de leds en un puerto cada 500ms y parpadeo de un led en RA1 cada 100ms](http://github.com/Hotboards/Examples/blob/master/Microchip/swtimers3.X/main.c)
- [Ejemplo 4: Parpadeo de led con prioridad alta, CPU a 48MHz y base de tiempo a 10ms](http://github.com/Hotboards/Examples/blob/master/Microchip/swtimers4.X/main.c)


**(adc) Convertidor analogo digital**

- [Ejemplo 1: lectura simple de una canal de adc](http://github.com/Hotboards/Examples/blob/master/Microchip/adc1.X/main.c)
- [Ejemplo 2: lectura múltiple de diferentes canales de adc](http://github.com/Hotboards/Examples/blob/master/Microchip/adc2.X/main.c)


**(uart) Puerto serial**

- [Ejemplo 1: Transmicion de una cadena de caracteres a 115200](http://github.com/Hotboards/Examples/blob/master/Microchip/uart1.X/main.c)
- [Ejemplo 2: Transmicion de una cadena de caracteres con interrupciones a 115200](http://github.com/Hotboards/Examples/blob/master/Microchip/uart2.X/main.c)
- [Ejemplo 3: Transmicion de una cadena cada que se presiona un botón a 9600](http://github.com/Hotboards/Examples/blob/master/Microchip/uart3.X/main.c)
- [Ejemplo 4: Simple eco de un caracter escrito en una terminal a 9600](http://github.com/Hotboards/Examples/blob/master/Microchip/uart4.X/main.c)
- [Ejemplo 5: Encendido y apagado de leds con recepción de cadenas por puerto serial a 9600](http://github.com/Hotboards/Examples/blob/master/Microchip/uart5.X/main.c)
- [Ejemplo 6: Transmicion de una cadena de caracteres a 115200 usando uart2](http://github.com/Hotboards/Examples/blob/master/Microchip/uart6.X/main.c)


**(spi) - Serial Peripheral Interface**

- [Ejemplo 1: Transmicion y recepción de datos](https://github.com/Hotboards/Examples/blob/master/Microchip/spi1.X/main.c)
- [Ejemplo 2: Transmicion y recepción de datos con spi2](https://github.com/Hotboards/Examples/blob/master/Microchip/spi2.X/main.c)


**(i2c) - Inter-Integrated Circuit**

- [Ejemplo 1: Lectura de un registro, (registro del sensor TC47)](https://github.com/Hotboards/Examples/blob/master/Microchip/i2c1.X/main.c)
- [Ejemplo 2: Lectura continua de un registro, (lectura de la temperatura)](https://github.com/Hotboards/Examples/blob/master/Microchip/i2c2.X/main.c)


**(pwm) - Modulacion de Ancho de Pulso**

- [Ejemplo 1: Señal a 1KHz y 80% en el canal A del modulo PWM 1](https://github.com/Hotboards/Examples/blob/master/Microchip/pwm1.X/main.c)
- [Ejemplo 2: Señales a 2KHz al 30% en los canales A, B y C del modulo PWM 1](https://github.com/Hotboards/Examples/blob/master/Microchip/pwm2.X/main.c)
- [Ejemplo 3: Señales a una frecuencia de 1KHz con diferente duty cycle usando PWM1 y PWM2](https://github.com/Hotboards/Examples/blob/master/Microchip/pwm3.X/main.c)
- [Ejemplo 4: Simple dimmer de 1% a 100% en el PWM 1 canal A, 750Hz de Frecuencia](https://github.com/Hotboards/Examples/blob/master/Microchip/pwm4.X/main.c)


**(usb cdc) Universal Serial Bus, clase CDC**

- [Ejemplo 1: Transmicion continua de una cadena de caracteres](http://github.com/Hotboards/Examples/blob/master/Microchip/usb_cdc1.X/main.c)
- [Ejemplo 2: Simple eco de caracteres](http://github.com/Hotboards/Examples/blob/master/Microchip/usb_cdc2.X/main.c)
- [Ejemplo 3: Transmicion continua de una cadena de caracteres usando interrupciones](http://github.com/Hotboards/Examples/blob/master/Microchip/usb_cdc3.X/main.c)


Middleware
---------

**(gpis) Entradas de propósito general**

- [Ejemplo 1: Invertir el estado de un led cada que se presiona un botón](http://github.com/Hotboards/Examples/blob/master/Microchip/gpis1.X/main.c)
- [Ejemplo 2: Aumentar el tiempo que se debe presionar un botón](http://github.com/Hotboards/Examples/blob/master/Microchip/gpis2.X/main.c)
- [Ejemplo 3: Apagar y prender un led según el estado de un botón/interruptor](http://github.com/Hotboards/Examples/blob/master/Microchip/gpis3.X/main.c)
- [Ejemplo 4: Invertir el estado de 3 leds acorde a la activación de 3 botones](http://github.com/Hotboards/Examples/blob/master/Microchip/gpis4.X/main.c)


**(gpos) Salidas de proposito general**

- [Ejemplo 1: Invertir el estado de un led cada 200ms](http://github.com/Hotboards/Examples/blob/master/Microchip/gpos1.X/main.c)
- [Ejemplo 2: Encender un led por 300ms cada que se presione un botón](http://github.com/Hotboards/Examples/blob/master/Microchip/gpos2.X/main.c)
- [Ejemplo 3: Parpadeo un led a 50ms por un lapso de 1s](http://github.com/Hotboards/Examples/blob/master/Microchip/gpos3.X/main.c)
- [Ejemplo 4: Parpadeo de 4 leds a diferentes timepos](http://github.com/Hotboards/Examples/blob/master/Microchip/gpos4.X/main.c)


**(Keyboard) Teclado Matricial**

- [Ejemplo 1: Simple lectura de teclado y despliegue con leds](http://github.com/Hotboards/Examples/blob/master/Microchip/keyboard1.X/main.c)
- [Ejemplo 2: Teclas con diferente tiempo de presionado](http://github.com/Hotboards/Examples/blob/master/Microchip/keyboard2.X/main.c)


**(6800) Interfaz paralela 6800**

- [Ejemplo 1: Inicilizacion de un controlador hd44780](http://github.com/Hotboards/Examples/blob/master/Microchip/68001.X/main.c)
- [Ejemplo 2: Escritura de un dato a un controlador hd44780](http://github.com/Hotboards/Examples/blob/master/Microchip/68002.X/main.c)
- [Ejemplo 3: Escritura de un dato a un controlador hd44780 en modo 4 bits a 48MHz](http://github.com/Hotboards/Examples/blob/master/Microchip/68003.X/main.c)


**(printf) Salidas por pantalla formateadas**

- [Ejemplo 1: Trasnmicion de cadenas formateadas con la función xprintf](http://github.com/Hotboards/Examples/blob/master/Microchip/printf1.X/main.c)
- [Ejemplo 2: Transmicion de una cadena formateada con xsprintf por interrupciones](http://github.com/Hotboards/Examples/blob/master/Microchip/printf2.X/main.c)
- [Ejemplo 3: Printf como herramienta de depuración](http://github.com/Hotboards/Examples/blob/master/Microchip/printf3.X/main.c)

**(7segments) Display de 7 segmentos**

- [Ejemplo 1: Simple despliegue de 4 numeros ](http://github.com/Hotboards/Examples/blob/master/Microchip/7segments_1.X/main.c)
- [Ejemplo 2: Contador de 0 a 255 con tres display](http://github.com/Hotboards/Examples/blob/master/Microchip/7segments_2.X/main.c)
- [Ejemplo 3: Despliegue de voltaje (0 a 3.3) con punto decimal](http://github.com/Hotboards/Examples/blob/master/Microchip/7segments_3.X/main.c)


Modules
------

**(eeprom25xx) - Memorias Microchip Eeprom spi**

- [Ejemplo 1: Escribir y leer una pagina entera en la memoria](https://github.com/Hotboards/Examples/blob/master/Microchip/eprom25xx1.X/main.c)


**(hd44780) LCD alfanumerico**

- [Ejemplo 1: Envió de mensajes en diferentes posiciones del lcd](http://github.com/Hotboards/Examples/blob/master/Microchip/hd447801.X/main.c)
- [Ejemplo 2: Uso de la funciones printf con el lcd](http://github.com/Hotboards/Examples/blob/master/Microchip/hd447802.X/main.c)


**(st7032) - Controlador LCD Sitronix**

- [Ejemplo 1: Envió de mensajes en diferentes posiciones del lcd](https://github.com/Hotboards/Examples/blob/master/Microchip/st7032.X/main.c)


**(tc74ax) - Sensor de Temperatura Microchip**

- [Ejemplo 1: Lectura de la temperatura](https://github.com/Hotboards/Examples/blob/master/Microchip/TC74Ax1.X/main.c)

