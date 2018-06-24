#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;

int joyX = 0;
int joyY = 1;

int joyVal;
int addVal = 5;
int srNumBottom;
int srNumBase;
int opposite;

void setup() {
  Serial.begin(9600);  
  servo0.attach(2);
  servo1.attach(3);
  servo2.attach(4);
  // put your setup code here, to run once:
  srNumBottom = 90;
  srNumBase = 90;
  opposite = 90;
}

void loop() {
  joyVal = analogRead(joyX);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  if(joyVal > 140){
     if((srNumBottom + addVal) <= 180){
        srNumBottom += addVal; 
     }
  }else if(joyVal < 20){
       if((srNumBottom - addVal) > 0){
         srNumBottom -= addVal;
        }
   }
   delay(100);
   servo0.write(srNumBottom);

    Serial.print("x: ");
    Serial.print(srNumBottom);
    Serial.print("\n");
 
  joyVal = analogRead(joyY);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  
  
  if(joyVal > 140){
     if((srNumBase + addVal) <= 180){
        srNumBase += addVal; 
     }
     if((opposite - addVal) > 0){
           opposite -= addVal;
     }
  }else if(joyVal < 20){
     if((srNumBase - addVal) > 40){
        srNumBase -= addVal;
     }
     if((opposite + addVal) <= 150){
        opposite += addVal; 
     }
   }
  Serial.print("y: ");
    Serial.print(srNumBase);
    Serial.print("\n");
  delay(20);
  
  servo2.write(opposite);
  
  servo1.write(srNumBase);
  delay(15);
  // put your main code here, to run repeatedly:

}
