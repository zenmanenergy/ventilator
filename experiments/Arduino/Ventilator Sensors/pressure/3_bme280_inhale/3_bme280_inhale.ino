

#include <Wire.h> 
#include "SSD1306Wire.h"
#include <Adafruit_BME280.h>

 
#define SDA 4
#define SCL 5

#define SDA_2 15
#define SCL_2 13

#define SDA_3 26
#define SCL_3 25
SSD1306Wire  display(0x3c, SCL, SDA);

unsigned long oldTime;
TwoWire Wire2 = TwoWire(2);
TwoWire Wire3 = TwoWire(3);
Adafruit_BME280 bme2;
Adafruit_BME280 bme3;

float ambientPressure, offset2, offset3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("bmp180 read value");
  Wire.begin(SDA, SCL,100000);
  Wire2.begin(SDA_2, SCL_2, 100000);
  Wire3.begin(SDA_3, SCL_3, 100000);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  display.clear();
  display.drawString(32, 14, "BMe180");
  display.drawString(32, 24, " Read value");
  display.display();
  delay(500);
  Serial.println("beginning");
  
  if (!bme2.begin(0x76, &Wire2)) {
    
  Serial.println("cannot find -1");
    display.clear();
    display.drawString(0, 24, "cannot find bme180-2");
    display.display();
    while (1) {}
  }
  Serial.println("found 1");
  if (!bme3.begin(0x76, &Wire3)) {
  Serial.println("cannot find -3");
    display.clear();
  display.drawString(0, 24, "cannot find bme180-3");
    display.display();
  while (1) {}
  }
  Serial.println("found 2");
  
  ambientPressure=bme2.readPressure();
  offset2=0;
  offset3 = ambientPressure-bme3.readPressure();
}

void loop() {
  
  detectPressure();
  delay(100);
}

void detectPressure(){
//  Serial.print("Temperature = ");
//  Serial.print(bme2.readTemperature());
//  Serial.println(" *C");
//  
  Serial.print("P2 = ");
  Serial.print(bme2.readPressure() + offset2);
  Serial.print("|");
  Serial.print(ambientPressure-(bme2.readPressure()+ offset2)); 
  Serial.print("    P3 = ");
  Serial.print(bme3.readPressure()+ offset3);
  Serial.print("|");
  Serial.print(ambientPressure-(bme3.readPressure()+ offset3));
  Serial.print("    diff:");
  Serial.print((bme2.readPressure()+ offset2)-(bme3.readPressure()+ offset3));
  Serial.print(" Pa");

  Serial.print("    ");
  display.clear();
  //display.drawStringMaxWidth(32, 0, 80,String(bme2.readTemperature()) + "C");
  display.drawStringMaxWidth(32, 10, 80,String(bme2.readPressure()) + " Pa");
  display.drawStringMaxWidth(32, 10, 80,String(bme3.readPressure()) + " Pa");
  if (ambientPressure-bme2.readPressure() > 100){
    display.drawStringMaxWidth(32, 20, 80,"inhale");
  Serial.println(" inhale!");
  } else if (ambientPressure-bme2.readPressure() < -100){
    display.drawStringMaxWidth(32, 20, 80,"exhale");
  Serial.println(" exhale!");
  } else{
    display.drawStringMaxWidth(32, 20, 80,"not breathing");
  Serial.println(" not breathing!");
  }
  display.display();
}
