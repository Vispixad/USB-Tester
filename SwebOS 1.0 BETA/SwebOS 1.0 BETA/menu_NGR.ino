/* // Отрисовка полусфер
  drawHemisphere1(84, 4, 8, tft.color565(238, 255, 0));
  drawHemisphere2(84, 84, 8, tft.color565(0, 166, 255));
  }*/
//---------------------------------------------------------------------------------------
/*void drawHemisphere1(int16_t x, int16_t y, int16_t radius, uint16_t color) {
  int16_t cx = x;
  int16_t cy = y;

  for (int16_t dy = 0; dy <= radius; dy++) {
    int16_t dx = (int16_t)round(sqrt(radius * radius - dy * dy));

    // Отрисовка окружности с учетом заливки
    tft.drawFastHLine(cx - dx, cy + dy, 2 * dx, color);
  }
  }
  //---------------------------------------------------------------------------------------
  void drawHemisphere2(int16_t x, int16_t y, int16_t radius, uint16_t color) {
  int16_t cx = x;
  int16_t cy = y;

  for (int16_t dy = 0; dy <= radius; dy++) {
    int16_t dx = (int16_t)round(sqrt(radius * radius - dy * dy));

    // Отрисовка окружности с учетом заливки
    tft.drawFastHLine(cx - dx, cy + dy, 2 * dx, color);
  }
  }*/
