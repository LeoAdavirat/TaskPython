//LATEST CODE

#include <LiquidCrystal.h>
#include <Stepper.h>

LiquidCrystal lcd(12, 7, 6, 5, 4, 3);  // Initialize the LCD library with the pins you are using

const int buttonHour = A0; // Pin for the button to adjust hours
const int buttonMinute = A1; // Pin for the button to adjust minutes
const int buttonSecond = A2; // Pin for the button to adjust seconds
const int buttonReset = A3; // Pin for the button to reset the timer

int hours = 0;
int minutes = 0;
int seconds = 0;
long int second = 300000;

int initialHours = 0; // Store initial countdown hours
int initialMinutes = 0; // Store initial countdown minutes
int initialSeconds = 0; // Store initial countdown seconds
int previousMillis = 0;

bool startPressed = false; // Flag to track if the start button has been pressed
bool timerFinished = false; // Flag to indicate if the timer has finished
int displayMode = 0; //0 1
// 0 display the timer to configure
// 1 start the timer

// Pin definitions
const int buttonPin = 2;
const int ledPin = 13;
const int motorPins[] = {8, 9, 10, 11};

// Define the number of steps per revolution
const int stepsPerRevolution = 200;

// Initialize the stepper motor object with the number of steps and the pins it's connected to
Stepper myStepper(stepsPerRevolution, motorPins[0], motorPins[1], motorPins[2], motorPins[3]);
//void displayTime();
//void runStepperMotor();
// Variables to track button state and timing
bool allowButtonPress = true;
long int buttonMillis = 0;
bool blinkingLED = false; // Changed to false initially
unsigned long lastButtonPressTime = 0;

bool motorRan = false; // Flag to track if the motor has run

int timerSecond = 300000;

void runStepperMotor() {
  
  // Rotate the motor for 1/3 of a full rotation
  myStepper.step(stepsPerRevolution / 3);

  // Optional delay after motor movement
  delay(500); // Adjust as needed
  // Rotate the motor for 1/3 of a full rotation
  myStepper.step(stepsPerRevolution / 3);

  // Optional delay after motor movement
  delay(500); // Adjust as needed
  // Rotate the motor for 1/3 of a full rotation
  myStepper.step(stepsPerRevolution / 3);

  // Optional delay after motor movement
  delay(500); // Adjust as needed
  // Rotate the motor for 1/3 of a full rotation
  myStepper.step(stepsPerRevolution / 3);

  // Optional delay after motor movement
  delay(500); // Adjust as needed
}

void displayTime(int second) {
  if (second >= 0) {
    lcd.clear();
  lcd.setCursor(0,0);
  int tempSecond = second/1000;
  int displayHour = tempSecond / 3600;
  int displayMinute = (tempSecond - displayHour*60)/60;
  int displaySecond = tempSecond - displayHour * 3600 - displayMinute * 60;
  lcd.print("Time: " + String(displayHour) + ":" + String(displayMinute) +  ":" + String(displaySecond));
  Serial.println("Time: " + String(displayHour) + ":" + String(displayMinute) +  ":" + String(displaySecond));
  }
  // Serial.println(second);
  // ONLY DISPLAY IF IT'S MORE THAN 0
}


void setup() {
  lcd.begin(16, 2);  // Set up the LCD's number of columns and rows
  pinMode(buttonHour, INPUT_PULLUP); // Set button pins as input with pullup resistors
  pinMode(buttonMinute, INPUT_PULLUP);
  pinMode(buttonSecond, INPUT_PULLUP);
  pinMode(buttonReset, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT); // Initialize LED pin
  digitalWrite(ledPin, LOW); // Turn off LED initially
  myStepper.setSpeed(60); // Set the speed of the stepper motor
  
  displayTime(second);
  Serial.begin(9600);
}

void loop() {
  // Display on LCD
  if (displayMode == 0) {displayTime(second);}
  else {displayTime(timerSecond); second = timerSecond;}
  // Serial.println(millis());
  Serial.println(millis() - buttonMillis);
  // Check hour button
  if (digitalRead(buttonHour) == LOW) {
    if (millis() - buttonMillis >= 3000) {
      allowButtonPress = true;
    }
    if (allowButtonPress) {second += 3600000;}
  }
  // Check minute button
  if (digitalRead(buttonMinute) == LOW) {
    if (millis() - buttonMillis >= 3000) {
      allowButtonPress = true;
    }
    if (allowButtonPress) {second += 60000;}
  }

  // check second button
  if (digitalRead(buttonSecond) == LOW) {
    if (millis() - buttonMillis >= 3000) {
      allowButtonPress = true;
    }
    if (allowButtonPress) {second++;}
  }

  // check reset button
  if (digitalRead(buttonReset) == LOW) {
    if (millis() - buttonMillis >= 3000) {
      allowButtonPress = true;
    }
    if (allowButtonPress) {
      if (displayMode == 0) {
        displayMode = 1;
      } else {
        displayMode = 0;
      }
    }
  }

  int interval = millis() - previousMillis;
  second -= interval;

  // Blink LED logic
  if (blinkingLED) {
    digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle LED state
    delay(500);
  }
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    if (second <= 0)
    {// Stop LED blinking
    blinkingLED = false;
    digitalWrite(ledPin, 0);
    // Run stepper motor for 1/3 of a full rotation
    runStepperMotor();

    motorRan = true; // Set motor run flag}
  }

  // Check if the motor has run
  if (motorRan) {
    // Reset countdown timer to initial time
    motorRan = false; // Reset motor run flag
  }
  previousMillis = millis();
}
}
