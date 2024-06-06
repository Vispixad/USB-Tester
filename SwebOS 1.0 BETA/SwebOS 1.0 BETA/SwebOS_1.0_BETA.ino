#include <FS.h>
#include <LittleFS.h>
#include <TFT_eSPI.h>
#include "esp32-hal.h"
#include <I2Cdev.h>
#include <Wire.h>
#include <MPU6050.h>
#include <QuickCharge.h>
#include <SoftwareSerial.h>
#include "PTSans_Bold18.h"
#include "PTSans_Bold22.h"
#include "PTSans_Bold53.h"
#include "PTSans_Bold32.h"
#include "PTSans_Bold30.h"
#include "PTSans_Bold34.h"
#include "PTSans_Bold28.h"
#include "PTSans_Bold16.h"
#include "PTSans_Regular24.h"
#include "PTSans_Regular12.h"
#include "PTSans_Regular16.h"
#include "PTSans_Regular18.h"
#include "PTSans_Regular22.h"
#include <Fonts/PTSans_Bold26pt7b.h>
#include <Fonts/PTSans_Bold15pt7b.h>
#include <Fonts/PTSans_Bold13pt7b.h>
#include <Fonts/PTSans_Bold17pt7b.h>
#include <Fonts/PTSans_Bold16pt7b.h>
#include <Fonts/PTSans_Regular12pt7b.h>
#include <Fonts/PTSans_Regular14pt7b.h>
#include <Fonts/OpenSans_Condensed_Bold8pt7b.h>
#include <Fonts/PTSans_Bold8pt7b.h>
#include <Fonts/PTSans_Regular9pt7b.h>
#include <Fonts/PTSans_Regular8pt7b.h>
#include <Fonts/PTSans_Regular6pt7b.h>
#include <Fonts/PTSans_Bold9pt7b.h>
#include <Fonts/PTSans_Regular10pt7b.h>
#include <Fonts/PTSans_Bold14pt7b.h>
#include <Fonts/PTSans_Regular11pt7b.h>
#include "SDL_Arduino_INA3221.h"

#define LONG_PRESS_DURATION 350          // Длительность для определения длинного нажатия (в миллисекундах)
unsigned long buttonPressStartTime = 0;  // Переменная для хранения времени начала нажатия

#define LIPO_BATTERY_CHANNEL 1
#define SOLAR_CELL_CHANNEL 2
#define OUTPUT_CHANNEL 3

#define DP_H_PIN 4
#define DP_L_PIN 5
#define DM_H_PIN 1
#define DM_L_PIN 2

#define BUTTON_UP 19
#define BUTTON_DOWN 21
#define BUTTON_AVER 20

int virtualRXPin = 39;
int virtualTXPin = 14;

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite voltageSprite = TFT_eSprite(&tft);
TFT_eSprite currentSprite = TFT_eSprite(&tft);
TFT_eSprite wattSprite = TFT_eSprite(&tft);
TFT_eSprite tempSprite = TFT_eSprite(&tft);
TFT_eSprite TimeAppSprite = TFT_eSprite(&tft);
TFT_eSprite TimeBatSprite = TFT_eSprite(&tft);
TFT_eSprite ampHrsSprite = TFT_eSprite(&tft);
TFT_eSprite wattHrsSprite = TFT_eSprite(&tft);
TFT_eSprite dispResSprite = TFT_eSprite(&tft);
TFT_eSprite TimeSettSprite = TFT_eSprite(&tft);
TFT_eSprite TempSettSprite = TFT_eSprite(&tft);
TFT_eSprite voltNGRSprite = TFT_eSprite(&tft);
TFT_eSprite currNGRSprite = TFT_eSprite(&tft);
TFT_eSprite wattNGRSprite = TFT_eSprite(&tft);

