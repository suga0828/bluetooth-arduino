#include <SoftwareSerial.h>

SoftwareSerial ModuloBluetooth(10, 11);

int LIGHT_1 = 2;
int LIGHT_2 = 4;
int LIGHT_3 = 7;

void setup() {
  ModuloBluetooth.begin(38400);

  pinMode(LIGHT_1, OUTPUT);
  pinMode(LIGHT_2, OUTPUT);
  pinMode(LIGHT_3, OUTPUT);
}

void loop() {
  if (ModuloBluetooth.available()) {
    char data = ModuloBluetooth.read();

    switch (data) {
      case '1':
        digitalWrite(LIGHT_1, !digitalRead(LIGHT_1));
        break;
      case '2':
        digitalWrite(LIGHT_2, !digitalRead(LIGHT_2));
        break;
      case '3':
        digitalWrite(LIGHT_3, !digitalRead(LIGHT_3));
        break;
      case '4':
        digitalWrite(LIGHT_1, LOW);
        digitalWrite(LIGHT_2, LOW);
        digitalWrite(LIGHT_3, LOW);
        break;
    }
  }
}
