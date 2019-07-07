
void setup() 
{
  Serial.begin(9600);
}
 
void loop() 
{
  float sensorVoltage; 
  float sensorValue;
  float uvLevel;
  
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue/1024*3.3;
  uvLevel = sensorVoltage/0.1;
 
  Serial.print("UV Index = ");
  Serial.print(uvLevel);
  Serial.println();
  if (uvLevel <= 2 ){
    Serial.print("Low Risk");
  }
  else if (uvLevel <= 5){
    Serial.print("Moderate Risk");
  }
  else if (uvLevel <= 7){
    Serial.print("High Risk");
  }
  else if (uvLevel <= 10){
    Serial.print("Very High Risk");
  }
  else if (uvLevel > 10){
    Serial.print("EXTREME RISK");
  }
  Serial.println();
  delay(3000);
}
