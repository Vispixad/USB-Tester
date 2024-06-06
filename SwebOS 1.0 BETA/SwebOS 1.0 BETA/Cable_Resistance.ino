#define TEXT_COLOR ST77XX_WHITE
#define BACKGROUND_COLOR ST77XX_BLACK

/*const int analogPinA0 = A0;
  const int analogPinA1 = A1;*/
const int buttonPin1 = 12; // Пин кнопки
const int buttstat2 = 5; // Пин второй кнопки
bool buttstat = false; // Состояние кнопки
// Объявление переменных для прямоугольников
int16_t rectX4, rectY4, rectWidth4, rectHeight4, cornerRadius4;
int16_t rectX5, rectY5, rectWidth5, rectHeight5, cornerRadius5;

/*drawHemisphere1(150, 152, 10, tft.color565(238, 255, 0)); // Отрисовка полусфер
  drawHemisphere2(150, 152, 7, tft.color565(0, 166, 255));
  drawHemisphere3(150, 232, 10, tft.color565(238, 255, 0));
  drawHemisphere4(151, 231, 7, tft.color565(0, 166, 255));*/
//---------------------------------------------------------------------------------------
/*void drawHemisphere1(int16_t x, int16_t y, int16_t radius, uint16_t color) {
  int16_t cx = x;
  int16_t cy = y;

  for (int16_t dy = 0; dy <= radius; dy++) {
    // Вычисляем соответствующий радиус по X для каждой строки
    int16_t dx = (int16_t)round(sqrt(radius * radius - dy * dy));

    // Рисуем верхнюю половину эллипса
    for (int16_t i = cx - dx; i <= cx + dx; i++) {
      tft.drawPixel(i, cy - dy, color);
      tft.drawPixel(i, cy + dy, color); // Рисуем нижнюю половину эллипса
    }
  }
  }
  void drawHemisphere2(int16_t x, int16_t y, int16_t radius, uint16_t color) {
  int16_t cx = x;
  int16_t cy = y;

  for (int16_t dy = 0; dy <= radius; dy++) {
    int16_t dx = (int16_t)round(sqrt(radius * radius - dy * dy));

    // Рисуем верхнюю половину окружности
    for (int16_t i = cx - dx; i <= cx + dx; i++) {
      tft.drawPixel(i, cy - dy, color);
    }
  }
  }
  void drawHemisphere3(int16_t x, int16_t y, int16_t radius, uint16_t color) {
  int16_t cx = x;
  int16_t cy = y;

  for (int16_t dy = 0; dy <= radius; dy++) {
    int16_t dx = (int16_t)round(sqrt(radius * radius - dy * dy));

    // Рисуем нижнюю половину окружности
    for (int16_t i = cx - dx; i <= cx + dx; i++) {
      tft.drawPixel(i, cy + dy, color);
    }
  }
  }
  void drawHemisphere4(int16_t x, int16_t y, int16_t radius, uint16_t color) {
  int16_t cx = x;
  int16_t cy = y;

  for (int16_t dy = 0; dy <= radius; dy++) {
    int16_t dx = (int16_t)round(sqrt(radius * radius - dy * dy));

    // Рисуем нижнюю половину окружности
    for (int16_t i = cx - dx; i <= cx + dx; i++) {
      tft.drawPixel(i, cy + dy, color);
    }
  }
  }*/
