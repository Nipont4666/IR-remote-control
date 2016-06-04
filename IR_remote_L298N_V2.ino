#include <IRremote.h>

int RECV_PIN = 11;

int statusled = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

//Motor Right
const int enableR = 3;
const int MotorR1 = 4;
const int MotorR2 = 5;

//Motor Left
const int enableL = 6;
const int MotorL1 = 7;
const int MotorL2 = 8;

int enableRval ;
int enableLval ;
int MotorR1val ;
int MotorR2val ;
int MotorL1val ;
int MotorL2val ;

int MotorRspeed ;
int MotorLspeed ;

void setup()

{

irrecv.enableIRIn();

  pinMode(statusled,OUTPUT);
  digitalWrite(statusled,LOW);

  pinMode (enableR, OUTPUT);
  pinMode (MotorR1, OUTPUT);
  pinMode (MotorR2, OUTPUT);  

  pinMode (enableL, OUTPUT);
  pinMode (MotorL1, OUTPUT);
  pinMode (MotorL2, OUTPUT);  
  
  digitalWrite(enableR , HIGH);
  digitalWrite(enableL , HIGH);
}

void loop() {

if (irrecv.decode(&results)) {

digitalWrite(statusled,HIGH);

irrecv.resume();
/////////////////////////////////////////////////////////////////////////
if (results.value == 0xFF18E7){ // type button 2 forward robot control
 
     MotorRspeed =  200;
     MotorLspeed =  MotorRspeed;
       
     MotorR1val = 1;
     MotorR2val = 0;
     MotorL1val = 1;
     MotorL2val = 0;
     Motor();
     Serial.print("Forward");
/////////////////////////////////////////////////////////////////////////
}else if(results.value == 0xFF10EF){ // type button 4 turn left robot control 

     MotorRspeed = 200;
     MotorLspeed = 0;
    
      MotorR1val = 1;
      MotorR2val = 0;
      MotorL1val = 1;
      MotorL2val = 0;   
      Motor();
      Serial.print("Forward Left");
  

}else if(results.value == 0xFF30CF){ // type button 1 rotate left robot control 

     MotorRspeed = 200;
     MotorLspeed = MotorRspeed;
      MotorR1val = 1;
      MotorR2val = 0;
      MotorL1val = 0;
      MotorL2val = 1;  
      Motor();
      Serial.print("Rotate Left"); 
  

}else if(results.value == 0xFF5AA5){ // type button 6 turn right robot control 
        
     MotorRspeed = 0;
     MotorLspeed = 200;
     
      MotorR1val = 1;
      MotorR2val = 0;
      MotorL1val = 1;
      MotorL2val = 0;
      Motor();
      Serial.print("Forward Right");


}else if(results.value == 0xFF7A85){ // type button 3 rotate right robot control 
         
     MotorRspeed = 200;
      
     MotorLspeed = MotorRspeed;
        
      MotorR1val = 0;
      MotorR2val = 1;
      MotorL1val = 1;
      MotorL2val = 0;   
       Motor();
       Serial.print("Rotate Right");


} else if(results.value == 0xFF4AB5){ // type button 8 backward robot control

     MotorRspeed = 200;
         
     MotorLspeed = MotorRspeed;
        
      MotorR1val = 0;
      MotorR2val = 1;
      MotorL1val = 0;
      MotorL2val = 1;   
      Motor();
      Serial.print("Backward");
      
}else if(results.value == 0xFF38C7){ // type button 5 stop robot control 

      MotorRspeed = 0;
      MotorLspeed = 0;
 
      MotorR1val = 0;//off 
      MotorR2val = 0;
      MotorL1val = 0;
      MotorL2val = 0;
      Motor();
      Serial.print("Stop");

}

}

}
void Motor() {
//Right Motor 
  analogWrite(enableR , MotorRspeed);// 
  digitalWrite (MotorR1,MotorR1val);
  digitalWrite (MotorR2,MotorR2val);  
  delay (100);
 //Left Motor 
   analogWrite(enableL , MotorLspeed);// 
  digitalWrite (MotorL1,MotorL1val);
  digitalWrite (MotorL2,MotorL2val);  
  delay (100);
}
