#include <Adafruit_LiquidCrystal.h>
int a = 0;
int b = 0;
int tempSensorPin = 1;
Adafruit_LiquidCrystal lcd_1(0);


void setup()
{
  lcd_1.begin(16, 2);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  a = analogRead(A0);
  b = map(a,0,1023,0,255);
  
  int reading = analogRead(tempSensorPin);
  float voltage = reading * 4.68;
  voltage /= 1024;
  float temperture = (voltage - 0.5) * 100;
  
  Serial.println(b);
  
  lcd_1.setCursor(0, 0);
  
  
  if(b>100)
  {
    if(temperture>25)
    {
      Serial.println("Serial detected");
      delay(100);
      digitalWrite(12, HIGH);
      delay(0);
      digitalWrite(11, HIGH);     
      lcd_1.setCursor(0, 0);
      lcd_1.print("AC  ON");
      lcd_1.setCursor(0, 1);
      lcd_1.print("Lights  ON");
    }
    else
    {
      Serial.println("Serial detected");
      delay(100);
      digitalWrite(12, HIGH);
      delay(0);
      digitalWrite(11, LOW); 
      lcd_1.setCursor(0, 0);
      lcd_1.print("AC OFF");
      lcd_1.setCursor(0, 1);
      lcd_1.print("Lights  ON");
    }
  }
  else
  {
  	digitalWrite(12, LOW);
    delay(0);
    digitalWrite(11, LOW);
    lcd_1.setCursor(0, 0);
    lcd_1.print("AC OFF");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Lights OFF");
  }
  
  
  
}