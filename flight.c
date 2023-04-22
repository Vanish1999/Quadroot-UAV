#include <Servo.h>
int key1=11;
int a=0;
int b=0;
int i=0;
const int ting=2;    //设定SR04连接到Arduino引脚
const int echo=3;          //设定SR04连接到Arduino引脚
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
  pinMode(ting,OUTPUT);     //连接SR04的引脚
pinMode(echo,INPUT);       //设置输入状态
Serial.println("ultrasonic sensor");   
  a=40;
  b=1;
}
void loop(){
   Serial.println("Waiting!");
if(digitalRead(key1)==0){
  Serial.println("Unlocking!");}
  /*解锁***********************/
yaw.write(140);
roll.write(40);
pitch.write(140);
thr.write(35);
delay(5000);
yaw.write(40);
pitch.write(40);
/*********************************/
/*加减油门************************/
thr.write(80);
delay(3500);
for (int i= 80 ;i>=30;i--)
{
        thr.write(i);
        delay(500);
  }
/* 
/*定高*****************************/
/*for(sb(distance)<100)
  thr.write(i++);
  /*定高*****************************/
/*yaw.write(93);
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
} */
}
float csb(float distance) 
{ 
digitalWrite(ting,LOW); //产生一个10US的高脉冲去触发Trigpin
delayMicroseconds(2);             
delayMicroseconds(10);            
digitalWrite(ting,LOW);         
distance=pulseIn(echo,HIGH)/58.00; //检测脉冲宽度，并计算出距离  
Serial.print(distance);                 //打印
Serial.print("cm"); //打印
Serial.println("\n");                //打印
delay(200);
return distance;
}