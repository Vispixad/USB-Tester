// Другие элементы
/*const int analogPinA0 = A0;
  const int analogPinA1 = A1;*/
float angle = -50; // Угол для вращения круга
int buttonPressCounter = 0; // Счетчик нажатий кнопки
float voltage1, voltage2, voltage3;
/*drawHemisphere1(150, 152, 9, tft.color565(238, 255, 0)); // Отрисовка полусфер
  drawHemisphere2(150, 232, 9, tft.color565(0, 166, 255));*/
/*---------------------------------------------------------------------------------------
  void drawHemisphere1(int16_t x, int16_t y, int16_t radius, uint16_t color) {
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

  void drawHemisphere2(int16_t x, int16_t y, int16_t radius, uint16_t color) {
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
*/
//---------------------------------------------------------------------------------------
void rotatePointQC(int &x, int &y, int angle, int centerX, int centerY) {
  float radianAngle = angle * PI / 180.0;
  int tempX = x - centerX;
  int tempY = y - centerY;
  x = round(tempX * cos(radianAngle) - tempY * sin(radianAngle) + centerX);
  y = round(tempX * sin(radianAngle) + tempY * cos(radianAngle) + centerY);
}
void drawTriangleQC(int posX, int posY, int angle) {
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
  rotatePointQC(temp_x0, temp_y0, angle, centerX, centerY);
  rotatePointQC(temp_x1, temp_y1, angle, centerX, centerY);
  rotatePointQC(temp_x2, temp_y2, angle, centerX, centerY);

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
void drawRectQC2() {
  tft.setRotation(2);
  tft.fillRoundRect(-8, 0, 144, 320, 7, tft.color565(8, 8, 8));
  tft.drawRoundRect(-8, 0, 144, 320, 7, tft.color565(21, 21, 21));
  tft.fillSmoothRoundRect(179, 2, 34, 140, 9, tft.color565(230, 207, 0), TFT_BLACK);
  tft.fillSmoothRoundRect(179, 156, 34, 162, 9, tft.color565(0, 173, 20), TFT_BLACK);
  tft.fillSmoothRoundRect(141, 2, 34, 140, 9, tft.color565(128, 0, 227), TFT_BLACK);
  tft.fillRoundRect(194, 295, 4, 9, 0, tft.color565(255, 255, 255));
}
void drawTextQC2() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  tft.setTextColor(textColor1);
  tft.drawString("Qualcomm QC2.0", 85, 5);
  tft.setRotation(0);
}
void buttonQC2() {
  unsigned long lastqc2Down = 0;
  const unsigned long qc2Down = 100;
  if (digitalRead(BUTTON_DOWN) == LOW && millis() - lastqc2Down > qc2Down) {
    if (!QC2down) {
      QC2down = true;
      stopedQC2 = true;
      tft.fillScreen(TFT_BLACK);
      drawFast();
      drawTextFast();
      updateRectQC();
      stopedwar = true;
      wardown = true;
      warup = true;
      menufast = false;
      fastdown = false;
      buttonFast = false;
      wardown = true;
      /*menufast = false;
        warup = true;
        menuapp = true;
        menuappr = true;*/
    } else {
    }
  }
}
void triggedQC2() {
  if (!stopedQC2) {
    if (!rotationCompleted) {
      /*// Увеличиваем угол для вращения
        angle += 0.2;*/
      tft.setRotation(3);
      tft.setFreeFont(&PTSans_Regular9pt7b);
      tft.setCursor(50, 190);
      tft.setTextColor(tft.color565(200, 200, 200));
      tft.print("Entering QC2.0, please wait");
      /*// Рисуем круг в новом положении
        int16_t x0 = 80 + cos(angle) * 25; // Вычисляем новые координаты круга
        int16_t y0 = 150 + sin(angle) * 25;
        tft.fillCircle(x0, y0, 3, tft.color565(2, 189, 45)); // Рисуем круг красного цвета */
      delay(400);
      rotationCompleted = true;
    }

    // Установка QC и чтение напряжения для QC.set(+4000)
    if (!rangesChecked) {
      QC.setMode(QC_VAR);
      QC.set(+9000);
      delay(60);

      // Чтение и запись данных напряжения
      float busvoltage1 = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);

      // Установка нового значения для QC
      QC.set(+12000);
      delay(80);

      // Чтение и запись данных напряжения
      float busvoltage2 = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);

      // Установка еще одного значения для QC
      QC.set(+20000);
      delay(40);

      // Чтение и запись данных напряжения
      float busvoltage3 = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);

      QC.set(+5000);
      delay(50);

      // Возвращение к обычному положению
      tft.setRotation(0);

      // Проверка диапазонов напряжений
      bool range1 = (busvoltage1 >= 7 && busvoltage1 <= 10);
      bool range2 = (busvoltage2 >= 10 && busvoltage2 <= 13);
      bool range3 = (busvoltage3 >= 17 && busvoltage3 <= 21);

      if (range1 && range2 && range3) {
        draw4Tiles();
      } else if ((range1 && range2) || (range1 && range3) || (range2 && range3)) {
        draw3Tiles();
      } else if (range1 || range2 || range3) {
        draw2Tiles();
      } else {
        drawNone();
      }
    }
    rangesChecked = true;
    static unsigned long previousUpdateMillis = 0;
    const long updateInterval = 80;
    unsigned long currentMillis = millis();

    // Проверяем, прошло ли достаточно времени для обновления данных
    if (currentMillis - previousUpdateMillis >= updateInterval) {
      previousUpdateMillis = currentMillis;

      tft.startWrite();
      tft.setRotation(3);
      tft.setFreeFont(&PTSans_Bold15pt7b);

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
      tft.fillRect(4, 32, 135, 26, tft.color565(230, 207, 0));

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
      tft.setCursor(8, 54);
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

      tft.setFreeFont(&PTSans_Bold15pt7b);
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

      tft.setCursor(164, 54);
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

      tft.setFreeFont(&PTSans_Bold15pt7b);
      // Прямоугольник для обновления мощности
      tft.fillRect(4, 70, 135, 26, tft.color565(128, 0, 227));
      // Расчет мощности только с максимального канала
      float power = voltage * (current / 1000);

      // Разделение мощности на целую и дробную части
      int power_int = int(power);
      int power_frac = int((power - power_int) * 100000);

      // Перевод дробной части в строку
      char power_frac_str[6];
      sprintf(power_frac_str, "%05d", power_frac);
      tft.setCursor(8, 92);
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
    tft.setRotation(0);
    delay(20);
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
    delay(40);
    /*if (digitalRead(BUTTON_AVER) == LOW) {
      buttonPressCounter++;
      switch (buttonPressCounter) {
        case 1:
          moveAndChangeColor(rectX6, rectY6, rectColor6, 9, 0, tft.color565(200, 200, 200));
          moveAndChangeColor(rectX7, rectY7, rectColor7, 9, 0, tft.color565(200, 200, 200));
          moveAndChangeColor(rectX8, rectY8, rectColor8, -9, 0, tft.color565(0, 166, 255));
          moveAndChangeColor(rectX9, rectY9, rectColor9, -9, 0, tft.color565(0, 166, 255));
          break;
        case 2:
          moveAndChangeColor(rectX10, rectY10, rectColor10, 9, 0, tft.color565(200, 200, 200));
          moveAndChangeColor(rectX11, rectY11, rectColor11, 9, 0, tft.color565(200, 200, 200));
          moveAndChangeColor(rectX12, rectY12, rectColor12, -9, 0, tft.color565(0, 166, 255));
          moveAndChangeColor(rectX13, rectY13, rectColor13, -9, 0, tft.color565(0, 166, 255));
          break;
      }
      }*/
  }
}
/*void moveAndChangeColor(int16_t &rectX, int16_t &rectY, uint16_t &rectColor, int16_t moveX, int16_t moveY, uint16_t newColor) {
  rectY += moveY; // Перемещение прямоугольника по вертикали
  rectColor = newColor; // Изменение цвета прямоугольника
  }*/
