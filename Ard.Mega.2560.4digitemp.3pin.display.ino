// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS1 2
#define ONE_WIRE_BUS2 3
#define ONE_WIRE_BUS3 4
#define ONE_WIRE_BUS4 5
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire2(ONE_WIRE_BUS2);
OneWire oneWire3(ONE_WIRE_BUS3);
OneWire oneWire4(ONE_WIRE_BUS4);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
DallasTemperature sensors3(&oneWire3);
DallasTemperature sensors4(&oneWire4);
//LiquidCrystal lcd(12, 11, 6, 5, 4, 3); // Pins des LCD festlegen
LiquidCrystal lcd(6, 7, 8, 9, 10, 11); // Pins des LCD festlegen
/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
 // Serial.begin(9600);
 // Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors1.begin();
  sensors2.begin();
  lcd.begin(16, 2); // Display mit 16 Zeichen und 2 Zeilen
  lcd.setCursor(0, 0); //Startposition: Erstes Zeichen in der oberen Zeile
  lcd.print("S1"); // Das soll permanent in der oberen Zeile angezeigt werden
  lcd.setCursor(9, 0); //Startposition: Erstes Zeichen in der oberen Zeile
  lcd.print("S2"); // Das soll permanent in der oberen Zeile angezeigt werden
  lcd.setCursor(0, 1); //Startposition: Erstes Zeichen in der oberen Zeile
  lcd.print("S3"); // Das soll permanent in der oberen Zeile angezeigt werden
  lcd.setCursor(9, 1); //Startposition: Erstes Zeichen in der oberen Zeile
  lcd.print("S4"); // Das soll permanent in der oberen Zeile angezeigt werden
}
/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  delay(2000);
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors1.requestTemperatures(); // Send the command to get temperatures
  sensors2.requestTemperatures(); // Send the command to get temperatures
  sensors3.requestTemperatures(); // Send the command to get temperatures
  sensors4.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC1 = sensors1.getTempCByIndex(0);
  float tempC2 = sensors2.getTempCByIndex(0);  
  float tempC3 = sensors3.getTempCByIndex(0);
  float tempC4 = sensors4.getTempCByIndex(0);
  // Check if reading was successful
  if(tempC1 != DEVICE_DISCONNECTED_C) {
    lcd.setCursor(0, 0);
    lcd.print(tempC1);
    lcd.print("\337C "); // \337 -> Grad
//    Serial.print("Temperature for the device 1 (index 0) is: ");
//    Serial.println(tempC);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("ErSe1!"); // Das soll permanent in der oberen Zeile angezeigt werden
//    Serial.println("Error: Could not read temperature data");
  }
  if(tempC2 != DEVICE_DISCONNECTED_C) {
    lcd.setCursor(9, 0);
    lcd.print(tempC2);
    lcd.print("\337C "); // \337 -> Grad
//    Serial.print("Temperature for the device 1 (index 0) is: ");
//    Serial.println(tempC);
  } else {
    lcd.setCursor(9, 0);
    lcd.print("ErSe2!"); // Das soll permanent in der oberen Zeile angezeigt werden
//    Serial.println("Error: Could not read temperature data");
  }
  if(tempC3 != DEVICE_DISCONNECTED_C) {
    lcd.setCursor(0, 1);
    lcd.print(tempC3);
    lcd.print("\337C "); // \337 -> Grad
//    Serial.print("Temperature for the device 1 (index 0) is: ");
//    Serial.println(tempC);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("ErSe3!"); // Das soll permanent in der oberen Zeile angezeigt werden
//    Serial.println("Error: Could not read temperature data");
  }
  if(tempC4 != DEVICE_DISCONNECTED_C) {
    lcd.setCursor(9, 1);
    lcd.print(tempC4);
    lcd.print("\337C "); // \337 -> Grad
//    Serial.print("Temperature for the device 1 (index 0) is: ");
//    Serial.println(tempC);
  } else {
    lcd.setCursor(9, 1);
    lcd.print("ErSe4!"); // Das soll permanent in der oberen Zeile angezeigt werden
//    Serial.println("Error: Could not read temperature data");
  }
}
