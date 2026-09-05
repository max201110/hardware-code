#include <WiFi.h>
#include <Arduino.h>

// ESP32 Wi-Fi scanner: prints nearby networks without storing credentials.
void setup() {
  Serial.begin(115200);
  delay(500);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("Wi-Fi scan ready");
}

void loop() {
  int count = WiFi.scanNetworks();
  Serial.printf("Found %d networks\n", count);
  for (int i = 0; i < count; ++i) {
    Serial.printf("%2d: %s (%d dBm) %s\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "open" : "protected");
  }
  WiFi.scanDelete();
  delay(10000);
}

