# Synchronicity iOS Application
Synchronicity is an iOS application that controls an LED wearable via Bluetooth communication.

## Getting Started
This project can be broken up into three different portions:
1. iOS Application
2. Arduino program
3. Hardware

### iOS Application
This app will require the use of Xcode and will be written in Swift language. It also utilizes the already installed bluetooth library called CoreBluetooth.

```
Install Xcode
```
Xcode can be found in the 
[Mac App Store](https://apps.apple.com/us/app/xcode/id497799835)

The program is written using Swift language and the 
[CoreBluetooth library](https://developer.apple.com/documentation/corebluetooth) for Xcode/Swift. No additional downloading is needed to utilize the library as it comes pre installed on Xcode.

### Arduino Program
The Arduino board program needs to be uploaded using the 
[Arduino IDE.](https://www.arduino.cc/en/main/software)

### Hardware Required
* [Arduino Nano 33 BLE (with or without headers installed)](https://store.arduino.cc/usa/nano-33-ble)
* Neopixel Jewel
