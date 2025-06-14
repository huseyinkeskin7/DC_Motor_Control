#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32, 16, 2); // Defines the address of the LCD screen as a 16x2 display with the address 32.

#define clockwisebutton 13 // Clockwise rotation button
#define counterclockwisebutton 12 // Counterclockwise rotation button
#define speedupbutton 2 // Speed increase button
#define speeddownbutton 7 // Speed decrease button
#define redled 9 // Pin for the red LED
#define greenled 8 // Pin for the green LED
#define stopbutton 5 // Stop button
#define enablepin 10 // Enable pin for the motor driver
#define inputone 4 // First direction pin of the motor
#define inputtwo 3 // Second direction pin of the motor
#define bluepin 6 // Pin for the blue LED
// Defines buttons and LEDs used in the system.

int currentSpeed = 31; // Initial speed of the motor is defined.

void setup() {
  lcd.init();       // Initializing the LCD screen
  lcd.backlight(); // Turning on the backlight of the LCD

  // defining pin modes - specifying which connection is input and which is output.
  pinMode(redled, OUTPUT);
  pinMode(inputtwo, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(inputone, OUTPUT);
  pinMode(speeddownbutton, INPUT);
  pinMode(speedupbutton, INPUT);
  pinMode(counterclockwisebutton, INPUT);
  pinMode(clockwisebutton, INPUT);
  pinMode(stopbutton, INPUT);

  // Setting initial states when the system is first started.
  digitalWrite(inputone, LOW); // First direction pin of the motor is set to LOW
  digitalWrite(inputtwo, LOW); // Second direction pin of the motor is set to LOW
  digitalWrite(redled, LOW); // Red LED is set to LOW
  digitalWrite(greenled, LOW); // Green LED is set to LOW

  // Writing messages to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("EEE305 PROJECT-3");
  lcd.setCursor(4, 1);
  lcd.print("GROUP-2");
}

void loop() {
  clockwiseButtonHandler(); // Calls the function for clockwise rotation.
  counterclockwiseButtonHandler(); // Calls the function for counterclockwise rotation.
  speedUpButtonHandler(); // Calls the function for speed increase.
  speedDownButtonHandler(); // Calls the function for speed decrease.
  stopButtonHandler(); // Calls the function for stopping.
  extrastopButtonHandler(); // Calls the function for extra stopping.
}

void clockwiseButtonHandler() {
  if (digitalRead(clockwisebutton) == HIGH) {
    // Checks if the clockwise rotate button is pressed.
    while (digitalRead(clockwisebutton) == HIGH); // Waits until the button is released.
    digitalWrite(inputone, HIGH); // Sends HIGH command to the 1st pin of the driver.
    digitalWrite(inputtwo, LOW); // Sends LOW command to the 2nd pin of the driver.
    analogWrite(enablepin, currentSpeed); // Sets the motor speed.
    digitalWrite(redled, HIGH); // Red LED is turned ON.
    digitalWrite(greenled, LOW); // Green LED is turned OFF.
  }
}

void counterclockwiseButtonHandler() {
  if (digitalRead(counterclockwisebutton) == HIGH) {
    // Checks if the counterclockwise rotate button is pressed.
    while (digitalRead(counterclockwisebutton) == HIGH);
    digitalWrite(inputone, LOW); // Sends LOW command to the 1st pin of the driver.
    digitalWrite(inputtwo, HIGH); // Sends HIGH command to the 2nd pin of the driver.
    analogWrite(enablepin, currentSpeed);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
  }
}

void speedUpButtonHandler() {
  if (digitalRead(speedupbutton) == HIGH) {
    // Checks the status of the speed increase button.
    while (digitalRead(speedupbutton) == HIGH);
    currentSpeed += 63;
    // Increases the current speed.
    if (currentSpeed > 255){
      // Checks the maximum speed limit.
      currentSpeed = 255; // If limit exceeded, sets the motor speed to maximum.
    }
    // Sets motor speed using PWM signal.
    analogWrite(enablepin, currentSpeed);
    analogWrite(bluepin, currentSpeed); // Adjusts the brightness of the blue LED based on motor speed.
  }
}

void speedDownButtonHandler() {
  if (digitalRead(speeddownbutton) == HIGH) {
    while (digitalRead(speeddownbutton) == HIGH);
    // Waits until the button is released.
    currentSpeed -= 63;
    // Decreases the current speed.
    if (currentSpeed < 0) {
      // Checks the minimum speed limit.
      currentSpeed = 31; // If limit exceeded, sets the minimum speed.
    }
    analogWrite(enablepin, currentSpeed); // Sends the motor speed value to the PWM input of the driver.
    analogWrite(bluepin, currentSpeed); // Adjusts the brightness of the blue LED based on motor speed.
  }
}

void stopButtonHandler() {
  if (digitalRead(speedupbutton) == HIGH && digitalRead(speeddownbutton) == HIGH) {
    // Checks if both speed increase and speed decrease buttons are pressed at the same time.
    digitalWrite(inputone, LOW);    // Sends LOW to the first motor input.
    digitalWrite(inputtwo, LOW);   // Sends LOW to the second motor input.
    digitalWrite(redled, LOW);    // Turns off the red LED
    digitalWrite(greenled, LOW); // Turns off the green LED
    digitalWrite(bluepin, LOW); // Turns off the blue LED
    analogWrite(enablepin, 0); // Stops the motor.
  }
}

void extrastopButtonHandler() {
  if (digitalRead(stopbutton) == HIGH) {
    // Checks if the button is pressed.
    digitalWrite(inputone, LOW);    // Sends LOW to the first motor input.
    digitalWrite(inputtwo, LOW);   // Sends LOW to the second motor input.
    digitalWrite(redled, LOW);    // Turns off the red LED
    digitalWrite(greenled, LOW); // Turns off the green LED
    digitalWrite(bluepin, LOW); // Turns off the blue LED
    analogWrite(enablepin, 0); // Stops the motor.
  }
}
