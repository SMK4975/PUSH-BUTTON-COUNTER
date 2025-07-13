#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7;
int counter = 0;
bool lastButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Count: ");
  lcd.setCursor(7, 0);
  lcd.print(counter);
}

void loop() {
  bool currentState = digitalRead(buttonPin);
  if (currentState == HIGH && lastButtonState == LOW) {
    counter++;
    lcd.setCursor(7, 0);
    lcd.print("    ");
    lcd.setCursor(7, 0);
    lcd.print(counter);
    delay(200);
  }
  lastButtonState = currentState;
}
