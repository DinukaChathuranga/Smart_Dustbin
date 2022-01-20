// lcd rx =1,enable=2,pins=5,6,7,9
// ultrasonic= trig 2,echo 4
//led red=13,green= 12,blue=10
// servo 9
//pir 8

#include <Wire.h>
#include <hd44780.h>                       
#include <hd44780ioClass/hd44780_I2Cexp.h> 

const int LCD_COLS = 16;
const int LCD_ROWS = 2;
hd44780_I2Cexp lcd;
#include <Servo.h>
#define trig 2
#define echo 4
Servo Dustbin;


void setup() {
  // put your setup code here, to run once:
Dustbin.attach(9); Dustbin.write(0);
pinMode(8,INPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(10,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

lcd.begin(LCD_COLS, LCD_ROWS);
lcd.setCursor(3,0);
lcd.print("WELCOME TO");
delay(3000);

lcd.setCursor(0,1);
lcd.print(" SMART DUSTBIN");
delay(6000);
lcd.clear();
delay(500);
lcd.setCursor(3,0);
lcd.print("Loading...");
delay(3000);
}
void loop() {
  // put your main code here, to run repeatedly:
 lcd.clear();
 digitalWrite(trig ,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
  delayMicroseconds(10);
 digitalWrite(trig,LOW);


  long t = pulseIn(echo,HIGH);
  long cm = t/29/2;
  long n=100*cm/30;
 
 

lcd.setCursor (6,0);
lcd.print(100-n);
lcd.setCursor (9,0);
lcd.print("%");
delay(1000);


if( cm >0 && cm<=5)
{
  digitalWrite(10,LOW);
digitalWrite(12,LOW);


  digitalWrite(13,HIGH);
  Dustbin.write(0);
}

else if(cm>5 && cm<=18)
{

digitalWrite(10,LOW);
digitalWrite(13,LOW);
digitalWrite(12,HIGH);  
int val = digitalRead(8);
if ( val == 1){
  

 Dustbin.write(150);
 delay (200);
 
 }
 else{
 
  Dustbin.write(0);
  }
 }
else if (cm>18)
{
  digitalWrite(12,LOW);
digitalWrite(13,LOW);
digitalWrite(10,HIGH); 
  int val = digitalRead(8);
if ( val == 1){
  Dustbin.write(150);
  delay (200);
 
 }
 else{
 
  Dustbin.write(0);
  }
 }
  
  
}


  
