/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-i2c-communication-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, 5, 4);

#define SDA_1 15
#define SCL_1 13

#define SDA_2 15
#define SCL_2 13

TwoWire I2Ctwo = TwoWire(1);

Adafruit_BME280 bme1;
Adafruit_BME280 bme2;

void setup() {
  Serial.begin(115200);
  Serial.println(F("BME280 test"));
  I2Ctwo.begin(SDA_2, SCL_2, 100000);
  //bool status1 = bme1.begin(0x76, &I2Cone);
  bool status2 = bme2.begin(0x76, &I2Ctwo);  

  
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  display.clear();
  display.drawString(32, 14, "2x BMP180");
  display.drawString(32, 24, " Read value");
  display.display();

  
  delay(500);
  if (!status1) {
    Serial.println("Could not find a valid BME280_1 sensor, check wiring!");
    
    while (1);
  }
  
  if (!status2) {
    Serial.println("Could not find a valid BME280_2 sensor, check wiring!");
    
    while (1);
  }
  
  Serial.println("done");
}

void loop() { 
  // Read from bme1
display.clear();
  display.drawString(32, 14, String(bme1.readPressure()) + " Pa");
  //display.drawString(32, 24, String(bme2.readPressure()) + " Pa");
  display.display();
//  display.clear();
//  display.drawStringMaxWidth(32, 0, 80,"Static Pressure:");
//  display.drawStringMaxWidth(32, 10, 80,String(bme1.readPressure()) + " Pa");
//
//   display.drawStringMaxWidth(32, 30, 80,"Stagnation Pressure:");
//  display.drawStringMaxWidth(32, 40, 80,String(bme2.readPressure()) + " Pa");
//  display.display();
  
//  Serial.print("Temperature from BME1= ");
//  Serial.print(bme1.readTemperature());
//  Serial.println(" *C");
//
//  Serial.print("Humidity from BME1 = ");
//  Serial.print(bme1.readHumidity());
//  Serial.println(" %");
//
  Serial.print("Pressure from BME1 = ");
  Serial.print(bme1.readPressure());
  Serial.println(" Pa");
//
//  Serial.println("--------------------");
//
//  // Read from bme2
//  Serial.print("Temperature from BME2 = ");
//  Serial.print(bme2.readTemperature());
//  Serial.println(" *C");
//
//  Serial.print("Humidity from BME2 = ");
//  Serial.print(bme2.readHumidity());
//  Serial.println(" %");
//
//  Serial.print("Pressure from BME2 = ");
//  Serial.print(bme2.readPressure() / 100.0F);
//  Serial.println(" hPa");
//
//  Serial.println("--------------------");
  
  delay(1000);
}
