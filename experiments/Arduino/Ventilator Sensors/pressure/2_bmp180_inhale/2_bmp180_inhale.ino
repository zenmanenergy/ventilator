

#include <Wire.h> 
#include "SSD1306Wire.h"
#include <Adafruit_BMP085.h>
 

Adafruit_BMP085 bmp;
  
SSD1306Wire  display(0x3c, 5, 4);

unsigned long oldTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("bmp180 read value");
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  display.clear();
  display.drawString(32, 14, "BMP180");
  display.drawString(32, 24, " Read value");
  display.display();
  delay(500);
  
  
  if (!bmp.begin(3)) {
    display.clear();
  display.drawString(32, 24, "cannot find bmp180");
    display.display();
  while (1) {}
  }
  
  
}

void loop() {
  
  detectPressure();
}

void detectPressure(){
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  display.clear();
  display.drawStringMaxWidth(32, 0, 80,String(bmp.readTemperature()) + "C");
  display.drawStringMaxWidth(32, 10, 80,String(bmp.readPressure()) + " Pa");
  if (bmp.readPressure() < 100000){
    display.drawStringMaxWidth(32, 20, 80,"inhale");
  } else if (bmp.readPressure() > 106000){
    display.drawStringMaxWidth(32, 20, 80,"exhale");
  } else{
    display.drawStringMaxWidth(32, 20, 80,"not breathing");
  }
  display.display();
}
