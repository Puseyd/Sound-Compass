/*
  Knock Sensor

  This sketch reads a piezo element to detect a knocking sound.
  It reads an analog pin and compares the result to a set threshold.
  If the result is greater than the threshold, it writes "knock" to the serial
  port, and toggles the LED on pin 13.

  The circuit:
  - positive connection of the piezo attached to analog in 0
  - negative connection of the piezo attached to ground
  - 1 megohm resistor attached from analog in 0 to ground

  created 25 Mar 2007
  by David Cuartielles <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/sensors/Knock/
*/


// these constants won't change:
/*Arduino PWM (Pulse Width Modulation) pins enable digital pins to simulate analog output (0-5V) by switching on and off rapidly, 
allowing control of LED brightness, motor speeds, and more using analogWrite() (values 0-255). On an Arduino Uno/Nano, 
these pins are 3, 5, 6, 9, 10, and 11, usually marked with a tilde (~ )*/
const int redLedPin = 5;
const int whiteLedPin = 9;
const int blueLedPin = 3;        
const int knockSensor1 = A0;
const int knockSensor2 = A1;  // the piezo is connected to analog pin 0
const int threshold = 1;   // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading1, sensorReading2 = 0; 
 // variable to store the value read from the sensor pin
int ledState = LOW;
int count1, count2 = 0;;     // variable used to store the last LED status, to toggle the light
//Change it to an even more variable led state

void setup() {
  pinMode(redLedPin, OUTPUT); 
  pinMode(whiteLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  //int count = 0;
  sensorReading1 = analogRead(knockSensor1);
  sensorReading2 = analogRead(knockSensor2);
  //Make another variable, a counter. Everytime a knock is registered, the count will be incremented by 1. So when the count is even, the led should be off, or turned off.
  //Otherwise, when the count is odd count % 2 == 1, The led will be turned on.

  // if the sensor reading is greater than the threshold:
  //Consider changing the max brighntess to 127.
  
  if (sensorReading1 >= threshold) { 
    if (count1 % 2 == 0){
      for (int i = 0; i <= 127; i++) {
        analogWrite(redLedPin, i);
        delay(20);
        
        //ledState = 255;
      } 
      count1++;
    } else {
        for (int i = 127; i >=0; i--){
        analogWrite(redLedPin,i);
        delay(10);
        
        }
        count1++;
      }
    
    // toggle the status of the ledPin:
    //ledState = !ledState;
    //Increasing the intensity

    // update the LED pin itself:
    //digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
    Serial.println(count1);
    delay(100);  // delay to avoid overloading the serial port buffer


    //If the redLed is on and the whiteLed is on, then the blue led will be on.
  }
}

/*
int ledPin = 9; // PWM pin
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  // Increase Intensity
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(10);
  }
  // Decrease Intensity
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(10);
  }
  */