const uint16_t dataMinus [] PROGMEM = {
  0x18a0, 0x4200, 0x4200, 0x4200, 0x4200, 0x4200, 0x4200, 0x2120, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x4200, 0xff60,
  0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xe680, 0x62e0, 0x0841, 0x0841, 0x0841, 0x0841, 0x4200, 0xff60, 0xff60, 0xff60,
  0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xe680, 0x2120, 0x0841, 0x0841, 0x4200, 0xff60, 0xff60, 0x7360, 0x4200, 0x4200,
  0x4200, 0x7360, 0xe680, 0xff60, 0xff60, 0xe680, 0x18a0, 0x0841, 0x4200, 0xff60, 0xff60, 0x4200, 0x0841, 0x0841, 0x0841, 0x0841,
  0x0841, 0x83c0, 0xff60, 0xff60, 0xc5a0, 0x0841, 0x4200, 0xff60, 0xff60, 0x4200, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841,
  0xb520, 0xff60, 0xff60, 0x4200, 0x4200, 0xff60, 0xff60, 0x4200, 0x0841, 0x0841, 0xc5a0, 0xff60, 0x4200, 0x0841, 0x2120, 0xff60,
  0xff60, 0x83c0, 0x4200, 0xff60, 0xff60, 0x4200, 0x3180, 0x4200, 0xd620, 0xff60, 0x7360, 0x4200, 0x18a0, 0xe680, 0xff60, 0xb520,
  0x4200, 0xff60, 0xff60, 0x4200, 0xc5a0, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0x4200, 0xc5a0, 0xff60, 0xc5a0, 0x4200, 0xff60,
  0xff60, 0x4200, 0x9440, 0xc5a0, 0xef00, 0xff60, 0xd620, 0xc5a0, 0x3180, 0xc5a0, 0xff60, 0xc5a0, 0x4200, 0xff60, 0xff60, 0x4200,
  0x0841, 0x0841, 0xc5a0, 0xff60, 0x4200, 0x0841, 0x0841, 0xef00, 0xff60, 0x9440, 0x4200, 0xff60, 0xff60, 0x4200, 0x0841, 0x0841,
  0x62e0, 0x83c0, 0x2120, 0x0841, 0x62e0, 0xff60, 0xff60, 0x5280, 0x4200, 0xff60, 0xff60, 0x4200, 0x0841, 0x0841, 0x0841, 0x0841,
  0x0841, 0x2120, 0xe680, 0xff60, 0xe680, 0x0841, 0x4200, 0xff60, 0xff60, 0x4200, 0x0841, 0x0841, 0x0841, 0x0841, 0x4200, 0xe680,
  0xff60, 0xff60, 0x62e0, 0x0841, 0x4200, 0xff60, 0xff60, 0xd620, 0xc5a0, 0xc5a0, 0xc5a0, 0xef00, 0xff60, 0xff60, 0xff60, 0x83c0,
  0x0841, 0x0841, 0x4200, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xff60, 0xef00, 0x7360, 0x0841, 0x0841, 0x0841,
  0x3180, 0xc5a0, 0xc5a0, 0xc5a0, 0xc5a0, 0xc5a0, 0xc5a0, 0xa4c0, 0x7360, 0x18a0, 0x0841, 0x0841, 0x0841, 0x0841
};
// 'Frame 6 (1)', 14x17px
const uint16_t dataPlus [] PROGMEM = {
  0x0063, 0x00c8, 0x00c8, 0x00c8, 0x00c8, 0x00c8, 0x00c8, 0x0084, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x00c8, 0x02bf,
  0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x027c, 0x012c, 0x0841, 0x0841, 0x0841, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x02bf,
  0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x027c, 0x0084, 0x0841, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x014e, 0x00c8, 0x00c8,
  0x00c8, 0x014e, 0x025c, 0x02bf, 0x02bf, 0x027c, 0x0063, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0841, 0x0841, 0x0841, 0x0841,
  0x0841, 0x0170, 0x02bf, 0x02bf, 0x0218, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841,
  0x01f6, 0x02bf, 0x02bf, 0x00c8, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0084, 0x02bf,
  0x02bf, 0x0170, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x00a6, 0x00c8, 0x00c8, 0x00c8, 0x00c8, 0x00c8, 0x0063, 0x025c, 0x02bf, 0x01f6,
  0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0218, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x00c8, 0x0218, 0x02bf, 0x0218, 0x00c8, 0x02bf,
  0x02bf, 0x00c8, 0x0192, 0x0218, 0x0218, 0x0218, 0x0218, 0x0218, 0x00a6, 0x0218, 0x02bf, 0x0218, 0x00c8, 0x02bf, 0x02bf, 0x00c8,
  0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x0841, 0x029d, 0x02bf, 0x0192, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0841, 0x0841,
  0x0841, 0x0841, 0x0841, 0x0841, 0x012c, 0x02bf, 0x02bf, 0x00ea, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0841, 0x0841, 0x0841, 0x0841,
  0x0841, 0x0084, 0x027c, 0x02bf, 0x025c, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x00c8, 0x0841, 0x0841, 0x0841, 0x0841, 0x00c8, 0x027c,
  0x02bf, 0x02bf, 0x012c, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x023a, 0x0218, 0x0218, 0x0218, 0x029d, 0x02bf, 0x02bf, 0x02bf, 0x0170,
  0x0841, 0x0841, 0x00c8, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x02bf, 0x029d, 0x014e, 0x0841, 0x0841, 0x0841,
  0x00a6, 0x0218, 0x0218, 0x0218, 0x0218, 0x0218, 0x0218, 0x01d4, 0x014e, 0x0063, 0x0841, 0x0841, 0x0841, 0x0841
};
void rotatePointNGR(int &x, int &y, int angle, int centerX, int centerY) {
  float radianAngle = angle * PI / 180.0;
  int tempX = x - centerX;
  int tempY = y - centerY;
  x = round(tempX * cos(radianAngle) - tempY * sin(radianAngle) + centerX);
  y = round(tempX * sin(radianAngle) + tempY * cos(radianAngle) + centerY);
}
void drawTriangleNGR(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(255, 255, 255);

  int16_t x0 = 11;
  int16_t y0 = 16;
  int16_t x1 = 18;
  int16_t y1 = 9;
  int16_t x2 = 24;
  int16_t y2 = 16;

  int centerX = (x0 + x1 + x2) / 3;
  int centerY = (y0 + y1 + y2) / 3;

  // Declare temporary variables for rotated coordinates
  int temp_x0 = x0;
  int temp_y0 = y0;
  int temp_x1 = x1;
  int temp_y1 = y1;
  int temp_x2 = x2;
  int temp_y2 = y2;

  // Rotate each point in place
  rotatePointNGR(temp_x0, temp_y0, angle, centerX, centerY);
  rotatePointNGR(temp_x1, temp_y1, angle, centerX, centerY);
  rotatePointNGR(temp_x2, temp_y2, angle, centerX, centerY);

  // Update original coordinates
  x0 = temp_x0;
  y0 = temp_y0;
  x1 = temp_x1;
  y1 = temp_y1;
  x2 = temp_x2;
  y2 = temp_y2;

  x0 += posX;
  y0 += posY;
  x1 += posX;
  y1 += posY;
  x2 += posX;
  y2 += posY;

  float scale = 1;
  x0 *= scale;
  y0 *= scale;
  x1 *= scale;
  y1 *= scale;
  x2 *= scale;
  y2 *= scale;

  tft.fillTriangle(x0, y0, x1, y1, x2, y2, triangleColor);
}
void drawRectNGR() {
  tft.setRotation(2);
  tft.fillSmoothRoundRect(139, 166, 97, 150, 4, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillSmoothRoundRect(189, 4, 46, 156, 7, tft.color565(230, 207, 0), TFT_BLACK);
  tft.fillSmoothRoundRect(140, 4, 46, 156, 7, tft.color565(0, 173, 20), TFT_BLACK);
  tft.fillSmoothRoundRect(91, 4, 46, 156, 7, tft.color565(128, 0, 227), TFT_BLACK);

  tft.fillSmoothRoundRect(49, 166, 42, 150, 4, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillSmoothRoundRect(4, 166, 42, 150, 4, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillSmoothRoundRect(94, 166, 42, 150, 4, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillSmoothRoundRect(65, 4, 22, 156, 4, tft.color565(8, 8, 8), TFT_BLACK);
  tft.fillRoundRect(103, 172, 8, 137, 2, tft.color565(30, 30, 30));
  tft.drawRoundRect(103, 172, 8, 137, 2, tft.color565(45, 45, 45));
  tft.fillRoundRect(170, 138, 4, 9, 0, tft.color565(255, 255, 255));

  /*tft.setRotation(3);
    tft.pushImage(3, 50, 14, 17, dataPlus);
    tft.pushImage(60, 50, 14, 17, dataMinus);*/
}
//---------------------------------------------------------------------------------------
void drawTextNGR() {
  tft.setRotation(3);
  tft.setTextSize(1);
  tft.loadFont(PTSans_Regular16);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("Trigging", 172, 155);
  tft.drawString("Time Limit", 172, 200);
  tft.drawString("NGR Statistics", 172, 11);
  tft.drawString("Offline", 172, 111);
  tft.drawString("100%", 268, 111);

  tft.setTextColor(tft.color565(170, 170, 170), tft.color565(60, 60, 60));
  tft.drawString("- NONE", 172, 174);
  tft.drawString("- 00:00:00", 172, 219);
  tft.drawString("- 01/10", 172, 29);
  tft.drawString("- 00:00:00", 172, 47);
  tft.drawString("- CAP: 0.00000 Ah", 172, 65);
  tft.drawString("- NGR: 0.00000 Wh", 172, 83);

  tft.loadFont(PTSans_Regular12);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(230, 207, 0));
  tft.drawString("VBUS", 9, 7);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 173, 20));
  tft.drawString("IBUS", 9, 56);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(128, 0, 227));
  tft.drawString("PBUS", 9, 105);

  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(170, 170, 170), tft.color565(60, 60, 60));
  tft.drawString("---- NA ----", 10, 204);
  tft.drawString("---- NA ----", 10, 224);
  tft.setRotation(0);
}
void drawVoltNGR() {
  static unsigned long lastdrawVoltNGR = 0;
  static const unsigned long singledrawVoltNGR = 30;
  unsigned long currentMillisNGR = millis();
  if (currentMillisNGR - lastdrawVoltNGR >= singledrawVoltNGR) {
    if (digitalRead(BUTTON_AVER) == LOW) {
      if (!ngrcells) {
        lastdrawVoltNGR = currentMillisNGR;
        ngrvolt = true;
        menudown = true;
        ngrdown = false;
        ngrupped = false;
        menupped = true;
        menuappr = true;
        averbuttonapp = true;
        tft.fillRoundRect(80, 40, 149, 130, 5, tft.color565(30, 30, 30));
        tft.drawRoundRect(80, 40, 149, 130, 5, tft.color565(50, 50, 50));
        tft.fillRoundRect(83, 43, 143, 28, 4, tft.color565(10, 32, 64));
        tft.drawRoundRect(83, 43, 143, 28, 4, tft.color565(19, 89, 191));
        tft.setRotation(3);
        tft.loadFont(PTSans_Bold18);
        tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
        tft.drawString("Last group", 87, 51);
        tft.drawString("Next group", 87, 76);
        tft.drawString("Start offline", 87, 101);
        tft.drawString("Clear offline", 87, 126);
        tft.drawString("Start Limit", 87, 151);
      }
    }
  }
  static unsigned long lastdownNGR = 0;
  static const unsigned long singledownNGR = 50;
  unsigned long downMillisNGRV = millis();
  if (downMillisNGRV - lastdownNGR >= singledownNGR) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      if (!ngrdown) {
        lastdownNGR = downMillisNGRV;
        drawMenu1();
        ngrvolt = false;
        menudown = false;
        ngrdown = true;
        ngrupped = true;
        menupped = false;
        menuappr = false;
        averbuttonapp = false;
      }
    }
  }
  static unsigned long lastupNGR = 0;
  static const unsigned long singleupNGR = 100;
  unsigned long upMillisNGRV = millis();
  if (upMillisNGRV - lastupNGR >= singleupNGR) {
    if (digitalRead(BUTTON_UP) == LOW) {
      if (!ngrupped) {
        lastupNGR = upMillisNGRV;
        PushNGR++;
        if (PushNGR > 4) {
          PushNGR = 1;
        }
        changeRectNGR(PushNGR);
      }
    }
  }

  if (!ngrvolt) {
    unsigned long previousMillis = 0;
    const long interval = 160;
    unsigned long currentMillis = millis();
    tft.setRotation(3);

    int sensorValue1 = analogRead(18);
    float voltage1 = sensorValue1 * (3.3 / 4095.0);

    int sensorValue2 = analogRead(16);
    float voltage2 = sensorValue2 * (3.3 / 4095.0);

    tft.fillRect(22, 156, 55, 17, tft.color565(8, 8, 8));
    tft.fillRect(98, 156, 55, 17, tft.color565(8, 8, 8));

    // Display voltage readings
    tft.loadFont(PTSans_Bold18);
    tft.setTextColor(tft.color565(210, 210, 210), tft.color565(85, 85, 85));
    tft.drawString(String(voltage1, 3) + "V", 23, 161);
    tft.drawString(String(voltage2, 3) + "V", 99, 161);

    // Check conditions and display appropriate text
    /*if (voltage1 >= 2.7 && voltage1 <= 3.3 && voltage2 >= 0.4 && voltage2 <= 1.0) {
      // Display "QC 2.0 (9V)"
      tft.fillRect(6, 178, 110, 20, tft.color565(0, 0, 0));
      tft.setFreeFont(&PTSans_Regular9pt7b);
      tft.setCursor(10, 193);
      tft.setTextColor(tft.color565(210, 210, 210));
      tft.print("QC 2.0 (9V)");
      } else if (voltage1 >= 0.4 && voltage1 <= 1.0 && voltage2 >= 0.4 && voltage2 <= 1.0) {
      // Display "QC 2.0 (12V)"
      tft.fillRect(6, 178, 110, 20, tft.color565(0, 0, 0));
      tft.setFreeFont(&PTSans_Regular9pt7b);
      tft.setCursor(10, 193);
      tft.setTextColor(tft.color565(210, 210, 210));
      tft.print("QC 2.0 (12V)");
      } else if (voltage1 >= 2.7 && voltage1 <= 3.3 && voltage2 >= 2.7 && voltage2 <= 3.3) {
      // Display "QC 2.0 (20V)"
      tft.fillRect(6, 178, 110, 20, tft.color565(0, 0, 0));
      tft.setFreeFont(&PTSans_Regular9pt7b);
      tft.setCursor(10, 193);
      tft.setTextColor(tft.color565(210, 210, 210));
      tft.print("QC 2.0 (20V)");
      } else {
      tft.fillRect(6, 178, 110, 20, tft.color565(0, 0, 0));
      tft.setFreeFont(&PTSans_Regular9pt7b);
      tft.setCursor(10, 193);
      tft.setTextColor(tft.color565(210, 210, 210));
      tft.print("---- NA ----");
      }*/
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Читаем ток с обоих каналов
      float current_lipo = ina3221.getCurrent_mA(LIPO_BATTERY_CHANNEL);
      float current_solar = ina3221.getCurrent_mA(SOLAR_CELL_CHANNEL);

      // Определение канала с максимальным током
      int max_channel;
      if (current_lipo > current_solar) {
        max_channel = LIPO_BATTERY_CHANNEL;
      } else {
        max_channel = SOLAR_CELL_CHANNEL;
      }

      float voltage = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);
      int int_voltage = voltage * 100000;
      voltNGRSprite.fillSprite(tft.color565(230, 207, 0));
      voltNGRSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(230, 207, 0));
      voltNGRSprite.loadFont(PTSans_Bold32);
      char volt[20];
      int volt1 = int_voltage / 100000;
      int volt2 = (int_voltage / 100) % 1000;
      int volt3 = int_voltage % 100;
      sprintf(volt, "%d.%02d %03d", volt1, volt2, volt3);
      voltNGRSprite.drawString(volt, 3, 0);
      int voltNGRWidth = voltNGRSprite.textWidth(volt);
      voltNGRSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(230, 207, 0));
      voltNGRSprite.loadFont(PTSans_Bold18);
      voltNGRSprite.drawString(" V", voltNGRWidth + 8, 9);
      voltNGRSprite.pushSprite(5, 22);

      float current;
      if (max_channel == LIPO_BATTERY_CHANNEL) {
        current = (current_lipo / 1000);
      } else {
        current = (current_solar / 1000);
      }
      int int_current = current * 100000;
      currNGRSprite.fillSprite(tft.color565(0, 173, 20));
      currNGRSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 173, 20));
      currNGRSprite.loadFont(PTSans_Bold32);
      char curr[20];
      int curr1 = int_current / 100000;
      int curr2 = (int_current / 100) % 1000;
      int curr3 = int_current % 100;
      sprintf(curr, "%d.%02d %03d", curr1, curr2, curr3);
      currNGRSprite.drawString(curr, 3, 0);
      int currNGRWidth = currNGRSprite.textWidth(curr);
      currNGRSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 173, 20));
      currNGRSprite.loadFont(PTSans_Bold18);
      currNGRSprite.drawString(" A", currNGRWidth + 8, 9);
      currNGRSprite.pushSprite(5, 71);

      float power = voltage * (current / 1000);
      int int_power = power * 100000;
      wattNGRSprite.fillSprite(tft.color565(128, 0, 227));
      wattNGRSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(128, 0, 227));
      wattNGRSprite.loadFont(PTSans_Bold32);
      char watt[20];
      int power1 = int_power / 100000;
      int power2 = (int_power / 100) % 1000;
      int power3 = int_power % 100;
      sprintf(watt, "%d.%02d %03d", power1, power2, power3);
      wattNGRSprite.drawString(watt, 3, 0);
      int wattNGRWidth = wattNGRSprite.textWidth(watt);
      wattNGRSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(128, 0, 227));
      wattNGRSprite.loadFont(PTSans_Bold18);
      wattNGRSprite.drawString(" W", wattNGRWidth + 8, 9);
      wattNGRSprite.pushSprite(5, 120);
    }
  }
}
void changeRectNGR(int rectNGR) {
  selectRectNGR = rectNGR;
  uint16_t selectedFillNGR = tft.color565(10, 32, 64);
  uint16_t selectedBorderNGR = tft.color565(19, 89, 191);
  uint16_t unselectedFillNGR = tft.color565(19, 19, 19);
  uint16_t unselectedBorderNGR = tft.color565(32, 32, 32);
  for (int i = 1; i <= 5; i++) {
    uint16_t fillNGR = (i == rectNGR) ? selectedFillNGR : unselectedFillNGR;
    uint16_t borderNGR = (i == rectNGR) ? selectedBorderNGR : unselectedBorderNGR;
    drawRectedNGR(i, fillNGR, borderNGR);
  }
}
void drawRectedNGR(int rectNGR, uint16_t fillNGR, uint16_t borderNGR) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectNGR < 1 || rectNGR > 5)
    return;
  switch (rectNGR) {
    case 1: rectX = 83; rectY = 43; rectWidth = 143; rectHeight = 28; cornerRadius = 4;
      break;
    case 2: rectX = 111; rectY = 43; rectWidth = 143; rectHeight = 28; cornerRadius = 4;
      break;
    case 3: rectX = 139; rectY = 43; rectWidth = 143; rectHeight = 28; cornerRadius = 4;
      break;
    case 4: rectX = 167; rectY = 43; rectWidth = 143; rectHeight = 28; cornerRadius = 4;
      break;
    case 5: rectX = 195; rectY = 43; rectWidth = 143; rectHeight = 28; cornerRadius = 4;
      break;
  }
}
