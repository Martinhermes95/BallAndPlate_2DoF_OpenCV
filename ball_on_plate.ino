#include <Servo.h>
Servo servox;
Servo servoy;

int DadoX = 90;
int DadoY = 90;
int Cont = 0;

void setup() {
Serial.begin(115200); // set the baud rate
Serial.println("Ready"); // print "Ready" once
servox.attach(9);
servoy.attach(10);
}

void loop() {

if (Serial.available()) {
    Cont = 1;
    while(Cont < 3){
      if (Serial.available()) {
      DadoY = DadoX;
      DadoX = Serial.read();
      Cont = Cont + 1;
      }
  }
  
servoy.write(DadoY);
servox.write(DadoX);
}
}
