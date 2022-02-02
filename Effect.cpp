#pragma once
#include <FastLED.h> 

#define LED_PIN     32
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    32

static CRGB ledsEffects[NUM_LEDS];

class Effect {
public:
  Effect()
  {
    
  }
  Effect(String effectName, size_t numLeds) : effectName(effectName), numLeds(numLeds)
  {
    brightness = 255;
  };
  Effect(String effectName, size_t numLeds, size_t brighness) : effectName(effectName), numLeds(numLeds), brightness(brighness)
  {
    
  };

  void setup()
  {
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(ledsEffects, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness( brightness );
  }
  
  void setBrightness(size_t v)
  {
    brightness = v;
    FastLED.setBrightness( brightness );
  }
  
  virtual void loop()
  {
  }

  virtual void stop()
  {
  }

  size_t getFPS() const {
    return fps;
  }
  
protected:
  String effectName;
  size_t numLeds;
  size_t brightness;
  size_t fps = 30;
};