SoftwareSerial virtualSerial(virtualRXPin, virtualTXPin);
QuickCharge QC(DP_H_PIN, DP_L_PIN, DM_H_PIN, DM_L_PIN, QC_CLASS_B);
MPU6050 mpu;
SDL_Arduino_INA3221 ina3221;

//-------------------------ФЛАГИ МЕНЮ И ПРОЧЕГО-------------------------
int cellIndex = 0;  // Индекс ячейки
int brightnessLevel = 1023;
int standbyBrightness = 200;  // Уровень яркости в режиме ожидания
int standbyInterval = 1;      // Интервал времени в минутах для перехода в режим ожидания
unsigned long lastActiveTime = 0;
bool standbyModeEnabled = true;  // Флаг для включения/выключения режима ожидания
int currentApp = 0;
float displayValue = 3.0;
float displayEff = 60;
int currentMenu = 1;
int PushApp = 0;
int PushNGR = 0;
int currentStat = 0;
int currentBat = 0;
int buttonFast = 0;
int currentToll = 0;
int buttonList = 0;
int selectRectNGR = 1;      // прямоугольники в MENU_NGR, по умолничанию выбран (1)
int selectedRectangle = 1;  // прямоугольники в меню Application, по умолничанию выбран (1)
int selectedRectlist = 1;
int selectedStat = 1;  // прямоугольники в меню Statistics, по умолничанию выбран (1)
int selectedBat = 1;
int selectedToll = 1;  // прямоугольники в меню Tollbox, по умолничанию выбран (1)
int currentRectangle = 1;
int currentState = 0;
int buttonStateFast = 0;
int lastbuttonStateFast = 0;
int selectedRectangleFast = 1;
bool ngrvolt = false;
bool ngrcells = false;
bool skipDrawChoiceApp = true;
bool skipDrawChoice = true;
bool skipDraw = true;
bool skip = false;
bool buttonState = false;
bool menufast = false;
bool isScreenRotated = false;
bool averbuttonapp = false;
bool tollup = false;       // обработка кнопки BUTTON_UP для прямоугольников в меню Tollbox
bool menuapp = false;      // рисование самого меню приложений
bool menuappr = false;     // 2 часть флага menuapp
bool timeoverapp = false;  // показ времени работы в приложениях
bool warup = false;        // обработка кнопки BUTTON_UP в меню WARNING
bool genmvolt = false;
bool settrig = true;
bool setgiro = true;
bool setrec = true;
bool setgen = true;
bool setsys = true;
bool menupped = false;
bool ngrupped = true;
bool ngrdown = true;
bool vmotor = false;  //обработка вибромотора для нажатий кнопок
bool settup = false;  // обработка кнопки BUTTON_UP в меню SETTING
bool setdown = false;
bool wardown = false;  // обработка кнопки BUTTON_DOWN в меню WARNING
bool menudown = false;
bool fastdown = false;
bool stopedwar = false;
bool stopedfast = false;
bool timeoverwar = true;
//------------------ФЛАГИ ДЛЯ МЕНЮ ТРИГГЕРA QC2.0----------------------
bool QC2down = true;
bool stopedQC2 = true;
//------------------ФЛАГИ ДЛЯ МЕНЮ ТРИГГЕРA QC3.0----------------------
bool QC3down = true;
bool stopedQC3 = true;
//-------------------ФЛАГИ ДЛЯ МЕНЮ ТРИГГЕРA PD------------------------
bool stopedPD = true;
bool PDdown = true;
//---------------------------------------------------------------------
bool stopedtoll = false;
bool stopedresist = false;
bool stopedstat = false;
bool stopedcable = false;
bool listup = false;
bool tolldown = false;  // обработка кнопки BUTTON_DOWN в меню Toolbox
bool statdown = false;  // обработка кнопки BUTTON_DOWN в меню Statistics
bool statup = false;    // обработка кнопки BUTTON_UP в меню Statistics
bool batup = true;
bool cellbatup = true;
bool batdown = false;
bool cellbatdown = true;
bool updateTimeBat = true;
bool updateTimedBat = true;
bool presetdown = true;
bool presetdownsys = true;
bool updatedevinfo = true;
bool stopset = false;
bool predownlight = true;
bool setgenlight = true;
bool stopsyslight = true;
bool stopsetbackup = true;
bool stopsyslevel = true;
bool setgenlevel = true;
bool stopsetsys = true;
bool stopsetgen = true;
bool voltbatup = true;
bool effbatup = true;
bool qcdown = false;          // обработка кнопки BUTTON_DOWN в меню DETECT_V1
const int digitalPinA0 = 41;  // контакт д-
const int digitalPinA1 = 42;  // контакт д+
const int Datap = 18;
const int Datam = 16;
bool voltageReadFlag = false;
bool dataReadFlag = false;

