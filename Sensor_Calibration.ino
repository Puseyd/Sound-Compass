
/*
Sesnor Calibration
*/
const int pin4 = A5; //Change the pin number accordingly
const int pin3 = A4; //Change the pin number accordingly

const int pin2 = A3; //Change the pin number accordingly

const int pin1 = A2; //Change the pin number accordingly

int S1, S2, S3, S4;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);


  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  S1 = analogRead(pin1);
  S2 = analogRead(pin2);
  S3 = analogRead(pin3);
  S4 = analogRead(pin4);



  Serial.println("Pin1: ");
  Serial.println(S1);
  Serial.println("Pin2: ");
  Serial.println(S2);
  Serial.println("Pin3: ");
  Serial.println(S3);
  Serial.println("Pin4: ");
  Serial.println(S4);

  delay(500);
}
