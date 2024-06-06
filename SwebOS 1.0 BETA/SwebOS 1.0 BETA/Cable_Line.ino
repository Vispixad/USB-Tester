unsigned long transmissionStartTime = 0;
unsigned long transmissionEndTime = 0;
unsigned long receptionStartTime = 0;
unsigned long receptionEndTime = 0;
const unsigned long transmissionDuration = 200;
String lastTransmittedString = "";
String lastReceivedString = "";

unsigned long totalBytesSent = 0;
unsigned long totalBytesReceived = 0;

unsigned int charactersToSend = 35;
unsigned int charactersSent = 0;

unsigned long totalTransmissionTime = 0;

/*void rotatePointRes(int &x, int &y, int angle, int centerX, int centerY) {
  float radianAngle = angle * PI / 180.0;
  int tempX = x - centerX;
  int tempY = y - centerY;
  x = round(tempX * cos(radianAngle) - tempY * sin(radianAngle) + centerX);
  y = round(tempX * sin(radianAngle) + tempY * cos(radianAngle) + centerY);
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

  // Declare temporary variables for rotated coordinates
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
  }*/
void drawRectCable() {
  tft.setRotation(2);
  tft.fillRoundRect(179, 12, 34, 130, 9, tft.color565(230, 207, 0));
  tft.fillRoundRect(179, 156, 34, 152, 9, tft.color565(0, 173, 20));
  tft.fillRoundRect(141, 12, 34, 130, 9, tft.color565(128, 0, 227));
  tft.fillRoundRect(2, 4, 134, 312, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(2, 4, 134, 312, 4, tft.color565(21, 21, 21));
  tft.fillRoundRect(194, 287, 4, 9, 0, tft.color565(255, 255, 255));
}
void drawTextCable() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(200, 200, 200);
  uint16_t textColor2 = tft.color565(255, 255, 255);
  tft.setTextColor(textColor2);
  tft.drawString("Cable Line Integrity", 65, 5);
  tft.setTextColor(textColor1);
  tft.drawString("USB-C -> USB-A", 9, 108);
  tft.setRotation(0);
}
String generateRandomString(int length) {
  String randomString = "";
  char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  for (int i = 0; i < length; i++) {
    int index = random(0, sizeof(characters) - 1);
    randomString += characters[index];
  }
  return randomString;
}

void sendString(const String &data) {
  virtualSerial.println(data);
  totalBytesSent += data.length();
}

void CableLine() {
  if (!stopedcable) {
    if (millis() - transmissionStartTime < transmissionDuration && charactersSent < charactersToSend) {
      String randomString = generateRandomString(1);
      sendString(randomString);
      lastTransmittedString += randomString;
      transmissionEndTime = millis();
      receptionStartTime = micros();
      totalTransmissionTime += transmissionEndTime - transmissionStartTime;
      charactersSent++;
    } else {
      receptionEndTime = micros();
      tft.init();
      tft.fillScreen(TFT_BLACK);
      tft.setRotation(2);
      drawRectCable();
      drawTextCable();
      drawTriangleRes(26, 10, 0);
      tft.setCursor(9, 145);
      tft.setFreeFont(&PTSans_Bold9pt7b);
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.setRotation(3);
      String firstSixChars = lastTransmittedString.substring(0, 6);
      String transmittedString = "CC1 " + firstSixChars + " - ";
      tft.print(transmittedString);
      tft.setCursor(116, 145);
      if (lastReceivedString.length() == 0) {
        tft.setTextColor(tft.color565(255, 255, 255));
        tft.print("------");
        tft.setTextColor(tft.color565(255, 0, 60));
        tft.print(" UDN");
      } else {
        String firstSixCharsReceived = lastReceivedString.substring(0, 11);
        tft.setTextColor(tft.color565(255, 255, 255));
        tft.print(firstSixCharsReceived);
        tft.setTextColor(tft.color565(38, 132, 255));
        tft.print(" DNE");
      }
      tft.setCursor(210, 145);
      tft.setTextColor(tft.color565(204, 160, 0));
      tft.print(String(receptionEndTime - receptionStartTime) + "us");

      int lostBytes = lastTransmittedString.length() - lastReceivedString.length();
      if (lostBytes < 0) {
        lostBytes = 0;
      }
      tft.setCursor(250, 145);
      tft.setTextColor(tft.color565(204, 160, 0));
      tft.print(String(lostBytes) + "B");

      while (true) {
      }
    }
    if (virtualSerial.available()) {
      String receivedData = virtualSerial.readStringUntil('\n');
      lastReceivedString += receivedData;
      totalBytesReceived += receivedData.length();
    }
    static unsigned long previousUpdateMillis = 0;
    const long updateInterval = 80;
    unsigned long currentMillis = millis();

    // Проверяем, прошло ли достаточно времени для обновления данных
    if (currentMillis - previousUpdateMillis >= updateInterval) {
      previousUpdateMillis = currentMillis;
      tft.setRotation(3);
      tft.setFreeFont(&PTSans_Bold13pt7b);

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
      tft.setCursor(18, 53);
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

      tft.setFreeFont(&PTSans_Bold13pt7b);
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

      tft.setCursor(164, 53);
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

      tft.setFreeFont(&PTSans_Bold13pt7b);
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
      tft.setCursor(18, 91);
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
