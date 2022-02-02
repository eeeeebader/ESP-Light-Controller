#pragma once
#include "Effect.cpp"

class StroboEffect : public Effect {
public:
  
  StroboEffect(String effectName, size_t numLeds) : Effect(effectName, numLeds)
  {
    brightness = 255;
    FastLED.setBrightness( brightness );
  }

  StroboEffect(String effectName, size_t numLeds, size_t brightness) : Effect(effectName, numLeds, brightness)
  { 
    
  }

  void loop()
  {
    for(int i = 0; i < numLeds; i++)
    {
      if(i % 2 == 0)
      {
        ledsEffects[i] = CRGB(0,0,0);
        continue;
      }

      ledsEffects[i] = CRGB(225,235,255);
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second); 
    
    for(int i = 0; i < numLeds; i++)
    {
      if(i % 2 == 0)
      {
        ledsEffects[i] = CRGB(225,235,255);
        continue;
      }
      
      ledsEffects[i] = CRGB(0,0,0);
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second); 
  }

  void stop()
  {
    FastLED.clear();
    FastLED.show();
  }

private:
  size_t frames_per_second = 7;
};
