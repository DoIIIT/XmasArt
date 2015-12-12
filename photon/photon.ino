#include <ledcontroller.h>

using LedController::Color;
using LedController::LedStrip;

Color prettyblue(0xFF0000);
Color prettygreen(0xFFFF00);

int led = D7;

#define PIN_SDI D2    // Red data wire (not the red 5V wire!)
#define PIN_CKI D3   // Green wire

// RandomMarquee marquee = RandomMarquee();
LedStrip ledStrip = LedStrip(PIN_SDI, PIN_CKI);

void setup() {
  pinMode(led,OUTPUT);

  // Clear the LED Strip
  ledStrip.setup();
  ledStrip.clear();
  ledStrip.send();

  Spark.function("led",ledToggle);
  Spark.function("ledstrip",ledStripToggle);

  delay(2000);

}

void loop() {

  /*ledToggle("on");*/
  /*ledStripToggle("on");*/
  /*delay(2000);*/
  /*ledToggle("off");
  ledStripToggle("off");
  delay(2000);*/
}

int ledToggle(String command) {

    if (command=="on") {
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led,LOW);
        return 0;
    }
    else {
        return -1;
    }
}

int ledStripState = 1;

int ledStripToggle(String param) {
  ledStripState = ledStripToggleWithCommand(ledStripState*-1);
  ledToggle("on");
  return 1;
}

int ledStripToggleWithCommand(int command) {
    if (command==1) {
      ledStrip.clear();
        for (int i = 0; i <= 31; i++) {
          ledStrip.getColors()[i].add(prettyblue.scaled(0.8));
        }
        ledStrip.send();
    }
    else if (command==-1) {
        ledStrip.clear();
        for (int i = 0; i <= 31; i++) {
          ledStrip.getColors()[i].add(prettygreen.scaled(0.8));
        }
        ledStrip.send();
    }
    else {
        return -1;
    }
    return command;
}
