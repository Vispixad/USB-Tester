int menubuttonStateSet = 0;
String intervalText = "";
int lastButtonmenu = 0;
int currentsys = 0;
int currentgen = 0;
int currentrec = 0;
int currenttrig = 0;
int currentgiro = 0;
int currentset = 0;
int selectRectangleSet = 1;
int selectRectangleSetSys = 0;
int selectRectangleSetGen = 0;
int selectRectangleSetRec = 0;
int selectRectangleSetTrig = 0;
int selectRectangleSetGiro = 0;
int selectRectangleSetting = 0;
void drawSetting() {
  tft.setRotation(2);
  tft.fillSmoothRoundRect(32, 243, 25, 70, 5, tft.color565(10, 32, 64), TFT_BLACK);
  tft.drawSmoothRoundRect(32, 243, 6, 6, 25, 70, tft.color565(30, 93, 186), tft.color565(10, 32, 64));
  tft.fillRoundRect(70, 3, 142, 78, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(70, 3, 142, 78, 4, tft.color565(26, 26, 26));
}
void drawTextSetting() {
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  tft.setTextColor(textColor1);
  tft.drawString("< Setting", 4, 5);
  tft.setRotation(0);
}
void Setting() {
  static unsigned long lastUpSetting = 0;
  static const unsigned long singleButtonSetting = 100;
  unsigned long currentMillisSet = millis();
  if (currentMillisSet - lastUpSetting >= singleButtonSetting) {
    if (digitalRead(BUTTON_DOWN) == LOW) {
      if (!setdown) {
        lastUpSetting = currentMillisSet;
        tft.fillScreen(TFT_BLACK);
        drawMenu5();
        menudown = false;
      }
      if (!presetdown) {
        lastUpSetting = currentMillisSet;
        settup = false;
        setsys = true;
        setgen = true;
        setrec = true;
        settrig = true;
        setgiro = true;
        stopset = false;
        presetdown = true;
      }
      if (!presetdownsys) {
        lastUpSetting = currentMillisSet;
        drawFifthMenu();
        updatedevinfo = true;
        settup = true;
        setsys = false;
        setgen = true;
        setrec = true;
        settrig = true;
        setgiro = true;
      }
      if (!predownlight) {
        lastUpSetting = currentMillisSet;
        setgen = false;
        setgenlight = true;
        setgenlevel = true;
        stopsetgen = false;
        stopsyslight = true;
        stopsyslevel = true;
        predownlight = true;
        presetdown = false;
      }
    }
  }
  static unsigned long lastButtonUp = 0;
  static const unsigned long singleButtonDelay = 200;
  unsigned long currentMillisSetUp = millis();
  if (currentMillisSetUp - lastButtonUp >= singleButtonDelay) {
    if (digitalRead(BUTTON_UP) == LOW) {
      // Обработка для меню
      if (!settup) {
        currentset++;
        if (currentset > 5) {
          currentset = 1;
        }
        RectangleSetting(currentset);
        changeMenuItem(currentset);
      }
      // Обработка для подменю (система)
      if (!setsys) {
        currentsys++;
        if (currentsys > 5) {
          currentsys = 1;
        }
        RectangleSetSys(currentsys);
      }
      // Обработка для подменю (главные)
      if (!setgen) {
        currentgen++;
        if (currentgen > 4) {
          currentgen = 1;
        }
        RectangleSetGen(currentgen);
      }
      if (!setrec) {
        currentrec++;
        if (currentrec > 5) {
          currentrec = 1;
        }
        RectangleSetRec(currentrec);
      }
      if (!settrig) {
        currenttrig++;
        if (currenttrig > 5) {
          currenttrig = 1;
        }
        RectangleSetTrig(currenttrig);
      }
      if (!setgiro) {
        currentgiro++;
        if (currentgiro > 5) {
          currentgiro = 1;
        }
        RectangleSetGiro(currentgiro);
      }
      if (!setgenlight) {
        if (brightnessLevel < 1023) { // Проверка на максимальную яркость
          brightnessLevel += 51; // Увеличение яркости на примерно 5%
          if (brightnessLevel > 1023) {
            brightnessLevel = 1023; // Ограничение яркости максимальным значением
          }
          ledcWrite(0, brightnessLevel); // Установка нового уровня яркости
        }
      }
      if (!setgenlevel) {
        if (standbyInterval < 30) {  // Проверка на максимальный интервал
          if (standbyInterval == 0) {
            standbyInterval = 1;  // Устанавливаем 1 минуту, если был "OFF"
          } else {
            standbyInterval += 1;  // Увеличение интервала на 1 минуту
          }
          standbyModeEnabled = true;  // Включение режима ожидания
          lastActiveTime = millis();  // Обновление времени последней активности
          tft.setRotation(3);
          tft.setFreeFont(&PTSans_Regular9pt7b);
          tft.setTextSize(1);
          tft.setTextColor(tft.color565(255, 255, 255));
          tft.fillRect(255, 63, 60, 19, tft.color565(10, 32, 64));
          String intervalText;
          if (standbyModeEnabled) {
            intervalText = String(standbyInterval) + " min";
          } else {
            intervalText = "OFF";
          }
          tft.drawString(intervalText, 257, 62);
        }
      }

      lastButtonUp = currentMillisSetUp;
    }
  }
  static unsigned long lastButtonPress = 0;
  static const unsigned long buttonPressDelay = 250;
  unsigned long currentMillisSetAver = millis();
  if (digitalRead(BUTTON_AVER) == LOW) {
    if (currentMillisSetAver - lastButtonPress >= buttonPressDelay) {
      if (!stopset) {
        switch (currentset) {
          case 1:
            settup = true;
            setsys = true;
            setgen = false;
            setrec = true;
            settrig = true;
            setgiro = true;
            stopset = true;
            setdown = true;
            stopsetgen = false;
            presetdown = false;
            menudown = true;
            break;
          case 2:
            settup = true;
            setsys = true;
            setgen = true;
            setrec = false;
            settrig = true;
            setgiro = true;
            setdown = true;
            presetdown = false;
            menudown = true;
            break;
          case 3:
            settup = true;
            setsys = true;
            setgen = true;
            setrec = true;
            settrig = false;
            setgiro = true;
            setdown = true;
            presetdown = false;
            menudown = true;
            break;
          case 4:
            settup = true;
            setsys = true;
            setgen = true;
            setrec = true;
            settrig = true;
            setgiro = false;
            setdown = true;
            presetdown = false;
            menudown = true;
            break;
          case 5:
            settup = true;
            setsys = false;
            setgen = true;
            setrec = true;
            settrig = true;
            setgiro = true;
            stopsetsys = false;
            stopset = true;
            setdown = true;
            presetdown = false;
            menudown = true;
            tft.setRotation(2);
            tft.fillRoundRect(148, 86, 90, 113, 4, tft.color565(10, 32, 64));
            tft.drawRoundRect(148, 86, 90, 113, 4, tft.color565(30, 93, 186));
            tft.setRotation(3);
            tft.setTextColor(tft.color565(255, 255, 255));
            tft.setFreeFont(&PTSans_Regular12pt7b);
            tft.drawString("Sweb", 97, 35);
            tft.setTextColor(tft.color565(0, 85, 255));
            tft.setFreeFont(&PTSans_Bold14pt7b);
            tft.drawString("OS", 153, 35);
            tft.setFreeFont(&PTSans_Regular9pt7b);
            tft.setTextColor(tft.color565(200, 200, 200));
            tft.drawString("1.0.BETA", 107, 55);
            break;
        }
      }
      //обработка кнопки для поднастроек в настройках системы
      if (!stopsetsys) {
        switch (currentsys) {
          case 1:
            tft.setRotation(2);
            tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
            drawSetOTAUpdate();
            setsys = true;
            presetdown = true;
            presetdownsys = false;
            break;
          case 2:
            tft.setRotation(2);
            tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
            setsys = true;
            presetdown = true;
            presetdownsys = false;
            break;
          case 3:
            tft.setRotation(2);
            tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
            drawSetBackup();
            stopsetbackup = false;
            stopsetsys = true;
            setsys = true;
            presetdown = true;
            presetdownsys = false;
            break;
          case 4:
            tft.setRotation(2);
            tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
            drawSetDevInfo();
            drawSetDevInfo();
            updatedevinfo = false;
            setsys = true;
            presetdown = true;
            presetdownsys = false;
            break;
          case 5:
            tft.setRotation(2);
            tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
            drawSetFullReset();
            setsys = true;
            presetdown = true;
            presetdownsys = false;
            break;
        }
      }
      //обработка кнопки для поднастроек в главных настройках (GENERAL)
      if (!stopsetgen) {
        switch (currentgen) {
          case 1:
            setgen = true;
            setgenlight = false;
            stopsetgen = true;
            stopsyslight = false;
            presetdown = true;
            predownlight = false;
            break;
          case 2:
            setgen = true;
            setgenlevel = false;
            stopsetgen = true;
            stopsyslevel = false;
            presetdown = true;
            predownlight = false;
            break;
          case 3:

            break;
          case 4:

            break;
        }
      }
      if (!stopsyslight) {
        if (brightnessLevel > 0) {
          brightnessLevel -= 51; // Уменьшение яркости на примерно 5%
          if (brightnessLevel < 0) {
            brightnessLevel = 0;
          }
          ledcWrite(0, brightnessLevel);
        }
      }
      if (!stopsyslevel) {
        if (standbyInterval > 1) {
          standbyInterval -= 1;  // Уменьшение интервала на 1 минуту
        } else {
          standbyModeEnabled = false;
        }
        lastActiveTime = millis();
        tft.setRotation(3);
        tft.setFreeFont(&PTSans_Regular9pt7b);
        tft.setTextSize(1);
        tft.setTextColor(tft.color565(255, 255, 255));
        tft.fillRect(255, 63, 60, 19, tft.color565(10, 32, 64));
        String intervalText;
        if (standbyModeEnabled) {
          intervalText = String(standbyInterval) + " min";
        } else {
          intervalText = "OFF";
        }
        tft.drawString(intervalText, 257, 62);
      }
      if (!stopsetbackup) {
        /*tft.setRotation(2);
          tft.fillRoundRect(30, 86, 170, 230, 4, tft.color565(8, 8, 8));
          tft.drawRoundRect(30, 86, 170, 230, 4, tft.color565(26, 26, 26));
          tft.setRotation(2);
          tft.fillRoundRect(88, 110, 107, 130, 7, tft.color565(8, 8, 8));
          tft.drawRoundRect(88, 110, 107, 130, 7, tft.color565(23, 23, 23));
          tft.fillRoundRect(55, 110, 30, 130, 7, tft.color565(82, 24, 24));

          tft.setRotation(3);
          tft.setFreeFont(&PTSans_Regular10pt7b);
          tft.setTextSize(1);
          uint16_t textColor1 = tft.color565(255, 255, 255);

          tft.setCursor(127, 67);
          tft.setTextColor(textColor1);
          tft.print("High Temp");

          tft.setFreeFont(&PTSans_Regular9pt7b);
          tft.setCursor(117, 90);
          tft.setTextColor(textColor1);
          tft.print("Your device is");

          tft.setCursor(117, 108);
          tft.setTextColor(textColor1);
          tft.print("hot, we advise");

          tft.setCursor(117, 126);
          tft.setTextColor(textColor1);
          tft.print("you to cool it");

          tft.setCursor(117, 144);
          tft.setTextColor(textColor1);
          tft.print("down");*/
      }
      lastButtonPress = currentMillisSetAver;
    }
  }
}
//------------------------------------------ПУНКТЫ НАСТРОЕК---------------------------------------------
void RectangleSetting(int rectangleSet) {
  selectRectangleSetting = rectangleSet;
  for (int i = 1; i <= 5; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleSet) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleSet) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectSet(i, fillColor, borderColor);
  }
}
void drawRectSet(int rectangleSet, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX = 32 + (rectangleSet - 1) * 27; // Вычисляем rectX на основе rectangleSet
  int16_t rectY = 243;
  int16_t rectWidth = 25;
  int16_t rectHeight = 70;
  int16_t cornerRadius = 4;
  if (rectangleSet < 1 || rectangleSet > 5)
    return;

  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);
  tft.setTextColor(textColor1);
  tft.drawString("< Setting", 4, 5);
  tft.setTextColor(textColor1);
  tft.drawString("General", 11, 36);
  tft.setTextColor(textColor1);
  tft.drawString("Record", 11, 63);
  tft.setTextColor(textColor1);
  tft.drawString("Trigger", 11, 89);
  tft.setTextColor(textColor1);
  tft.drawString("GiroAx", 11, 117);
  tft.setTextColor(textColor1);
  tft.drawString("System", 11, 143);
  tft.setRotation(0);
}
//----------------------------------------ПУНКТЫ НАСТРОЕК СИСТЕМЫ-------------------------------------------
void RectangleSetSys(int rectangleSetSys) {
  selectRectangleSetSys = rectangleSetSys;
  for (int i = 1; i <= 5; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleSetSys) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleSetSys) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectSetSys(i, fillColor, borderColor);
  }
}
void drawRectSetSys(int rectangleSetSys, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectangleSetSys < 1 || rectangleSetSys > 5)
    return;
  tft.setRotation(2);
  switch (rectangleSetSys) {
    case 1:
      rectX = 148; rectY = 86; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 2:
      rectX = 148; rectY = 203; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 3:
      rectX = 82; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 4:
      rectX = 49; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 5:
      rectX = 16; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular12pt7b);
  tft.drawString("Sweb", 97, 35);
  tft.setTextColor(textColor2);
  tft.setFreeFont(&PTSans_Bold14pt7b);
  tft.drawString("OS", 153, 35);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextColor(textColor3);
  tft.drawString("1.0.BETA", 107, 55);

  // Получаем информацию о доступной и общей памяти
  size_t freeMemory = ESP.getFreeHeap() / 1024;
  size_t totalMemory = ESP.getHeapSize() / 1024;

  // Конвертируем память из килобайт в мегабайты
  float freeMemoryMB = (float)freeMemory / 1024;
  float totalMemoryMB = (float)totalMemory / 1024;

  /*tft.setTextColor(textColor1);
    tft.setFreeFont(&PTSans_Regular12pt7b);
    tft.drawString((freeMemoryMB), 240, 31);
    tft.setTextColor(textColor2);
    tft.setFreeFont(&PTSans_Bold14pt7b);
    tft.drawString((totalMemoryMB), 240, 56);*/
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextColor(textColor1);
  tft.drawString("Software", 92, 100);
  tft.setTextColor(textColor1);
  tft.drawString("V1.0 (Beta)", 227, 100);
  tft.setTextColor(textColor1);
  tft.drawString("Backup and recovery", 92, 133);
  tft.setTextColor(textColor1);
  tft.drawString(">", 295, 134);
  tft.setTextColor(textColor1);
  tft.drawString("Device Information", 92, 166);
  tft.setTextColor(textColor1);
  tft.drawString(">", 295, 167);
  tft.setTextColor(textColor1);
  tft.drawString("Full reset", 92, 199);
  tft.setTextColor(textColor1);
  tft.drawString(">", 295, 200);
  tft.setRotation(0);
}
//------------------------------------ПУНКТЫ ГЛАВНЫХ НАСТРОЕК-----------------------------------------
void RectangleSetGen(int rectangleSetGen) {
  selectRectangleSetGen = rectangleSetGen;
  for (int i = 1; i <= 4; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleSetGen) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleSetGen) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectSetGen(i, fillColor, borderColor);
  }
}
void drawRectSetGen(int rectangleSetGen, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectangleSetGen < 1 || rectangleSetGen > 4)
    return;
  tft.setRotation(2);
  switch (rectangleSetGen) {
    case 1:
      rectX = 185; rectY = 86; rectWidth = 52; rectHeight = 233; cornerRadius = 4;
      break;
    case 2:
      rectX = 130; rectY = 86; rectWidth = 52; rectHeight = 233; cornerRadius = 4;
      break;
    case 3:
      rectX = 75; rectY = 86; rectWidth = 52; rectHeight = 233; cornerRadius = 4;
      break;
    case 4:
      rectX = 20; rectY = 86; rectWidth = 52; rectHeight = 233; cornerRadius = 4;
      break;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  tft.setTextColor(textColor1);
  tft.drawString("Display bright", 92, 8);
  tft.setTextColor(textColor1);
  tft.drawString("100", 273, 8);
  tft.setTextColor(textColor1);
  tft.drawString("Standby time", 92, 61);
  tft.setTextColor(textColor1);
  tft.drawString(intervalText, 270, 61);
  tft.setTextColor(textColor1);
  tft.drawString("Rotate", 92, 115);
  tft.setTextColor(textColor1);
  tft.drawString("ON", 270, 115);
  tft.setRotation(0);
}
//------------------------------------ПУНКТЫ НАСТРОЕК (Запись)--------------------------------------
void RectangleSetRec(int rectangleSetRec) {
  selectRectangleSetRec = rectangleSetRec;
  for (int i = 1; i <= 5; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleSetRec) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleSetRec) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectSetRec(i, fillColor, borderColor);
  }
}
void drawRectSetRec(int rectangleSetRec, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectangleSetRec < 1 || rectangleSetRec > 5)
    return;
  tft.setRotation(2);
  switch (rectangleSetRec) {
    case 1:
      rectX = 148; rectY = 86; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 2:
      rectX = 148; rectY = 203; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 3:
      rectX = 82; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 4:
      rectX = 49; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 5:
      rectX = 16; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
}
//------------------------------------ПУНКТЫ НАСТРОЕК (ТРИГГЕР)--------------------------------------
void RectangleSetTrig(int rectangleSetTrig) {
  selectRectangleSetTrig = rectangleSetTrig;
  for (int i = 1; i <= 5; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleSetTrig) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleSetTrig) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectSetTrig(i, fillColor, borderColor);
  }
}
void drawRectSetTrig(int rectangleSetTrig, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectangleSetTrig < 1 || rectangleSetTrig > 5)
    return;
  tft.setRotation(2);
  switch (rectangleSetTrig) {
    case 1:
      rectX = 148; rectY = 86; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 2:
      rectX = 148; rectY = 203; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 3:
      rectX = 82; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 4:
      rectX = 49; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 5:
      rectX = 16; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
}
//------------------------------------ПУНКТЫ НАСТРОЕК (ГИРОСКОП)--------------------------------------
void RectangleSetGiro(int rectangleSetGiro) {
  selectRectangleSetGiro = rectangleSetGiro;
  for (int i = 1; i <= 5; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleSetGiro) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleSetGiro) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectSetGiro(i, fillColor, borderColor);
  }
}
void drawRectSetGiro(int rectangleSetGiro, uint16_t fillColor, uint16_t borderColor) {
  int16_t rectX, rectY, rectWidth, rectHeight, cornerRadius;
  if (rectangleSetGiro < 1 || rectangleSetGiro > 5)
    return;
  tft.setRotation(2);
  switch (rectangleSetGiro) {
    case 1:
      rectX = 148; rectY = 86; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 2:
      rectX = 148; rectY = 203; rectWidth = 90; rectHeight = 113; cornerRadius = 4;
      break;
    case 3:
      rectX = 82; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 4:
      rectX = 49; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
    case 5:
      rectX = 16; rectY = 86; rectWidth = 30; rectHeight = 230; cornerRadius = 4;
      break;
  }
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
}
//--------------------------РЕЗЕРВИРОВАНИЕ И ВОССТАНОВЛЕНИЕ-----------------------------
void drawSetBackup() {
  tft.setRotation(2);
  tft.fillRoundRect(30, 86, 170, 230, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(30, 86, 170, 230, 4, tft.color565(26, 26, 26));
  /*tft.fillRoundRect(137, 86, 30, 230, 4, tft.color565(8, 8, 8));
    tft.fillRoundRect(104, 86, 30, 230, 4, tft.color565(8, 8, 8));
    tft.fillRoundRect(71, 86, 30, 230, 4, tft.color565(8, 8, 8));
    tft.fillRoundRect(38, 86, 30, 230, 4, tft.color565(8, 8, 8));*/
  tft.setRotation(3);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);
  uint16_t textColor4 = tft.color565(255, 255, 255);
  tft.setCursor(94, 27);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular11pt7b);
  tft.print("< Backup and re...");

  /*tft.setFreeFont(&PTSans_Regular9pt7b);
    tft.setCursor(92, 59);
    tft.setTextColor(textColor1);
    tft.print("SDK:");

    tft.setCursor(220, 59);
    tft.setTextColor(textColor1);
    tft.print(ESP.getSdkVersion());

    tft.setCursor(92, 92);
    tft.setTextColor(textColor1);
    tft.print("Temperature:");

    tft.setCursor(92, 125);
    tft.setTextColor(textColor1);
    tft.print("Clock frequency:");

    tft.setCursor(241, 126);
    tft.setTextColor(textColor1);
    tft.print(ESP.getCpuFreqMHz());
    tft.print(" MHz");

    tft.setCursor(92, 158);
    tft.setTextColor(textColor1);
    tft.print("Opertime:");*/
  tft.setRotation(0);
  // Проверяем наличие файлов в папке /backup
  File dir = LittleFS.open("/backup");
  File file = dir.openNextFile();
  if (!file) {
    Serial.println("В папке /backup нет файлов");
    tft.setRotation(3);
    tft.setFreeFont(&PTSans_Bold9pt7b);
    tft.setCursor(140, 82);
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.print("No files found");
    tft.setFreeFont(&PTSans_Regular9pt7b);
    tft.setCursor(115, 107);
    tft.print("There are no backups");
    tft.setCursor(115, 132);
    tft.print("at the moment, click");
    tft.setCursor(115, 157);
    tft.print("the middle button to");
    tft.setCursor(115, 182);
    tft.print("create one");
  } else {
    // Если хотя бы один файл найден, выполнить другое действие
    Serial.println("В папке /backup есть файлы");
    // Ваш код для выполнения, если в папке есть файлы
    file.close();
  }
  dir.close();
}
//-----------------------------ИНФОРМАЦИЯ ОБ УСТРОЙСТВЕ-------------------------------------
void drawSetDevInfo() {
  tft.setRotation(2);
  tft.fillRoundRect(170, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(137, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(104, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(71, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(38, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.setRotation(3);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);
  uint16_t textColor4 = tft.color565(255, 255, 255);
  tft.setCursor(94, 27);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular11pt7b);
  tft.print("< Device Inform...");

  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(92, 60);
  tft.setTextColor(textColor1);
  tft.print("SDK:");

  tft.setCursor(220, 60);
  tft.setTextColor(textColor1);
  tft.print(ESP.getSdkVersion());

  tft.setCursor(92, 92);
  tft.setTextColor(textColor1);
  tft.print("Temperature:");

  tft.setCursor(92, 125);
  tft.setTextColor(textColor1);
  tft.print("Clock frequency:");

  tft.setCursor(241, 126);
  tft.setTextColor(textColor1);
  tft.print(ESP.getCpuFreqMHz());
  tft.print(" MHz");

  tft.setCursor(92, 158);
  tft.setTextColor(textColor1);
  tft.print("Opertime:");

  tft.setCursor(92, 191);
  tft.setTextColor(textColor1);
  tft.print("Number of starts:");

  /*tft.setCursor(270, 191);
    tft.setTextColor(textColor1);
    tft.print(newCount);
    tft.setRotation(0);*/
}
//------------------------------ОБНОВЛЕНИЕ УСТРОЙСТВА---------------------------------------------
void drawSetOTAUpdate() {
  tft.setRotation(2);
  tft.fillRoundRect(54, 86, 183, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(21, 86, 30, 230, 4, tft.color565(0, 82, 235));
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);
  uint16_t textColor4 = tft.color565(255, 255, 255);

  tft.setCursor(94, 27);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular11pt7b);
  tft.print("< OTA Update");

  tft.setCursor(150, 95);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular14pt7b);
  tft.print("Sweb");

  tft.setCursor(213, 95);
  tft.setTextColor(textColor2);
  tft.setFreeFont(&PTSans_Bold16pt7b);
  tft.print("OS");

  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(160, 117);
  tft.setTextColor(textColor3);
  tft.print("1.0.BETA");

  tft.setCursor(140, 209);
  tft.setTextColor(textColor4);
  tft.setFreeFont(&PTSans_Bold9pt7b);
  tft.print("START UPDATE");
  tft.setRotation(0);
}
//------------------------------ПОЛНЫЙ СБРОС УСТРОЙСТВА---------------------------------------------
void drawSetFullReset() {
  tft.setRotation(2);
  tft.fillRoundRect(54, 86, 183, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(21, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);
  uint16_t textColor4 = tft.color565(255, 0, 60);

  tft.setCursor(94, 27);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular11pt7b);
  tft.print("< Delete all data?");

  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(92, 56);
  tft.setTextColor(textColor3);
  tft.print("Cells with data");

  tft.setCursor(92, 85);
  tft.setTextColor(textColor3);
  tft.print("Curve graph data");

  tft.setCursor(92, 114);
  tft.setTextColor(textColor3);
  tft.print("User Settings");

  tft.setCursor(92, 143);
  tft.setTextColor(textColor3);
  tft.print("Saved screenshots");

  tft.setCursor(92, 172);
  tft.setTextColor(textColor3);
  tft.print("Other system data");

  tft.setCursor(150, 209);
  tft.setTextColor(textColor4);
  tft.setFreeFont(&PTSans_Bold9pt7b);
  tft.print("DELETE ALL");
  tft.setRotation(0);
}
//------------------------------------РИСОВАНИЕ ПОДПУНКТОВ-----------------------------------------------
void changeMenuItem(int menuItemNumber) {
  selectRectangleSet = menuItemNumber;
  switch (menuItemNumber) {
    case 1:
      drawDefaultMenu();
      break;
    case 2:
      drawSecondMenu();
      break;
    case 3:
      drawThirdMenu();
      break;
    case 4:
      drawFourthMenu();
      break;
    case 5:
      drawFifthMenu();
      break;
    default:
      break;
  }
}
void drawDefaultMenu() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
  tft.fillRoundRect(185, 86, 52, 233, 4, tft.color565(10, 32, 64));
  tft.fillRoundRect(130, 86, 52, 233, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(75, 86, 52, 233, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(20, 86, 52, 233, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(95, 240, 25, 50, 4, tft.color565(92, 92, 92));

  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  uint16_t textColor1 = tft.color565(255, 255, 255);

  tft.setCursor(92, 22);
  tft.setTextColor(textColor1);
  tft.print("Display bright");

  tft.setCursor(273, 22);
  tft.setTextColor(textColor1);
  tft.print("100");

  tft.setCursor(92, 75);
  tft.setTextColor(textColor1);
  tft.print("Standby time");

  tft.setCursor(270, 75);
  tft.setTextColor(textColor1);
  tft.print(intervalText);

  tft.setCursor(92, 129);
  tft.setTextColor(textColor1);
  tft.print("Rotate");

  tft.setCursor(270, 129);
  tft.setTextColor(textColor1);
  tft.print("ON");

  tft.setRotation(0);
}
void drawSecondMenu() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(18, 201, 67);
  uint16_t textColor3 = tft.color565(200, 200, 200);

  tft.setCursor(97, 110);
  tft.setTextColor(textColor1);
  tft.print("there is nothing here,");

  tft.setCursor(153, 140);
  tft.setTextColor(textColor2);
  tft.print("this is the 2 menu");
}

void drawThirdMenu() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(18, 201, 67);
  uint16_t textColor3 = tft.color565(200, 200, 200);

  tft.setCursor(97, 110);
  tft.setTextColor(textColor1);
  tft.print("there is nothing here,");

  tft.setCursor(153, 140);
  tft.setTextColor(textColor2);
  tft.print("this is the 3 menu");
}

void drawFourthMenu() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(18, 201, 67);
  uint16_t textColor3 = tft.color565(200, 200, 200);

  tft.setCursor(97, 110);
  tft.setTextColor(textColor1);
  tft.print("there is nothing here,");

  tft.setCursor(153, 140);
  tft.setTextColor(textColor2);
  tft.print("this is the 4 menu");
}

