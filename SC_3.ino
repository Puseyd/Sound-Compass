/*
SC_3
Author: David Pusey & Brandon Delgado

Third iteration of the sound compass. 

*/


const int analogPin1 = A2;
const int analogPin2 = A3;  //Possibly add a space bewteen the variable name and the bracket
const int analogPin3 = A4;
const int analogPin4 = A5;


const int cardinalPins[4] = {5, 7, 9, 11};  // N, E, S, W respectively
const int NEPin = 6;
const int SEPin = 8;
const int SWPin = 10;
const int NWPin = 12;
const int threshold = 390;

int N = 0;  //sensorVal1
int E = 0;  //sensorVal2
int S = 0;  //sensorVal3
int W = 0;  //sensorVal4

int sensArr[4] =  {0, 0, 0, 0 };  //Instantiate the array to 0 to avoid garbage values populating.

void setup() {

  pinMode(analogPin1, INPUT);
  pinMode(analogPin2, INPUT);
  pinMode(analogPin3, INPUT);
  pinMode(analogPin4, INPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(cardinalPins[i], OUTPUT);
  }

  pinMode(NEPin, OUTPUT);
  pinMode(SEPin, OUTPUT);
  pinMode(SWPin, OUTPUT);
  pinMode(NWPin, OUTPUT);

  Serial.begin(9600);

  //int max = max(a, b);

  //Serial.print("The larger value is: ");
  //Serial.println(max);
}

void loop() {
  /*
  We are going to create an array that will hold the values of each sensor.
  Populate the array with the values.
  Take the average of the values
    Which ever two values are greater than average will be used to set the LED state
*/
  int sum = 0;
  float avg = 0;


  sensArr[0] = analogRead(analogPin1);  //N
  sensArr[1] = analogRead(analogPin2);  //E
  sensArr[2] = analogRead(analogPin3);  //S
  sensArr[3] = analogRead(analogPin4);  //W


  for (int i = 0; i < 4; i++) {
    sum += sensArr[i];
  }
  avg = sum / 4.0;

  for (int i = 0; i < 4; i++) {
    if (sensArr[i] > avg) {
      digitalWrite(cardinalPins[i], HIGH);

    } else {
      digitalWrite(cardinalPins[i], LOW);
    }
  }

  if ((sensArr[0] > avg) && (sensArr[1] > avg)) {
    digitalWrite(NEPin, HIGH);
  } else {
    digitalWrite(NEPin, LOW);
  }
  if ((sensArr[1] > avg) && (sensArr[2] > avg)) {
    digitalWrite(SEPin, HIGH);
  } else {
    digitalWrite(SEPin, LOW);
  }
  if ((sensArr[2] > avg) && (sensArr[3] > avg)) {
    digitalWrite(SWPin, HIGH);
  } else {
    digitalWrite(SWPin, LOW);
  }
  if ((sensArr[3] > avg) && (sensArr[0] > avg)) {
    digitalWrite(NWPin, HIGH);
  } else {
    digitalWrite(NWPin, LOW);
  }

  delay(1000);
}
