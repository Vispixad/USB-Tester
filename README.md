<h1 align="center">ESP32-Tester</h1>

![usb-tester](https://img.shields.io/badge/usb-tester-red?style=flat&logo=educative)
![programming](https://img.shields.io/badge/programming-blue?style=flat&logo=cplusplus)
![ESP32](https://img.shields.io/badge/ESP32-gray?style=flat&logo=espressif)

> [!CAUTION]
> Если у вас возникают ошибки или другие трудности, советуем следить за
> обновлениями, а также писать об этом нам, так как проект находится в активной разработке.
> 
> **Советуем прочитать** [**инструкцию по установке и настройке для прошивки тестера**](https://github.com/Vispixad/ESP32-USB-Tester/blob/main/Instructions.md), а также [**документацию программы для пк**](https://github.com/Vispixad/ESP32-USB-Tester/blob/main/PC%20Program.md)
 
ESP32-Tester - это DIY вариант USB тестеров от различных производителей, сделанный на основе ESP32-S3N16R8. Я реализовал много разных функций от простого измерения напряжения, тока, подсчета ватт (V, A, W) - до просмотра 
протоколов которые может выдать ваш блок питания, измерения сопротивления кабеля и прочего. Проект все еще находится в разработке и прошивка с каждым днем расширяется как и его возможности.

## Содержание
- [**Что такое USB Tester?**](#что-такое-usb-tester)
- [**Компоненты**](#компоненты)
     - [Дисплей](#дисплей)
     - [INA3221 (АЦП)](#ina3221-ацп)
     - [MPU-9250 (акселерометр, гироскоп, компас)](#mpu-9250-акселерометр-гироскоп-компас)
     - [ESP32-S3N16R8](#esp32-s3n16r8)
- [**Интерфейс**](#интерфейс)
     - [Главное меню](#главное-меню)
     - [NGR меню](#ngr-меню)
     - [Графики](#графики)
     - [Application](#application)
- [**Fast Charge**](#fast-charge)
     - [Warning](#warning)
     - [Detection](#detection)
     - [Fast Charge (Trigger)](#fast-charge-trigger)
- [**Statistics**](#statistics)
     - [NGR Statistics](#ngr-statistics)
     - [Battery CAP](#battery-cap)
     - [Offline Recording](#offline-recording)
- [**Toolbox**](#toolbox)
     - [Countdown](#countdown)
- [**Setting**](#setting)
     - [General](#general)
     - [System](#system)

## Что такое USB Tester?
**USB Tester** – это устройство для измерения параметров USB-портов и кабелей, таких как напряжение, ток и мощность, а также для тестирования функциональности USB-устройств. Оно полезно как для обычных пользователей, так и для профессионалов.

USB Tester может быть компактным прибором с дисплеем, показывающим основные значения, поступающие через USB-порт. Более продвинутые модели также предоставляют информацию о протоколах зарядки (например, Apple, Qualcomm Quick Charge).

Основная функция USB Tester'а – проверка работоспособности USB-портов и оценка качества зарядки различных устройств, а также соответствие стандартам USB.

<h1 align="center">Компоненты</h1>

## Дисплей
В своем проекты я использовал комопненты доступные на площадке AliExpress также покупал в местных магазинах. Первое что мы сможем увидеть в тестере это сам дисплей, я выбрал **IPS 2 inch (240*320)**, он имеет хорошую цветопередачу, плотность пикселей и технологию IPS, что дает хорошие углы обзора по сравнению с TFT, таким образом он отлично подходит для этого проекта.

![TFT-2 0-inch-IC-ST7789V-RGB-240x320-SPI-wymiary-](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/62fba501-9909-4379-95e9-d13d091512f1)

## INA3221 (АЦП)
Следущее что мы можем увидеть после включения устройства это основные данные: V, A, W, для этой цели я преобрел АЦП **INA3221**. Это цифровой трехканальный датчик тока и напряжения с шиной I2C, нам будут нужны несколько каналов так как имеются 2 входных (USB-A, USB Type-C) и 2 выходных (USB-A, USB Type-C). Также он удобен тем что имеет множество индикаторов для определения ошибок в работе, что вполне можно добавить в свой проект:

![ina3221_3265472](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/86a92149-87d6-4b74-b699-448245379324)

- **LED1** — индикатор наличия питания.
- **LED2** — питание находится в запрограммированном диапазоне (0 — 26 вольт)
- **LED3** — критическая проблема такой как неверная полярность или короткое замыкание (канал CRI)
- **LED4** — ошибка измерения (Канал WAR)
- **LED5** — обрыв линии питания одного из трех выводов (Канал ТС).

Подробнее можете ознакомиться на различных сайтах, а мы продолжим. 

## MPU-9250 (акселерометр, гироскоп, компас)
У тестера есть функция поворота дисплея при наклоне (аналогичное есть в вашем смартфоне), для такого используется MPU-9250 - это 9-ти осевое устройство
(3-х осевой акселерометр, 3-х осевой гироскоп, 3-х осевой компас магнитометр). Как видим есть запас в виде компаса (поэтому если 9250 у вас стоит дорого, берите MPU6500), но пока не нашел ему применение в данном
устройстве, в свою же очередь гироскоп и акселерометр используются для функции поворота дисплея.

![513VIvLM-HL](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/6e5f72e5-f634-4b9b-84ae-83aaca236cd1)

## ESP32-S3N16R8
Далее идут различные порты, кнопки, обвязка и сама плата МК - это ESP32-S3N16R8. Она имеет 16Мб постоянной памяти (PSRAM), 8Мб оперативной (RAM). Этого с избытком хватает для такого проекта, но не обязательно брать версию с 8Мб RAM - вы ее не сможете полностью забить.

![scale_1200](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/34f7b422-d83c-4f71-b241-abdde5182c83)

<h1 align="center">Интерфейс</h1>

## Главное меню
![IMG_20240724_175715](https://github.com/user-attachments/assets/9d26895a-9ef0-4f7d-a970-b13130443524)
Перейдем к интерфейсу самого тестера, при запуске нас встречает главное меню с основными показаниями, температурой самого устройства (данные берутся с встроенного температурного датчика ESP32) и индикатор **stop/start**, ниже прописаны дейсвия для кнопок на этом меню:
- **Нажатие (средняя кнопка)** - stop/start показаний (для просмотра данных если требуется)
- **Нажатие (правая кнопка)** - переход на следущее меню

## NGR меню
![IMG_20240724_175401](https://github.com/user-attachments/assets/959b8ee3-99ec-45fe-b639-a166c643d28d)
Здесь имеется отображение основных данных (V, A, W) но уже добавляется показ данных на **DATA** контактах **(D+, D-)**, небольшая область для показа данных с определенной ячейки, показ до 3-х возможных протоколов зарядки
для общей информации, работает ли триггер **(NONE/QC2.0...)**, запись данных:
- **Вкл - ONLINE**
- **Выкл - OFFLINE** 
(шкала показывает оставщуюся память устройства, точнее области которая для этого выделена в памяти) и лимит времени. Также из мелкого интерфейса имеется стрелка для показа направления в какой порт подключено и шкала которая заполняется в зависимости от данных.
## Графики
![IMG_20240724_175836](https://github.com/user-attachments/assets/e39570c1-1027-495a-9bba-f4d304acb615)![IMG_20240724_180004](https://github.com/user-attachments/assets/aa8b2706-2fe9-41a7-8ce6-9e131429740e)
Следущее третье меню это меню графиков, их тут 3 вида:
- **График V/A** - (напряжение, ток)
- **График D+/D-** - (плюс и минус DATA контактов)
- **График CC1/CC2** - (CC1 и CC2).

На каждом из них можно сделать паузу аналогично главному меню. Тестер сам подбирает диапазон отображения чтобы было видно кривую и не выходило за границы.

> [!IMPORTANT]
> Стоит также отметить что в графике **CC1/CC2**, если у вас не подключено устройство по **USB-C** или вход подключен к USB-A тестер вам об этом сообщит и пропустит этот график из-за отсутствия таких контактов, пример показан ниже:
> 
> ![IMG_20240724_180059](https://github.com/user-attachments/assets/7d4a5e7f-5491-4c5f-8d09-7bd495ecaddf)

## Application
![IMG_20240724_193503](https://github.com/user-attachments/assets/026bd005-aa56-43a3-bcc3-2130099ad1bc)
Последнее дочерное меню это - меню приложений или **Application**, здесь в прямоугольниках идут разветвления на другие подменю.

Также внизу показывается **время работы устройства**, что может быть полезным в некоторых случаях. По поводу управления:
- **нажатие (кнопка вперед)** - выбор подкатегорий (выбранная отмечается синим).
- **нажатие (кнопка назад)** - переход на предыдущее меню.
- **нажатие (средняя кнопка)** - сделает переход в выбранную подкатегорию.

<h1 align="center">Fast Charge</h1>

## Warning
![IMG_20240724_193740](https://github.com/user-attachments/assets/570e8eb2-9c53-48b4-b074-84bc686d901d)

При заходе в подкатегорию **Fast Charge** нас встречает предупреждение, ниже 3 кнопки на выбор:
- **READY** - переход в триггеры быстрой зарядки (Samsung AfS, QC2.0, 3.0 и прочее).
- **AUTO** - переход в сканирование вашего блока питания на наличие протоколов зарядки.
- **CANCEL** - выход из подкатегории.

## Detection
![IMG_20240724_200746](https://github.com/user-attachments/assets/15f970ea-0d35-4000-8708-8bd98c9339aa)
Разберем случай нажатия на пукт **AUTO**, вверху написана версия детектирования, статус - **Testig или Finish**, далее ниже по очереди тестрируется каждый протокол на наличие его в БП, методом вызова (триггер).

> [!NOTE]
> Подробнее о протоколах и их работе с Arduino совместимыми платами можно по ссылкам ниже:
> 
> [Что такое быстрая зарядка](https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D1%82%D0%BE%D0%BA%D0%BE%D0%BB%D1%8B_%D0%B1%D1%8B%D1%81%D1%82%D1%80%D0%BE%D0%B9_%D0%B7%D0%B0%D1%80%D1%8F%D0%B4%D0%BA%D0%B8) -> [Интеграция QC2.0 в Arduino](https://github.com/GyverLibs/QuickCharge)

## Fast Charge (Trigger)
![IMG_20240724_203440](https://github.com/user-attachments/assets/ca0e1011-760f-4e94-9d08-c4f0ea6d4743)
![IMG_20240724_203354](https://github.com/user-attachments/assets/72ca0a32-31e4-4d22-959d-a893aaf1c924)
![IMG_20240724_203330](https://github.com/user-attachments/assets/d19d0514-cadf-4572-bbc4-292e193a2e56)
В этом меню нам доступно **6 триггеров** (список расширяется с обновлениями) и **автодетект протоколов**. Были добавлены анимации перемещения и скроллбар для удобства.
По навигации:
- **нажатие (кнопка вперед)** - выбор одного из триггеров (выбранное отмечается синим).
- **нажатие (кнопка назад)** - переход на предыдущее меню.
- **нажатие (средняя кнопка)** - сделает переход в меню выбранного триггера.

<h1 align="center">Statistics</h1>

![IMG_20240724_201419](https://github.com/user-attachments/assets/10ee23cf-4f1f-495d-af50-168ab024438a)

Здесь доступно 3 подменю:
- **Список со статистикой ячеек**
- **Измерение емкости батареи**
- **Запись кривых граифика**
Навигация такая же как и для других меню, не вижу смысла это обьяснять.

## NGR Statistics

## Battery CAP
![IMG_20240724_201505](https://github.com/user-attachments/assets/5d02685b-091f-4f7d-8ca1-bc644d7490af)
Это меню измерения емкости батарей и прочего, в самом вверху есть индикатор **ON/OFF** который показывает включена ли запись данных о емкости в ячейку.

Ниже показано номер ячейку куда будет идти запись, время записи, емкость в **Ah** и **Wh**, также напряжение и предположительное **КПД** батареи.
Красным показаны **Ah** только пересчитаны с выбранными вами напряжением и **КПД**.

> [!CAUTION]
> Сохранение идет только после остановки записи удержанием, поэтому если вы выключите устройство до остановки данные не будут сохранены.
> Если делать сохранение через какое то время **0.5-1s**, память проживет гораздо меньше из-за более частого количества записей.

Что касается навигации, она чуть отличается и более запутанная:
- **удержание 0.5s (средняя кнопка)** - ON/OFF записи данных в выбранную ячейку.
- **нажатие (кнопка назад)** - переход на предыдущее меню.
- **нажатие (кнопка вперед)** - если нажать кнопку вперед, подсветится синим прямоугольником один из параметров (номер ячейки, напряжения, КПД) и дальше мы сможем выбирать по очереди любой. Для подтверждения нажмите среднюю кнопку.
  - **нажатие (кнопка вперед)** - если после нажатия средней кнопки для подтверждения, нажать кнопку вперед, мы сможем увеличивать напряжение (шаг 0.1V), номер ячейки или КПД (шаг 1%).
  - **нажатие (кнопка назад)** - если после нажатия средней кнопки для подтверждения, нажать кнопку назад, мы сможем уменьшать напряжение (шаг 0.1V), номер ячейки или КПД (шаг 1%).

## Offline Recording

<h1 align="center">Toolbox</h1>

![IMG_20240724_201549](https://github.com/user-attachments/assets/212413ca-0d15-45fb-aff1-22327293d85e)
![IMG_20240724_201622](https://github.com/user-attachments/assets/8349d92b-09d4-4247-80ca-ed28457b7d8e)
![IMG_20240724_202222](https://github.com/user-attachments/assets/b1b53f63-55dc-45fc-afba-f7d932e5587f)

В этой подкатегории есть много различных функций такие как измерение сопротивления кабеля, генератор сигналов, осциллограф и другие. Некоторые на этапе разработки.

## Countdown
![IMG_20240724_202354](https://github.com/user-attachments/assets/28eb56d3-275b-4de7-b76b-88070d762a59)

<h1 align="center">Setting</h1>

## General
![IMG_20240724_202545](https://github.com/user-attachments/assets/795ca7a6-c50e-405e-abcb-c83dea30c26e)

## System
![IMG_20240724_202717](https://github.com/user-attachments/assets/e0519007-06be-4778-8afc-506ddb7548f1)
