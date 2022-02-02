#include <cmath>
#include <vector>
#include <exception>

#include "Effect.cpp"

using namespace std;

static int ledWaveLength = 15;
static vector<float> fadeMatrix;
  
class Drop {
public:
  static void calcFadeMatrix() {
    float max_value = 2.5+ 0.08 * (sin(1.2 * 0.01) / (0.01 * 0.01));
    for(int i = -ledWaveLength*2; i < ledWaveLength*2; i++) {
      float current_value = 2.5 + 0.08 * (sin(1.2 * abs(i + 0.01)) / (0.01 * abs(i + 0.01)));
      float p = (max_value / 100) * current_value;
      fadeMatrix.push_back(p);
    }
  }
  Drop(size_t startPos, size_t endPos) : cycle(0) {
    pos = random(startPos, endPos); 
    r = 240;
    g = 70; 
    b = 10;
  }
  Drop(int pos, int relativePos, size_t cycle) : pos(pos), relativePos(relativePos), cycle(cycle) {
    int posFadeMatrix = (fadeMatrix.size() / 2) + relativePos;
    float p = fadeMatrix.at(posFadeMatrix);
    r = 240 * p;
    g = 70 * p; 
    b = 10 * p;
  };

  void reduce() {
    r -= 15;
    g -= 6;
    b -= 3;
  }

  int pos = 0;
  int relativePos = 0;
  size_t cycle = 0;
  int r = 0;
  int g = 0;
  int b = 0;

  int minR = 11;
  int minG = 11;
  int minB = 0;
private:
};

class RainDrop {
public:  
  RainDrop(size_t numLeds) : numLeds(numLeds) {
    if(fadeMatrix.size() <= 0)
    {
      Drop::calcFadeMatrix();
    }
    dropWave.push_back(Drop(10, numLeds - 10));   
  };

  void loop() {
    for(int i = 0; i < dropWave.size(); i++) {
      auto& drop = dropWave.at(i);
      drop.reduce();
      if(drop.cycle == 1 && abs(drop.relativePos) < ledWaveLength)
      {
        if(drop.relativePos <= 0 && drop.pos - 1 > 0 )
          dropWave.push_back(Drop(drop.pos - 1, drop.relativePos - 1, 0));
        if(drop.relativePos >= 0 && drop.pos + 1 < numLeds)
          dropWave.push_back(Drop(drop.pos + 1, drop.relativePos + 1, 0));
      }
      drop.cycle++;
      ledsEffects[drop.pos] = CRGB(max(min(drop.r + ledsEffects[drop.pos].r, 240), 12), max(min(drop.g + ledsEffects[drop.pos].g, 70), 4), max(min(drop.b + ledsEffects[drop.pos].b, 10), 0));
    }
  }

  size_t getMaxCycle() {
    return dropWave.at(0).cycle;
  }

  bool isEveryDropZero() {
    for(const auto& drop : dropWave) {
      if(drop.r >= 11 || drop.b >= 11 || drop.b > 0) {
        return false;
      }
    }
    return true;
  }

  bool doDelete() {
    return dropWave.size() >= 2 * ledWaveLength + 1 && isEveryDropZero() || dropWave.at(0).cycle > 150;
  }
private:
  vector<Drop> dropWave;
  size_t dropSpawnCycle = 5;
  size_t numLeds = 0;
  
};

class RainEffect : public Effect {
public:
  RainEffect(String effectName, size_t numLeds) : Effect(effectName, numLeds)
  {
    brightness = 255;
    FastLED.setBrightness( brightness );
    fps = 20;
  }

  RainEffect(String effectName, size_t numLeds, size_t brightness) : Effect(effectName, numLeds, brightness)
  { 
    fps = 20;
  }
  
  void loop() {
      
    bool doSpawn = random(0, 1000) <= 950 ? true : false;
    if(doSpawn && rainDrops.size() < 25)
    {
      rainDrops.push_back(RainDrop(numLeds));
    }
    resetLed();
    for(int i = 0; i < rainDrops.size(); i++) 
    {
      if(rainDrops.at(i).doDelete())
      {
        rainDrops.erase(rainDrops.begin() + i);
        i--;
        continue;
      }
       rainDrops.at(i).loop();
    }

    if(rainDrops.size() == 0) {
      rainDrops.push_back(RainDrop(numLeds));   
    }
    
    FastLED.show();
  }



  void stop() {
    FastLED.clear();
    FastLED.show();
  }


private:
  void resetLed() {
    for(int i = 0; i < NUM_LEDS; i++) {
      ledsEffects[i] = CRGB(12,4,0);
    }
  }

  vector<RainDrop> rainDrops; 
  
};
