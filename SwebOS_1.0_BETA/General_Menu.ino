void drawRectGenM() {
  tft.setRotation(2);
  tft.fillRoundRect(-23, -10, 263, 240, 14, tft.color565(8, 8, 8));
  tft.fillRoundRect(-13, 238, 67, 90, 8, tft.color565(8, 8, 8));
  tft.fillSmoothRoundRect(212, 240, 28, 70, 14, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillSmoothCircle(226, 290, 9, tft.color565(0, 214, 296), TFT_BLACK);
  tft.fillSmoothCircle(226, 254, 9, tft.color565(145, 58, 58), TFT_BLACK);
  tft.fillSmoothRoundRect(219, -10, 21, 240, 4, tft.color565(230, 207, 0), TFT_BLACK);
  tft.fillSmoothRoundRect(30, 238, 25, 90, 4, tft.color565(92, 28, 37), TFT_BLACK);
  tft.fillSmoothRoundRect(139, -10, 21, 240, 4, tft.color565(0, 173, 20), TFT_BLACK);
  tft.fillSmoothRoundRect(54, -10, 21, 240, 4, tft.color565(128, 0, 227), TFT_BLACK);
}
void drawTextGenM() {
  tft.setRotation(3);

  /*tft.setFreeFont(&PTSans_Bold9pt7b);*/
  tft.loadFont("PTSans-Bold18", LittleFS);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(230, 207, 0));
  tft.drawString("VBUS", 6, 3);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 173, 20));
  tft.drawString("IBUS", 6, 84);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(128, 0, 227));
  tft.drawString("PBUS", 6, 169);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(92, 28, 37));
  tft.drawString("TEMP", 244, 190);
  tft.unloadFont();
  tft.setRotation(0);
}
void drawVoltGenM() {
  static unsigned long lastdrawVoltGenM = 0;
  static const unsigned long singledrawVoltGenM = 200;
  unsigned long currentMillisGenM = millis();
  static bool genmvolt = false;  // Инициализация переменной genmvolt

  if (currentMillisGenM - lastdrawVoltGenM >= singledrawVoltGenM) {
    if (digitalRead(BUTTON_AVER) == LOW) {
      lastdrawVoltGenM = currentMillisGenM;
      if (genmvolt) {
        genmvolt = false;
        tft.setRotation(2);
        tft.fillSmoothCircle(226, 290, 9, tft.color565(0, 219, 88), TFT_BLACK);
        tft.fillSmoothCircle(226, 254, 9, tft.color565(133, 0, 31), TFT_BLACK);
      } else {
        genmvolt = true;
        tft.setRotation(2);
        tft.fillSmoothCircle(226, 290, 9, tft.color565(0, 122, 29), TFT_BLACK);
        tft.fillSmoothCircle(226, 254, 9, tft.color565(255, 0, 60), TFT_BLACK);
      }
    }
  }
  if (!genmvolt) {
    /*// Читаем ток с обоих каналов
      float current_lipo = ina3221.getCurrent_mA(LIPO_BATTERY_CHANNEL);
      float current_solar = ina3221.getCurrent_mA(SOLAR_CELL_CHANNEL);

      // Определение канала с максимальным током
      int max_channel;
      if (current_lipo > current_solar) {
      max_channel = LIPO_BATTERY_CHANNEL;
      } else {
      max_channel = SOLAR_CELL_CHANNEL;
      }*/
    tft.setRotation(3);
    // Получение напряжения батареи
    float voltage = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);
    int volt = (voltage >= 10.0) ? 4 : 5;
    voltageSprite.fillSprite(tft.color565(8, 8, 8));
    voltageSprite.setTextColor(tft.color565(255, 255, 255), TFT_BLACK);
    voltageSprite.loadFont("PTSans-Bold53", LittleFS);
    /*voltageSprite.setFreeFont(&PTSans_Bold26pt7b);*/
    voltageSprite.drawString(String(voltage, volt), 3, 0);
    int voltageWidth = voltageSprite.textWidth(String(voltage, volt));
    voltageSprite.setTextColor(tft.color565(255, 255, 255), TFT_BLACK);
    voltageSprite.loadFont("PTSans-Bold22", LittleFS);
    /*voltageSprite.setFreeFont(&PTSans_Bold13pt7b);*/
    voltageSprite.drawString("V", voltageWidth + 20, 19);
    voltageSprite.pushSprite(0, 34);
    tft.unloadFont();

    // Получение тока
    float current = (ina3221.getShuntVoltage_mV(LIPO_BATTERY_CHANNEL) / 1000);
    int curr = (current >= 10.0) ? 4 : 5;
    currentSprite.fillSprite(tft.color565(8, 8, 8));
    currentSprite.setTextColor(tft.color565(255, 255, 255), TFT_BLACK);
    currentSprite.loadFont("PTSans-Bold53", LittleFS);
    /*currentSprite.setFreeFont(&PTSans_Bold26pt7b);*/
    currentSprite.drawString(String(current, curr), 3, 0);
    int currentWidth = currentSprite.textWidth(String(current, curr));
    currentSprite.setTextColor(tft.color565(255, 255, 255), TFT_BLACK);
    currentSprite.loadFont("PTSans-Bold22", LittleFS);
    /*currentSprite.setFreeFont(&PTSans_Bold13pt7b);*/
    currentSprite.drawString("A", currentWidth + 20, 19);
    currentSprite.pushSprite(0, 115);
    tft.unloadFont();

    // Получение мощности (ватт)
    float power = voltage * current;
    int pow = (power >= 10.0) ? 4 : 5;
    wattSprite.fillSprite(tft.color565(8, 8, 8));
    wattSprite.setTextColor(tft.color565(255, 255, 255), TFT_BLACK);
    wattSprite.loadFont("PTSans-Bold53", LittleFS);
    /*wattSprite.setFreeFont(&PTSans_Bold26pt7b);*/
    wattSprite.drawString(String(power, pow), 3, 0);
    int powerWidth = wattSprite.textWidth(String(power, pow));
    wattSprite.setTextColor(tft.color565(255, 255, 255), TFT_BLACK);
    wattSprite.loadFont("PTSans-Bold22", LittleFS);
    /*wattSprite.setFreeFont(&PTSans_Bold13pt7b);*/
    wattSprite.drawString("W", powerWidth + 16, 19);
    wattSprite.pushSprite(0, 195);
    tft.unloadFont();

    // Получение мощности (ватт)
    tempSprite.fillSprite(tft.color565(8, 8, 8));
    tempSprite.setTextColor(TFT_WHITE);
    tempSprite.loadFont("PTSans-Bold18", LittleFS);
    /*tempSprite.setFreeFont(&PTSans_Bold9pt7b);*/
    tempSprite.drawString(String(temperatureRead(), 1) + " C", 3, 0);
    tempSprite.pushSprite(244, 218);
    tft.unloadFont();
    delay(80);
  }
}
