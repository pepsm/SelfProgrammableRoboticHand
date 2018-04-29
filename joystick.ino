#include <Servo.h>
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            
#define VOUT_JOY_PIN A2          
#define XJOY_PIN A1                  
Servo myservo ;

void setup() 
{
  Serial.begin(9600);
  pinMode(VOUT_JOY_PIN, OUTPUT) ;    
  pinMode(GROUND_JOY_PIN, OUTPUT) ;  
  digitalWrite(VOUT_JOY_PIN, HIGH) ; 
  digitalWrite(GROUND_JOY_PIN,LOW) ; 
  myservo.attach(9); 
}

void loop() 
{
  delay(200);                    
  int joystickXVal = analogRead(XJOY_PIN) ;  
  Serial.print(joystickXVal);                
  Serial.println(" = input from joystick");  
  Serial.print((joystickXVal+544)/10);       
  Serial.println(" = output to servo");      
  Serial.println() ;
  myservo.write((joystickXVal+544)/10);     
}