void drawNone() {

}
void draw4Tiles() {
  tft.fillRoundRect(24, 6, 90, 72, 7, tft.color565(46, 5, 5));
  tft.drawRoundRect(24, 6, 90, 72, 7, tft.color565(56, 21, 21));
  tft.fillRoundRect(15, 84, 90, 72, 7, tft.color565(10, 10, 10));
  tft.drawRoundRect(15, 84, 90, 72, 7, tft.color565(19, 19, 19));
  tft.fillRoundRect(15, 162, 90, 72, 7, tft.color565(10, 10, 10));
  tft.drawRoundRect(15, 162, 90, 72, 7, tft.color565(19, 19, 19));
  tft.fillRoundRect(15, 240, 90, 72, 7, tft.color565(10, 10, 10));
  tft.drawRoundRect(15, 240, 90, 72, 7, tft.color565(19, 19, 19));
  tft.setRotation(3);
  uint16_t textColor2 = tft.color565(200, 200, 200);
  uint16_t textColor3 = tft.color565(204, 157, 157);
  tft.setFreeFont(&PTSans_Regular12pt7b);
  tft.setTextColor(textColor3);
  tft.drawString("5V", 26, 166);
  tft.setTextColor(textColor2);
  tft.drawString("9V", 105, 175);
  tft.setTextColor(textColor2);
  tft.drawString("12V", 178, 175);
  tft.setTextColor(textColor2);
  tft.drawString("20V", 255, 175);
  tft.setRotation(0);
}
void draw3Tiles() {
  tft.fillRoundRect(24, 45, 90, 72, 7, tft.color565(46, 5, 5));
  tft.drawRoundRect(24, 45, 90, 72, 7, tft.color565(56, 21, 21));
  tft.fillRoundRect(15, 123, 90, 72, 7, tft.color565(10, 10, 10));
  tft.drawRoundRect(15, 123, 90, 72, 7, tft.color565(19, 19, 19));
  tft.fillRoundRect(15, 201, 90, 72, 7, tft.color565(10, 10, 10));
  tft.drawRoundRect(15, 201, 90, 72, 7, tft.color565(19, 19, 19));
  tft.setRotation(3);
  tft.setTextSize(1);
  uint16_t textColor2 = tft.color565(200, 200, 200);
  uint16_t textColor3 = tft.color565(204, 157, 157);
  tft.setFreeFont(&PTSans_Regular12pt7b);
  tft.setTextColor(textColor3);
  tft.drawString("5V", 65, 152);
  tft.setTextColor(textColor2);
  tft.drawString("9V", 144, 161);
  tft.drawString("12V", 217, 161);
  tft.setRotation(0);
}
void draw2Tiles() {
  tft.fillRoundRect(24, 84, 90, 72, 7, tft.color565(46, 5, 5));
  tft.drawRoundRect(24, 84, 90, 72, 7, tft.color565(56, 21, 21));
  tft.fillRoundRect(15, 162, 90, 72, 7, tft.color565(10, 10, 10));
  tft.drawRoundRect(15, 162, 90, 72, 7, tft.color565(19, 19, 19));
  tft.setRotation(3);
  tft.setTextSize(1);
  uint16_t textColor2 = tft.color565(200, 200, 200);
  uint16_t textColor3 = tft.color565(204, 157, 157);
  tft.setFreeFont(&PTSans_Regular12pt7b);
  tft.setCursor(104, 166);
  tft.setTextColor(textColor3);
  tft.print("5V");
  tft.setCursor(183, 175);
  tft.setTextColor(textColor2);
  tft.print("9V");
  tft.setRotation(0);
}
