 
 
 
 void measure(){
        showWaitMsg();
        int numOfMeasures = 20;
        int finalMeasurment = 0;
        for(int i=0; i<numOfMeasures; i++){
            VL53L0X_RangingMeasurementData_t measure;
            lox.rangingTest(&measure, false);
         if (measure.RangeStatus != 4) {
              int mm = measure.RangeMilliMeter-28; // Example value in millimeters (as an integer)
              if (mm > 40){
                 finalMeasurment = finalMeasurment+mm;
                 delay(250);
                 Serial.print("Reading measurement - ");
                 Serial.println(mm);
              }
         }else {
            u8g2.clearBuffer();
            Serial.println("Out of range!");
            u8g2.print("Out of range!");
         }
      }
        showMeasure(finalMeasurment/numOfMeasures);
  }
