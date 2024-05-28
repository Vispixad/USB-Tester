void drawRectList() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 0, 180, 320, 4, tft.color565(8, 8, 8)); //структура (вверх - вниз), (вправо - влево), (ширина), (длина), (радиус закруглений))
  tft.fillRoundRect(185, 0, 29, 320, 4, tft.color565(8, 8, 8));
  /*tft.fillRoundRect(60, 70, 130, 170, 4, tft.color565(10, 10, 10));
  tft.drawRoundRect(60, 70, 130, 170, 4, tft.color565(19, 19, 19));*/
}
void drawTextList() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor3 = tft.color565(255, 239, 0);
  tft.setTextColor(textColor1);
  tft.drawString("Statistics", 110, 5);
  tft.setTextColor(textColor3);
  tft.drawString("No", 10, 34);
  tft.drawString("CAP", 78, 34);
  tft.drawString("NGR", 148, 34);
  tft.drawString("Time", 245, 34);
}
void NGRStat() {
  static unsigned long lastButtonList = 0;
  static const unsigned long singleButtonList = 100;
  unsigned long currentList = millis();
  if (currentList - lastButtonList >= singleButtonList) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      /*if (!tolldown) {*/
      lastButtonList = currentList;
      /*stopedstat = true;*/
      tft.fillScreen(TFT_BLACK);
      drawRectStat();
      drawTextStat();
      listup = true;
      statdown = false;
      statup = false;
      menuappr = true;
      averbuttonapp = true;
      timeoverapp = true;
      stopedstat = false;
      /*}*/
    }
  }
  if (digitalRead(BUTTON_UP) == LOW) {
    if (!listup) {
      tft.setRotation(2);
      buttonList++;
      if (buttonList > 6) {
        buttonList = 1;
      }
      changeRectList(buttonList);
      drawMultipleCells();
    }
  }
}
void changeRectList(int rectangleList) {
  selectedRectlist = rectangleList;
  // Очистить предыдущий выбранный прямоугольник
  for (int i = 1; i <= 6; i++) {
    uint16_t fillColor = (i == rectangleList) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleList) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectStat(i, fillColor, borderColor);
  }
}
void drawMultipleCells() {
  /*tft.setFont(&PTSans_Regular9pt7b);
    for (int cell = 1; cell <= 10; cell++) {
    Data data;
    int address = cell * EEPROM_SIZE;
    EEPROM.get(address, data);

    // Отображаем информацию для текущей ячейки
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.setRotation(1);

    // Рассчитываем координаты вывода информации для текущей ячейки
    int16_t textX = 10; // X координата
    int16_t textY = 84 + (cell - 1) * 29; // Y координата

    // Выводим номер ячейки
    tft.setCursor(textX, textY);
    if (cell < 10) tft.print("0");
    tft.print(cell);

    // Выводим данные для ячейки
    tft.setCursor(70, textY + 29);
    tft.print(data.wattHours, 5);

    tft.setCursor(142, textY + 29);
    tft.print(data.ampHours, 5);

    tft.setCursor(232, textY + 29);
    formatElapsedTime(data.elapsedTime);

    tft.setRotation(0);
    }*/
}
void drawRectStat(int rectangleList, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  switch (rectangleList) {
    case 1:
      rectX = 149; rectY = 4; rectWidth = 26; rectHeight = 312; cornerRadius = 4;
      break;
    case 2:
      rectX = 120; rectY = 4; rectWidth = 26; rectHeight = 312; cornerRadius = 4;
      break;
    case 3:
      rectX = 91; rectY = 4; rectWidth = 26; rectHeight = 312; cornerRadius = 4;
      break;
    case 4:
      rectX = 62; rectY = 4; rectWidth = 26; rectHeight = 312; cornerRadius = 4;
      break;
    case 5:
      rectX = 33; rectY = 4; rectWidth = 26; rectHeight = 312; cornerRadius = 4;
      break;
    case 6:
      rectX = 4; rectY = 4; rectWidth = 26; rectHeight = 312; cornerRadius = 4;
      break;
    default:
      return;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
}
