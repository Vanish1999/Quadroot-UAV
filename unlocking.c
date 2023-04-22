#include <Servo.h>
int key1=11;
int a=0;
int b=0;
int i=0;
Servo roll;
Servo pitch;  
Servo thr;  
Servo yaw;  
void setup(){
  Serial.begin(9600);
  pinMode(key1,INPUT_PULLUP);
 roll.attach(5);  // 舵机控制信号引脚 
  pitch.attach(6);  // 舵机控制信号引脚 
  thr.attach(7);  // 舵机控制信号引脚 
  yaw.attach(8);  // 舵机控制信号引脚 
  a=40;
  b=1;
}
void loop(){
   Serial.println("Waiting!");
if(digitalRead(key1)==0){
  Serial.println("Unlocking!");
yaw.write(140);
roll.write(40);
pitch.write(140);
thr.write(40);
delay(5000);
yaw.write(93);
roll.write(93);
    pitch.write(93);
    Serial.println("Up!");
    for(i=40;i<=80;i++){
    thr.write(i);
    delay(100);
    }
    Serial.println("Down!");
 for(i=80;i>=40;i--){
    thr.write(i);
    delay(200);
    } 
yaw.write(40);
Serial.println("Locking");
delay(5000);
yaw.write(93);
}
} 
