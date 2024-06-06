void drawRectPD() {
  tft.setRotation(2);
  tft.fillRoundRect(-3, 0, 144, 320, 7, tft.color565(8, 8, 8));
  tft.drawRoundRect(-3, 0, 144, 320, 7, tft.color565(21, 21, 21));
  tft.fillSmoothRoundRect(179, 2, 34, 140, 9, tft.color565(230, 207, 0), TFT_BLACK);
  tft.fillSmoothRoundRect(179, 156, 34, 162, 9, tft.color565(0, 173, 20), TFT_BLACK);
  tft.fillSmoothRoundRect(141, 2, 34, 140, 9, tft.color565(128, 0, 227), TFT_BLACK);
  tft.fillSmoothRoundRect(60, 50, 35, 210, 9, tft.color565(80, 80, 80), TFT_BLACK);
  tft.fillSmoothRoundRect(60, 50, 35, 70, 9, tft.color565(2, 91, 232), TFT_BLACK);
  tft.fillRoundRect(194, 287, 4, 9, 0, tft.color565(2, 172, 230));
  tft.fillRoundRect(27, 50, 26, 51, 7, tft.color565(14, 14, 14));
  tft.drawRoundRect(27, 50, 26, 51, 7, tft.color565(22, 22, 22));
  tft.fillRoundRect(27, 208, 26, 52, 7, tft.color565(14, 14, 14));
  tft.drawRoundRect(27, 208, 26, 52, 7, tft.color565(22, 22, 22));
}
void drawTextPD() {
  tft.setRotation(3);
  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("PD Trigger", 82, 5);

  /*tft.setTextColor(tft.color565(200, 200, 200), tft.color565(80, 80, 80));
  tft.drawString("3.6-20V", 54, 125);
  tft.drawString("-0.2V", 55, 192);
  tft.drawString("+0.2V", 212, 192);

  tft.loadFont(PTSans_Regular24);
  tft.drawString("5.1V", 208, 153);*/
  tft.setRotation(0);
}
void buttonPD() {
  unsigned long lastPDDown = 0;
  const unsigned long PDDown = 100;
  if (digitalRead(BUTTON_DOWN) == LOW && millis() - lastPDDown > PDDown) {
    if (!PDdown) {
      PDdown = true;
      stopedPD = true;
      tft.fillScreen(TFT_BLACK);
      drawFast();
      drawTextFast();
      updateFast();
      stopedwar = true;
      wardown = true;
      warup = true;
      menufast = false;
      fastdown = false;
      buttonFast = false;
      wardown = true;
    } else {
    }
  }
}
void triggedPD() {
  if (!stopedPD) {
    static unsigned long previousUpdateMillis = 0;
    const long updateInterval = 80;
    unsigned long currentMillis = millis();

    // Проверяем, прошло ли достаточно времени для обновления данных
    if (currentMillis - previousUpdateMillis >= updateInterval) {
      previousUpdateMillis = currentMillis;

      tft.startWrite();
      tft.setRotation(3);
      tft.setFreeFont(&PTSans_Bold14pt7b);

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
      tft.fillRect(14, 32, 125, 26, tft.color565(230, 207, 0));

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
    tft.setRotation(0);

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
