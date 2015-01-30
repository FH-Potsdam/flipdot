
/*
flip a flipdot with serial commands
 author: fabianmoronzirfas
 Based on  an example from the Fritzing Creator Kit: www.fritzing.org/creatorkit.
*/

int flip=11; // dot direction one Pin
int flop=10; // dot direction two Pin
int incomingByte = 0;   // for incoming serial data
boolean stopit = true; // run or stop the flipdot
boolean flipit = false; // flip one way
boolean flopit = false; // flop the other way
void setup(){
  Serial.begin(9600); // we need this for Serial input
  pinMode(flip,OUTPUT);        // pin A declared as OUTPUT
  pinMode(flop,OUTPUT);        // pin B declared as OUTPUT
}
void loop(){
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    if(incomingByte == '1'){
      Serial.println(" that means stop the flipdot");
      stopit = true;
    }
    if(incomingByte == '0'){
      Serial.println(" that means flip/flop the flipdot");
      stopit = false;
    }
    if(incomingByte == '5'){
      flipit = true;
      Serial.println(" that means flip the flipdot");
    }
    if(incomingByte == '6'){
      Serial.println(" that means flop the flipdot");
      flopit = true;
    }
  }

  // now if this is true we stop the flip flop
  if(stopit != true){
    digitalWrite(flip,HIGH);     // dot direction one pin switched to HIGH (+5V)
    digitalWrite(flop,LOW);      // dot direction two pin switched to LOW  (GND)
    delay(10);
    digitalWrite(flip,LOW);    // dot direction one pin switched to LOW (GND)  
    delay(1000);


    digitalWrite(flip,LOW);     // dot direction one pin switched to HIGH (GND)
    digitalWrite(flop,HIGH);  // dot direction two pin switched to LOW  (+5V)

    delay(10);
    digitalWrite(flop,LOW);  // dot direction two pin switched to LOW  (GND)
    delay(1000); 
  } 


  // flip once
  if(flipit == true){
    digitalWrite(flop, LOW);
    digitalWrite(flip, HIGH);
    delay(10);
    digitalWrite(flip, LOW);
    flipit = false;
  }
  // flop once
  if(flopit == true){
    digitalWrite(flip, LOW);
    digitalWrite(flop, HIGH);
    delay(10);
    digitalWrite(flop, LOW);
    flopit = false;
  }
}








