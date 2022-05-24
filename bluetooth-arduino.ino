/* ******************************************

Autor: Alexander Sandoval. 1701727.
Descripcion: programa para activar/desactivar
3 salidas de un arduino mediante bluetooth.
'1' activa la salida 1.
'2' activa la salida 2.
'3' activa la salida 3.
'4' desactiva todas las salidas.

****************************************** */

#include <SoftwareSerial.h>

SoftwareSerial ModuloBluetooth(10, 11); // Conectado a los pines 10 y 11

int LIGHT_1 = 2; // Salida 1 al pin digital 2
int LIGHT_2 = 4; // Salida 2 al pin digital 4
int LIGHT_3 = 7; // Salida 3 al pin digital 7

void setup() {
  // Inicializacion del modulo bluetooth
  ModuloBluetooth.begin(38400);

  // Configuracion de los pines de salida
  pinMode(LIGHT_1, OUTPUT); // Configura pin como salida
  pinMode(LIGHT_2, OUTPUT); // Configura pin como salida
  pinMode(LIGHT_3, OUTPUT); // Configura pin como salida
}

void loop() {
  if (ModuloBluetooth.available()) { // Consulta disponibilidad del modulo bluetooth
    char data = ModuloBluetooth.read(); // Lee el dato recibido

    switch (data) {
      case '1': // Si el dato es 1
        digitalWrite(LIGHT_1, !digitalRead(LIGHT_1)); // Se cambia el estado de la salida 1
        break;
      case '2': // Si el dato es 2
        digitalWrite(LIGHT_2, !digitalRead(LIGHT_2)); // Se cambia el estado de la salida 2
        break;
      case '3': // Si el dato es 3
        digitalWrite(LIGHT_3, !digitalRead(LIGHT_3)); // Se cambia el estado de la salida 3
        break;
      case '4': // Si el dato es 4
        digitalWrite(LIGHT_1, LOW); // Se desactiva la salida 1
        digitalWrite(LIGHT_2, LOW); // Se desactiva la salida 2
        digitalWrite(LIGHT_3, LOW); // Se desactiva la salida 3
        break;
    }
  }
}
