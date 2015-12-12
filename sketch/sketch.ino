#include <ledcontroller.h>

using LedController::Color;
using LedController::LedStrip;

Color prettyblue(0x6BBAFC);

#define PIN_SDI 2    // Red data wire (not the red 5V wire!)
#define PIN_CKI 3   // Green wire

// RandomMarquee marquee = RandomMarquee();
LedStrip ledStrip = LedStrip(PIN_SDI, PIN_CKI);

void setup() {
  // Clear the LED Strip
  ledStrip.setup();
  ledStrip.clear();
  ledStrip.send();
  
  delay(2000);
  
}

void loop() {
  for (int i = 0; i <= 31; i++) {
    ledStrip.getColors()[i].add(prettyblue.scaled(0.8));
  }

  ledStrip.send();
}

