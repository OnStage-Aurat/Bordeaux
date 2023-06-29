#include <Servo.h>

#define SERIALE Serial1

const int triggerPort = 6;
const int echoPort = 7;

Servo mano;
Servo braccio;
Servo dito;
Servo tieni;

// Posizione Iniziale
void posIn();
void fire();
int calcolaDistanza();
void testLunghezza();
void knife();

void setup() {
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);

  SERIALE.begin(9600);

  braccio.attach(2);
  mano.attach(3);
  dito.attach(4);
  tieni.attach(5);
  posIn();
}
char incomingbyte;
void loop() {
  if (SERIALE.available()) {
    incomingbyte = (char)SERIALE.read();
    switch (incomingbyte) {
      case 'f':
        delay(1000);
        testlunghezza(calcolaDistanza());
        delay(1000);
        posIn();
        break;
      case 'k':
        knife();
        delay(1000);
        posIn();
        break;
      default:
        break;
    }
  }
}

void fire()
{
  int var = 120;
  while (var > 40) {
    dito.write(var);
    var -= 3;
  }
  delay(1500);
  tieni.write(110);
  delay(300);
  dito.write(160);
  delay(1500);
  tieni.write(80);
}
void posIn()
{
  braccio.write(150);
  mano.write(30); //70 GRADI --> 190 CM  65--> 170 CM 55--> 150 CM //45 GRADI 65CM, 50 GRADI 90 CM, 55 GRADI
  dito.write(175);
  tieni.write(80);
}
int calcolaDistanza()
{
  int durata = 0, distanza = 0;
  do {
    delay(200);
    digitalWrite(triggerPort, LOW);
    delayMicroseconds(100);
    digitalWrite(triggerPort, HIGH);
    delayMicroseconds(100);
    digitalWrite(triggerPort, LOW);
    durata = pulseIn(echoPort, HIGH);
    distanza = int(0.034 * durata / 2);
  } while (distanza <= 50 || distanza >= 160);
  return distanza;
}
void testlunghezza(int distance) {
  if (distance > 70 && distance < 110) {
    mano.write(58);
    braccio.write(braccio.read() - 5);
  }
  else if (distance > 100 && distance < 130)
    mano.write(65);
  else if (distance > 130 && distance < 160)
    mano.write(70);
  delay(1000);
  fire();
}
void knife()
{
  mano.write(80);
  braccio.write(170);
  delay(400);
  fire();
  delay(500);
  posIn();
  delay(3000);
  mano.write(80);
  braccio.write(140);
  delay(1000);
  fire();
}
