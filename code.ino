#include <Keyboard.h>

const int switchPin = 9;
int switchState = HIGH;
int prevSwitchState = HIGH;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  switchState = digitalRead(switchPin);
  
  if (switchState == LOW && prevSwitchState == HIGH) {
    Keyboard.print("PARAFUSOS_PRESENTES");
    delay(100); // Delay to ensure all characters are typed
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(1000); // Delay to avoid repeated key presses
  }
  
  prevSwitchState = switchState;
}
