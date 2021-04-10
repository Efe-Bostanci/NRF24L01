#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int veri[1];
RF24 radio(9, 10);
const uint64_t eslesme = 0xE8E8F0F0E1LL;
int joystick;    
void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(eslesme);
}

void loop() 
{
  joystick = analogRead(0);

  veri[0] = joystick / 6;
  radio.write(veri , 1);
  Serial.println(veri[0]);
  delay(5);

}
