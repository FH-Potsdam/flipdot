/*
flip a flipdot
 author: fabianmoronzirfas
 Based on  an example from the Fritzing Creator Kit: www.fritzing.org/creatorkit.
 */
int flip=11;                    // dot direction one Pin
int flop=10;                    // dot direction two Pin
void setup(){
  pinMode(flip,OUTPUT);        // pin A declared as OUTPUT
  pinMode(flop,OUTPUT);        // pin B declared as OUTPUT
}
void loop(){
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



