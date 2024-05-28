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

![TFT-2 0-inch-IC-ST7789V-RGB-240x320-SPI-wymiary-](https://github.com/Vispixad/ESP32-USB-Tester/assets/161984981/62fba501-9909-4379-95e9 -d13d091512f1)

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
Next come various ports, buttons, harness and the MK board itself - this is ESP32-S3N16R8. It has 16 MB of permanent memory (PSRAM), 8 MB of random access memory (RAM).
