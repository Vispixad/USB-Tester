<h1 align="center">ESP32-Tester</h1>

![usb-tester](https://img.shields.io/badge/usb-tester-red?style=flat&logo=educative)
![programming](https://img.shields.io/badge/programming-blue?style=flat&logo=cplusplus)
![ESP32](https://img.shields.io/badge/ESP32-gray?style=flat&logo=espressif)

![IMG_20240528_201432](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/5fde4f38-2ab2-40d2-ab2c-9211365a272d)

> [!CAUTION]
> If you experience errors or other difficulties, we advise you to monitor
> updates, and also write to us about it, since the project is under active development.
> If you have difficulty understanding Russian, choose the version with a language more convenient for you: English -> **Russian** -> Українська

ESP32-Tester is a DIY version of USB testers from various manufacturers, based on the ESP32-S3N16R8. I have implemented many different functions from simple measurement of voltage, current, counting watts (V, A, W) - to viewing
protocols that your power supply can produce, cable resistance measurements and other things. The project is still under development and the firmware is expanding every day, as are its capabilities.

## Content
- [**What is USB Tester?**](#what-is-usb-tester)
- [**Components**](#Components)
 - [Display](#display)
 - [INA3221 (ADC)](#ina3221-ADC)
 - [MPU-9250 (accelerometer, gyroscope, compass)](#mpu-9250-accelerometer-gyroscope-compass)
 - [ESP32-S3N16R8](#esp32-s3n16r8)
- [**Interface**](#Interface)
 - [Main menu](#main-menu)
 - [NGR menu](#ngr-menu)
 - [Charts](#graphs)
 - [Application](#application)
- [**Fast Charge**](#fast-charge)
 - [Warning](#warning)

## What is USB Tester?
**USB Tester** is a device that is used to measure various parameters of USB ports or USB cables such as voltage, current and power and also to test the functionality of USB devices.

This is a useful tool for both ordinary users and professionals in this field. USB Tester can be presented in the form of a small device that connects to the USB port of a computer or charger, or be equipped with a display that shows the main values ​​​​coming through the USB port. More advanced USB Testers can also provide information about charging protocols (e.g. Apple, Qualcomm Quick Charge, Samsung AFC) and more.

Its main function is to help users check the functionality of USB ports on devices and also evaluate the charging quality of various devices, including mobile phones, tablets, headphones and other gadgets. It can also be used to check that devices comply with USB standards.
<h1 align="center">Components</h1>

## Display
In my projects, I used components available on the AliExpress site and also bought them from local stores. The first thing we can see in the tester is the display itself, I chose **IPS 2 inch (240*320)**, it has good color reproduction, pixel density and IPS technology, which gives good viewing angles compared to TFT, so it great for this project.

![TFT-2 0-inch-IC-ST7789V-RGB-240x320-SPI-wymiary](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/62fba501-9909-4379-95e9-d13d091512f1)

## INA3221 (ADC)
The next thing we can see after turning on the device is the basic data: V, A, W, for this purpose I purchased an ADC **INA3221**. This is a digital three-channel current and voltage sensor with an I2C bus; we will need several channels since there are 2 input (USB-A, USB Type-C) and 2 output (USB-A, USB Type-C). It is also convenient because it has many indicators for identifying errors in operation, which can be easily added to your project:

![ina3221_3265472](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/86a92149-87d6-4b74-b699-448245379324)

- **LED1** — power supply indicator.
- **LED2** - power is in the programmed range (0 - 26 volts)
- **LED3** - critical problem such as incorrect polarity or short circuit (CRI channel)
- **LED4** - measurement error (WAR Channel)
- **LED5** — break in the power line of one of the three pins (TC Channel).

You can find out more on various sites, and we will continue.

## MPU-9250 (accelerometer, gyroscope, compass)
The tester has a function to rotate the display when tilted (a similar feature is found in your smartphone), for this the MPU-9250 is used - this is a 9-axis device
(3-axis accelerometer, 3-axis gyroscope, 3-axis compass magnetometer). As you can see, there is a reserve in the form of a compass (so if the 9250 is expensive for you, take the MPU6500), but I have not yet found a use for it in this
device, in turn, the gyroscope and accelerometer are used for the display rotation function.

![513VIvLM-HL](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/6e5f72e5-f634-4b9b-84ae-83aaca236cd1)

## ESP32-S3N16R8
Next come various ports, buttons, harness and the MK board itself - this is ESP32-S3N16R8. It has 16 MB of permanent memory (PSRAM), 8 MB of random access memory (RAM). This is more than enough for such a project, but you don’t have to take the version with 8MB of RAM - you won’t be able to fill it completely.

![scale_1200](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/34f7b422-d83c-4f71-b241-abdde5182c83)

<h1 align="center">Interface</h1>

## Main menu
![IMG_20240528_162028](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/4a0813a4-f7ec-45e7-909a-f29be2995bdc)
Let's move on to the interface of the tester itself, upon startup we are greeted by the main menu with the main readings, the temperature of the device itself (data is taken from the built-in temperature sensor ESP32) and the **stop/start** indicator, below are the actions for the buttons on this menu:
- **Press (middle button)** - stop/start readings (to view data if required)
- **Press (right button)** - go to the next menu
- **Hold (middle button)** - number of readings taken per second (go in a circle 5 - 50 - 1000)

##NGR menu
![IMG_20240528_171536](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/7a422ec2-4542-4a1c-abb6-830a2bd5b0a4)
Here there is a display of basic data (V, A, W), but a display of data on **DATA** contacts **(D+, D-)** is already added, a small area for displaying data from a specific cell (parsing later), display up to 3 possible charging protocols
for general information, whether the trigger **(NONE/QC2.0...)** works, data entry:
- **On - ONLINE**
- **Off - OFFLINE**
(the scale shows the remaining memory of the device, more precisely the area that is allocated for this in memory) and the time limit. Also from the small interface there is an arrow to show the direction to which port is connected and a scale that fills depending on the data.
## Charts
![IMG_20240304_130422](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/a5f01732-1c56-4ccc-8536-27ed29358283)
The next third menu is the chart menu, there are 3 types of them:
- **V/A graph** - (voltage, current)
- **Graph D+/D-** - (plus and minus DATA contacts)
- **CC1/CC2 schedule** - (CC1 and CC2).
On each of them you can pause in the same way as the main menu. The tester itself selects the display range so that the curve is visible and does not go beyond the boundaries.

> [!IMPORTANT]
> It is also worth noting that in the **CC1/CC2** graph, if you do not have a device connected via **USB-C** or the input is connected to USB-A, the tester will inform you about this and skip this graph due to the lack of such contacts, an example is shown below:
>
> ![IMG_20240528_172332](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/4465e063-705b-473b-a3e9-96949952094e)

## Application
![IMG_20240528_185722](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/2edf4742-6736-4471-9b1c-fd436cc80ed9)
The last child menu is the application menu or **Application**, here in the rectangles there are branches to other submenus, which are described below.

It also shows **device operating time** at the bottom, which can be useful in some cases. Regarding management:
- **press (forward button)** we will select different subcategories (the selected one is marked in blue).
- **press (back button)** we will go to the previous menu.
- **pressing (middle button)** will go to a submenu or subcategory.

<h1 align="center">Fast Charge</h1>

##Warning
![IMG_20240528_185651](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/b84a39c4-2723-43bd-a3df-f53ae74e62f6)

When entering the **Fast Charge** subcategory we are greeted with a warning, below there are 3 items to choose from:
- **READY** - transition to fast charging triggers (Samsung AfS, QC2.0, 3.0, etc.).
- **AUTO** - switch to scanning your power supply for the presence of a particular charging protocol.
- **CANCEL** - exit from the subcategory.

## Detection v1.4
![IMG_20240528_221609](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/61513ae1-aaef-4ae7-a267-e4cec1c8b75c)
Let's look at the case of clicking on the **AUTO** item, the detection version is written at the top, the status is **Testig or Finish**, then below, each protocol is tested in turn for its presence in the BP, using the calling method (trigger).

> [!NOTE]
> For more information about the protocols and how they work with Arduino compatible boards, please follow the links below:
>
> [What is fast charging](https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%BE%D1%82%D0%BE%D0%BA%D0%BE%D0%BB%D1%8B_%D0%B1%D1%8B%D1%81%D1%82%D1%80%D0%BE%D0%B9_%D0%B7%D0%B0%D1%80%D1%8F%D0%B4%D0%BA%D0%B8) -> [QC2.0 integration in Arduino](https://github.com/GyverLibs/QuickCharge)
