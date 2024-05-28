/*TaskHandle_t PCDataTask;
TaskHandle_t RotateTask;
TaskHandle_t TempTask;
TaskHandle_t TimeTask;

void PCDataTaskFunction(void *pvParameters) {
  for (;;) {
    PCData();
    vTaskDelay(40 / portTICK_PERIOD_MS);
  }
}

void RotateTaskFunction(void *pvParameters) {
  for (;;) {
    Rotate();
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}
void TempTaskFunction(void *pvParameters) {
  for (;;) {
    Temp();
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}
void TimeTaskFunction(void *pvParameters) {
  for (;;) {
    unsigned long days, hours, minutes, seconds;
    RealTime(days, hours, minutes, seconds);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void createTasks() {
  xTaskCreatePinnedToCore(
    PCDataTaskFunction,     // Функция задачи PCData
    "PCDataTask",           // Имя задачи
    20000,                  // Размер стека задачи
    NULL,                   // Параметры задачи
    1,                      // Приоритет задачи
    &PCDataTask,            // Указатель на дескриптор задачи
    0                       // Номер ядра (0 для ядра 0, 1 для ядра 1)
  );

  xTaskCreatePinnedToCore(
    RotateTaskFunction,     // Функция задачи Rotate
    "RotateTask",           // Имя задачи
    20000,                  // Размер стека задачи
    NULL,                   // Параметры задачи
    1,                      // Приоритет задачи
    &RotateTask,            // Указатель на дескриптор задачи
    0                       // Номер ядра (0 для ядра 0, 1 для ядра 1)
  );

  xTaskCreatePinnedToCore(
    TempTaskFunction,       // Функция задачи Temp
    "TempTask",             // Имя задачи
    20000,                  // Размер стека задачи
    NULL,                   // Параметры задачи
    1,                      // Приоритет задачи
    &TempTask,              // Указатель на дескриптор задачи
    0                       // Номер ядра (0 для ядра 0, 1 для ядра 1)
  );
  xTaskCreatePinnedToCore(
    TimeTaskFunction,    // Функция задачи DisplayTask
    "TimeTask",          // Имя задачи
    20000,                  // Размер стека задачи
    NULL,                   // Параметры задачи
    1,                      // Приоритет задачи
    &TimeTask,           // Указатель на дескриптор задачи
    0                       // Номер ядра (0 для ядра 0, 1 для ядра 1)
  );
}*/
