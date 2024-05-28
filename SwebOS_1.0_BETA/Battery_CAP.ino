float ampHours = 0;
float wattHours = 0;
void drawRectBattery() {
  tft.fillSmoothCircle(14, 15, 6, tft.color565(255, 0, 60), TFT_BLACK);
  tft.setRotation(2);
  tft.fillRoundRect(0, 0, 58, 320, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(0, 0, 58, 320, 4, tft.color565(21, 21, 21));
  tft.fillRoundRect(61, 0, 149, 320, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(61, 0, 149, 320, 4, tft.color565(21, 21, 21));
}
void drawTextBattery() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(232, 190, 2);
  tft.setTextColor(textColor1);
  tft.drawString("<", 10, 5);
  tft.setTextColor(textColor1);
  tft.drawString("Battery capacity", 90, 5);
  tft.setTextColor(textColor1);
  tft.drawString("Group:", 8, 36);
  tft.setTextColor(textColor1);
  tft.drawString("Time:", 40, 59);
  tft.setTextColor(textColor1);
  tft.drawString("CAP:", 40, 82);
  tft.setTextColor(textColor1);
  tft.drawString("NRG:", 40, 105);
  tft.setTextColor(textColor1);
  tft.drawString("BatVol:", 8, 132);
  tft.setTextColor(textColor1);
  tft.drawString("ConvEff:", 8, 154);
  tft.setTextColor(textColor1);
  tft.drawString("(3.0-5.0)", 113, 132);
  tft.setTextColor(textColor1);
  tft.drawString("(60-99)", 128, 154);
  tft.setTextColor(textColor1);
  tft.drawString("Results:", 8, 203);
  tft.setFreeFont(&PTSans_Bold9pt7b);
  tft.setCursor(62, 50);
  tft.setTextColor(tft.color565(3, 161, 252));
  if (cellIndex + 1 < 10) {
    tft.print("0");
  }
  tft.print(String(cellIndex + 1));
  tft.setTextColor(textColor2);
  tft.drawString((String(displayValue, 1) + "V"), 70, 132);
  tft.setTextColor(textColor2);
  tft.drawString((String(displayEff, 0) + "%"), 83, 154);
  tft.setRotation(0);
}
void drawBattery() {
  if (!updateTimeBat) {
    const unsigned long intervaled = 1000;
    static unsigned long previousMillised = 0;
    unsigned long currentMillised = millis();
    if (currentMillised - previousMillised >= intervaled) {
      previousMillised = currentMillised;
      unsigned long milliseconds = currentMillised;
      RealTimed(days, hours, minutes, seconds);
      tft.setRotation(3);
      TimeBatSprite.fillSprite(tft.color565(8, 8, 8));
      TimeBatSprite.setTextColor(tft.color565(210, 210, 210));
      TimeBatSprite.setFreeFont(&PTSans_Bold9pt7b);
      char buffer[20];
      sprintf(buffer, "%d Days %02d:%02d:%02d", days, hours, minutes % 60, seconds % 60);
      TimeBatSprite.drawString(buffer, 2, 0);
      TimeBatSprite.pushSprite(85, 59);
    }
    delay(65);
    tft.setRotation(3);
    float current = ina3221.getCurrent_mA(SOLAR_CELL_CHANNEL);
    static float ampHours = 0;
    ampHours += ((current / 1000) * (seconds / 3600));
    int ampHrs = (ampHours >= 10.0) ? 4 : 5;
    ampHrsSprite.fillSprite(tft.color565(8, 8, 8));
    ampHrsSprite.setTextColor(tft.color565(210, 210, 210));
    ampHrsSprite.setFreeFont(&PTSans_Bold9pt7b);
    ampHrsSprite.drawString(String(ampHours, ampHrs) + " Ah", 2, 0);
    ampHrsSprite.pushSprite(82, 81);

    tft.setRotation(3);
    float voltage = ina3221.getBusVoltage_V(SOLAR_CELL_CHANNEL);
    float wattHours = ampHours * voltage;
    int wattHrs = (wattHours >= 10.0) ? 4 : 5;
    wattHrsSprite.fillSprite(tft.color565(8, 8, 8));
    wattHrsSprite.setTextColor(tft.color565(210, 210, 210));
    wattHrsSprite.setFreeFont(&PTSans_Bold9pt7b);
    wattHrsSprite.drawString(String(wattHours, wattHrs) + " Wh", 2, 0);
    wattHrsSprite.pushSprite(82, 104);

    tft.setRotation(3);
    float displayResult = displayValue * ampHours * (displayEff / 100);
    int dispRes = (displayResult >= 10.0) ? 4 : 5;
    dispResSprite.fillSprite(tft.color565(8, 8, 8));
    dispResSprite.setTextColor(tft.color565(255, 0, 30));
    dispResSprite.setFreeFont(&PTSans_Bold17pt7b);
    dispResSprite.drawString(String(displayResult, dispRes), 5, 0);
    int dispResWidth = dispResSprite.textWidth(String(displayResult, dispRes));
    dispResSprite.setFreeFont(&PTSans_Bold9pt7b);
    dispResSprite.drawString(" Ah", dispResWidth + 10, 8);
    dispResSprite.pushSprite(80, 198);

    /*tft.setRotation(3);
    tft.setFreeFont(&PTSans_Bold17pt7b);
    tft.fillRect(80, 198, 130, 45, tft.color565(8, 8, 8));
    float displayValue = 0;
      float displayEff = 0;
    float displayResult = displayValue * ampHours * (displayEff / 100);
    tft.setCursor(85, 223);
    tft.setTextColor(tft.color565(255, 0, 30));
    if (displayResult >= 0) {
      if (displayResult >= 10) {
        tft.print(displayResult, 4);
      } else {
        tft.print(displayResult, 5);
      }
    } else {
      tft.print("0");
    }
    tft.setFreeFont(&PTSans_Bold9pt7b);
    tft.setCursor(215, 218);
    tft.print(" Ah");*/
    tft.setRotation(0);
  }
  static unsigned long lastButtonBat = 0;
  static const unsigned long singleButtonBat = 150;
  unsigned long currentBatted = millis();
  if (currentBatted - lastButtonBat >= singleButtonBat) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      if (!batdown) {
        lastButtonBat = currentBatted;
        tft.fillScreen(TFT_BLACK);
        drawRectStat();
        drawTextStat();
        batup = true;
        stopedstat = false;
        listup = true;
        statdown = false;
        statup = false;
        menuappr = true;
        averbuttonapp = true;
        timeoverapp = true;
      }
      if (!cellbatdown) {
        batup = false;
        cellbatup = true;
        voltbatup = true;
        batdown = false;
        cellbatdown = true;
      }
    }
  }
  static unsigned long lastUpBat = 0;
  static const unsigned long singleUpBat = 150;
  unsigned long currentMillisBat = millis();
  if (currentMillisBat - lastUpBat >= singleUpBat) {
    if (digitalRead(BUTTON_UP) == LOW) {
      if (!batup || !cellbatup || !voltbatup || !effbatup) {
        lastUpBat = currentMillisBat;
        if (!batup) {
          currentBat++;
          if (currentBat > 3) {
            currentBat = 1;
          }
          changeBatColor(currentBat);
        }
        if (!cellbatup) {
          // Обработка для cellbatup
          cellIndex = (cellIndex + 1) % 10;
          String fileName = "/capacity/cell" + String(cellIndex + 1) + ".txt";
          File file = LittleFS.open(fileName, FILE_READ);
          if (!file) {
          } else {
            tft.setRotation(3);
            tft.fillRect(63, 36, 25, 20, tft.color565(8, 8, 8));
            tft.fillRect(85, 59, 135, 19, tft.color565(8, 8, 8));
            tft.fillRect(82, 81, 90, 18, tft.color565(8, 8, 8));
            tft.fillRect(82, 104, 95, 18, tft.color565(8, 8, 8));
            int y = 73;
            while (file.available()) {
              String line = file.readStringUntil('\n');
              tft.setFreeFont(&PTSans_Bold9pt7b);
              tft.setTextColor(tft.color565(210, 210, 210));
              tft.setCursor(84, y);
              tft.print(line);
              Serial.println(line);
              y += 23;
            }
            file.close();
          }
          tft.setRotation(3);
          tft.setFreeFont(&PTSans_Bold9pt7b);
          tft.fillRect(63, 36, 25, 20, tft.color565(8, 8, 8));
          tft.setCursor(63, 50);
          tft.setTextColor(tft.color565(3, 161, 252));
          if (cellIndex < 9) {
            tft.print("0");
          }
          tft.print(String(cellIndex + 1));
        }
        if (!voltbatup) {
          // Обработка для voltbatup
          displayValue += 0.1;
          if (displayValue >= 5.0) {
            displayValue = 3.0;
          }
          tft.setRotation(3);
          tft.setFreeFont(&PTSans_Bold9pt7b);
          tft.fillRect(66, 132, 40, 20, tft.color565(8, 8, 8));
          tft.setTextColor(tft.color565(232, 190, 2));
          tft.drawString((String(displayValue, 1) + "V"), 70, 132);
        }
        if (!effbatup) {
          // Обработка для voltbatup
          displayEff += 1;
          if (displayEff >= 100) {
            displayEff = 60;
          }
          tft.setRotation(3);
          tft.setFreeFont(&PTSans_Bold9pt7b);
          tft.fillRect(79, 154, 40, 20, tft.color565(8, 8, 8));
          tft.setTextColor(tft.color565(232, 190, 2));
          tft.drawString((String(displayEff, 0) + "%"), 83, 154);
        }
      }
    }
  }
  static bool rectStated = false;
  if (digitalRead(BUTTON_AVER) == LOW) {
    buttonPressStartTime = millis();
    while (digitalRead(BUTTON_AVER) == LOW) {
    }
    unsigned long buttonPressDuration = millis() - buttonPressStartTime;
    if (buttonPressDuration >= LONG_PRESS_DURATION) {
      if (!rectStated) {
        updateTimeBat = false;
        updateTimedBat = false;
        days = 0; hours = 0; minutes = 0; seconds = 0; ampHours = 0; wattHours = 0;
        tft.setRotation(4);
        tft.fillSmoothCircle(14, 15, 6, TFT_GREEN, TFT_BLACK);
      } else {
        updateTimeBat = true;
        updateTimedBat = true;
        tft.setRotation(4);
        tft.fillCircle(14, 15, 6, tft.color565(255, 0, 60));
        tft.fillSmoothCircle(14, 15, 6, tft.color565(255, 0, 60), TFT_BLACK);
        saveDataToFile();
      }
      rectStated = !rectStated;
    } else {
      switch (currentBat) {
        case 1:
          batup = true;
          cellbatup = false;
          effbatup = true;
          voltbatup = true;
          batdown = true;
          cellbatdown = false;
          statdown = true;
          break;
        case 2:
          batup = true;
          cellbatup = true;
          voltbatup = false;
          effbatup = true;
          batdown = true;
          cellbatdown = false;
          statdown = true;
          break;
        case 3:
          batup = true;
          cellbatup = true;
          voltbatup = true;
          effbatup = false;
          batdown = true;
          cellbatdown = false;
          statdown = true;
          break;
      }
    }
  }
}
void saveDataToFile() {
  String fileName = "/capacity/cell" + String(cellIndex + 1) + ".txt";
  File dataFile = LittleFS.open(fileName, "w");

  if (dataFile) {
    dataFile.print(days);
    dataFile.print(" days ");
    dataFile.print(hours);
    dataFile.print(":");
    if (minutes < 10) dataFile.print("0");
    dataFile.print(minutes % 60);
    dataFile.print(":");
    if (seconds < 10) dataFile.print("0");
    dataFile.println(seconds % 60);
    if (ampHours >= 0) {
      if (ampHours >= 10) {
        dataFile.println(ampHours, 4);
      } else {
        dataFile.println(ampHours, 5);
      }
    } else {
      dataFile.println("0");
    }
    if (wattHours >= 0) {
      if (wattHours >= 10) {
        dataFile.println(wattHours, 4);
      } else {
        dataFile.println(wattHours, 5);
      }
    } else {
      dataFile.println("0");
    }
    dataFile.close();
  } else {
  }
}
void RealTimed(unsigned long& days, unsigned long& hours, unsigned long& minutes, unsigned long& seconds) {
  if (!updateTimedBat) {
    static unsigned long startTimed = millis();
    unsigned long currentTimed = millis();
    unsigned long elapsedTimed = currentTimed - startTimed;
    seconds = elapsedTimed / 1000;
    minutes = seconds / 60;
    hours = minutes / 60;
    days = hours / 24;
  }
}
void changeBatColor(int rectangleBat) {
  selectedBat = rectangleBat;
  uint16_t selectedFillColor = tft.color565(10, 32, 64);
  uint16_t selectedBorderColor = tft.color565(19, 89, 191);
  uint16_t unselectedFillColor = tft.color565(21, 21, 21);
  uint16_t unselectedBorderColor = tft.color565(21, 21, 21);
  for (int i = 1; i <= 3; i++) {
    uint16_t fillColor = (i == rectangleBat) ? selectedFillColor : unselectedFillColor;
    uint16_t borderColor = (i == rectangleBat) ? selectedBorderColor : unselectedBorderColor;
    drawBat(i, fillColor, borderColor);
  }
}
void drawBat(int rectangleBat, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectangleBat < 1 || rectangleBat > 3)
    return;
  switch (rectangleBat) {
    case 1:
      rectX = 36; rectY = 52; rectWidth = 26; rectHeight = 59; cornerRadius = 4;
      break;
    case 2:
      rectX = 76; rectY = 52; rectWidth = 26; rectHeight = 59; cornerRadius = 4;
      break;
    case 3:
      rectX = 106; rectY = 52; rectWidth = 26; rectHeight = 59; cornerRadius = 4;
      break;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
}
