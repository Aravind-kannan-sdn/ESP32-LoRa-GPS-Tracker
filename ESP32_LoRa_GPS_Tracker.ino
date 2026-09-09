/*
  DIY ESP32 LoRa GPS Tracker with Live Google Maps Integration

  SMALL INTENTIONAL ISSUE:
  GPS_RX and GPS_TX are assigned to the same GPIO (17).
  Use separate GPIOs, e.g. RX=16 and TX=17, for the corrected version.
*/

#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial GPS(2);

#define LORA_SS   5
#define LORA_RST  14
#define LORA_DIO0 2

// GPS pins
#define GPS_RX 16
#define GPS_TX 17

unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(115200);
  GPS.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);

  Serial.println("ESP32 LoRa GPS Tracker");
  Serial.println("Waiting for GPS data...");
}

void loop() {
  while (GPS.available() > 0) {
    gps.encode(GPS.read());
  }

  if (millis() - lastUpdate >= 5000) {
    lastUpdate = millis();

    if (gps.location.isValid()) {
      double latitude = gps.location.lat();
      double longitude = gps.location.lng();

      Serial.print("Latitude: ");
      Serial.println(latitude, 6);
      Serial.print("Longitude: ");
      Serial.println(longitude, 6);

      Serial.print("Google Maps: https://www.google.com/maps?q=");
      Serial.print(latitude, 6);
      Serial.print(",");
      Serial.println(longitude, 6);
    } else {
      Serial.println("Waiting for valid GPS fix...");
    }
  }
}
