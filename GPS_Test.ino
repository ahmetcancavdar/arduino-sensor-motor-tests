#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4;   // GPS TX -> Arduino pin 4
static const int TXPin = 3;   // GPS RX -> Arduino pin 3
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);
}

void loop() {
  // GPS'den gelen tüm verileri TinyGPS++'a okut
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  // Yeni bir konum geldiyse seri porta yazdır
  if (gps.location.isUpdated()) {
    Serial.print(gps.location.lat(), 6);
    Serial.print(",");
    Serial.println(gps.location.lng(), 6);
  }
}
