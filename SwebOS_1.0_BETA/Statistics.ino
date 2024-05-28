void drawRectStat() {
  tft.setRotation(2);
  tft.fillRoundRect(158, 0, 52, 320, 4, tft.color565(10, 32, 64));
  tft.drawRoundRect(158, 0, 52, 320, 4, tft.color565(30, 93, 186));
  tft.fillRoundRect(102, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(46, 0, 52, 320, 4, tft.color565(8, 8, 8));
}
void drawTextStat() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  // Установка цвета текста
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(2, 91, 232);

  tft.setCursor(110, 19);
  tft.setTextColor(textColor1);
  tft.print("Statistics");

  tft.setCursor(8, 50);
  tft.setTextColor(textColor1);
  tft.print("NGR Statistics");

  tft.setCursor(8, 70);
  tft.setTextColor(textColor2);
  tft.print("List of cell data");

  tft.setCursor(8, 106);
  tft.setTextColor(textColor1);
  tft.print("Battery CAP");

  tft.setCursor(8, 125);
  tft.setTextColor(textColor2);
  tft.print("Battery capacity measurement");

  tft.setCursor(8, 162);
  tft.setTextColor(textColor1);
  tft.print("Offline Recording");

  tft.setCursor(8, 184);
  tft.setTextColor(textColor2);
  tft.print("View recording of curves offline");

  tft.setRotation(0);
}
void drawChoiceStat() {
  static unsigned long lastUpStatTwo = 0;
  static const unsigned long singleButtonStatTwo = 50;
  unsigned long currentMillisStatTwo = millis();
  if (currentMillisStatTwo - lastUpStatTwo >= singleButtonStatTwo) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      if (!statdown) {
        lastUpStatTwo = currentMillisStatTwo;
        tft.fillScreen(TFT_BLACK);
        drawMenu5();
        menudown = false;
      }
    }
  }
  static unsigned long lastUpStat = 0;
  static const unsigned long singleButtonStat = 150;
  unsigned long currentMillisStat = millis();
  if (currentMillisStat - lastUpStat >= singleButtonStat) {
    if (digitalRead(BUTTON_UP) == LOW) {
      if (!statup) {
        lastUpStat = currentMillisStat;
        currentStat++;
        if (currentStat > 3) {
          currentStat = 1;
        }
        changeStatColor(currentStat);
      }
    }
  }
  if (digitalRead(BUTTON_AVER) == LOW) {
    if (!stopedstat) {
      // Проверяем, какой прямоугольник выбран
      switch (currentStat) {
        case 1:
          tft.fillScreen(TFT_BLACK);
          drawRectList();
          drawTextList();
          statup = true;
          menuappr = true;
          listup = false;
          statdown = true;
          stopedstat = true;
          break;
        case 2:
          tft.fillScreen(TFT_BLACK);
          drawRectBattery();
          drawTextBattery();
          batup = false;
          statup = true;
          menuappr = true;
          statdown = true;
          stopedstat = true;
          break;
        case 3:
          tft.fillScreen(TFT_BLACK);
          statup = true;
          menuappr = true;
          statdown = true;
          stopedstat = true;
          tft.setRotation(2);
          drawTriangleRec1(103, -5, 180);
          drawTriangleRec2(101, 297, 0);
          drawGraphRec1();
          drawGraphRec2();
          tft.setRotation(3);
          drawTextGraphRec();
          break;
      }
    }
  }
}
void changeStatColor(int rectangleStat) {
  selectedStat = rectangleStat;

  uint16_t selectedFillColor = tft.color565(10, 32, 64);
  uint16_t selectedBorderColor = tft.color565(19, 89, 191);
  uint16_t unselectedFillColor = tft.color565(8, 8, 8);
  uint16_t unselectedBorderColor = tft.color565(8, 8, 8);

  for (int i = 1; i <= 3; i++) {
    uint16_t fillColor = (i == rectangleStat) ? selectedFillColor : unselectedFillColor;
    uint16_t borderColor = (i == rectangleStat) ? selectedBorderColor : unselectedBorderColor;
    drawStat(i, fillColor, borderColor);
  }
}

void drawStat(int rectangleToll, uint16_t fillColor, uint16_t borderColor) {
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
  tft.print("NGR Statistics");

  tft.setCursor(8, 70);
  tft.setTextColor(textColor2);
  tft.print("List of cell data");

  tft.setCursor(8, 106);
  tft.setTextColor(textColor1);
  tft.print("Battery CAP");

  tft.setCursor(8, 125);
  tft.setTextColor(textColor2);
  tft.print("Battery capacity measurement");

  tft.setCursor(8, 162);
  tft.setTextColor(textColor1);
  tft.print("Offline Recording");

  tft.setCursor(8, 184);
  tft.setTextColor(textColor2);
  tft.print("View recording of curves offline");
  tft.setRotation(0);
}
