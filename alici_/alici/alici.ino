#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "Servo.h"

Servo motor;
int veri[1];
RF24 radio(9, 10);
const uint64_t eslesme = 0xE8E8F0F0E1LL;
void setup()
{
  motor.attach(6);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, eslesme);
  radio.startListening();
}

void loop()
{
  if (radio.available())
  {
    bool done = false;
    while (!done)
    {
      done = radio.read(veri, 1);
      Serial.println(veri[0]);
      delay(10);
      motor.write(veri[0]);
    }
  }
  else 
  {
    Serial.println("Sinyal Bulunamadı...");
  }
}
