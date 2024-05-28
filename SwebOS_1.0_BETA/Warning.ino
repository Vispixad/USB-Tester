void drawRecWar() {
  tft.setRotation(2);
  tft.fillRoundRect(25, 18, 180, 277, 7, tft.color565(8, 8, 8));
  tft.drawRoundRect(25, 18, 180, 277, 7, tft.color565(23, 23, 23));
  tft.fillRoundRect(36, 52, 26, 59, 4, tft.color565(15, 15, 15));
  tft.drawRoundRect(36, 52, 26, 59, 4, tft.color565(28, 28, 28));
  tft.fillRoundRect(36, 199, 26, 62, 4, tft.color565(15, 15, 15));
  tft.drawRoundRect(36, 199, 26, 62, 4, tft.color565(28, 28, 28));
  tft.fillRoundRect(36, 130, 26, 50, 4, tft.color565(15, 15, 15));
  tft.drawRoundRect(36, 130, 26, 50, 4, tft.color565(28, 28, 28));
}
void drawTextWar() {
  tft.setRotation(3);
  tft.setTextSize(1);
  tft.setFreeFont(&PTSans_Regular9pt7b);

  uint16_t textColor1 = tft.color565(255, 0, 60);
  uint16_t textColor2 = tft.color565(255, 255, 255);
  uint16_t textColor3 = tft.color565(180, 180, 180);

  tft.setTextColor(textColor2);
  tft.drawString("WARNING!", 110, 8);
  tft.setTextColor(textColor1);
  tft.drawString("Fast charging features may result", 27, 42);
  tft.setTextColor(textColor1);
  tft.drawString("in increased voltage, which may", 30, 64);
  tft.setTextColor(textColor1);
  tft.drawString("damage your device being char-", 30, 86);
  tft.setTextColor(textColor1);
  tft.drawString("ged. Please be careful using this", 24, 108);
  tft.setTextColor(textColor1);
  tft.drawString("feature, we are not responsible", 27, 130);
  tft.setTextColor(textColor1);
  tft.drawString("for your actions.", 27, 152);
  tft.setTextColor(textColor3);
  tft.drawString("Ready", 57, 182);
  tft.setTextColor(textColor3);
  tft.drawString("Auto", 137, 182);
  tft.setTextColor(textColor3);
  tft.drawString("Cancel", 205, 182);
  tft.setRotation(0);
}
void ButtonWar() {
  // Переменные для хранения времени удерживания кнопок
  static unsigned long buttonHoldTime1 = 0;
  static unsigned long buttonHoldTimeAver = 0;
  static unsigned long buttonHoldTimeDown = 0;

  // Обработка первой кнопки
  if (digitalRead(BUTTON_UP) == LOW) {
    if (!warup) {
      stopedwar = false;
      unsigned long currentMillis = millis();
      if (currentMillis - buttonHoldTime1 > 150) {
        currentState++;
        if (currentState > 3) currentState = 1;
        updateRectangles(currentState);
        buttonHoldTime1 = currentMillis;
      }
    }
  } else {
    buttonHoldTime1 = 0;
  }
  unsigned long lastButtonDownTime = 0;
  const unsigned long buttonDownDelay = 60;
  if (digitalRead(BUTTON_DOWN) == LOW && millis() - lastButtonDownTime > buttonDownDelay) {
    if (!wardown) {
      lastButtonDownTime = millis();
      tft.fillScreen(TFT_BLACK);
      drawMenu5();
      menudown = false;
    } else {
    }
  }
  if (digitalRead(BUTTON_AVER) == LOW) {
    if (!stopedwar) {
      // Проверяем, какой прямоугольник выбран
      switch (currentState) {
        case 1:
          stopedwar = true;
          tft.fillScreen(TFT_BLACK);
          drawFast();
          drawTextFast();
          QC2down = true;
          stopedQC2 = true;
          QC3down = true;
          stopedQC3 = true;
          menufast = false;
          warup = true;
          menuapp = true;
          menuappr = true;
          break;
        case 2:
          stopedwar = true;
          tft.fillScreen(TFT_BLACK);
          drawRectQC();
          drawTextQC();
          buttonQC();
          startQC();
          workQC();
          menuapp = true;
          menuappr = true;
          timeoverapp = true;
          warup = true;
          settup = true;
          wardown = true;
          break;
        case 3:
          tft.fillScreen(TFT_BLACK);
          drawMenu5();
          menudown = false;
          break;
      }
    } else {
    }
  }
}
void updateRectangles(int currentState) {
  tft.setRotation(2);
  lastButtonPressTime = millis();

  switch (currentState) {
    case 1:
      // Синие: 6 и 7
      tft.fillRoundRect(36, 52, 26, 59, 4, tft.color565(10, 32, 64));
      tft.drawRoundRect(36, 52, 26, 59, 4, tft.color565(30, 93, 186));
      // Серые: 10 и 11, 8 и 9
      tft.fillRoundRect(36, 130, 26, 50, 4, tft.color565(11, 11, 11));
      tft.drawRoundRect(36, 130, 26, 50, 4, tft.color565(20, 20, 20));
      tft.fillRoundRect(36, 199, 26, 62, 4, tft.color565(11, 11, 11));
      tft.drawRoundRect(36, 199, 26, 62, 4, tft.color565(20, 20, 20));
      break;
    case 2:
      // Синие: 10 и 11
      tft.fillRoundRect(36, 130, 26, 50, 4, tft.color565(10, 32, 64));
      tft.drawRoundRect(36, 130, 26, 50, 4, tft.color565(30, 93, 186));
      // Серые: 8 и 9, 6 и 7
      tft.fillRoundRect(36, 52, 26, 59, 4, tft.color565(11, 11, 11));
      tft.drawRoundRect(36, 52, 26, 59, 4, tft.color565(20, 20, 20));
      tft.fillRoundRect(36, 199, 26, 62, 4, tft.color565(11, 11, 11));
      tft.drawRoundRect(36, 199, 26, 62, 4, tft.color565(20, 20, 20));
      break;
    case 3:
      // Синие: 8 и 9
      tft.fillRoundRect(36, 199, 26, 62, 4, tft.color565(10, 32, 64));
      tft.drawRoundRect(36, 199, 26, 62, 4, tft.color565(30, 93, 186));
      // Серые: 10 и 11, 6 и 7
      tft.fillRoundRect(36, 130, 26, 50, 4, tft.color565(11, 11, 11));
      tft.drawRoundRect(36, 130, 26, 50, 4, tft.color565(20, 20, 20));
      tft.fillRoundRect(36, 52, 26, 59, 4, tft.color565(11, 11, 11));
      tft.drawRoundRect(36, 52, 26, 59, 4, tft.color565(20, 20, 20));
      break;
  }
  drawTexting();
}
void drawTexting() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(57, 196);
  tft.setTextColor(tft.color565(180, 180, 180));
  tft.print("Ready");

  tft.setCursor(137, 196);
  tft.setTextColor(tft.color565(180, 180, 180));
  tft.print("Auto");

  tft.setCursor(205, 196);
  tft.setTextColor(tft.color565(180, 180, 180));
  tft.print("Cancel");
  tft.setRotation(0);
}
