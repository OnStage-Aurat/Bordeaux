#include <Servo.h>
#define DELAYMEDIO delay(800);
#define DELAYCORTO delay(500);è

const int triggerPort = 6;
const int echoPort = 7;

Servo mano;
Servo braccio;
Servo dito;
Servo tieni;

void pos1();
void pos2();

int calcolaDistanza();
void testLunghezza();
void spettacolofinale();


int incomingByte;

void setup() {
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  Serial.begin(9600);

  braccio.attach(2);
  mano.attach(3);
  dito.attach(4);
  tieni.attach(5);
  pos1();

}

void loop() {

  digitalWrite( triggerPort, LOW );
  delayMicroseconds(100);
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds(10);
  digitalWrite(triggerPort, LOW );
  int durata = pulseIn( echoPort, HIGH );
  int distanza = 0.034 * durata / 2;
  incomingByte = 0;
  /* if (Serial.available() > 0) {
     incomingByte = Serial.read();
    }
    switch (incomingByte) {

     case 'G':
       fire1();
       break;

     case 'h':
       spettacolofinale();
       break;

     case 'p':
       testlunghezza(distanza);
       break;
     case 'l':
       testlunghezza(70);
       break;
     case 'k':
       testlunghezza(90);
       break;
     case 'j':
       testlunghezza(150);
       break;

     case 'm': sparaelefante(); break;

     case '0': provatesta(); break;
    }
    incomingByte = 0;
    delay(1500);*/
  if (calcolaDistanza2() < 20)
  {
    delay(500); 
    spettacolofinale();
  }
}

void fire1()
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
void pos1()
{
  braccio.write(150);
  mano.write(30); //70 GRADI --> 190 CM  65--> 170 CM 55--> 150 CM //45 GRADI 65CM, 50 GRADI 90 CM, 55 GRADI
  dito.write(175);
  tieni.write(80);
}
void stop()
{
  int durata = 0;
  int distanza = 0;


  do {
    delay(200);
    digitalWrite(triggerPort, LOW);
    delayMicroseconds(100);
    digitalWrite(triggerPort, HIGH);
    delayMicroseconds(100);
    digitalWrite(triggerPort, LOW);
    durata = pulseIn(echoPort, HIGH);
    distanza = int(0.034 * durata / 2);
   //Serial.println(distanza);
  } while (distanza > 20);
  
}

int calcolaDistanza()
{
  int durata = 0;
  int distanza = 0;


  do {
    delay(200);
    digitalWrite(triggerPort, LOW);
    delayMicroseconds(100);
    digitalWrite(triggerPort, HIGH);
    delayMicroseconds(100);
    digitalWrite(triggerPort, LOW);
    durata = pulseIn(echoPort, HIGH);
    distanza = int(0.034 * durata / 2);
   //Serial.println(distanza);
  } while (distanza <= 50 || distanza >= 160);
  return distanza;
}

int calcolaDistanza2()
{
  int durata = 0;
  int distanza = 0;
    delay(200);
    digitalWrite(triggerPort, LOW);
    delayMicroseconds(100);
    digitalWrite(triggerPort, HIGH);
    delayMicroseconds(100);
    digitalWrite(triggerPort, LOW);
    durata = pulseIn(echoPort, HIGH);
    distanza = int(0.034 * durata / 2);
  return distanza;
}

void testlunghezza(int distance) {
  //Servo mano;
  //mano.attach(3);
 // Serial.println("funzione testLungezza: " + distance);
  /*if (distance > 50 && distance < 70){ 
    mano.write(50);
    braccio.write(braccio.read()-15);
  }
*/
   if (distance > 70 && distance < 110){
    mano.write(58);
     braccio.write(braccio.read()-5);}
    

  else if (distance > 100 && distance < 130)
    mano.write(65);

  else if (distance > 130 && distance < 160)
    mano.write(70);
  delay(1000);
  fire1();
}

void spettacolofinale()
{
  
  sparaelefante();
  delay(700);
  pos1();
  delay(2000);
  for (int i = 0; i < 2; i++) {
    delay(6000);
    testlunghezza(calcolaDistanza());
    delay(1000);
    pos1();
  }
  delay(6000);
  provatesta();
  delay(2000);
  pos1();
}

void sparaelefante()
{
  braccio.write(45);
  mano.write(60);
  fire1();
}


void provatesta()
{
  mano.write(80);
  braccio.write(170);
  delay(400);
  fire1();
  delay(500);
  pos1();
  delay(3000);
  mano.write(80);
  braccio.write(140);
  delay(1000);
  fire1();
}
