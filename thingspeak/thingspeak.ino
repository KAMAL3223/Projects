#include <ThingSpeak.h>

delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;

  if (distance >= 50 || distance <= 0) 
        {
        //Serial.println("no object detected");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
        //Serial.println("object detected \n");
        Serial.print("Distance= ");              
        Serial.println(distance);    
        tone(Buzzer,400);            
        digitalWrite(ledPin,HIGH);
  }

if(WiFi.status() != WL_CONNECTED){
  Serial.print("Attempting to connect");
  while(WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid, password); 
    delay(5000);     
  } 
  Serial.println("\nConnected.");
}

//Serial.println("WiFi connected");
  Serial.println("IP address: ");
  
  Serial.println(WiFi.localIP());
  delay(500);

  int httpCode = ThingSpeak.writeField(myChannelNumber, 1, distance, "PS00N48QR8EIJ31L");
if (httpCode == 200) {
    Serial.println("Channel write successful.");
  }
  else {
    Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
  }
  
 //ultra();
 pir();
}
