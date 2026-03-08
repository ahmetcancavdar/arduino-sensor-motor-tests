// Single Motor Control (Serial: w forward, s backward, x stop)

const int ENA = 10;   // PWM pin
const int IN1 = 9;
const int IN2 = 8;

int speedPWM = 200;   // Speed between 0-255 (adjustable)

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);

  stopMotor();
  Serial.println("Ready: 'w' forward, 's' backward, 'x' stop");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();

    if (c == 'w' || c == 'W') {
      forward();
      Serial.println("Forward");
    } 
    else if (c == 's' || c == 'S') {
      backward();
      Serial.println("Backward");
    } 
    else if (c == 'x' || c == 'X') {
      stopMotor();
      Serial.println("Stop");
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedPWM);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speedPWM);
}

void stopMotor() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
