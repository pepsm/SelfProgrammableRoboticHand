#include <Servo.h>
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            
#define VOUT_JOY_PIN A2          
#define YJOY_PIN A1      
#define XJOY_PIN A0  
#define POT_PIN A4             

Servo myservo1 ;
Servo myservo2 ;
Servo myservo3 ;

int led_first_servo = 13;
int led_second_servo = 12;
int led_third_servo = 11;
long pot_pin_val = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(VOUT_JOY_PIN, OUTPUT) ;    
  pinMode(GROUND_JOY_PIN, OUTPUT) ;  
  digitalWrite(VOUT_JOY_PIN, HIGH) ; 
  digitalWrite(GROUND_JOY_PIN,LOW) ; 
  myservo1.attach(9); 
  myservo2.attach(8);
  myservo3.attach(7);
  pinMode(led_first_servo, OUTPUT);
  pinMode(led_second_servo, OUTPUT);
  pinMode(led_third_servo, OUTPUT);
}

void loop() 
{                 
  long joystickYVal = analogRead(YJOY_PIN) ; 
  long joystickXVal = analogRead(XJOY_PIN) ; 
  pot_pin_val = analogRead(POT_PIN);           
  
  //pot_pin_val = map(pot_pin_val, 0, 1023, 0, 180);                      

  if(joystickYVal > 490 && joystickYVal < 508) digitalWrite(led_first_servo, LOW);
  else digitalWrite(led_first_servo, HIGH);
  
  if(joystickXVal > 509 && joystickXVal < 518) digitalWrite(led_second_servo, LOW);
  else digitalWrite(led_second_servo, HIGH);
  
  Serial.print(pot_pin_val);                
  Serial.println("= input from potentiometer") ;
  myservo1.write((joystickYVal+544)/10);   
  myservo2.write((joystickXVal+544)/10);
  myservo3.write((pot_pin_val+544)/10);   
}
