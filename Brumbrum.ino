const int wheelL1pin = 4;
const int wheelL2pin = 6;

const int wheelR1pin = 8;
const int wheelR2pin = 10;

const int trig = 11;
const int echo = 12;
int duracion;
float distancia;

const int onBoardLed = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(wheelL1pin, OUTPUT);
  pinMode(wheelL2pin, OUTPUT);
  pinMode(wheelR1pin, OUTPUT);
  pinMode(wheelR2pin, OUTPUT);

  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);

  pinMode(onBoardLed, OUTPUT);
}

void stop() {
  analogWrite(wheelL1pin, 0);
  analogWrite(wheelL2pin, 0);

  analogWrite(wheelR1pin, 0);
  analogWrite(wheelR2pin, 0);
  
  delay(1000);
}

void brumbrum() {
  analogWrite(wheelL1pin, 100);
  analogWrite(wheelL2pin, 0);
  
  analogWrite(wheelR1pin, 100);
  analogWrite(wheelR2pin, 0);
  
  delay(1000);
}

void brumbrum_nt() {
  analogWrite(wheelL1pin, 0);
  analogWrite(wheelL2pin, 100);

  analogWrite(wheelR1pin, 0);
  analogWrite(wheelR2pin, 100);
  
  delay(1000);
}

void turnLeft() {
  analogWrite(wheelL1pin, 0);
  analogWrite(wheelL2pin, 100);

  analogWrite(wheelR1pin, 100);
  analogWrite(wheelR2pin, 0);
  
  delay(1000);
}

void turnRight() {
  analogWrite(wheelL1pin, 100);
  analogWrite(wheelL2pin, 0);

  analogWrite(wheelR1pin, 0);
  analogWrite(wheelR2pin, 100);
  
  delay(1000);
}

void loop() {
  digitalWrite(trig, HIGH);
  delay(100);
  digitalWrite(trig, LOW);

  duracion = pulseIn(echo, HIGH);
  distancia = duracion/58;

  if(distancia < 15) turnRight();
  else brumbrum();
}
