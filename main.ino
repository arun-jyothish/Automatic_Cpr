#include <Servo.h>
#include <PulseSensorPlayground.h> 
const int PulseWire = 0;  


int compServoPin = 6, respServoPin = 5;
Servo compServo;
Servo respServo;

void setup(){
  compServo.attach(compServoPin);
  respServo.attach(respServoPin);
}

void loop(){
  
  int repetitionCount = 4;  // change count 
  int delay_time = 2000;    // in ms delay time b/w squeeze
  int highAngle = 180;
  int lowAngle = 0;
  
  //  compression 
  for (int  i = 0 ; i < repetitionCount ; ++i){
    compServo.write(lowAngle);
    delay(delay_time);
    compServo.write(highAngle);
    delay(delay_time);
    //delay(delay_time);
  }
  
  
  
  //    Respiration
  
  repetitionCount = 2;
  /*
  lowAngle = 0;
  highAngle = 180;
  delay_time = 300;
  */
  
  for (int i = 0; i < repetitionCount ; ++i){
  respServo.write(lowAngle);
    delay(delay_time);
    respServo.write(highAngle);
    delay(delay_time);
    //delay(delay_time);
  }
}
