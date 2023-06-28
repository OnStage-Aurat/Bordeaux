#include <Servo.h>
Servo spalla;
Servo polso;
Servo naso;
Servo giro; 
Servo pinza;
void setup() {
  pinMode(13, OUTPUT);
  spalla.attach(8);
  spalla.write(90);
  Serial.begin(9600);
  polso.attach(9);
  polso.write(30);
  naso.attach(10);
  naso.write(180);
  giro.attach(11);
  giro.write(180);
  pinza.attach(12);
  pinza.write(180);
}
int incoming = 'n';
int gradi = 0;
void loop() {
  if (Serial.available())
    incoming = Serial.read();
  Serial.flush();

  switch (incoming) {
    case '0': spalla.write(100);
      polso.write(30);
      naso.write(180);
      giro.write(180);
      pinza.write(180);
      delay(250);
      break;
    //proboscide
    case 'p': polso.write(130);
      delay(2000);
      polso.write(30);
      break;

    case 'd': gradi = spalla.read() + 1;
      if (gradi < 135)spalla.write(gradi);
      //Serial.println(gradi);
      break;
    case 'D': gradi = spalla.read() + 5;
      if (gradi < 135)spalla.write(gradi);
      //Serial.println(gradi);
      break;
    case 's': gradi = spalla.read() - 1;
      if (gradi > 45)spalla.write(gradi);
      break;
    case 'S': gradi = spalla.read() - 5;
      if (gradi > 45)spalla.write(gradi);
      break;
    case 'k': gradi = polso.read() - 3;
      if (gradi >= 0)polso.write(gradi);
      break;
    case 'i': gradi = polso.read() + 3;
      if (gradi < 180)polso.write(gradi);
      break;

    case 'c': pinza.write(180);
      break;
    case 'a': pinza.write(125);
      break;
    case 't': pinza.write(155);
      break;
    //lava i denti
    case '1': naso.write(50);
      delay(250);
      for (int j = 0; j < 5; j++) {
        for (int gradi = 120; gradi > 90; gradi--) {
          spalla.write(gradi);
          delay(15);
        }
        delay(250);
        for (int gradi = 90; gradi < 120; gradi++) {
          spalla.write(gradi);
          delay(15);
        }

      }
      naso.write(180);
      break;
    //forbici
    case '2': polso.write(80);
      delay(250);
      naso.write(90);
      delay(250);
      for (int j = 0; j < 5; j++) {
        pinza.write(125);
        delay(500);
        pinza.write(180);
        delay(500);
      }
      polso.write(30);
      naso.write(180);
      break;
    case 'n': break;


  }
  incoming = 'n';
}
