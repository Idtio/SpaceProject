// C++ code

//

#include <Adafruit_NeoPixel.h>

#define PIN 13

#include "Adafruit_LEDBackpack.h"

#define F 349.23

Adafruit_7segment led_display1 = Adafruit_7segment();

Adafruit_7segment led_display2 = Adafruit_7segment();

int time;

int c=0;

int x=0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800);


void setup()

{

pinMode(12,OUTPUT);

led_display1.begin(112);

time=2359;

strip.begin();

strip.show();

}


void loop()

{

digitalWrite(12,HIGH);

  while(time>=0){

    if(time== time-time%100){

      time= time-41;

   }else if(time==1){

    led_display1.println(time);

      led_display1.writeDisplay();

      delay(10);

      time--;

     tone(11,F,1000);

    }else{

     led_display1.println(time);

      led_display1.writeDisplay();

      delay(10);

      time--;

     rainbowCycle(1);


    }

   }


}

void rainbowCycle(uint8_t wait) {

  uint16_t i, j;


  for(j=0; j<50; j++) {

    for(i=0; i< strip.numPixels(); i++) {

      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));

    }

    strip.show();

    delay(wait);

  }

}






uint32_t Wheel(byte WheelPos) {

  WheelPos = 255 - WheelPos;

  if(WheelPos < 85) {

    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);

  } else if(WheelPos < 170) {

    WheelPos -= 85;

    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);

  } else {

    WheelPos -= 170;

    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);

  }

}