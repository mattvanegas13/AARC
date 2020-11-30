#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_PIN 8
#define DHT_TYPE DHT11
#define RS 1
#define E  2
#define R4 4
#define R5 5
#define R6 6
#define R7 7

int   BUFFERTIME = 1000;
int   dt = 1000;
float humidity;
float tempC;
float tempF;

LiquidCrystal lcd(RS,E,R4,R5,R6,R7);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  lcd.begin(16,2);
  dht.begin();
  delay(BUFFERTIME);
}

void loop() {
  humidity =  dht.readHumidity();
  tempC = dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(dt);
}