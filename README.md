SANTIAGO SIERRA Y PABLO GARCÍA

Introduccion:

Este proyecto de arquitectura de hardware se basa en el uso de la plataforma mbed para desarrollar una aplicación que involucra una pantalla LCD, un teclado y algunas operaciones matemáticas.
-Se importan diferentes librerias, entre ellas las librerias de el LCD y el Keypad muy importantes en este proyecto
```bash
#include "mbed.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
#include <TextLCD.h>
#include <Keypad.h>

TextLCD lcd(D2,D3,D4,D5,D6,D7,TextLCD::LCD16x2);
```
-Se inicializan variable que seran indispensables en el proyecto. tambien se llama a la funcion lcd.cls() la cual funciona para preparar que pantalla LCD se borre y se ponga en blanco, eliminando cualquier texto o gráfico que estuviera previamente presente en la pantalla. Esto es útil, por ejemplo, cuando deseas mostrar información actualizada en la pantalla sin que la información anterior interfiera.
luegos se utiliza la funcion lcd.printf() para imprimir los textos en el lcd. Se utiliza el wait_us() para que se muestre bien el texto en la pantalla lcd sin ningun bug y por ultimo se llama a la funcion leerOpcion para agarrar el numero presionado en el teclado.

```bash
  double x1;
  double y1;
  double x2;
  double y2;
  int num1;
  lcd.cls();
  lcd.printf("Ingresa el numero 1 para determinar el intercepto con el eje y la "
          "recta entre 2 puntos, el 2 para calcular promedio o el 3 para "
          "generar colores en led. \n");
    wait_us(5000000);

  num1 = leerOpcion();
```
-Se verifica si la variable num1 es igual a 1 para determinar si se debe realizar esta sección de código. Luego se limpia la pantalla LCD para asegurarse de que esté en blanco antes de mostrar un nuevo mensaje, despues Imprime en la pantalla LCD el mensaje, luego se pausa la ejecución del programa por un corto tiempo y se almacena en la variable el numero que el usurio dio por medio del tecclado marcial. Por ultimo muestra en el lcd el numero seleccionado y repite este proceso otras 3 veces.

```bash
if (num1 == 1) {
    lcd.cls();
    lcd.printf("Ingrese la x1: ");
    wait_us(5000000);
    x1 = stod(numeroReal());

    lcd.cls();
    lcd.printf("%d", int(x1));
    wait_us(5000000);

    lcd.cls();
    lcd.printf("Ingrese la y1: ");
    wait_us(5000000);

    y1 = stod(numeroReal());

    lcd.cls();
    lcd.printf("%d", int(y1));
    wait_us(5000000);

    lcd.cls();
    lcd.printf("Ingrese la x2: ");
    wait_us(5000000);

    x2 = stod(numeroReal());

    lcd.cls();
   lcd.printf("%d",int(x2));
    wait_us(5000000);

    lcd.cls();
    lcd.printf("Ingrese la y2: ");
    wait_us(5000000);

    y2 = stod(numeroReal());

    lcd.cls();
    lcd.printf("%d",int(y2));
    wait_us(5000000);
```
