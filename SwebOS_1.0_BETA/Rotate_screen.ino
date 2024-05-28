void Rotate() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  if (ax >= 3500 && ax <= 16384 && !isScreenRotated) {
    isScreenRotated = true;
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(2);
  } else if (ax >= -16384 && ax <= -2000 && isScreenRotated) {
    isScreenRotated = false;
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(0);
  }
}
