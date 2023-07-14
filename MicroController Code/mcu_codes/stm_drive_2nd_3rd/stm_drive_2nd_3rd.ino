//HardwareTimer timer(3);

#include <Wire.h>

/////
int address = 15;   //change address here 15,16,17
/////
#define LED_BUILTIN PC13
#define CSr PA2
#define CSl PA3
#define slpr PA4
#define slpl PA5
#define DIRr PA1
#define DIRl PA7
#define PWMr PB0
#define PWMl PB1


int vel1 ,vel2 , om1 ,om2 = 0, hb =0;
int pwmr = 0, pwml = 0;
int vel,omega=0;

void receiveEvent(int howMany)
{
  if ( Wire.available())
  {
    vel1 = Wire.read();
    //vel2 = Wire.read();
    om1 = Wire.read();
    //om2 = Wire.read();
    hb = Wire.read();
    
    //vel = vel1 + (vel2<<8);
    //omega = om1 + (om2<<8);
    
    vel=vel1-127;
    omega=om1-127;	  
	
  }
}

void setup()
{ Serial.end();
  pinMode(PA11, OUTPUT);
  //timer.setPrescaleFactor(32);
  //timer.setOverflow(127);
  //timer.refresh();
  

  pinMode(PWMl, OUTPUT);
  pinMode(PWMr, OUTPUT);
  pinMode(slpl, OUTPUT);
  pinMode(slpr, OUTPUT);
  pinMode(DIRr, OUTPUT);
  pinMode(DIRl, OUTPUT);
  pinMode(CSr, INPUT);
  pinMode(CSl, INPUT);

  digitalWrite(slpl, HIGH);
  digitalWrite(slpr, HIGH);

  pinMode(PC13, OUTPUT);
  digitalWrite(PC13, HIGH);

  Wire.begin(address);

  Wire.onReceive(receiveEvent);

 //pwmWrite(PWMl, 0);
  //pwmWrite(PWMr,0);
  digitalWrite(slpl, LOW);
  digitalWrite(slpr,LOW);
  digitalWrite(DIRr, LOW);
  digitalWrite(DIRl, LOW);

}

#define analogMax 255
void loop()
{
//  analogWriteFrequency(17000);
  pwmr = int(vel+omega)*255/110;
  pwml = int(vel-omega)*255/110;
  if (pwmr>255) 
    pwmr = 255;
   else if (pwmr<-255)
    pwmr = -255;
  if (pwml>255) 
    pwml = 255;
   else if (pwml<-255)
    pwml = -255;

  if (hb==0)
  {
	  if (pwmr > 0)
	  {
	    digitalWrite(slpr, HIGH);
	    digitalWrite(DIRr, HIGH);
	    analogWrite(PWMr, abs(pwmr));
      
	  }
	  else if (pwmr < 0)
	  {
	    digitalWrite(slpr, HIGH);
	    digitalWrite(DIRr, LOW);
	    analogWrite(PWMr, abs(pwmr));
      digitalWrite(PC13,LOW);
      delay(100);
      digitalWrite(PC13,HIGH);
      delay(100);
	  }
	  else
	  {
	    digitalWrite(slpr, LOW);
      digitalWrite(DIRr,LOW);
	    analogWrite(PWMr, 0);
     digitalWrite(PC13,LOW);
      delay(100);
	  }

	  if (pwml > 0)
	  {
	    digitalWrite(slpl, HIGH);
	    digitalWrite(DIRl, LOW);
	    analogWrite(PWMl, abs(pwml));
	  }
	  else if (pwml < 0)
	  {
	    digitalWrite(slpl, HIGH);
	    digitalWrite(DIRl, HIGH);
	    analogWrite(PWMl, abs(pwml));
      digitalWrite(PC13,LOW);
      delay(100);
      digitalWrite(PC13,HIGH);
      delay(100);
	  }
	  else
	  {
	    digitalWrite(slpl, LOW);
      digitalWrite(DIRl, LOW);
	    analogWrite(PWMl, 0);
	  }
  }
  else
  {
  	digitalWrite(slpr, LOW);
	analogWrite(PWMr, 0);
	digitalWrite(slpl, LOW);
	analogWrite(PWMl, 0);
  }

  // give PWM time to properly write
  delay (10);

}
