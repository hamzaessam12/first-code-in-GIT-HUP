#define S_PEEDL 10
#define S_PPEEDR 5
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define s1 11
#define s2 12
#define s3 13

int sl, sm, sr;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(S_PEEDL, 255);
  analogWrite(S_PPEEDR, 255);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(S_PEEDL, 255);
  analogWrite(S_PPEEDR, 255);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(S_PEEDL, 255);
  analogWrite(S_PPEEDR, 255);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(S_PEEDL, 255);
  analogWrite(S_PPEEDR, 255);
}

void stopp() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(S_PEEDL, 0);
  analogWrite(S_PPEEDR, 0);
}

void loop() {
  sl = digitalRead(s1);
  sm = digitalRead(s2);
  sr = digitalRead(s3);

  if (sl == 1 && sm == 1 && sr == 1) {
    stopp();
  } else if (sl == 0 && sm == 1 && sr == 1) {
    right();
  } else if (sl == 1 && sm == 1 && sr == 0) {
    left();
  } else if (sl == 0 && sm == 0 && sr == 0) {
    forward();
  }
}