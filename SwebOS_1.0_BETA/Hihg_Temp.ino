bool isRedRectangleDrawn = false;
bool isBlueRectangleDrawn = false;
unsigned long lastButtonPressTime = 0;
void Temp() {
  float temp = temperatureRead();
  if (digitalRead(BUTTON_AVER) == LOW && isRedRectangleDrawn) {
    tft.fillScreen(TFT_BLACK);
    isRedRectangleDrawn = false;
    isBlueRectangleDrawn = false;
    lastButtonPressTime = millis();
  }
  if (temp >= 40 && temp <= 100 && !isRedRectangleDrawn && (millis() - lastButtonPressTime) > 5000) {
    TempRect();
    isRedRectangleDrawn = true;
    for (int i = 5; i > 0; i--) {
      const unsigned long interval = 1000;
      static unsigned long previousMillis = 0;
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        tft.setRotation(3);
        tft.setFreeFont(&PTSans_Regular9pt7b);
        tft.setTextSize(1);
        tft.setTextColor(tft.color565(219, 2, 2));
        tft.setCursor(120, 174);
        tft.print("Agree(");
        tft.print(i);
        tft.print(")");
      }
      tft.fillRect(167, 160, 15, 20, tft.color565(102, 24, 24));
    }
    tft.setRotation(2);
    tft.fillSmoothRoundRect(55, 88, 30, 130, 7, tft.color565(232, 9, 9), TFT_BLACK);
    tft.setRotation(3);
    tft.setFreeFont(&PTSans_Regular9pt7b);
    tft.setTextSize(1);
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.setCursor(128, 174);
    tft.print("Agree");
    isBlueRectangleDrawn = true;
  } else if ((temp < 25 || temp > 100) && isRedRectangleDrawn) {
    tft.fillScreen(TFT_BLACK);
    isRedRectangleDrawn = false;
    isBlueRectangleDrawn = false;
  }
}
void TempRect() {
  tft.setRotation(2);
  tft.fillSmoothRoundRect(88, 88, 107, 130, 7, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillSmoothRoundRect(88, 88, 107, 130, 7, tft.color565(23, 23, 23), TFT_BLACK);
  tft.fillSmoothRoundRect(55, 88, 30, 130, 7, tft.color565(82, 24, 24), TFT_BLACK);
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular10pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  tft.setTextColor(textColor1);
  tft.drawString("High Temp", 105, 53);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.drawString("Your device is", 95, 76);
  tft.drawString("hot, we advise", 95, 94);
  tft.drawString("you to cool it", 95, 112);
  tft.drawString("down", 95, 130);
}
