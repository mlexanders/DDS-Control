#include "DdsBuilder.h"
/* CHANNEL B
9	  PB0 ( SS/PCINT0 )	  Digital pin 53
20	PB1 ( SCK/PCINT1 )	Digital pin 52 
21	PB2 ( MOSI/PCINT2 )	Digital pin 51 
22	PB3 ( MISO/PCINT3 )	Digital pin 50 
23	PB4 ( OC2A/PCINT4 )	Digital pin 10 
24	PB5 ( OC1A/PCINT5 )	Digital pin 11 
25	PB6 ( OC1B/PCINT6 )	Digital pin 12 
26	PB7 ( OC0A/OC1C   )	Digital pin 13 
*/

int dataPin = 51;   //SDI   - 2
int clockPin = 52;  //SCK   - 1
int csPin = 53;     //SCSn  - 0

//int dataPin = 13;   //SDI   - 5
//int clockPin = 10;  //SCK   - 2
//int csPin = 11;     //SCSn  - 3

void _SDI(bool _bit);  //SDI
void _CLK(bool _bit);  //SCK
void _SCS(bool _bit);  //SCSn

Dds *dds = DdsBuilder::useSerialController(&_SDI, &_SCS, &_CLK).getDds();

void setup() {
  //Serial.begin(9600);
  PORTB = 0b00000000;
  // init pins
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(csPin, OUTPUT);
  // DDRB = 0b00101100;
  // dds->init();
  //  dds->setFreq(300);
  //dds->setA(0b11111111111000);
}


void loop() {
  dds->init();
  dds->setFreq(300);
  //delay(1000);
  dds->setA(0.3);
  delay(1000);
  //dds->setA(0.2);
}

void _SDI(bool _bit) {
  setBit(2, _bit);
}

void _SCS(bool _bit) {
  setBit(0, _bit);
}

void _CLK(bool _bit) {
  setBit(1, _bit);
}

//Установка i-го бита в значение val
void setBit(int i, bool val) {
  if (val) {
    PORTB |= (1 << i);
  } else {
    PORTB &= ~(1 << i);
  }
}
