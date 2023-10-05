#include "mbed.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
#include <TextLCD.h>
#include <Keypad.h>


//SOLO FALTA PROBAR
TextLCD lcd(D2,D3,D4,D5,D6,D7,TextLCD::LCD16x2);

const int numRows = 4;
const int numCols = 4;

char keyMap[numRows][numCols] = {{'1', '2', '3', 'A'},
                                 {'4', '5', '6', 'B'},
                                 {'7', '8', '9', 'C'},
                                 {'*', '0', '.', 'D'}};

DigitalOut rowPins[numRows] = {DigitalOut(D2), DigitalOut(D3), DigitalOut(D4),
                               DigitalOut(D5)};
DigitalIn colPins[numCols] = {DigitalIn(D6), DigitalIn(D7), DigitalIn(D8),
                              DigitalIn(D9)};

int leerOpcion() {
  int numero = -1;
  while (numero < 0 || numero > 3) {
    for (int i = 0; i < numRows; i++) {
      rowPins[i] = 0;

      for (int j = 0; j < numCols; j++) {
        if (!colPins[j]) {
          char keyPressed = keyMap[i][j];

          if (keyPressed >= '0' && keyPressed <= '3') {
            numero = keyPressed - '0';
          } else if (keyPressed == '*') {
            break;
          }

          ThisThread::sleep_for(500ms);
        }
      }

      if (numero >= 0 && numero <= 3) {
        break;
      }

      rowPins[i] = 1;
    }
  }
  return numero;
}

string numeroReal() {
  string x;
  char keyPressed;
  while (keyPressed != '*') {
    for (int i = 0; i < numRows; i++) {
      rowPins[i] = 0;

      for (int j = 0; j < numCols; j++) {
        if (!colPins[j]) {
          keyPressed = keyMap[i][j];
          ThisThread::sleep_for(500ms);
          if (keyPressed == '*') {
            break;
          } else {
            x = x + keyPressed;
            cout << x << endl;
          }
        }
      }

      rowPins[i] = 1;
    }
  }
  return x;
}

int main() {
  double x1;
  double y1;
  double x2;
  double y2;
  int num1;
  lcd.cls();
  lcd.printf("Ingresa 1 para intercepto con el eje Y y"
          "recta entre 2 puntos, 2 para promedio o 3 "
          " para generar colores en led. \n");
    wait_us(5000000);

  num1 = leerOpcion();

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

    double pendiente = (y2 - y1) / (x2 - x1);

    double interceptoY = y1 - (pendiente * x1);

    lcd.cls();
    lcd.printf("La pendiente de la recta es: %d",int(pendiente));
    wait_us(5000000);

    lcd.cls();
    lcd.printf("El intercepto en Y es: %d", int(interceptoY ));
    wait_us(5000000);

  } else if (num1 == 2) {
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
    lcd.printf("La desviación estándar es: %d", int(desviacionEstandar));
    wait_us(5000000);

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
  }
}
