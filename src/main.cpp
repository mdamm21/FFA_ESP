#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Definitionen für Ultraschallsensor
#define trigPin 8  // GPIO 0 orangenes Kabel D8
#define echoPin 4  // GPIO 4 gelbes Kabel   D4

const char* ssid = "4E:50:FC:FC:F7:3A:45";
const char* password = "maxgehtindie4bHI";

void setup() {
// Initialisierung der seriellen Schnittstelle für Debugging
  Serial.begin(115200);

  // Verbindung zum WLAN herstellen
  WiFi.begin(ssid, password);
  if (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Pins für Ultraschallsensor einstellen
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  // Trig-Pin auf HIGH setzen für 10 Mikrosekunden
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo-Pin lesen und die Zeit in Mikrosekunden messen
  duration = pulseIn(echoPin, HIGH);

  // Berechnung der Entfernung in Zentimetern
  distance = (duration / 2) / 29.1;

  // Senden der Entfernung an den Arduino
  Serial.println(distance);

  delay(1000); // 1 Sekunde warten, bevor der nächste Wert gemessen wird
}