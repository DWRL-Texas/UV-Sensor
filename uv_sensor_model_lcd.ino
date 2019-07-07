#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
     
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}
 
void loop() 
{
  float sensorVoltage; 
  float sensorValue;
  float uvLevel;
  float uvThreat;
  
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue/1024*3.3;
  uvLevel = sensorVoltage/0.1;
 
  Serial.print("UV Index = ");
  Serial.print(uvLevel);
  Serial.println();


  lcd.clear();
  lcd.print("UV Level = ");
  lcd.print(uvLevel);
  lcd.setCursor(0,1);
  if (uvLevel <= 2 ){
    lcd.print("Low Risk");
  }
  else if (uvLevel <= 5){
    lcd.print("Moderate Risk");
  }
  else if (uvLevel <= 7){
    lcd.print("High Risk");
  }
  else if (uvLevel <= 10){
    lcd.print("Very High Risk");
  }
  else if (uvLevel > 10){
    lcd.print("EXTREME RISK");
  }
  delay(3000);
}
