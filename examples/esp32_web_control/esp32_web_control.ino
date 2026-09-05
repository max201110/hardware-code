#include <WiFi.h>
#include <WebServer.h>

const char* AP_NAME = "SmartCar-Setup";
WebServer server(80);
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

void page() {
  const bool on = digitalRead(LED_BUILTIN);
  String html = "<html><meta name='viewport' content='width=device-width'><body><h1>SmartCar Setup</h1>";
  html += "<p>LED: " + String(on ? "ON" : "OFF") + "</p><a href='/led/on'>ON</a> &nbsp; <a href='/led/off'>OFF</a></body></html>";
  server.send(200, "text/html; charset=utf-8", html);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  WiFi.softAP(AP_NAME);
  Serial.print("Open http://"); Serial.println(WiFi.softAPIP());
  server.on("/", page);
  server.on("/led/on", [] { digitalWrite(LED_BUILTIN, HIGH); page(); });
  server.on("/led/off", [] { digitalWrite(LED_BUILTIN, LOW); page(); });
  server.begin();
}

void loop() { server.handleClient(); }
