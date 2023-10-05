SANTIAGO SIERRA Y PABLO GARCÍA

Introduccion:

Este proyecto de arquitectura de hardware se basa en el uso de la plataforma mbed para desarrollar una aplicación que involucra una pantalla LCD, un teclado y algunas operaciones matemáticas.Se utilizan 2 librerias en especial para el desarrollo de este proyecto, entre ellas la libreria de la pantalla LCD de la cual estaremos usando funciones como .cls(), .printf(), etc. Y la libreria del Keypad de la cual estremos usando metodos como .numeroReal(), .leerOpcion(), etc.


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
int main(){
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
-Se inicializa y asigna un valor a la variable pendiente y la variable intercepto las cuales se definen por su definicion. Luego se limpia el lcd y se imprime la pendiente y luego el intercepto.

```bash
    double pendiente = (y2 - y1) / (x2 - x1);

    double interceptoY = y1 - (pendiente * x1);

    lcd.cls();
    lcd.printf("La pendiente de la recta que pasa por los dos puntos es: %d",int(pendiente));
    wait_us(5000000);

    lcd.cls();
    lcd.printf("El intercepto en el eje y es: %d", int(interceptoY ));
    wait_us(5000000);
```
-Este fragmento de código es parte de un programa que permite calcular el promedio y la desviación estándar de un conjunto de temperaturas ingresadas por el usuario. Cuando el usuario selecciona la opción "2" en el menú principal, el programa entra en esta sección. El usuario debe ingresar la cantidad de temperaturas (N) que desea analizar. Se crea un vector temperaturas de tamaño N para almacenar las temperaturas ingresadas por el usuario.  Se calcula el promedio de las temperaturas ingresadas sumando todas las temperaturas y dividiendo el resultado por N. Los resultados del promedio y la desviación estándar se muestran en la pantalla LCD para que el usuario los vea.

Se limpia el lcd en cada interacion y se pausa el programa las veces necesarias con la funcion wait_us().
```bash
else if (num1 == 2) {
    int N;
    lcd.cls();
    lcd.printf( "Ingrese la cantidad de temperaturas (N): ");
    wait_us(5000000);
    N = stoi(numeroReal());

    vector<double> temperaturas(N);

    for (int i = 0; i < N; i++) {
      lcd.cls();
      lcd.printf("Ingrese la temperatura %d :",i + 1);
      wait_us(5000000);
      temperaturas[i] = stod(numeroReal());
    }

    double suma = 0;
    for (int i = 0; i < N; i++) {
      suma += temperaturas[i];
    }
    double promedio = suma / N;

    double sumaCuadrados = 0;
    for (int i = 0; i < N; i++) {
      sumaCuadrados += pow(temperaturas[i] - promedio, 2);
    }
    double desviacionEstandar = sqrt(sumaCuadrados / N);
    
    lcd.cls();
    lcd.printf( "El promedio de las temperaturas es: %d", int(promedio));
    lcd.printf("La desviación estándar de las temperaturas es: %d", int(desviacionEstandar));
    wait_us(5000000);

```
-Se declaran tres variables de tipo double: r, g y b, que se utilizarán para almacenar los valores de intensidad deseados para los LEDs, Se limpia la pantalla LCD, Se solicita al usuario que ingrese el valor de intensidad deseado para el LED rojo, Se lee la entrada del usuario y se almacena en la variable 'r'. Se repiten los pasos otras 2 veces con los otros leds. Finalmente, se utiliza la función write para establecer la intensidad de cada LED (rojo, verde y azul)

```bash
} else if (num1 == 3) {
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);
    double r, g, b;
    lcd.cls();
    lcd.printf( "ingresar el valor del led Rojo(de 0 a 255):");
    wait_us(5000000);
    r = stod(numeroReal());
    lcd.cls();
    lcd.printf("ingresar el valor del led verde(de 0 a 255):");
    wait_us(5000000);
    g = stod(numeroReal());
    lcd.cls();
    lcd.printf("ingresar el valor del led Rojo(de 0 a 255):");
    wait_us(5000000);
    b = stod(numeroReal());


    ledR.write(r/255);
    ledG.write(g/255);
    ledB.write(b/255);
```
