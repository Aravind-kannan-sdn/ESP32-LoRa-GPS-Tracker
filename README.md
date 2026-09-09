# DIY ESP32 LoRa GPS Tracker with Live Google Maps Integration

A GPS tracking prototype using an **ESP32**, GPS module and LoRa-ready communication architecture. The ESP32 reads GPS coordinates and generates a Google Maps URL for the current location.

## Features

- ESP32-based GPS tracking
- GPS latitude and longitude extraction
- Google Maps location link generation
- LoRa interface pins reserved for long-range transmission
- Serial Monitor debugging
- Low-cost embedded-system prototype

## Components

- ESP32 development board
- NEO-6M or similar GPS module
- SX1278/RA-02 or similar LoRa module
- Jumper wires
- Breadboard
- USB cable

## Working

1. ESP32 initializes the GPS serial interface.
2. The GPS module sends NMEA data.
3. TinyGPSPlus parses the GPS information.
4. Latitude and longitude are obtained after a valid GPS fix.
5. A Google Maps URL is generated using the coordinates.
6. In a complete version, the coordinates can be transmitted through LoRa to a receiver.

## Example Google Maps Link

```text
https://www.google.com/maps?q=LATITUDE,LONGITUDE
```

## Example Serial Output

```text
ESP32 LoRa GPS Tracker
Waiting for GPS data...
Latitude: 12.XXXXXX
Longitude: 80.XXXXXX
Google Maps: https://www.google.com/maps?q=12.XXXXXX,80.XXXXXX
```

## GPS Connections

| GPS | ESP32 |
|---|---|
| VCC | Suitable supply |
| GND | GND |
| TX | GPS_RX |
| RX | GPS_TX |

## LoRa Pins

| LoRa | ESP32 |
|---|---|
| NSS/SS | GPIO 5 |
| RST | GPIO 14 |
| DIO0 | GPIO 2 |

SPI pins depend on the ESP32 board and LoRa module.

## Required Library

Install **TinyGPSPlus** through the Arduino IDE Library Manager.

For actual LoRa transmission, add the appropriate LoRa library for your module.

## Small Intentional Issue

This version intentionally contains a **small coding mistake**:

```cpp
#define GPS_RX 17
#define GPS_TX 17
```

Both GPS serial pins use the same GPIO. This can cause GPS communication to fail or behave incorrectly.

A typical correction is:

```cpp
#define GPS_RX 16
#define GPS_TX 17
```

The exact pins should match your board and wiring.

## Future Improvements

- Complete LoRa transmitter and receiver
- Live web dashboard
- Automatic map tracking
- OLED display
- Battery monitoring
- Speed and altitude monitoring
- Geofencing
- Data logging
- MQTT/HTTP integration

## Privacy Note

GPS coordinates are sensitive location information. Use tracking systems only with appropriate permission and protect transmitted location data.

## License

MIT License. See `LICENSE`.
