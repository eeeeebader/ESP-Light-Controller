#pragma once
#include "Effect.cpp"

class FireEffect : public Effect {
public:
  FireEffect(String effectName, size_t numLeds) : Effect(effectName, numLeds)
  {
    brightness = 255;
    FastLED.setBrightness( brightness );
  }

  FireEffect(String effectName, size_t numLeds, size_t brightness) : Effect(effectName, numLeds, brightness)
  { 
  }

  void loop()
  {
    Fire2012();
  
    FastLED.show();
  }

  void stop()
  {
    memset(heat, 0, sizeof(heat));
    FastLED.clear();
    FastLED.show();
  }

private:
  bool gReverseDirection = false;
  size_t cooling = 55;
  size_t sparking = 120;
  size_t frames_per_second = 30;
  byte heat[NUM_LEDS];
  
  
  void Fire2012()
  {
    // Step 1.  Cool down every cell a little
      for( int i = 0; i < numLeds; i++) {
        heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / numLeds) + 2));
      }
    
      // Step 2.  Heat from each cell drifts 'up' and diffuses a little
      for( int k= numLeds - 1; k >= 2; k--) {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 5] ) / 3;
      }
      
      // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
      if( random8() < sparking ) {
        int y = random8(7);
        heat[y] = qadd8( heat[y], random8(160,255) );
      }
  
      // Step 4.  Map from heat cells to LED colors
      for( int j = 0; j < numLeds; j++) {
        CRGB color = HeatColor( heat[j]);
        int pixelnumber;
        if( gReverseDirection ) {
          pixelnumber = (numLeds-1) - j;
        } else {
          pixelnumber = j;
        }
        ledsEffects[pixelnumber] = color;
      }
  }
};
