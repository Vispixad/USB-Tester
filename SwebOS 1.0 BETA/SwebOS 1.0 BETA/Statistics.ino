void drawRectStat() {
  tft.setRotation(2);
  tft.fillRoundRect(158, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(102, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(46, 0, 52, 320, 4, tft.color565(8, 8, 8));
}
void drawTextStat() {
  tft.setRotation(3);
  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("Statistics", 104, 7);
  tft.drawString("NGR Statistics", 8, 38);
  tft.drawString("Battery CAP", 8, 94);
  tft.drawString("Offline Recording", 8, 148);

  tft.setTextColor(tft.color565(2, 91, 232), tft.color565(0, 43, 112));
  tft.drawString("List of cell data", 8, 59);
  tft.drawString("Battery capacity measurement", 8, 115);
  tft.drawString("View recording of curves offline", 8, 171);
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
  tft.setRotation(0);
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
  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("NGR Statistics", 8, 38);
  tft.drawString("Battery CAP", 8, 94);
  tft.drawString("Offline Recording", 8, 148);

  tft.setTextColor(tft.color565(2, 91, 232), tft.color565(0, 43, 112));
  tft.drawString("List of cell data", 8, 59);
  tft.drawString("Battery capacity measurement", 8, 115);
  tft.drawString("View recording of curves offline", 8, 171);
}
