// NOTE all outputs are ACTIVE LOW

//HardwareTimer timer(3);

#include <stdlib.h>

#include <mcp_can.h>
#include <SPI.h>

#define SPI_CS_PIN 17
MCP_CAN CAN (SPI_CS_PIN);


#define LED 25

#define PWM1 15
#define INB1 14
#define INA1 13
#define EN1  12

#define PWM2 11
#define INB2 10
#define INA2 9
#define EN2  8

#define PWM3 7
#define INB3 6
#define INA3 5
#define EN3  4

#define PWM4 3
#define INB4 2
#define INA4 1
#define EN4  0



#define PWMMAX 0xFFF

void initAndClearOutputs ();
void fixPWM ();
void initCAN ();
void updatePinBuff ();
void writeMotors ();

// for CAN
#define STD_FRAME 0
const   unsigned long SELF_ID = 0xF1;

#define LOST_COMM_INTERVAL 2000
unsigned long last_comm_time = 0;
unsigned long curr_time = 0;

// PWM, EN, INA, INB (in that order)
uint8_t buff[16] = {0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0};

void setup () {
  //fixPWM ();
  
  writeMotors();
  initAndClearOutputs ();
  initCAN();

  curr_time = millis();
  last_comm_time = curr_time;
}

void loop () {
  curr_time = millis();
  if (CAN_MSGAVAIL == CAN.checkReceive())
  {
    Serial.println("received");
    unsigned char len;
    unsigned char tmp[8];
    CAN.readMsgBuf (&len, tmp);
    if (CAN.getCanId() == SELF_ID)
    {
      for (int i = 0; i < 4; i++)
        buff[4*i] = tmp[i];

       for (int i=4;i<8;i++)
       {
        buff[4*(i-4)+1] = tmp[i]&1;
        buff[4*(i-4)+2] = (tmp[i]>>1)&1;
        buff[4*(i-4)+3] = (tmp[i]>>2)&1;
        
       }
      last_comm_time = curr_time;
      digitalWrite (LED, HIGH);
    }
    last_comm_time = curr_time;
  }
  
  if (curr_time - last_comm_time > LOST_COMM_INTERVAL)
  {
    for (int i = 0; i < 16; i++)
      buff[i] = 0;
    last_comm_time = curr_time;
    digitalWrite (LED, LOW);
  }

  writeMotors();
}




void writeMotors () {

  analogWriteResolution(12);
  



  
  // motor_buff in this order: pwm, en, ina, inb
  analogWrite (PWM1,    (buff[0]*0x3FF)/0xFF);
  digitalWrite (EN1,  buff[1]);
  digitalWrite (INA1, buff[3]);
  digitalWrite (INB1, buff[2]);
  analogWrite (PWM2,    (buff[4]*0xFFF)/0xFF);
  digitalWrite (EN2,  buff[5]);
  digitalWrite (INA2, buff[6]);
  digitalWrite (INB2, buff[7]);
  analogWrite (PWM3,    (buff[8]*0xFFF)/0xFF);
  digitalWrite (EN3,  buff[9]);
  digitalWrite (INA3, buff[10]);
  digitalWrite (INB3, buff[11]);
  digitalWrite (PWM4, buff[13]);
  analogWrite (EN4,    (buff[12]*0xFFF)/0xFF);
  digitalWrite (INA4, buff[15]);
  digitalWrite (INB4, buff[14]);
}

/*void fixPWM() {
  //timer.setPrescaleFactor(4);
  //timer.setOverflow(1024);
  //timer.refresh();
}*/

void initCAN () {
  Serial.begin(500000);
  digitalWrite (LED, LOW);

  while (CAN_OK != CAN.begin(CAN_500KBPS))
  {
      digitalWrite (LED, HIGH);
      delay (500);
      digitalWrite (LED, LOW);
      delay (500);
  }
  
  digitalWrite (LED, HIGH);
  delay(1000);
  digitalWrite (LED, LOW);
  delay(1000);
  digitalWrite (LED, HIGH);
  delay(1000);
  Serial.println("CAN Working");
  delay(500);
}

void initAndClearOutputs () {
  pinMode (LED, OUTPUT);
  pinMode (PWM1, OUTPUT);
  pinMode (INB1, OUTPUT);
  pinMode (INA1, OUTPUT);
  pinMode (EN1, OUTPUT);
  pinMode (PWM2, OUTPUT);
  pinMode (INB2, OUTPUT);
  pinMode (INA2, OUTPUT);
  pinMode (EN2, OUTPUT);
  pinMode (PWM3, OUTPUT);
  pinMode (INB3, OUTPUT);
  pinMode (INA3, OUTPUT);
  pinMode (EN3, OUTPUT);
  pinMode (PWM4, OUTPUT);
  pinMode (INB4, OUTPUT);
  pinMode (INA4, OUTPUT);
  pinMode (EN4, OUTPUT);

  analogWriteResolution(12);
  

  digitalWrite (LED, HIGH);
  analogWrite (PWM1, PWMMAX);
  digitalWrite (INB1, HIGH);
  digitalWrite (INA1, HIGH);
  digitalWrite (EN1, HIGH);
  digitalWrite (PWM2, PWMMAX);
  digitalWrite (INB2, HIGH);
  digitalWrite (INA2, HIGH);
  digitalWrite (EN2, HIGH);
  analogWrite (PWM3, PWMMAX);
  digitalWrite (INB3, HIGH);
  digitalWrite (INA3, HIGH);
  digitalWrite (EN3, HIGH);
  digitalWrite (PWM4, HIGH);
  digitalWrite (INB4, HIGH);
  digitalWrite (INA4, HIGH);
  analogWrite (EN4, PWMMAX);
}
