#include "Adafruit_VL53L0X.h"
#include <U8g2lib.h>
#include <Wire.h>
#include <ButtonDebounce.h>

#define time_delay 2000
#define XSHUT 14
#define BTN_2 2
#define BTN_3 13
#define BTN_4 12

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

Adafruit_VL53L0X lox = Adafruit_VL53L0X();


  ButtonDebounce buttonMeasure(BTN_2, 250);
  ButtonDebounce buttonSend(BTN_3, 250);
  ButtonDebounce buttonCalibrate(BTN_4, 250);
 
 
  void setup() {
    Serial.begin(115200);
    
    buttonMeasure.setCallback([](const int state) {
      Serial.println("onButtonMeasure: " + String(state));
      if (state == 0){
         measure();
      }
    });

    buttonSend.setCallback([](const int state) {
      Serial.println("onButtonSend: " + String(state));
    });
    
    buttonCalibrate.setCallback([](const int state) {
      Serial.println("buttonCalibrate: " + String(state));
      goToSleep();
    });
    
    pinMode(XSHUT, OUTPUT);
    digitalWrite(XSHUT, HIGH);
    
    while (! Serial) {
      delay(1);
    }
    Serial.println("VL53L0X sensor test");
    if (!lox.begin()) {
      Serial.println(F("Failed to boot VL53L0X"));
      while (1);
    }
    lox.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_ACCURACY);
    //lox.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_LONG_RANGE);
    //lox.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_SPEED);
    //lox.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_DEFAULT);

   u8g2.begin();
   showWaitMsg();
   
   VL53L0X_RangingMeasurementData_t measure;
   lox.rangingTest(&measure, false);
   Serial.println(measure.RangeMilliMeter);
 
    showReadyMsg();
  }

  void loop() { 
    buttonMeasure.update();
    buttonSend.update();
    buttonCalibrate.update();
  }

  void goToSleep(){
    showSleepMsg();
    delay(3000);
    Serial.println("Sleep... ZZZZZZZ");
    digitalWrite(XSHUT, LOW);
    u8g2.setPowerSave(true);
    ESP.deepSleep(0);
  }
 
