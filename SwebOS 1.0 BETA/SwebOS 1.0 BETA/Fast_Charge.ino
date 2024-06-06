void drawFast() {
  tft.setRotation(2);
  tft.fillRoundRect(158, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(102, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(46, 0, 52, 320, 4, tft.color565(8, 8, 8));
  tft.fillRoundRect(-10, 0, 52, 320, 4, tft.color565(8, 8, 8));
}
void drawTextFast() {
  tft.setRotation(3);
  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("Fast Charge", 104, 7);
  tft.drawString("Automatic Detection", 8, 38);
  tft.drawString("PD Trigger", 8, 94);
  tft.drawString("QC 2.0", 8, 148);
  tft.drawString("QC 3.0", 8, 206);

  tft.setTextColor(tft.color565(2, 91, 232), tft.color565(0, 43, 112));
  tft.drawString("Checking for different protocols", 8, 59);
  tft.drawString("Power Delivery 2.0 and 3.0", 8, 115);
  tft.drawString("Quick Charge: 9V 12V 20V", 8, 171);
  tft.drawString("Quick Charge: 3.4 - 20V", 8, 229);
  tft.setRotation(0);
}
void drawChoiceFast() {
  unsigned long lastButtonUpFast = 0;
  unsigned long singleButtonFast = 100;
  delay(singleButtonFast);
  if (digitalRead(BUTTON_UP) == LOW) {
    if (!menufast) {
      buttonFast++;
      if (buttonFast > 4) {
        buttonFast = 1;
      }
      changeFastColor(buttonFast);
    }
  }
  unsigned long lastButtonDown = 0;
  const unsigned long buttonDown = 80;
  if (digitalRead(BUTTON_DOWN) == LOW && millis() - lastButtonDown > buttonDown) {
    if (!fastdown) {
      lastButtonDown = millis();
      tft.fillScreen(TFT_BLACK);
      drawMenu5();
      stopedfast = true;
      menufast = true;
    } else {
    }
  }
  if (digitalRead(BUTTON_AVER) == LOW) {
    if (!stopedfast) {
      switch (buttonFast) {
        case 1:
          tft.fillScreen(TFT_BLACK);
          drawRectQC();
          drawTextQC();
          buttonQC();
          startQC();
          workQC();
          stopedfast = true;
          menufast = true;
          fastdown = true;
          break;
        case 2:
          tft.fillScreen(TFT_BLACK);
          PDdown = false;
          stopedPD = false;
          stopedfast = true;
          menufast = true;
          fastdown = true;
          drawRectPD();
          drawTextPD();
          triggedPD();
          break;
        case 3:
        tft.fillScreen(TFT_BLACK);
          QC2down = false;
          stopedQC2 = false;
          stopedfast = true;
          menufast = true;
          fastdown = true;
          drawTriangleQC(26, 10, 0);
          drawRectQC2();
          drawTextQC2();
          triggedQC2();
          break;
        case 4:
          tft.fillScreen(TFT_BLACK);
          QC3down = false;
          stopedQC3 = false;
          stopedfast = true;
          menufast = true;
          fastdown = true;
          tft.fillScreen(TFT_BLACK);
          drawRectQC3();
          drawTextQC3();
          triggedQC3();
          break;
      }
    } else {
    }
  }
}
void changeFastColor(int rectangleFast) {
  selectedRectangleFast = rectangleFast;
  for (int i = 1; i <= 4; i++) { // Очистить предыдущий выбранный прямоугольник
    uint16_t fillColor = (i == rectangleFast) ? tft.color565(10, 32, 64) : tft.color565(8, 8, 8);
    uint16_t borderColor = (i == rectangleFast) ? tft.color565(30, 93, 186) : tft.color565(8, 8, 8);
    drawRectangleFast(i, fillColor, borderColor);
  }
}
void drawRectangleFast(int rectangleFast, uint16_t fillColor, uint16_t borderColor) {
  tft.setRotation(0);
  int16_t rectX = 30 + (rectangleFast - 1) * 56;
  int16_t rectY = 0;
  int16_t rectWidth = 52;
  int16_t rectHeight = 320;
  int16_t cornerRadius = 4;
  if (rectangleFast < 1 || rectangleFast > 4)
    return;
  tft.fillRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, fillColor);
  tft.drawRoundRect(rectX, rectY, rectWidth, rectHeight, cornerRadius, borderColor);
  tft.setRotation(3);
  tft.loadFont(PTSans_Regular18);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
  tft.drawString("Automatic Detection", 8, 38);
  tft.drawString("PD Trigger", 8, 94);
  tft.drawString("QC 2.0", 8, 148);
  tft.drawString("QC 3.0", 8, 206);

  tft.setTextColor(tft.color565(2, 91, 232), tft.color565(0, 43, 112));
  tft.drawString("Checking for different protocols", 8, 59);
  tft.drawString("Power Delivery 2.0 and 3.0", 8, 115);
  tft.drawString("Quick Charge: 9V 12V 20V", 8, 171);
  tft.drawString("Quick Charge: 3.4 - 20V", 8, 229);
  tft.setRotation(0);
}
