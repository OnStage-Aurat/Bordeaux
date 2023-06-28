#include <Servo.h>

Servo OX1;
Servo OY1;

Servo OX2;
Servo OY2;

Servo bocca1;
Servo bocca2;

Servo soprac1;
Servo soprac2;

char IncomingByte = 'n';

void setup()
{

  Serial.begin(9600);
  OX1.attach(2); // Quello a sinistra
  OY1.attach(3);
  OX2.attach(4); // Quello a destra
  OY2.attach(5);
  bocca1.attach(6); //quella a sinistra
  bocca2.attach(7); //quella a destra
  soprac1.attach(8); //quella  a destra
  soprac2.attach(9); //quella a sinistra
  bocca1.write(160);
  bocca2.write(30);
  soprac1.write(90);
  soprac2.write(70);
  OX1.write(80);
  OX2.write(80);
  OY1.write(50);
  OY2.write(100);
}

void loop() {
  if (Serial.available() > 0) {
    IncomingByte = Serial.read();
  }
  Serial.println(IncomingByte);
  switch (IncomingByte) {
    case 't': guardosx(); break;
    case 's': stupito(); break;
    case 'd': felice(); break;
    case 'l': neutro(); break;
    case 'k': oscillaocchi();break; 
    case 'n': break;
  }
  IncomingByte = 'n';
}
void oscillaocchi() 
{
  delay(500);
  OX1.write(50);
  OX2.write(50); 
  delay(500);
  OX1.write(120);
  OX2.write(120);
}

void stupito() {
  bocca1.write(160);
  bocca2.write(30);
  soprac1.write(70);
  soprac2.write(90);
  OX1.write(80);
  OX2.write(80);
  OY1.write(50);
  OY2.write(100);
}

void felice() { // da fare
  soprac2.write(70);
  soprac1.write(80);
   bocca1.write(70);
  bocca2.write(130);
   OY1.write(50);
  OY2.write(100);
  OX1.write(80);
  OX2.write(90);
  
}

void rabbia() { // da fare
  soprac1.write(75);
  soprac2.write(80);
  bocca1.write(10);
  bocca2.write(150);
  OX1.write(100);
  OX2.write(70);
  OY1.write(50);
  OY2.write(90);

}
void triste() { // da fare
  soprac2.write(150);
  soprac1.write(15);
  OY1.write(130);
  OY2.write(50);
  bocca1.write(160);
  bocca2.write(40);



}
void neutro() { // da fare
  soprac2.write(110);
  soprac1.write(50);
  OY1.write(50);
  OY2.write(100);
  OX1.write(80);
  OX2.write(90);
  bocca1.write(120);
  bocca2.write(100);

}
void centrato()
{
  OY1.write(50);
  OY2.write(100);
  OX1.write(80);
  OX2.write(90);
}
void guardodx()
{
  OX1.write(50);
  OX2.write(50);
}

void guardosx()
{
  OX1.write(120);
  OX2.write(120);
}
