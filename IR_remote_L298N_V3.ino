
/*
 Arduino Infrared control tracked robot
 Written by: Pason Tanpaiboon
 Febuary 2017
 Version.1.3
 12/2/2017  Add Backward left-right/Correct remote hex code
 
 This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ 
 or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

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
 Serial.begin(9600);
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
if (results.value == 0xFF18E7){ // push button 2 forward robot control
 
     MotorRspeed =  200;
     MotorLspeed =  MotorRspeed;
       
     MotorR1val = 1;
     MotorR2val = 0;
     MotorL1val = 1;
     MotorL2val = 0;
     Motor();
     Serial.println("Forward");
/////////////////////////////////////////////////////////////////////////
}else if(results.value == 0xFF30CF){ // push button 1 forward left robot control FF10EF      

     MotorRspeed = 200;
     MotorLspeed = 0;
    
      MotorR1val = 1;
      MotorR2val = 0;
      MotorL1val = 1;
      MotorL2val = 0;   
      Motor();
      Serial.println("Forward Left");
  

}else if(results.value == 0xFF10EF){ // push button 4 rotate left robot control FF10EF

     MotorRspeed = 200;
     MotorLspeed = MotorRspeed;
      MotorR1val = 1;
      MotorR2val = 0;
      MotorL1val = 0;
      MotorL2val = 1;  
      Motor();
      Serial.println("Rotate Left"); 
  

}else if(results.value == 0xFF7A85){ // push button 3 forward right robot control 
        
     MotorRspeed = 0;
     MotorLspeed = 200;
     
      MotorR1val = 1;
      MotorR2val = 0;
      MotorL1val = 1;
      MotorL2val = 0;
      Motor();
      Serial.println("Forward Right");


}else if(results.value == 0xFF5AA5){ // push button 6 rotate right robot control 
         
     MotorRspeed = 200;
      
     MotorLspeed = MotorRspeed;
        
      MotorR1val = 0;
      MotorR2val = 1;
      MotorL1val = 1;
      MotorL2val = 0;   
       Motor();
       Serial.println("Rotate Right");


} else if(results.value == 0xFF4AB5){ // push button 8 backward robot control

     MotorRspeed = 200;
         
     MotorLspeed = MotorRspeed;
        
      MotorR1val = 0;
      MotorR2val = 1;
      MotorL1val = 0;
      MotorL2val = 1;   
      Motor();
      Serial.println("Backward");
      
} else if(results.value == 0xFF42BD){ // push button 7 backward left robot control

     MotorRspeed = 200;
         
     MotorLspeed = 0;
        
      MotorR1val = 0;
      MotorR2val = 1;
      MotorL1val = 0;
      MotorL2val = 1;   
      Motor();
      Serial.println("Backward Left");
            
} else if(results.value == 0xFF52AD){ // push button 9 backward left robot control

     MotorRspeed = 0;
         
     MotorLspeed = 200;
        
      MotorR1val = 0;
      MotorR2val = 1;
      MotorL1val = 0;
      MotorL2val = 1;   
      Motor();
      Serial.println("Backward Right");      

      
}else if(results.value == 0xFF38C7){ // push button 5 stop robot control 

      MotorRspeed = 0;
      MotorLspeed = 0;
 
      MotorR1val = 0;//off 
      MotorR2val = 0;
      MotorL1val = 0;
      MotorL2val = 0;
      Motor();
      Serial.println("Stop");

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
