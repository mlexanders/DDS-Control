#include "SerialController.h"
#include "Command.h"

int dataPin = 53;
int clockPin = 22;
int csPin = 48;

void writeByte(bool byte){
  Serial.println(byte);
};

void chipSelectSwitch(bool byte){
  Serial.println("CS");
  Serial.println(byte);
  Serial.println("CS");
};

SerialController *sc = new SerialController(writeByte, chipSelectSwitch);

void setup() {
    Serial.begin(9600);
    // init pins
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(csPin, OUTPUT);
}

//EXAMPLE
void loop() {
  Command cmd = Command::SETA;
  short body = 0b0100000011111111;
  sc->write(cmd, body);
}
