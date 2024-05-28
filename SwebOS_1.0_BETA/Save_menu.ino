void saveCurrentMenu(int currentMenu) {
  File configFile = LittleFS.open(configFilePath, "w");
  if (!configFile) {
    return;
  }
  configFile.println(currentMenu);
  configFile.close();
}
int loadLastMenu() {
  if (!LittleFS.begin()) {
    return 1;
  }
  if (!LittleFS.exists(configFilePath)) {
    return 1;
  }
  File configFile = LittleFS.open(configFilePath, "r");
  if (!configFile) {
    return 1;
  }
  int lastMenu = configFile.parseInt();
  configFile.close();
  return lastMenu;
}