void drawFifthMenu() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 83, 240, 240, 0, tft.color565(0, 0, 0));
  tft.fillRoundRect(148, 86, 90, 113, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(148, 203, 90, 113, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(115, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(82, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(49, 86, 30, 230, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(16, 86, 30, 230, 4, tft.color565(8, 8, 8));

  tft.setRotation(3);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextSize(1);

  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(0, 85, 255);
  uint16_t textColor3 = tft.color565(200, 200, 200);

  tft.setCursor(97, 45);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular12pt7b);
  tft.print("Sweb");

  tft.setCursor(153, 45);
  tft.setTextColor(textColor2);
  tft.setFreeFont(&PTSans_Bold14pt7b);
  tft.print("OS");

  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(107, 67);
  tft.setTextColor(textColor3);
  tft.print("1.0.BETA");

  // Получаем информацию о доступной и общей памяти
  size_t freeMemory = ESP.getFreeHeap() / 1024;
  size_t totalMemory = ESP.getHeapSize() / 1024;

  // Конвертируем память из килобайт в мегабайты
  float freeMemoryMB = (float)freeMemory / 1024;
  float totalMemoryMB = (float)totalMemory / 1024;

  tft.setCursor(240, 45);
  tft.setTextColor(textColor1);
  tft.setFreeFont(&PTSans_Regular12pt7b);
  tft.print(freeMemoryMB);

  tft.setCursor(240, 70);
  tft.setTextColor(textColor2);
  tft.setFreeFont(&PTSans_Bold14pt7b);
  tft.print(totalMemoryMB);

  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setCursor(92, 114);
  tft.setTextColor(textColor1);
  tft.print("Software");

  tft.setCursor(227, 114);
  tft.setTextColor(textColor1);
  tft.print("V1.0 (Beta)");

  tft.setCursor(92, 147);
  tft.setTextColor(textColor1);
  tft.print("Backup and recovery");

  tft.setCursor(295, 148);
  tft.setTextColor(textColor1);
  tft.print(">");

  tft.setCursor(92, 180);
  tft.setTextColor(textColor1);
  tft.print("Device Information");

  tft.setCursor(295, 181);
  tft.setTextColor(textColor1);
  tft.print(">");

  tft.setCursor(92, 213);
  tft.setTextColor(textColor1);
  tft.print("Full reset");

  tft.setCursor(295, 214);
  tft.setTextColor(textColor1);
  tft.print(">");

  tft.setRotation(0);
}
