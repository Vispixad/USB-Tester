void buttonQC() {
  unsigned long lastButtonDown = 0;
  const unsigned long buttonDown = 50;
  if (digitalRead(BUTTON_DOWN) == LOW && millis() - lastButtonDown > buttonDown) {
    if (!qcdown) {
      lastButtonDown = millis();
      stopedwar = true;
      tft.fillScreen(TFT_BLACK);
      drawMenu5();
      /*averbuttonapp = true;
        menuapp = true;
        menuappr = true;
        timeoverapp = true;
        warup = false;
        wardown = false;
        menudown = true;*/
    } else {
    }
  }
}
void startQC() {
  tft.setFreeFont(&PTSans_Bold8pt7b);
  tft.setRotation(3);
  int type = QC.begin();
  switch (type) {
    case QC_NA:
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.drawString("QC 2.0->", 8, 36);
      tft.setTextColor (tft.color565(255, 0, 60));
      tft.drawString("NONE", 73, 36);
      break;
    case QC_GEN1:
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.drawString("QC 2.0->", 8, 36);
      tft.setTextColor (tft.color565(255, 0, 60));
      tft.drawString("NONE", 73, 36);
      break;
    case QC_GEN2:
      dispVoltStatus(9, 73, 50);
      dispVoltStatus(12, 100, 50);
      dispVoltStatus(20, 135, 50);
      break;
  }
}
void drawRectQC() {
  tft.setRotation(2);
  tft.fillRoundRect(0, 0, 210, 320, 4, tft.color565(8, 8, 8));
  tft.drawRoundRect(0, 0, 210, 320, 4, tft.color565(21, 21, 21));
}
void drawTextQC() {
  tft.setRotation(3);
  tft.setTextSize(1);
  uint16_t textColor1 = tft.color565(255, 255, 255);
  uint16_t textColor2 = tft.color565(50, 50, 50);
  uint16_t textColor3 = tft.color565(2, 91, 232);
  tft.setFreeFont(&PTSans_Regular9pt7b);
  tft.setTextColor(textColor1);
  tft.drawString("Detection", 8, 5);
  tft.setTextColor(textColor3);
  tft.drawString("Testing", 255, 5);
  tft.setFreeFont(&PTSans_Bold8pt7b);
  tft.setTextColor(textColor2);
  tft.drawString("QC 2.0->", 8, 36);
  tft.setTextColor(textColor2);
  tft.drawString("QC 3.0->", 8, 56);
  tft.setTextColor(textColor2);
  tft.drawString("BC 1.2->", 8, 76);
  tft.setRotation(0);
}

void workQC() {
  tft.setFreeFont(&PTSans_Bold8pt7b);
  QC.setMode(QC_VAR);
  if (!voltageReadFlag) {
    QC.set(-16400);
    delay(250);
    float busvoltage3 = 0;
    tft.setRotation(3);
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.drawString("QC 3.0->", 8, 56);
    busvoltage3 = ina3221.getBusVoltage_V(OUTPUT_CHANNEL);
    if (busvoltage3 >= 3.4 && busvoltage3 <= 4.5) {
      QC.set(+20000);
      delay(200);
      busvoltage3 = ina3221.getBusVoltage_V(OUTPUT_CHANNEL);
      tft.setTextColor(tft.color565(2, 91, 232));
      tft.drawString((String(busvoltage3, 2) + "V MAX"), 73, 56);
      voltageReadFlag = true;
    } else {
      tft.setTextColor(tft.color565(255, 0, 60));
      tft.drawString("NONE", 73, 56);
      voltageReadFlag = true;
    }
  }
  if (!dataReadFlag) {
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.drawString("BC 1.2->", 8, 76);
    delay(100);
    // Передача цифрового сигнала и проверка на возврат на другой пин
    digitalWrite(digitalPinA0, HIGH); // передаем цифровой сигнал на A0
    delay(10); // подождем, чтобы сигнал мог вернуться
    if (digitalRead(digitalPinA1) == HIGH) {
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.drawString("DCP 1.5A", 75, 76);
    } else {
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.drawString("SDP 500mA", 75, 76);
    }
    delay(50);
    digitalWrite(digitalPinA0, LOW);

    // Проверка напряжения на д-
    int sensorValueA1 = analogRead(digitalPinA1);
    float voltageA1 = sensorValueA1 * (3.3 / 4095.0);

    if (voltageA1 >= 0.5 && voltageA1 <= 0.7) {
      tft.setTextColor(tft.color565(255, 255, 255));
      tft.drawString("CDP 1.5A", 75, 76);
    }
    dataReadFlag = true;
  }
  tft.setRotation(2);
  tft.fillRect(255, 3, 65, 25, tft.color565(0, 0, 0));
  tft.setRotation(3);
  tft.setCursor(265, 19);
  tft.setTextColor(tft.color565(0, 222, 89));
  if (voltageReadFlag) {
    tft.setFreeFont(&PTSans_Regular9pt7b);
    tft.print("Finish");
  } else {
    tft.print("Testing");
  }
}

void dispVoltStatus(int targetVoltage, int xPos, int yPos) {
  tft.setFreeFont(&PTSans_Bold8pt7b);
  tft.setRotation(3);
  tft.setTextColor(tft.color565(255, 255, 255));
  tft.drawString("QC 2.0->", 8, 36);
  QC.setMode(QC_VAR);
  QC.set(targetVoltage * 1000);
  delay(180);

  float busvoltage3 = 0;
  busvoltage3 = ina3221.getBusVoltage_V(OUTPUT_CHANNEL);
  tft.setCursor(xPos, yPos);

  if ((busvoltage3 >= targetVoltage - 1) && (busvoltage3 <= targetVoltage + 1)) {
    tft.setTextColor (tft.color565(2, 91, 232));
  } else {
    tft.setTextColor (tft.color565(255, 0, 60));
  }
  tft.print(String(targetVoltage) + "V");
}
