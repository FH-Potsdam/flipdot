// using flipdots from here
// http://www.flipdots.com/

// written by Fabian "fabiantheblind" Moron Zirfas
//
int pinflip = 11;
int pinflop = 12;
int fliptime = 3000;

void setup(){
  pinMode(pinflip, OUTPUT);
  pinMode(pinflop, OUTPUT);  
  digitalWrite(pinflip, HIGH);
  digitalWrite(pinflop, LOW);
}

void loop(){


//  digitalWrite(pinflip, !digitalRead(pinflip));
digitalWrite(pinflip,LOW);
digitalWrite(pinflop,HIGH);
//  digitalWrite(pinflop,!digitalRead(pinflop));
  delay(fliptime);
digitalWrite(pinflop,LOW);
  digitalWrite(pinflip,HIGH);
  delay(fliptime);
}

