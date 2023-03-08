#include <LiquidCrystal_I2C.h>
#define echoPin D7
#define trigPin D6
#define buzzerPin D8
double distance ;
double duration;

LiquidCrystal_I2C lcd(0x27,16,2);


void setup()
{

  Serial.begin (9600);
pinMode(buzzerPin, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Abstand");
  lcd.setCursor(0,1);
  lcd.print(distance);

}


void loop(){  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;
Serial.println(distance);
delay(50);
 lcd.setCursor(0,1);
lcd.print(distance);
if (distance <= 15){
   digitalWrite(buzzerPin,HIGH);
   delay(100);
   digitalWrite(buzzerPin,LOW);
   Serial.println("BEEP");
   if (distance <= 10){
   digitalWrite(buzzerPin,HIGH);
   delay(10);
   digitalWrite(buzzerPin,LOW);
   Serial.println("BEEP");
   if (distance <= 5){
   digitalWrite(buzzerPin,HIGH);
   delay(1);
   digitalWrite(buzzerPin,LOW);
   Serial.println("BEEP");
   
  }
  }
  }
}
