# Synchronicity iOS Application
Synchronicity is an iOS application that controls an LED wearable via Bluetooth communication.

## Video Demo
[![Synchronicity Video Demo](https://i.imgur.com/r8Klbsv.png)](https://vimeo.com/416465739 "Synchronicity Video Demo")

## Getting Started
This project can be broken up into three different portions:
1. iOS Application
2. Arduino Program
3. Hardware Required (and not required)

### iOS Application
This app will require the use of Xcode and will be written in Swift language. It also utilizes the already installed bluetooth library called CoreBluetooth.

```
Install Xcode
```
Xcode can be found in the 
[Mac App Store](https://apps.apple.com/us/app/xcode/id497799835)

The program is written using Swift language and the 
[CoreBluetooth library](https://developer.apple.com/documentation/corebluetooth) for Xcode/Swift. No additional downloading is needed to utilize the library as it comes pre-installed on Xcode.

From here, you will be able to build the app and deploy onto your iOS device.
**Note: Depending on your Mac OS, Bluetooth Low Energy may or may not be supported on the Xcode simulator.** It is recommended to deploy on your personal device.

### Arduino Program
The Arduino board program needs to be uploaded using the 
[Arduino IDE.](https://www.arduino.cc/en/main/software)

After downloading the Arduino IDE software onto your machine, you will need to download the drivers for the specific board being used. Navigate to the top menu and go to:
```
Tools --> Board --> Boards Manager...
```
From here type the name of the board in the search bar, `Arduino Nano 33 BLE`, and click **Install** to install the related drivers.

Two additional Arduino libraries will need to be downloaded:
1. ArduinoBLE
2. Adafruit NeoPixel

In order to download Arduino libraries, navigate to the top menu and go to:
```
Tools --> Manage Libraries...
```
In the search bar, type `ArduinoBLE` and click **Install**. Do the same for the multiple `Adafruit Neopixel` library.

#### Uploading a Program onto the Board
Ensure you choose the correct Port before uploading the program.

Additionally, depending on how many LEDs you are using, you may need adjust the number of LEDs when setting up the Adafruit NeoPixel object.

The setup for this project relies on Pin 12 for the data output of the NeoPixels but this can be updated to what your project requires. Be sure to update the Pin # in the Arduino program if you do not use Pin 12.

Once all the steps above have been completed, you will be able upload the program onto the board.

### Hardware Required
* [Arduino Nano 33 BLE (with or without headers installed)](https://store.arduino.cc/usa/nano-33-ble)
* [NeoPixel Jewels](https://www.adafruit.com/product/2226)
  * This project uses three NeoPixel Jewels, total of 21 LEDs
* Solid core wires
* [LiIon/LiPoly Backpack Add-On](https://www.adafruit.com/product/2124)
  * Or any way to power circuit off battery power
* [LiIon/LiPoly Battery 3.7V 500mAh](https://www.adafruit.com/product/1578)
  * Amperage can vary but 500mAh was enough for initial project requirements

#### Additional Hardware Recommended
* [Adafruit Micro Lipo - USB LiIon/LiPoly charger](https://www.adafruit.com/product/1304)
  * Used the charge batteries so you don't have to keep buying new ones
* Breadboard
* Jumper wires
* Solid core wires
* Solder iron and solder
* Wire cutters/strippers

## Synchronicity Wire Schematic
![Synchronicity_Wire_Diagram](/images/Synchronicity_Wire_Sketch.png)

## Authors
**Farah Davoodi** | [https://github.com/in-formation](https://github.com/in-formation)

## Acknowledgements
Thank you to Adafruit for their amazing tutorial on creating a [Bluetooth Arduino application using Xcode/Swift.](https://learn.adafruit.com/crack-the-code)
Specific thanks to user TrevKnows, [https://github.com/TrevKnows](https://github.com/TrevKnows), for creating the tutorial that greatly helped create Synchronicity.

Thank you to Arduino for their [Arduino Bluetooth Low Energy Library](https://github.com/arduino-libraries/ArduinoBLE) that had a great example Arduino sketch that vastly helped my project connect to the iOS application.
