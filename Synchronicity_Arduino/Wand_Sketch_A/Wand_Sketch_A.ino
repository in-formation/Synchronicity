/*
 * My first Arduino Program
 * writted by ME and NOT an example
 * 
 * But I will be borrowing from many examples
*/

#include <ArduinoBLE.h>

BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service

// BLE LED Switch Characteristic - read and writable by central, increase base number by one
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

const int ledPin = LED_BUILTIN; // pin to use for LED on the board

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // set LED pin to output mode
  pinMode(ledPin, OUTPUT);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed...");

    while(1);
  }

  // Set advertised local name and service UUID
  BLE.setLocalName("Synchronicity");
  BLE.setAdvertisedService(ledService);

  // add the characteristic to the service
  ledService.addCharacteristic(switchCharacteristic);

  // add the service to the device
  BLE.addService(ledService);

  // set initial value for the characteristic to 0
  switchCharacteristic.writeValue(0);

  // start advertising ble device
  BLE.advertise();

  Serial.println("Synchronicity now advertising peripheral");

}

void loop() {
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      // if the remote device wrote to the characteristic,
      // use the value to control the LED:
//      Serial.print("The ledService UUID is: ");
//      Serial.println(ledService.uuid());
      
      if (switchCharacteristic.written()) {
        if (switchCharacteristic.value() == 5) {   // 
          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);         // will turn the LED on
        } else if (switchCharacteristic.value() == 9) {
          Serial.println("LED blink");
          digitalWrite(ledPin, HIGH); 
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          digitalWrite(ledPin, HIGH); 
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          digitalWrite(ledPin, HIGH); 
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          digitalWrite(ledPin, HIGH); 
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        } else {
          Serial.println(F("LED off"));
          digitalWrite(ledPin, LOW);          // will turn the LED off
        }
      }
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}
