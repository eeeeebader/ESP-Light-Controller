#include "AmbiLightServer.cpp"
#include "RainEffect.cpp"

AmbiLightServer ambiLightServer;

void setup() {
  Serial.begin(115200);
  ambiLightServer.setup();
}

void loop() {
  ambiLightServer.loop();
}
