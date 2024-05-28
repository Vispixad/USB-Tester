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
  tft.setFreeFont(&PTSans_Regular8pt7b);

  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor8 = tft.color565(170, 170, 170);

  tft.setCursor(172, 164); //(1 - коеф Х2, 2 - коеф Х1.875)
  tft.setTextColor(textColor1);
  tft.print("Trigging");

  tft.setCursor(172, 183);
  tft.setTextColor(textColor8);
  tft.print("- NONE");

  tft.setCursor(172, 209);
  tft.setTextColor(textColor1);
  tft.print("Time Limit");

  tft.setCursor(172, 228);
  tft.setTextColor(textColor8);
  tft.print("- 00:00:00");

  tft.setCursor(172, 20);
  tft.setTextColor(textColor1);
  tft.print("NGR Statistics");

  tft.setCursor(172, 38);
  tft.setTextColor(textColor8);
  tft.print("- 01/10");

  tft.setCursor(172, 56);
  tft.setTextColor(textColor8);
  tft.print("- 00:00:00");

  tft.setCursor(172, 74);
  tft.setTextColor(textColor8);
  tft.print("- CAP: 0.00000 Ah");

  tft.setCursor(172, 92);
  tft.setTextColor(textColor8);
  tft.print("- NGR: 0.00000 Wh");

  tft.setCursor(172, 120);
  tft.setTextColor(textColor1);
  tft.print("Offline");

  tft.setCursor(268, 120);
  tft.setTextColor(textColor1);
  tft.print("100%");

  tft.setFreeFont(&PTSans_Regular6pt7b);

  tft.setCursor(9, 15);
  tft.setTextColor(textColor1);
  tft.print("VBUS");

  tft.setCursor(9, 64);
  tft.setTextColor(textColor1);
  tft.print("IBUS");

  tft.setCursor(9, 113);
  tft.setTextColor(textColor1);
  tft.print("PBUS");

  tft.setFreeFont(&PTSans_Regular9pt7b);

  /*tft.setCursor(10, 193);
    tft.setTextColor(textColor8);
    tft.print("---- NA ----");*/

  tft.setCursor(10, 213);
  tft.setTextColor(textColor8);
  tft.print("---- NA ----");

  tft.setCursor(10, 233);
  tft.setTextColor(textColor8);
  tft.print("---- NA ----");

  tft.setRotation(1);
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
        tft.setFreeFont(&PTSans_Bold9pt7b);
        uint16_t textColor1 = tft.color565(255, 255, 255);
        tft.setTextColor(textColor1);
        tft.drawString("Last group", 87, 46);
        tft.setTextColor(textColor1);
        tft.drawString("Next group", 87, 71);
        tft.setTextColor(textColor1);
        tft.drawString("Start offline", 87, 96);
        tft.setTextColor(textColor1);
        tft.drawString("Clear offline", 87, 121);
        tft.setTextColor(textColor1);
        tft.drawString("Start Limit", 87, 146);
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
    tft.setFreeFont(&PTSans_Bold9pt7b);
    tft.setCursor(23, 170);
    tft.setTextColor(tft.color565(210, 210, 210));
    tft.setTextSize(1);
    tft.print(voltage1, 3);
    tft.print(F("V"));

    tft.setCursor(99, 170);
    tft.print(voltage2, 3);
    tft.print(F("V"));

    // Check conditions and display appropriate text
    if (voltage1 >= 2.7 && voltage1 <= 3.3 && voltage2 >= 0.4 && voltage2 <= 1.0) {
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
    }
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      tft.startWrite();
      tft.setFreeFont(&PTSans_Bold16pt7b);

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

      // Прямоугольник для обновления напряжения
      tft.fillRect(5, 21, 130, 26, tft.color565(230, 207, 0));

      float voltage = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);

      if (voltage < 0.0) {
        voltage = 0.0;
      }

      // Разделение напряжения на целую и дробную части
      int voltage_int = int(voltage);
      int voltage_frac = int((voltage - voltage_int) * 100000);

      // Перевод дробной части в строку
      char voltage_frac_str[6];
      sprintf(voltage_frac_str, "%05d", voltage_frac);

      // Вывод напряжения
      tft.setCursor(9, 43);
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.setTextSize(1);
      tft.print(voltage_int);
      tft.print(".");
      if (voltage_int >= 10) {
        // Если напряжение больше или равно 10, выводим два знака после запятой, затем пробел, затем еще два знака
        for (int i = 0; i < 2; i++) {
          tft.print(voltage_frac_str[i]);
        }
        tft.print(" ");
        for (int i = 2; i < 4; i++) {
          tft.print(voltage_frac_str[i]);
        }
      } else {
        // Если напряжение меньше 10, выводим три знака после запятой, затем пробел, затем еще два знака
        for (int i = 0; i < 3; i++) {
          tft.print(voltage_frac_str[i]);
        }
        tft.print(" ");
        for (int i = 3; i < 5; i++) {
          tft.print(voltage_frac_str[i]);
        }
      }
      tft.setFreeFont(&PTSans_Bold9pt7b);
      tft.print(F(" V"));

      // Установка нового шрифта
      tft.setFreeFont(&PTSans_Bold16pt7b);

      // Прямоугольник для обновления тока
      tft.fillRect(5, 72, 130, 26, tft.color565(0, 173, 20));

      float current;
      if (max_channel == LIPO_BATTERY_CHANNEL) {
        current = current_lipo;
      } else {
        current = current_solar;
      }

      // Разделение тока на целую и дробную части
      int current_int = int(current / 1000);
      int current_frac = int((current / 1000 - current_int) * 100000);

      // Перевод дробной части в строку
      char current_frac_str[6];
      sprintf(current_frac_str, "%05d", current_frac);

      // Вывод тока
      tft.setCursor(9, 93);
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.setTextSize(1);
      tft.print(current_int);
      tft.print(".");
      if (current_int >= 10) {
        // Если ток больше или равен 10, выводим два знака после запятой, затем пробел, затем еще два знака
        for (int i = 0; i < 2; i++) {
          tft.print(current_frac_str[i]);
        }
        tft.print(" ");
        for (int i = 2; i < 4; i++) {
          tft.print(current_frac_str[i]);
        }
      } else {
        // Если ток меньше 10, выводим три знака после запятой, затем пробел, затем еще два знака
        for (int i = 0; i < 3; i++) {
          tft.print(current_frac_str[i]);
        }
        tft.print(" ");
        for (int i = 3; i < 5; i++) {
          tft.print(current_frac_str[i]);
        }
      }
      tft.setFreeFont(&PTSans_Bold9pt7b);
      tft.print(F(" A"));

      // Установка нового шрифта
      tft.setFreeFont(&PTSans_Bold16pt7b);

      // Прямоугольник для обновления мощности
      tft.fillRect(5, 117, 130, 26, tft.color565(128, 0, 227));

      // Расчет мощности только с максимального канала
      float power = voltage * (current / 1000);

      // Разделение мощности на целую и дробную части
      int power_int = int(power);
      int power_frac = int((power - power_int) * 100000);

      // Перевод дробной части в строку
      char power_frac_str[6];
      sprintf(power_frac_str, "%05d", power_frac);

      tft.setCursor(9, 141);
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.setTextSize(1);
      tft.print(power_int);
      tft.print(".");
      if (power_int >= 10) {
        // Если мощность больше или равна 10, выводим два знака после запятой, затем пробел, затем еще два знака
        for (int i = 0; i < 2; i++) {
          tft.print(power_frac_str[i]);
        }
        tft.print(" ");
        for (int i = 2; i < 4; i++) {
          tft.print(power_frac_str[i]);
        }
      } else {
        // Если мощность меньше 10, выводим три знака после запятой, затем пробел, затем еще два знака
        for (int i = 0; i < 3; i++) {
          tft.print(power_frac_str[i]);
        }
        tft.print(" ");
        for (int i = 3; i < 5; i++) {
          tft.print(power_frac_str[i]);
        }
      }
      tft.setFreeFont(&PTSans_Bold9pt7b);
      tft.print(F(" W"));
      tft.endWrite();
    }
  }
}
void changeRectNGR(int rectNGR) {
  selectRectNGR = rectNGR;
  uint16_t selectedFillColor = tft.color565(10, 32, 64);
  uint16_t selectedBorderColor = tft.color565(19, 89, 191);
  uint16_t unselectedFillColor = tft.color565(19, 19, 19);
  uint16_t unselectedBorderColor = tft.color565(32, 32, 32);
  for (int i = 1; i <= 5; i++) {
    uint16_t fillColor = (i == rectNGR) ? selectedFillColor : unselectedFillColor;
    uint16_t borderColor = (i == rectNGR) ? selectedBorderColor : unselectedBorderColor;
    drawRectangle(i, fillColor, borderColor);
  }
}
void drawRectedNGR(int rectNGR, uint16_t fillColor, uint16_t borderColor) {
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
