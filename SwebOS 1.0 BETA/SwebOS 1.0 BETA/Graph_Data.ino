void rotatePointD(int &x, int &y, int angle, int centerX, int centerY) {
  float radianAngle = angle * PI / 180.0;
  int tempX = x - centerX;
  int tempY = y - centerY;
  x = round(tempX * cos(radianAngle) - tempY * sin(radianAngle) + centerX);
  y = round(tempX * sin(radianAngle) + tempY * cos(radianAngle) + centerY);
}
void drawTriangleD1(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(0, 129, 227);

  int16_t x0 = 11;
  int16_t y0 = 16;
  int16_t x1 = 18;
  int16_t y1 = 9;
  int16_t x2 = 24;
  int16_t y2 = 16;

  int centerX = (x0 + x1 + x2) / 3;  // Calculate the center of the triangle
  int centerY = (y0 + y1 + y2) / 3;

  // Declare temporary variables for rotated coordinates
  int temp_x0 = x0;
  int temp_y0 = y0;
  int temp_x1 = x1;
  int temp_y1 = y1;
  int temp_x2 = x2;
  int temp_y2 = y2;

  // Rotate each point in place
  rotatePointD(temp_x0, temp_y0, angle, centerX, centerY);
  rotatePointD(temp_x1, temp_y1, angle, centerX, centerY);
  rotatePointD(temp_x2, temp_y2, angle, centerX, centerY);

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
void drawTriangleD2(int posX, int posY, int angle) {
  uint16_t triangleColor = tft.color565(0, 129, 227);

  int16_t x0_2 = 11;
  int16_t y0_2 = 16;
  int16_t x1_2 = 18;
  int16_t y1_2 = 9;
  int16_t x2_2 = 24;
  int16_t y2_2 = 16;

  int centerX_2 = (x0_2 + x1_2 + x2_2) / 3;
  int centerY_2 = (y0_2 + y1_2 + y2_2) / 3;

  // Declare temporary variables for rotated coordinates
  int temp_x0_2 = x0_2;
  int temp_y0_2 = y0_2;
  int temp_x1_2 = x1_2;
  int temp_y1_2 = y1_2;
  int temp_x2_2 = x2_2;
  int temp_y2_2 = y2_2;

  // Rotate each point in place
  rotatePointD(temp_x0_2, temp_y0_2, angle, centerX_2, centerY_2);
  rotatePointD(temp_x1_2, temp_y1_2, angle, centerX_2, centerY_2);
  rotatePointD(temp_x2_2, temp_y2_2, angle, centerX_2, centerY_2);

  // Update original coordinates
  x0_2 = temp_x0_2;
  y0_2 = temp_y0_2;
  x1_2 = temp_x1_2;
  y1_2 = temp_y1_2;
  x2_2 = temp_x2_2;
  y2_2 = temp_y2_2;

  x0_2 += posX;
  y0_2 += posY;
  x1_2 += posX;
  y1_2 += posY;
  x2_2 += posX;
  y2_2 += posY;

  float scale = 1;
  x0_2 *= scale;
  y0_2 *= scale;
  x1_2 *= scale;
  y1_2 *= scale;
  x2_2 *= scale;
  y2_2 *= scale;

  tft.fillTriangle(x0_2, y0_2, x1_2, y1_2, x2_2, y2_2, triangleColor);
}
void drawGraphData1() {
  tft.setRotation(1);
  tft.drawFastHLine(13, 23, 294, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 24, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 40, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 56, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 72, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 88, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 104, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 120, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 136, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 152, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 168, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 184, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 200, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(14, 215, 292, tft.color565(13, 13, 13));
  tft.drawFastHLine(13, 216, 294, tft.color565(13, 13, 13));//(вправо-влево,вверх-вниз,длина)
}
void drawGraphData2() {
  tft.setRotation(0);
  tft.drawFastHLine(23, 13, 193, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 14, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 30, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 46, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 62, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 78, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 94, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 110, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 126, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 142, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 158, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 174, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 190, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 206, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 222, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 238, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 255, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 271, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 288, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(24, 305, 191, tft.color565(13, 13, 13));
  tft.drawFastHLine(23, 306, 193, tft.color565(13, 13, 13));
}
void drawTextGData() {
  tft.setRotation(3);
  tft.loadFont(PTSans_Bold18);
  tft.setTextColor(tft.color565(245, 212, 0), tft.color565(0, 0, 0));
  tft.drawString("+5.00V", 12, 4);
  tft.setTextColor(tft.color565(0, 129, 227), tft.color565(0, 0, 0));
  tft.drawString("10.00A", 256, 4);
  tft.setTextColor(tft.color565(245, 212, 0), tft.color565(0, 0, 0));
  tft.drawString("D+", 127, 4);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 0, 0));
  tft.drawString("/", 147, 2);
  tft.setTextColor(tft.color565(0, 129, 227), tft.color565(0, 0, 0));
  tft.drawString("D-", 156, 4);
  tft.setTextColor(tft.color565(245, 212, 0), tft.color565(0, 0, 0));
  tft.drawString("-5.00V", 12, 219);
  tft.setTextColor(tft.color565(0, 129, 227), tft.color565(0, 0, 0));
  tft.drawString("0.00A", 262, 219);
  tft.setTextColor(tft.color565(255, 255, 255), tft.color565(0, 0, 0));
  tft.drawString("0.1s", 115, 219);
  tft.drawString("/", 150, 219);
  tft.drawString("div", 161, 219);
  tft.setRotation(0);
}

void drawPauseGData() {
  bool buttonState = digitalRead(BUTTON_AVER);
  static unsigned long buttonHoldTime1 = 0;
  static bool rectState1 = false;
  if (buttonState == LOW) {
    unsigned long currentMillis = millis();
    if (currentMillis - buttonHoldTime1 > 200) {
      if (!rectState1) {
        tft.setRotation(2);
        tft.fillRect(218, 112, 19, 19, tft.color565(0, 0, 0));
        tft.fillRect(220, 115, 15, 3, tft.color565(255, 0, 60));
        tft.fillRect(220, 123, 15, 3, tft.color565(255, 0, 60));
      } else {
        tft.setRotation(2);
        tft.fillRect(218, 112, 19, 19, tft.color565(0, 0, 0));
        /*drawRotatedTriangle2(211, 98, 180);*/
      }
      rectState1 = !rectState1;
      buttonHoldTime1 = currentMillis;
    }
  } else {
    buttonHoldTime1 = 0;
  }
}