void rotatePointRes(int &x, int &y, int angle, int centerX, int centerY) {
  float radianAngle = angle * PI / 180.0;
  int tempX = x - centerX;
  int tempY = y - centerY;
  x = round(tempX * cos(radianAngle) - tempY * sin(radianAngle) + centerX);
  y = round(tempX * sin(radianAngle) + tempY * cos(radianAngle) + centerY);
}
void drawTriangleResT(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(255, 255, 255);

  int16_t x0 = 11;
  int16_t y0 = 16;
  int16_t x1 = 18;
  int16_t y1 = 9;
  int16_t x2 = 24;
  int16_t y2 = 16;

  int centerX = (x0 + x1 + x2) / 3;
  int centerY = (y0 + y1 + y2) / 3;

  int temp_x0 = x0;
  int temp_y0 = y0;
  int temp_x1 = x1;
  int temp_y1 = y1;
  int temp_x2 = x2;
  int temp_y2 = y2;

  rotatePointRes(temp_x0, temp_y0, angle, centerX, centerY);
  rotatePointRes(temp_x1, temp_y1, angle, centerX, centerY);
  rotatePointRes(temp_x2, temp_y2, angle, centerX, centerY);

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
void drawTriangleRes(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(255, 255, 255);

  int16_t x0 = 11;
  int16_t y0 = 16;
  int16_t x1 = 18;
  int16_t y1 = 9;
  int16_t x2 = 24;
  int16_t y2 = 16;

  int centerX = (x0 + x1 + x2) / 3;
  int centerY = (y0 + y1 + y2) / 3;

  int temp_x0 = x0;
  int temp_y0 = y0;
  int temp_x1 = x1;
  int temp_y1 = y1;
  int temp_x2 = x2;
  int temp_y2 = y2;

  // Rotate each point in place
  rotatePointRes(temp_x0, temp_y0, angle, centerX, centerY);
  rotatePointRes(temp_x1, temp_y1, angle, centerX, centerY);
  rotatePointRes(temp_x2, temp_y2, angle, centerX, centerY);

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
void drawRectResist() {
  tft.setRotation(2);
  tft.fillRoundRect(179, 12, 34, 130, 9, tft.color565(230, 207, 0));
  tft.fillRoundRect(179, 156, 34, 152, 9, tft.color565(0, 173, 20));
  tft.fillRoundRect(141, 12, 34, 130, 9, tft.color565(128, 0, 227));
  tft.fillRoundRect(73, 6, 65, 115, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(73, 6, 65, 115, 4, tft.color565(21, 21, 21));
  tft.fillRoundRect(4, 6, 65, 115, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(4, 6, 65, 115, 4, tft.color565(21, 21, 21));
  tft.fillRoundRect(4, 125, 134, 191, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(4, 125, 134, 191, 4, tft.color565(21, 21, 21));
  tft.fillRoundRect(194, 287, 4, 9, 0, tft.color565(255, 255, 255));
}
void drawTextResist() {
  tft.setRotation(3);
  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("Cable Resistance", 80, 5);

  tft.setTextColor(tft.color565(200, 200, 200), tft.color565(70, 70, 70));
  tft.drawString("Reference:", 9, 105);
  tft.drawString("Real Time:", 9, 173);
  tft.drawString("Result:", 129, 105);

  tft.loadFont(PTSans_Bold53);
  tft.setTextColor(tft.color565(60, 60, 60), tft.color565(20, 20, 20));
  tft.drawString("NULL", 147, 158);
  tft.loadFont(PTSans_Regular18);
  tft.setRotation(0);
}
void CableResist() {
  static unsigned long lastButtonResist = 0;
  static const unsigned long singleButtonClickResist = 100;
  unsigned long currentResist = millis();
  if (currentResist - lastButtonResist >= singleButtonClickResist) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      /*if (!tolldown) {*/
      lastButtonResist = currentResist;
      stopedresist = true;
      tft.fillScreen(TFT_BLACK);
      drawRectTollbox();
      drawTextTollbox();
      tolldown = false;
      tollup = false;
      menuappr = true;
      averbuttonapp = true;
      timeoverapp = true;
      /*}*/
    }
  }
  if (!stopedresist) {
    tollup = true;
    /* // Считывание состояния кнопок
      bool buttstat1 = digitalRead(buttonPin1);
      bool buttstat2 = digitalRead(buttonPin2);

      // Переменные для хранения времени удерживания кнопок
      static unsigned long buttonHoldTime1 = 0;
      static unsigned long buttonHoldTime2 = 0;

      // Переменные для отслеживания текущего состояния прямоугольников
      static bool rectState1 = false;
      static bool rectState2 = false;

      // Обработка первой кнопки
      if (buttstat1 == LOW) {
       unsigned long currentMillis = millis();
       if (currentMillis - buttonHoldTime1 > 100) {
         if (!rectState1) {
           tft.setRotation(0);
           // Изменение цвета прямоугольника 4 и 5
           uint16_t newRectColor4 = tft.color565(10, 32, 64);
           tft.fillRoundRect(73, 6, 65, 115, 4, newRectColor4);
           uint16_t newRectColor5 = tft.color565(30, 93, 186);
           tft.drawRoundRect(73, 6, 65, 115, 4, newRectColor5);
           // Изменение цвета прямоугольника 6 и 7
           uint16_t newRectColor6 = tft.color565(7, 7, 7);
           tft.fillRoundRect(4, 6, 65, 115, 4, newRectColor6);
           uint16_t newRectColor7 = tft.color565(16, 16, 16);
           tft.drawRoundRect(4, 6, 65, 115, 4, newRectColor7);
           drawTexting();
         } else {
           tft.setRotation(0);
           // Изменение цвета прямоугольника 6 и 7
           uint16_t newRectColor6 = tft.color565(10, 32, 64);
           tft.fillRoundRect(4, 6, 65, 115, 4, newRectColor6);
           uint16_t newRectColor7 = tft.color565(30, 93, 186);
           tft.drawRoundRect(4, 6, 65, 115, 4, newRectColor7);
           // Изменение цвета прямоугольника 4 и 5
           uint16_t newRectColor4 = tft.color565(7, 7, 7);
           tft.fillRoundRect(73, 6, 65, 115, 4, newRectColor4);
           uint16_t newRectColor5 = tft.color565(7, 7, 7);
           tft.drawRoundRect(73, 6, 65, 115, 4, newRectColor5);
           drawTexting();
         }
         rectState1 = !rectState1;
         buttonHoldTime1 = currentMillis;
       }
      } else {
       buttonHoldTime1 = 0;
      }

      // Обработка второй кнопки
      if (buttstat2 == LOW) {
       unsigned long currentMillis = millis();
       if (currentMillis - buttonHoldTime2 > 100) {
         if (!rectState2) {
           tft.setRotation(0);
           // Изменение цвета прямоугольника 6 и 7
           uint16_t newRectColor6 = tft.color565(10, 32, 64);
           tft.fillRoundRect(4, 6, 65, 115, 4, newRectColor6);
           uint16_t newRectColor7 = tft.color565(30, 93, 186);
           tft.drawRoundRect(4, 6, 65, 115, 4, newRectColor7);
           // Изменение цвета прямоугольника 4 и 5
           uint16_t newRectColor4 = tft.color565(7, 7, 7);
           tft.fillRoundRect(73, 6, 65, 115, 4, newRectColor4);
           uint16_t newRectColor5 = tft.color565(16, 16, 16);
           tft.drawRoundRect(73, 6, 65, 115, 4, newRectColor5);
           drawTexting();
         } else {
           tft.setRotation(0);
           // Изменение цвета прямоугольника 4 и 5
           uint16_t newRectColor4 = tft.color565(10, 32, 64);
           tft.fillRoundRect(73, 6, 65, 115, 4, newRectColor4);
           uint16_t newRectColor5 = tft.color565(30, 93, 186);
           tft.drawRoundRect(73, 6, 65, 115, 4, newRectColor5);
           // Изменение цвета прямоугольника 6 и 7
           uint16_t newRectColor6 = tft.color565(7, 7, 7);
           tft.fillRoundRect(4, 6, 65, 115, 4, newRectColor6);
           uint16_t newRectColor7 = tft.color565(16, 16, 16);
           tft.drawRoundRect(4, 6, 65, 115, 4, newRectColor7);
           drawTexting();
         }
         rectState2 = !rectState2;
         buttonHoldTime2 = currentMillis;
       }
      } else {
       buttonHoldTime2 = 0;
      }*/
    static unsigned long previousUpdateMillis = 0;
    const long updateInterval = 80;
    unsigned long currentMillis = millis();
    if (currentMillis - previousUpdateMillis >= updateInterval) {
      previousUpdateMillis = currentMillis;
      tft.setRotation(3);
      tft.setFreeFont(&PTSans_Bold14pt7b);
      float current_lipo = ina3221.getCurrent_mA(LIPO_BATTERY_CHANNEL);
      float current_solar = ina3221.getCurrent_mA(SOLAR_CELL_CHANNEL);
      int max_channel;
      if (current_lipo > current_solar) {
        max_channel = LIPO_BATTERY_CHANNEL;
        tft.fillRect(280, 32, 30, 26, tft.color565(80, 80, 80));
        drawTriangleRes(26, 10, 0);
      } else {
        max_channel = SOLAR_CELL_CHANNEL;
        tft.fillRect(280, 32, 30, 26, tft.color565(80, 80, 80));
        drawTriangleResT(26, 10, 90);
      }
      // Прямоугольник для обновления напряжения
      tft.fillRect(14, 32, 125, 26, tft.color565(230, 207, 0));
      float voltage = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);
      if (voltage < 0.0) {
        voltage = 0.0;
      }
      int voltage_int = int(voltage);
      int voltage_frac = int((voltage - voltage_int) * 100000);
      char voltage_frac_str[6];
      sprintf(voltage_frac_str, "%05d", voltage_frac);
      tft.setCursor(18, 52);
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

      tft.setFreeFont(&PTSans_Bold14pt7b);
      // Прямоугольник для обновления тока
      tft.fillRect(160, 32, 125, 26, tft.color565(0, 173, 20));

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

      tft.setCursor(164, 52);
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

      tft.setFreeFont(&PTSans_Bold14pt7b);
      // Прямоугольник для обновления мощности
      tft.fillRect(14, 70, 125, 26, tft.color565(128, 0, 227));
      // Расчет мощности только с максимального канала
      float power = voltage * (current / 1000);

      // Разделение мощности на целую и дробную части
      int power_int = int(power);
      int power_frac = int((power - power_int) * 100000);

      // Перевод дробной части в строку
      char power_frac_str[6];
      sprintf(power_frac_str, "%05d", power_frac);
      tft.setCursor(18, 90);
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
    tft.setFreeFont(&PTSans_Regular9pt7b);
    float vdatap = analogRead(Datap) * (3.3 / 4095.0);
    float vdatam = analogRead(Datam) * (3.3 / 4095.0);
    tft.setRotation(3);
    tft.fillRect(161, 72, 60, 17, tft.color565(0, 0, 0));
    tft.fillRect(246, 72, 60, 17, tft.color565(0, 0, 0));
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.drawString((String(vdatap, 3) + " V"), 163, 72);
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.drawString((String(vdatam, 3) + " V"), 248, 72);
  }
}
/*void drawTexting() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(9, 119);
  tft.setTextColor(tft.color565(200, 200, 200));
  tft.print("Reference:");

  tft.setCursor(9, 187);
  tft.setTextColor(tft.color565(200, 200, 200));
  tft.print("Real Time:");
  tft.setRotation(0);
  }*/
