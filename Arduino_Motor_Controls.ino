const int AIN1 = 13;
const int AIN2 = 12;
const int PWMA = 11;
const int button = 7;
const int switchPin = 8;
int motorSpeed;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  motorSpeed = analogRead(A0)/5+50;
  if (digitalRead(button) == LOW) {
    spinMotor(motorSpeed);
  } else {
    spinMotor(0);
  }
  Serial.println(motorSpeed);
}

void spinMotor(int motorSpeed)
{
  if (motorSpeed > 255)
  {
    motorSpeed = 255;                    
  }
  if (digitalRead(switchPin) == LOW) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }
  analogWrite(PWMA, motorSpeed);
}

