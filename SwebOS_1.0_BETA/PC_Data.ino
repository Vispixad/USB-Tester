void PCData() {
/*  unsigned long previousMillis = 0;
  const long interval = 10;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float v = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);
    float a = ina3221.getCurrent_mA(LIPO_BATTERY_CHANNEL) / 1000.0;
    float r = random(0, 1000) / 1000.0;
    int sensorValue1 = analogRead(18);
    float d1 = sensorValue1 * (3.3 / 4095.0);
    int sensorValue2 = analogRead(16);
    float d2 = sensorValue2 * (3.3 / 4095.0);
    int sensorValue3 = analogRead(17);
    float cc1 = sensorValue3 * (3.3 / 4095.0);
    int sensorValue4 = analogRead(3);
    float cc2 = sensorValue4 * (3.3 / 4095.0);

    Serial.print("vls\t");
    Serial.print(String(v, 4));
    Serial.print("\t");
    Serial.print(String(a, 4));
    Serial.print("\t");
    Serial.print(String(v * a, 4));
    Serial.print("\t");
    Serial.print(String(r, 4));
    Serial.print("\t");
    Serial.print(String(d1, 4));
    Serial.print("\t");
    Serial.print(String(d2, 4));
    Serial.print("\t");
    Serial.print(String(cc1, 4));
    Serial.print("\t");
    Serial.print(String(cc2, 4));
    Serial.print("\n");
    ReadSerial();
    if (InCmdIsFull) {
      InCmdIsFull = false;
      if (InCmd == CMD_VER) {
        Serial.print("\n");
        Serial.print(CMD_VER);
        Serial.print("\t");
        Serial.print("1\t1\n");
      } else if (InCmd == CMD_SN) {
        Serial.print("\n");
        Serial.print(CMD_SN);
        Serial.print("\t");
        Serial.print("1458fd\n");
      } else {
        Serial.print("\n");
        Serial.print(CMD_ERROR);
        Serial.print("\t");
        Serial.print("unknow command\n");
      }
      InCmd = "";
    }
  }*/
}