bool buttonStateQC = false;
bool lastbuttonStateQC = false;
bool rangesChecked = false;
bool rotationCompleted = false;
const char* configFilePath = "/config.txt";
//----------------------СЧЕТЧИК ВРЕМЕНИ РАБОТЫ--------------------------
unsigned long hours = 0;
unsigned long minutes = 0;
unsigned long seconds = 0;
unsigned long days = 0;
//----------КОМАНДЫ ДАННЫХ (СЕРИАЛ)---------------------
#define CMD_VER "ver"
#define CMD_SN "sn"
#define CMD_VALUES "vls"
#define CMD_ERROR "error"

String InCmd;
bool InCmdIsFull = false;

void ReadSerial() {
  while (Serial.available()) {
    char ch = Serial.read();
    if (ch == '\n' || ch == '\r') {
      InCmdIsFull = true;
      return;
    }
    InCmd += ch;
  }
}

void setup() {
  virtualSerial.begin(9600);
  randomSeed(analogRead(0));
  Serial.begin(115200);
  InCmd.reserve(10);
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);
  voltageSprite.createSprite(225, 43);
  currentSprite.createSprite(225, 43);
  wattSprite.createSprite(225, 43);
  tempSprite.createSprite(55, 20);
  TimeAppSprite.createSprite(143, 20);
  TimeBatSprite.createSprite(137, 19);
  ampHrsSprite.createSprite(92, 18);
  wattHrsSprite.createSprite(97, 18);
  dispResSprite.createSprite(160, 35);
  TimeSettSprite.createSprite(70, 19);
  TempSettSprite.createSprite(40, 19);
  voltNGRSprite.createSprite(150, 26);
  currNGRSprite.createSprite(150, 26);
  wattNGRSprite.createSprite(150, 26);
  if (!LittleFS.begin()) {
    while (1) yield();
  }
  //------------------------ПРОВЕРКА ФАЙЛОВОЙ СИСТЕМЫ------------------------------
  File root = LittleFS.open("/");
  if (!root) {
    return;
  }
  //---------------------СОЗДАНИЕ ПАПКИ ДАННЫХ ЕМКОСТЕЙ----------------------------
  // Проверяем, существует ли папка. Если нет, создаем ее.
  if (!LittleFS.exists("/capacity")) {
    LittleFS.mkdir("/capacity");
  }
  //-----------------------СОЗДАНИЕ ПАПКИ РЕЗЕРВНЫХ КОПИЙ---------------------------
  if (!LittleFS.exists("/backup")) {
    LittleFS.mkdir("/backup");
  }
  //-----------------------СОЗДАНИЕ ФАЙЛА КОЛ-ВО ЗАПУСКОВ---------------------------
  File file = LittleFS.open("/count.txt", "r");
  if (!file) {
    file = LittleFS.open("/count.txt", "w");
    if (!file) {
      return;
    }
    file.println("0");
  }
  String count = file.readStringUntil('\n');
  file.close();
  int newCount = count.toInt() + 1;
  file = LittleFS.open("/count.txt", "w");
  if (!file) {
    return;
  }
  file.println(newCount);
  file.close();
  //-------------------------СОЗДАНИЕ ФАЙЛОВ ЯЧЕЕК-----------------------------
  // Проверяем, существуют ли файлы, прежде чем создавать новые
  for (int i = 1; i <= 10; i++) {
    String fileName = "/capacity/cell" + String(i) + ".txt";
    if (!LittleFS.exists(fileName)) {
      File file = LittleFS.open(fileName, FILE_WRITE);
      if (!file) {
      } else {
        file.println("0 days 00:00:00");
        file.println("0.00000");
        file.println("0.00000");
        file.close();
      }
    } else {
    }
  }
  pinMode(15, OUTPUT);
  pinMode(13, OUTPUT);
  //-----ШИМ вибромотора-----
  ledcAttach(1, 13, 2000);  // Подключаем канал 1 к пину 13 с частотой 2000 Гц
  //----ШИМ яркости дисплея----
  lastActiveTime = millis();
  ledcAttach(0, 15, 5000);        // Подключаем канал 0 к пину 15 с частотой 5000 Гц
  ledcWrite(0, brightnessLevel);  // Устанавливаем яркость
  //определение состояния пинов
  pinMode(digitalPinA0, OUTPUT);
  pinMode(digitalPinA1, INPUT);
  pinMode(Datap, INPUT);
  pinMode(Datam, INPUT);
  pinMode(BUTTON_AVER, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  mpu.initialize();
  ina3221.begin();
  createTasks();
  int lastMenu = loadLastMenu();
  if (lastMenu != 0) {
    // Restore last menu
    currentMenu = lastMenu;
    switch (currentMenu) {
      case 1:
        drawMenu0();
        break;
      case 2:
        drawMenu1();
        break;
      case 3:
        drawMenu2();
        break;
      case 4:
        drawMenu3();
        break;
      case 5:
        drawMenu4();
        break;
      case 6:
        drawMenu5();
        break;
    }
  } else {
    drawMenu0();
  }
}
void loop() {
  static unsigned long lastButtonPress = 0;
  static unsigned long buttonHoldThreshold = 400;
  if (digitalRead(BUTTON_UP) == LOW && currentMenu != 6) {
    if (!menudown) {
      if (millis() - lastButtonPress >= buttonHoldThreshold || lastButtonPress == 0) {
        currentMenu++;
        if (currentMenu > 6) currentMenu = 1;
        switch (currentMenu) {
          case 1:
            drawMenu0();
            break;
          case 2:
            drawMenu1();
            break;
          case 3:
            drawMenu2();
            break;
          case 4:
            drawMenu3();
            break;
          case 5:
            drawMenu4();
            break;
          case 6:
            drawMenu5();
            break;
        }
        saveCurrentMenu(currentMenu);  // Save current menu to config file
        lastButtonPress = millis();
      }
    }
  }
  static unsigned long lastButtPrDown = 0;
  static unsigned long buttHoldDown = 400;
  if (digitalRead(BUTTON_DOWN) == LOW) {
    if (!menupped) {
      if (millis() - lastButtPrDown >= buttHoldDown || lastButtPrDown == 0) {
        currentMenu--;
        if (currentMenu < 1) currentMenu = 6;
        switch (currentMenu) {
          case 1:
            drawMenu0();
            break;
          case 2:
            drawMenu1();
            break;
          case 3:
            drawMenu2();
            break;
          case 4:
            drawMenu3();
            break;
          case 5:
            drawMenu4();
            break;
          case 6:
            drawMenu5();
            break;
        }
        saveCurrentMenu(currentMenu);  // Save current menu to config file
        lastButtonPress = millis();
      }
    }
  }
  if (digitalRead(BUTTON_AVER) == LOW) {
    if (!averbuttonapp) {
      // Проверяем, какой прямоугольник выбран
      switch (PushApp) {
        case 1:
          stopedwar = true;
          tft.fillScreen(TFT_BLACK);
          drawRecWar();
          drawTextWar();
          timeoverwar = false;
          menufast = true;
          averbuttonapp = true;
          menuapp = true;
          menuappr = true;
          timeoverapp = true;
          warup = false;
          wardown = false;
          menudown = true;
          break;
        case 2:
          tft.fillScreen(TFT_BLACK);
          drawRectStat();
          drawTextStat();
          stopedstat = false;
          listup = true;
          statup = false;
          averbuttonapp = true;
          menuapp = true;
          menuappr = true;
          timeoverapp = true;
          menudown = true;
          break;
        case 3:
          tft.fillScreen(TFT_BLACK);
          drawRectTollbox();
          drawTextTollbox();
          stopedresist = true;
          stopedtoll = false;
          stopedcable = true;
          tollup = false;
          menudown = true;
          menuappr = true;
          averbuttonapp = true;  // при нажатии кнопки aver постоянно рисуется какое-то из меню в Application
          timeoverapp = true;    // показ времени работы в приложениях
          break;
        case 4:
          tft.fillScreen(TFT_BLACK);
          drawSetting();
          drawTextSetting();
          setsys = true;
          setgen = true;
          setrec = true;
          settrig = true;
          setgiro = true;
          setdown = false;
          settup = false;
          menudown = true;
          averbuttonapp = true;
          timeoverapp = true;
          menuapp = true;
          menuappr = true;
          break;
      }
    } else {
    }
  }
  updateMenuContent();
  updateMenu();
  updateWar();
  updateFast();
  updateRectToll();
  updateRectStat();
  drawSetDeviseInfo();
  StandbyMode();
  VMotorMode();
}
void StandbyMode() {
  // Проверка нажатия любой из кнопок и переход в активный режим
  if (digitalRead(BUTTON_UP) == LOW || digitalRead(BUTTON_AVER) == LOW || digitalRead(BUTTON_DOWN) == LOW) {
    if (brightnessLevel != 1023) {
      int step = 1;
      int steps = 1023 - brightnessLevel;
      int delayBetweenSteps = 850 / steps;
      for (int i = 0; i < steps; i++) {
        brightnessLevel += step;
        ledcWrite(0, brightnessLevel);
        delay(delayBetweenSteps);
      }
    }
    lastActiveTime = millis();
  }
  if (standbyModeEnabled && (millis() - lastActiveTime > standbyInterval * 60000)) {
    if (brightnessLevel != standbyBrightness) {
      int step = (brightnessLevel > standbyBrightness) ? -1 : 1;
      int steps = abs(brightnessLevel - standbyBrightness);
      int delayBetweenSteps = 850 / steps;
      for (int i = 0; i < steps; i++) {
        brightnessLevel += step;
        ledcWrite(0, brightnessLevel);
        delay(delayBetweenSteps);
      }
    }
  }
}
void drawSetDeviseInfo() {
  if (!updatedevinfo) {
    unsigned long MillisDeviseInfo = millis();
    const unsigned long intervalinfo = 1000;
    tft.setRotation(3);
    TempSettSprite.fillSprite(tft.color565(8, 8, 8));
    TempSettSprite.loadFont(PTSans_Regular18);
    TempSettSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
    TempSettSprite.drawString(String(temperatureRead(), 0) + " C", 2, 0);
    TempSettSprite.pushSprite(272, 80);

    RealTime(days, hours, minutes, seconds);
    tft.setRotation(3);
    TimeSettSprite.fillSprite(tft.color565(8, 8, 8));
    TempSettSprite.setTextColor(tft.color565(255, 255, 255), tft.color565(120, 120, 120));
    TempSettSprite.loadFont(PTSans_Regular18);
    char buffer[20];
    sprintf(buffer, "%02d:%02d:%02d", hours, minutes % 60, seconds % 60);
    TimeSettSprite.drawString(buffer, 2, 0);
    TimeSettSprite.pushSprite(240, 146);
    tft.setRotation(0);
    if (millis() - MillisDeviseInfo >= intervalinfo) {
      MillisDeviseInfo = millis();
    }
  }
}
void updateMenuContent() {
  switch (currentMenu) {
    case 1:
      drawVoltGenM();
      break;
    case 2:
      drawVoltNGR();
      break;
    case 3:
      drawPauseGraph();
      break;
    case 4:
      drawPauseGData();
      break;
    case 5:
      drawPauseGCC();
      break;
    case 6:
      drawChoiceApp();
      break;
  }
}
void updateMenu() {
  switch (PushApp) {
    case 1:
      ButtonWar();
      break;
    case 2:
      drawChoiceStat();
      break;
    case 3:
      drawChoiceToll();
      break;
    case 4:
      Setting();
      break;
  }
}
void updateWar() {
  switch (currentState) {
    case 1:
      drawChoiceFast();
      break;
    case 2:
      buttonQC();
      break;
    case 3:

      break;
  }
}
void updateFast() {
  switch (buttonFast) {
    case 1:

      break;
    case 2:
      triggedPD();
      buttonPD();
      break;
    case 3:
      triggedQC2();
      buttonQC2();
      break;
    case 4:
      triggedQC3();
      buttonQC3();
      break;
  }
}
void updateRectToll() {
  switch (currentToll) {
    case 1:
      CableResist();
      break;
    case 2:

      break;
    case 3:
      CableLine();
      break;
  }
}
void updateRectStat() {
  switch (currentStat) {
    case 1:
      NGRStat();
      break;
    case 2:
      drawBattery();
      break;
    case 3:
      drawPauseGraphRec();
      break;
  }
}
void drawMenu0() {
  tft.fillScreen(TFT_BLACK);
  averbuttonapp = true;
  warup = true;
  settup = true;
  wardown = true;
  drawRectGenM();
  drawTextGenM();
}
void drawMenu1() {
  tft.fillScreen(TFT_BLACK);
  averbuttonapp = true;
  warup = true;
  settup = true;
  wardown = true;
  drawRectNGR();
  drawTextNGR();
  tft.setRotation(2);
  drawTriangleNGR(155, 135, 180);
}

