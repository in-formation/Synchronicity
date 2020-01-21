/*
 * My first Arduino Program
 * writted by ME and NOT an example
 * 
 * But I will be borrowing from many examples
*/

#include <ArduinoBLE.h>
#include <Adafruit_NeoPixel.h>


BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // BLE LED Service

// BLE LED Switch Characteristic - read and writable by central, increase base number by one
BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

const int ledPin = LED_BUILTIN; // pin to use for LED on the board
const int PIN = 12; // pin to use for Neopixels
const int ledCount = 7;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledCount, PIN, NEO_GRB + NEO_KHZ800);

int alpha; // Current value of the pixels
int dir = 1; // Direction of the pixels... 1 = getting brighter, 0 = getting dimmer
int flip; // Randomly flip the direction every once in a while
int minAlpha = 25; // Min value of brightness
int maxAlpha = 100; // Max value of brightness
int alphaDelta = 5; // Delta of brightness between times through the loop

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

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void colorSet(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
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
        if (switchCharacteristic.value() == 0) {
          strip.clear();
        }
        if (switchCharacteristic.value() == 1) {
          colorSet(strip.Color(255, 51, 204)); // magenta light ON
        }
        if (switchCharacteristic.value() == 5) {   // 
          flip = random(32);
          if(flip > 20) {
            dir = 1 - dir;
          }
          if(dir == 1) {
            alpha += alphaDelta;
          }
          if(dir == 0) {
            alpha -= alphaDelta;
          }
          if(alpha < minAlpha) {
            alpha = minAlpha;
            dir = 1;
          }
          if(alpha > maxAlpha) {
            alpha = maxAlpha;
            dir = 0;
          }
          colorSet(strip.Color(alpha, 0, 0)); // Red
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

//void colorSet(uint32_t c) {
//  for(uint16_t i=0; i<strip.numPixels(); i++) {
//    strip.setPixelColor(i, c);
//    strip.show();
//  }
//}
