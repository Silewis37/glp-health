#include <LiquidCrystal.h>  
// initialize the library with the pins on the Arduino board  
LiquidCrystal lcd(13, 12, 6, 4, 3, 2);  
const int temperature = A0; //A0 is the analog pin  
const int D = 8; // Vo of LCD is connected to pin 8 of the Arduino  
void setup()  
{  
  lcd.begin(16, 2);  
  Serial.begin(9600);  
  pinMode(D, OUTPUT);  
}  
void loop()   
{  
  digitalWrite(D,LOW);  
  int Temp = analogRead(temperature);  
  float volts = (Temp / 965.0) * 5;  
  float celcius = (volts - 0.5) * 100;  
  float fahrenheit = (celcius * 9 / 5 + 32);  
  Serial.println(fahrenheit);  
  lcd.setCursor(5, 0);  
  lcd.print(fahrenheit);  
  delay(2000);  
  // time delay of 2000 microseconds or 2 seconds  
}