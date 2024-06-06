void VMotorMode() {
  if (digitalRead(BUTTON_UP) == LOW || digitalRead(BUTTON_AVER) == LOW || digitalRead(BUTTON_DOWN) == LOW) {
    ledcWrite(1, 1023);
    delay(23);
    ledcWrite(1, 0);
    vmotor = true;
  } else if (digitalRead(BUTTON_UP) == HIGH || digitalRead(BUTTON_AVER) == HIGH || digitalRead(BUTTON_DOWN) == HIGH) {
    vmotor = false;
  }
}
