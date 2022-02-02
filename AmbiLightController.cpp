#include "AmbiLightController.h"

#include "FireEffect.cpp"
#include "StroboEffect.cpp"
#include "RainEffect.cpp"
#include "StaticEffect.cpp"


volatile bool doLoop = false; 
volatile SemaphoreHandle_t timerSemaphore;
bool timerIsActive = false;


hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer()
{
  portENTER_CRITICAL_ISR(&timerMux);
  doLoop = true;
  portEXIT_CRITICAL_ISR(&timerMux);

}

void AmbiLightController::setup()
{
  Drop::calcFadeMatrix();
  activeEffect->setup();
  startEffect("rain");
}

void AmbiLightController::stopEffect()
{
  activeEffect->stop();
  stopTimer();
  delete(activeEffect);
  activeEffect = new Effect();
}

void AmbiLightController::startEffect(const String& effect)
{
  if(effect == "fire")
  {
    delete(activeEffect);
    activeEffect = new FireEffect("Ambient Fire", NUM_LEDS);
    startFPSTimer(activeEffect->getFPS());
    Serial.println("Started fire effect");
  }
  if(effect == "strobo")
  {
    delete(activeEffect);
    activeEffect = new StroboEffect("Strobo Party", NUM_LEDS);
    startFPSTimer(activeEffect->getFPS());
    Serial.println("Started strobo effect");
  }
  if(effect == "rain")
  {
    delete(activeEffect);
    activeEffect = new RainEffect("Depression Party", NUM_LEDS);
    startFPSTimer(activeEffect->getFPS());
    Serial.println("Started rain effect");
  }
  if(effect == "static")
  {
    delete(activeEffect);
    activeEffect = new StaticEffect("Static Color x", NUM_LEDS);
    startFPSTimer(activeEffect->getFPS());
    Serial.println("Started static effect");
  }
}

void AmbiLightController::loopEffect()
{
  //do loop according to the fps
  if(doLoop) {
    //Serial.println("Free Heap Size:");
    //Serial.println(xPortGetFreeHeapSize());
    activeEffect->loop(); 
    doLoop = false;
  }
}

void AmbiLightController::setBrightness(size_t b)
{
  activeEffect->setBrightness(b);
}

void AmbiLightController::startFPSTimer(size_t fps) {
  if(timerIsActive) {
    stopTimer();
  }

  timer = timerBegin(0, 80, true);
  // Attach onTimer function to our timer.
  timerAttachInterrupt(timer, &onTimer, true);

  // Set alarm to call onTimer function every second (value in microseconds).
  // Repeat the alarm (third parameter)
    //timerAlarmWrite(timer, 1000000 / (fps * 100000), true);
  timerAlarmWrite(timer, 1000000 / fps, true);
  // Start an alarm
  timerAlarmEnable(timer);

  timerIsActive = true;
}

void AmbiLightController::stopTimer() {
  timerEnd(timer);
  doLoop = false;
  timerIsActive = false;
}
