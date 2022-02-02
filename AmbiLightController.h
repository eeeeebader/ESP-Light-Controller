#include "Effect.cpp"

class AmbiLightController {
public:
  void setup();
  void stopEffect();
  void startEffect(const String& effect);
  void loopEffect();
  void setBrightness(size_t b);

private:
  Effect* activeEffect = new Effect();
  
  void startFPSTimer(size_t fps);
  void stopTimer();
};
