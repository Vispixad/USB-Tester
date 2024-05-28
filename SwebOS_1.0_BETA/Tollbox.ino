void drawRectTollbox() {
  tft.setRotation(2);
  tft.fillRoundRect(158, 0, 52, 320, 4, tft.color565(10, 32, 64));
  tft.drawRoundRect(158, 0, 52, 320, 4, tft.color565(30, 93, 186));
  tft.fillRoundRect(102, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(46, 0, 52, 320, 4, tft.color565(8, 8, 8));
}
void drawTextTollbox() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  // Установка цвета текста
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(2, 91, 232);

  tft.setCursor(115, 19);
  tft.setTextColor(textColor1);
  tft.print("Toolbox");

  tft.setCursor(8, 50);
  tft.setTextColor(textColor1);
  tft.print("Cable resistance");

  tft.setCursor(8, 70);
  tft.setTextColor(textColor2);
  tft.print("Voltage based resist");

  tft.setCursor(8, 106);
  tft.setTextColor(textColor1);
  tft.print("USB E-Marker");

  tft.setCursor(8, 126);
  tft.setTextColor(textColor2);
  tft.print("Reading cable chip");

  tft.setCursor(8, 162);
  tft.setTextColor(textColor1);
  tft.print("Cable Line Integrity");

  tft.setCursor(8, 184);
  tft.setTextColor(textColor2);
  tft.print("In-depth inspection of cable lines");

    tft.setCursor(115, 215);
  tft.setTextColor(textColor1);
  tft.print("HID Devices");
  tft.setRotation(0);
}
void drawChoiceToll() {
  static unsigned long lastButtonUpTollbox = 0;
  static const unsigned long singleButtonClickTollbox = 100;
  unsigned long currentMillises = millis();
  if (currentMillises - lastButtonUpTollbox >= singleButtonClickTollbox) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      if (!tolldown) {
        lastButtonUpTollbox = currentMillises;
        tft.fillScreen(TFT_BLACK);
        drawMenu5();
        menudown = false;
        stopedtoll = true;
        tolldown = true;
        tollup = true;
      }
    }
  }
  static unsigned long lastButtonUpTime = 0;
  static const unsigned long singleButtonClickDelay = 120;
  unsigned long currentMillis = millis();
  if (currentMillis - lastButtonUpTime >= singleButtonClickDelay) {
    if (digitalRead(BUTTON_UP) == LOW) {
      if (!tollup) {
        lastButtonUpTime = currentMillis;
        /*stopedresist = true;*/
        currentToll++;
        if (currentToll > 3) {
          currentToll = 1;
        }
        changeTollColor(currentToll);
      }
    }
  }
  if (digitalRead(BUTTON_AVER) == LOW) {
    if (!stopedtoll) {
      // Проверяем, какой прямоугольник выбран
      switch (currentToll) {
        case 1:
          tft.fillScreen(TFT_BLACK);
          drawTriangleRes(26, 10, 0);
          drawTriangleResT(26, 10, 90);
          drawRectResist();
          drawTextResist();
          tolldown = true;
          stopedresist = false;
          break;
        case 2:
          tft.fillScreen(TFT_BLACK);

          break;
        case 3:
          tft.fillScreen(TFT_BLACK);
          drawRectCable();
          drawTextCable();
          stopedcable = false;
          break;
      }
    } else {
    }
  }
}
void changeTollColor(int rectangleToll) {
  selectedToll = rectangleToll;

  uint16_t selectedFillColor = tft.color565(10, 32, 64);
  uint16_t selectedBorderColor = tft.color565(19, 89, 191);
  uint16_t unselectedFillColor = tft.color565(8, 8, 8);
  uint16_t unselectedBorderColor = tft.color565(8, 8, 8);

  for (int i = 1; i <= 3; i++) {
    uint16_t fillColor = (i == rectangleToll) ? selectedFillColor : unselectedFillColor;
    uint16_t borderColor = (i == rectangleToll) ? selectedBorderColor : unselectedBorderColor;
    drawTollbox(i, fillColor, borderColor);
  }
}

void drawTollbox(int rectangleToll, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX = 30 + (rectangleToll - 1) * 56;
  int16_t rectY = 0;
  int16_t rectWidth = 52;
  int16_t rectHeight = 320;
  int16_t cornerRadius = 4;

  if (rectangleToll < 1 || rectangleToll > 3)
    return;

  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);

  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  // Установка цвета текста
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(2, 91, 232);

  tft.setCursor(8, 50);
  tft.setTextColor(textColor1);
  tft.print("Cable resistance");

  tft.setCursor(8, 70);
  tft.setTextColor(textColor2);
  tft.print("Voltage based resist");

  tft.setCursor(8, 106);
  tft.setTextColor(textColor1);
  tft.print("USB E-Marker");

  tft.setCursor(8, 126);
  tft.setTextColor(textColor2);
  tft.print("Reading cable chip");

  tft.setCursor(8, 162);
  tft.setTextColor(textColor1);
  tft.print("Cable Line Integrity");

  tft.setCursor(8, 184);
  tft.setTextColor(textColor2);
  tft.print("In-depth inspection of cable lines");
  tft.setRotation(0);
}
