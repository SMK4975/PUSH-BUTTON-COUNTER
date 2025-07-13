# PUSH-BUTTON-COUNTER

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: SEEPANA MURALIKRISHNA

*INTERN ID*: CT08DF1739

*DOMAIN*: EMBEDDED SYSTEMS

*DURATION*: 8 WEEKS

*MENTOR*: NEELA SANTOSH

# 🔢 Task 1: Push Button Counter

## 📘 Objective

The goal of this project is to build a **Push Button Counter** using an **Arduino Uno** and a **16x2 LCD Display**. Every time a button is pressed, the counter increments by 1 and displays the updated value on the LCD screen. This type of project demonstrates how to use digital input (a push button) and output (LCD display) effectively, and is applicable in simple user interfaces such as visitor counters, product counters, and more.


## 💻 Software Used

* **Tinkercad Circuits** – An online electronics simulator used to build and test the complete circuit without physical hardware.
* **Arduino IDE (structure)** – Code is written in C language using Arduino’s syntax and structure.
* **LiquidCrystal Library** – For controlling the 16x2 LCD in 4-bit mode.


## 🧰 Components Used

* Arduino Uno – 1
* 16x2 LCD Display – 1
* Push Button – 1
* 10kΩ Resistor – 1 (pull-down)
* 10kΩ Potentiometer – 1 (for LCD contrast)
* 220Ω Resistor – 1 (optional for LCD backlight)
* Breadboard – 1
* Jumper Wires – As required


## 🔌 Circuit Connections

### LCD (16x2) Connections

| LCD Pin  | Arduino Pin / Connection |
| -------- | ------------------------ |
| VSS      | GND                      |
| VDD      | 5V                       |
| V0       | Center of potentiometer  |
| RS       | D12                      |
| RW       | GND                      |
| E        | D11                      |
| D4       | D5                       |
| D5       | D4                       |
| D6       | D3                       |
| D7       | D2                       |
| A (LED+) | 5V via 220Ω resistor     |
| K (LED-) | GND                      |

### Potentiometer Connections

* One side → 5V
* Other side → GND
* Center → LCD pin 3 (V0)

### Push Button Connections

* One terminal → 5V
* Other terminal → D7 and GND via 10kΩ resistor (pull-down)


## 🧠 Working Principle

When the push button is pressed, the Arduino detects a digital HIGH signal at pin D7. A simple debounce delay prevents false multiple increments. When the press is confirmed, the counter variable is increased by one. The LCD updates the display with the new count value.

The LCD is run in 4-bit mode using the LiquidCrystal library, which helps reduce the number of data pins used. The system initializes the LCD, displays the word “Count:” and updates the number every time the button is pressed.


## 💻 Code (Arduino C)

```c
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
    delay(200);  // Debounce delay
  }
  lastButtonState = currentState;
}
```


## ▶️ Simulation Output

* When the simulation starts, the LCD displays "Count: 0".
* Each time the push button is clicked (simulated by mouse in Tinkercad), the counter increases by one and the new value is shown on the LCD.
* The delay ensures that bouncing doesn't cause false triggers.


## 🧪 Steps to Simulate in Tinkercad

1. Go to [https://www.tinkercad.com/](https://www.tinkercad.com/)
2. Log in and go to **Circuits → Create New Circuit**
3. Drag and place the following components:

   * Arduino Uno
   * 16x2 LCD
   * Breadboard
   * Push Button
   * 10kΩ Potentiometer
4. Connect all components as per the circuit description above.
5. Paste the code in the **Code Editor** (select "Text" mode).
6. Click **“Start Simulation”**
7. Press the button on the screen and observe the LCD update in real-time.

## Output

<img width="1920" height="1140" alt="Image" src="https://github.com/user-attachments/assets/e0ea71a4-6853-466e-8c20-7651b8278420" />

## 🎯 Final Notes

This project demonstrates fundamental skills in interfacing input and output components with a microcontroller. It uses embedded C programming in the Arduino IDE environment and simulates all functionality in Tinkercad Circuits. It is ideal for beginners exploring embedded systems and digital electronics.

