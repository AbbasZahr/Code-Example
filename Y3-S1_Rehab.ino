#include <IRremote.h> // Include the IRremote library for IR signal processing

IRrecv IR(3);
int relay2 = 9;
int relay = 8;
void setup() {
  // put your setup code here, to run once:
pinMode(relay, OUTPUT);
pinMode(relay2, OUTPUT);
IR.enableIRIn();
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if(IR.decodedIRData.decodedRawData == 0xE619FF00){  
      delay(50);
      digitalWrite(relay, HIGH);
      digitalWrite(relay2, HIGH);
      delay(10000);
      digitalWrite(relay, LOW);
    }
    if(IR.decodedIRData.decodedRawData == 0xE31CFF00){
      delay(50);
      digitalWrite(relay2, LOW);
      digitalWrite(relay,LOW);
      delay(3000);
     
    }
    delay(50);
    IR.resume();
  }
}
