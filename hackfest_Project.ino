#define set_password "project"

#include<SoftwareSerial.h>
#include<Servo.h>


// initialize the library instance

Servo motor;

SoftwareSerial bluetooth(10, 11); 

String password;

int buzzerpin=4;
int servopin=6;
int switchpin=3;
int peizopin=A0;

int peizo_reading;
const int thresh=500;

boolean locked = true;

void setup() {
  // put your setup code here, to run once:
pinMode(buzzerpin,OUTPUT);
pinMode(switchpin,INPUT);

motor.attach(servopin);
motor.write(0); 
bluetooth.begin(38400);
Serial.begin(9600);
  while (!Serial) {
    ; 
}
}

void loop() {
 bluetooth.listen(); 
 
 if(bluetooth.available()>0){
  password=readPass();
 Serial.println(password);
 if(password.equals(set_password))
 {
  if(locked){
  motor.write(150);
  
  
  } else{
    motor.write(0);
    
    
  }
  locked=!locked;
  delay(600);
 }
}
  
 else if(digitalRead(switchpin)==HIGH)
 {
  if(locked){
  motor.write(150);
  
  
  } else{
    motor.write(0);
    
    
  }
  locked=!locked;
  delay(600);
   
 }
 
 peizo_reading = analogRead(peizopin);
 
 if(peizo_reading>thresh)
 {
  digitalWrite(buzzerpin,HIGH);
  delay(4000);
  digitalWrite(buzzerpin,LOW);
 }

 
}

 
String readPass() {
  String text = "";
  while (1) {
    while (bluetooth.available() > 0) {
      char inChar = bluetooth.read();
      if (inChar == '\n') {
        return text;
      }
      else if (inChar != '\r') {
        text += inChar;
      }
    }
  }
}
