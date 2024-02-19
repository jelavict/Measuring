
void setTextFont(){
    u8g2.setFont(u8g2_font_spleen16x32_mf );
    u8g2.setFontRefHeightExtendedText();
    u8g2.setDrawColor(1);
    u8g2.setFontPosTop();
    u8g2.setFontDirection(0);
    u8g2.setCursor(0, 15);
}

void showSleepMsg(){
   u8g2.clearBuffer();
   setTextFont();
   u8g2.print("ZZZZZ...");
   u8g2.sendBuffer();
}

void showReadyMsg(){
   u8g2.clearBuffer();
   setTextFont();
   u8g2.print("Ready...");
   u8g2.sendBuffer();
}

void showWaitMsg(){
   u8g2.clearBuffer();
   setTextFont();
   u8g2.print("Wait...");
   u8g2.sendBuffer();
}

void showMeasure(int mm){
    u8g2.clearBuffer();
    setTextFont();
    Serial.print("Distance (mm): ");
    Serial.println(mm);
    float cm = mm / 10.0; // Convert millimeters to centimeters
    int cm_int = cm * 10; //
    Serial.print("Distance (cm): ");
    Serial.print(cm_int / 10);
    Serial.print(".");
    Serial.println(cm_int % 10);

    u8g2.print(cm_int / 10);
    u8g2.print(".");
    u8g2.print(cm_int % 10);
    u8g2.print(" cm");
    u8g2.sendBuffer();
  
}
