#pragma once

#include <WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "html.cpp"
#include "AmbiLightController.h";
class ClientWsArguments
{
public:
  enum CACommand
  {
    updateEffect,
    updateState,
    updateBrightness,
    none
  };

  CACommand command = none;
  String controllerName = "";
  String effect = "";
  size_t brightness = 0;
  int active = false;
  
  
  ClientWsArguments(String msg)
  {
    while (msg.length() > 0)
    {
      int idxCommand = msg.indexOf(';');
      if (idxCommand == -1 || idxCommand == 0)
        break;
      String m = msg.substring(0, idxCommand);
      String m1 = m.substring(0, msg.indexOf('='));
      String m2 = m.substring(msg.indexOf('=') + 1);
      if (m1 == "command")
      {
        if (m2 == "updateEffect")
        {
          command = updateEffect;
        }
        else if(m2 == "updateState")
        {
          command = updateState;
        }
        else if(m2 == "updateBrightness")
        {
          command = updateBrightness;
        }
      }
      else if (m1 == "brightness")
      {
        brightness = m2.toInt();
      }
      else if (m1 == "active")
      {
        active = m2 == "false" ? 0 : 1;
      }
      else if (m1 == "effect")
      {
        effect = m2;
      }
      else if (m1 == "controllerName")
      {
        controllerName = m2;
      }

      msg.remove(0, idxCommand + 1);
    }
  }
};


static AsyncWebServer server(80);
static AsyncWebSocket ws("/ws");
static AmbiLightController effectController;

class AmbiLightServer
{
public:

  void setup()
  {
    WiFi.softAP(ssid, password);
  
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
  
    initWebSocket();
  
    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send_P(200, "text/html", index_html, processor); });
  
    // Start server
    server.begin();

    effectController.setup();
  }
  
  void loop()
  {
    ws.cleanupClients();
    effectController.loopEffect();
  }


private:
  const char *ssid = "AmbientLights";
  const char *password = "000494806711";
  
  static void notifyClients()
  {
    //ws.textAll(String("{ \"data\": { \"timeAmount\": " + String(counterTime) + ", \"timeRepeats\": " + String(repeats - isrCounter) + ", \"timeRemaining\": " + String(counterTimeRemaining) + ", \"programState\":" + String(programmState) + " }}"));
  }
  static void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
  {
    AwsFrameInfo *info = (AwsFrameInfo *)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
    {
      String msg = "";
  
      for (size_t i = 0; i < info->len; i++)
      {
        msg += (char)data[i];
      }
      Serial.println(msg);
      ClientWsArguments ca(msg);
      if(ca.command == ClientWsArguments::CACommand::updateEffect)
      {
        effectController.startEffect(ca.effect);
      }
      else if(ca.command == ClientWsArguments::CACommand::updateState)
      {
        effectController.stopEffect();
      }
      else if (ca.command == ClientWsArguments::CACommand::updateBrightness) {
        effectController.setBrightness(ca.brightness);
      }
  
      notifyClients();
    }
  }
  static void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
  {
    switch (type)
    {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
    }
  }
  
  void initWebSocket()
  {
    ws.onEvent(onEvent);
    server.addHandler(&ws);
  }
  
  static String processor(const String &var)
  {
    //if (var == "TIMEERAMOUNT")
    //{
      //return String(counterTime);
    //}
  
    return var;
  }

};
