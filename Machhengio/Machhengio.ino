#include <DS3231.h>

int Relay = 6;

DS3231  rtc(SDA, SCL);
Time t;

const int OnHour = 16;
const int OnMin = 15;
const int OffHour = 16;
const int OffMin = 16;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.print(t.sec);
  Serial.print(" sec(s)");
  Serial.println(" ");
  delay (1000);
  
  /*if(t.hour == OnHour && t.min == OnMin){
    digitalWrite(Relay,HIGH);
    Serial.println("");
    }
    
    else if(t.hour == OffHour && t.min == OffMin){
      digitalWrite(Relay,LOW);
      Serial.println("");
    }*/
}
