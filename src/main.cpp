#include <Arduino.h>
#define candle1 D6
#define candle2 D7
#define delayt 300
#define randMax 30
#define randGo 4
#define maxChange 30
#define volmax 1024
#define volmin 300

int volcandle1 = 1024;
int volcandle2 = 1024;
boolean candle1Forward=false;
boolean candle2Forward=false;




void setup() {
  volcandle1=random(volmax);
  volcandle2=random(volmax);
}

void loop() {
  delay(delayt);
  if(random(randMax)<=randGo)
    candle1Forward=!candle1Forward;
  if(random(randMax)<=randGo)
    candle2Forward=!candle2Forward;
  if(candle1Forward)
   volcandle1=volcandle1+random(maxChange);
  else
    volcandle1=volcandle1-random(maxChange);
  if(candle2Forward)
   volcandle2=volcandle2+random(maxChange);
  else
    volcandle2=volcandle2-random(maxChange);
  if(volcandle1>volmax){
    volcandle1=volmax;
    candle1Forward=false;
  }
  if(volcandle2>volmax){
    volcandle2=volmax;
    candle2Forward=false;
  }
   if(volcandle1<volmin){
    volcandle1=volmin;
    candle1Forward=true;
  }
  if(volcandle2<volmin){
    volcandle2=volmin;
    candle2Forward=true;
  }
  analogWrite(candle1,volcandle1);
  analogWrite(candle2,volcandle2);
  // put your main code here, to run repeatedly:
}