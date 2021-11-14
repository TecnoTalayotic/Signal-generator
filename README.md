# Signal-generator
Generador de señales analógicas y digitales.

Con este generador de señales se puede controlar la señal digital cuadrada (PWM) y la señal analógica 0-5Vdc.

En el modo digital tenemos un potenciómetro para regular la amplitud de onda, y otro para elegir entre 14 frecuencias distintas.

En el modo analógico regulamos la tensión de salida de 0 - 5 Vdc a través de un Pin PWM y un filtro de paso bajo, convirtiendo la señal digital a analógica.

Los resultados se imprimen por puerto Serial y solo se modifican si algún valor se modifica.
.
Lo que no entiendo demasiado y no sé cómo modificarlo son los datos de frecuencia, más adelante indagaré en el tema.

..........................................................................

-Información sobre la regulación de la frecuencia extraída de:

https://www.electrodaddy.com/incrementando-la-frecuencia-pwm-de-arduino/

-Información del filtro paso bajo extraída de:

http://www.rinconingenieril.es/pwm-salida-analogica/
