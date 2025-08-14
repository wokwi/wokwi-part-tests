# Wokwi Part Tests

This repository contains a set of test projects for many Wokwi parts. The tests can be compiled using platformio and then run using the [Wokwi CLI](https://docs.wokwi.com/wokwi-ci/cli-installation).

## List of Tests

- board-ssd1306
  - [ESP32](./board-ssd1306/oled-esp32/)
- wokwi-analog-joystick
  - [Arduino Uno](./wokwi-analog-joystick/joystick-uno/)
- wokwi-dht22
  - [Arduino Uno](./wokwi-dht22/dht22-uno/)
  - [ESP32](./wokwi-dht22/dht22-esp32/)
  - [Raspberry Pi Pico](./wokwi-dht22/dht22-pico/)
  - [STM32L0](./wokwi-dht22/dht22-stm32/)
- wokwi-ili9341
  - [Arduino Uno](./wokwi-ili9341/lcd-uno/)
- wokwi-lcd1602
  - [Arduino Uno](./wokwi-lcd1602/lcd-uno/)
  - [ESP32-C3 + I2C](./wokwi-lcd1602/lcd-i2c-esp32-c3/)
- wokwi-micro-sd
  - [ESP32](./wokwi-micro-sd/sd-esp32/)
- wokwi-slide-potentiometer
  - [Arduino Uno](./wokwi-slide-potentiometer/pot-uno/)
  - [ESP32](./wokwi-slide-potentiometer/pot-esp32/)

## Running the tests

To build the test projects and run the tests, you need to install [PlatformIO Core](https://platformio.org/install/cli) and the [Wokwi CLI](https://docs.wokwi.com/wokwi-ci/cli-installation), get a [Wokwi CI token](https://wokwi.com/dashboard/ci) and set the `WOKWI_CLI_TOKEN` environment variable with the token.

Then use `pio run` to compile the project and `wokwi-cli . --scenario <scenario_file_name>.yaml` to run the tests. You can also use [Wokwi for VS Code](https://docs.wokwi.com/vscode/getting-started) to interactively simulate the test projects.

For example, to compile and run the tests for the `wokwi-dht22` part on the ESP32, you can use the following commands:

```
cd wokwi-dht22/dht22-esp32
pio run
wokwi-cli . --scenario dht22.test.yaml
```

The output of the test should look as follows this:

```
Wokwi CLI v0.16.0 (ff220a404971)
Connected to Wokwi Simulation API 1.0.0-0000000-g00000000
Starting simulation...
ets Jul 29 2019 12:21:46

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:1156
load:0x40078000,len:11456
ho 0 tail 12 room 4
load:0x40080400,len:2972
entry 0x400805dc
[DHT22 Sensor Test (ESP32)] Expected text matched: "ets Jul 29 2019 12:21:46"
DHT22 test!
[DHT22 Sensor Test (ESP32)] Expected text matched: "DHT22 test!"
[DHT22 Sensor Test (ESP32)] delay 500ms
Humidity: 45.80%  Temperature: 23.50Â°C
[DHT22 Sensor Test (ESP32)] Expected text matched: "Humidity: 45.80%  Temperature: 23.50Â°C"
[DHT22 Sensor Test (ESP32)] delay 500ms
Humidity: 45.80%  Temperature: 23.50Â°C
[DHT22 Sensor Test (ESP32)] Expected text matched: "Humidity: 45.80%  Temperature: 23.50Â°C"
[DHT22 Sensor Test (ESP32)] delay 500ms
Humidity: 66.90%  Temperature: 21.50Â°C
[DHT22 Sensor Test (ESP32)] Expected text matched: "Humidity: 66.90%  Temperature: 21.50Â°C"
[DHT22 Sensor Test (ESP32)] Scenario completed successfully
```
