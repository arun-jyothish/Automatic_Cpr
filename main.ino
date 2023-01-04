#include <Servo.h>
#include <millisDelay.h>
/* #include <PulseSensorPlayground.h> */ 
const int PulseWire = 0;  
millisDelay pulseSensorDelay;

int compServoPin = 6, respServoPin = 5;
Servo compServo;
Servo respServo;

int LED_PIN = 13;
void setup(){
	compServo.attach(compServoPin);
	respServo.attach(respServoPin);
	pinMode(LED_PIN,OUTPUT);
}

void other_main(){
	bool beatflag = readPulseSensor();
	if (beatflag)
		pulseSensorDelay.start(1e4);

	if( pulseSensorDelay.justFinished() ){
		if (!beatflag){
			main_fn(15,30);			// 30 (second arg) times compression within 15(first arg) seconds
		}
	}
}

void main_fn( int total_time, int total_compression ){
  
	
  int delay_time = total_time * 1000/ total_compression ;    // in ms delay time b/w squeeze
  delay_time -= 30;
  int compression_highAngle = 180;
  int compression_lowAngle = 0;
  
  //  compression 
  for (int  i = 0 ; i < total_compression ; ++i){
    compServo.write(compression_lowAngle);
    delay(30);
    compServo.write(compression_highAngle);
    delay(delay_time);
    //delay(delay_time);
  }

  //    Respiration
  int respiration_repetitionCount = 2;  // change count 
  int respiration_lowAngle = 0;
  int respiration_highAngle = 180;
  int respiration_inhale_delay_time = 300;
  int respiration_exhale_delay_time = 300;
  
  for (int i = 0; i < respiration_repetitionCount ; ++i){
  respServo.write(respiration_lowAngle);
    delay(respiration_inhale_delay_time);
    respServo.write(respiration_highAngle);
    delay(respiration_exhale_delay_time);
    //delay(delay_time);
  }
}

int pulseSensorPin = A0; 			// pulse sensor Pin
bool readPulseSensor(){
	int threshold = 700;
	millisDelay pulseInterval;
	do{
		pulseInterval.start(1000);
	}while(0);

	if (analogRead(pulseSensorPin) > threshold){
		digitalWrite(LED_PIN,HIGH);
		delay(100);
		digitalWrite(LED_PIN,LOW);
		return true;
	}
	if ( pulseInterval.justFinished() ){
		return false;	
	}
}

void loop(){
	/* other_main(); */
	Serial.println(analogRead(A0));
	delay(500);
}
