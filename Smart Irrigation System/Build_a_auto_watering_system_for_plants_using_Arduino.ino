#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensor_pin = A0;       //Sensor Pin
int relay_pin = 7;  //Relay Pin
int off = 4;


void setup()
{
  lcd.init();         // initialize the lcd
  lcd.backlight();  
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setBacklight(HIGH);
  pinMode(off, OUTPUT);
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");
  
  if(sensor_data >600)
  {
    Serial.println("Soil is dry");
    digitalWrite(off , LOW);
    digitalWrite(relay_pin, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Soil Dry");
    lcd.setCursor(0,1);
    lcd.print("Motor ON ");
  }

  else if(sensor_data < 300)
  {
    Serial.println("Soil is wet");
    digitalWrite(off , HIGH);
    digitalWrite(relay_pin, LOW);
    lcd.setCursor(0,0);
    lcd.print("Soil Wet");
    lcd.setCursor(0,1);
    lcd.print("Motor OFF");
  }

  delay(1000);
  }