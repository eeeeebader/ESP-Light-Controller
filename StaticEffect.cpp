#include "Effect.cpp"

class StaticEffect : public Effect {
public:
  StaticEffect(String effectName, size_t numLeds) : Effect(effectName, numLeds)
  {
    brightness = 120;
    FastLED.setBrightness( brightness );
  }

  StaticEffect(String effectName, size_t numLeds, size_t brightness) : Effect(effectName, numLeds, brightness)
  { 
  }

  void loop()
  {
    for(int i = 0; i < NUM_LEDS; i++) {
      ledsEffects[i] = CRGB(240,70,10);
    }

    FastLED.show();
  }

  void stop()
  {
    
  }

private:  
};