void drawMenu2() {
  tft.fillScreen(TFT_BLACK);
  averbuttonapp = true;
  warup = true;
  settup = true;
  wardown = true;
  tft.setRotation(2);
  drawTriangleVolt1(103, -5, 180);
  drawTriangleVolt2(101, 297, 0);
  drawTrianglePause(211, 108, 180);
  drawGraphVolt1();
  drawGraphVolt2();
  tft.setRotation(3);
  drawTextGraph();
}

void drawMenu3() {
  tft.fillScreen(TFT_BLACK);
  averbuttonapp = true;
  warup = true;
  settup = true;
  wardown = true;
  tft.setRotation(2);
  drawTriangleD1(103, -5, 180);
  drawTriangleD2(101, 297, 0);
  drawGraphData1();
  drawGraphData2();
  tft.setRotation(3);
  drawTextGData();
}

void drawMenu4() {
  tft.fillScreen(TFT_BLACK);
  averbuttonapp = true;
  warup = true;
  settup = true;
  wardown = true;
  tft.setRotation(2);
  drawTriangleCC1(103, -5, 180);
  drawTriangleCC2(101, 297, 0);
  drawGraphCC1();
  drawGraphCC2();
  tft.setRotation(3);
  drawTextGCC();
}

void drawMenu5() {
  tft.fillScreen(TFT_BLACK);
  tollup = true;
  timeoverapp = false;
  warup = true;
  settup = true;
  wardown = true;
  menuapp = false;
  menuappr = false;
  averbuttonapp = false;
  drawApp();
  drawTextApp();
}
