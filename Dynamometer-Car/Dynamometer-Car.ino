/*
 _____                                                  _              _____            
|  _  \                                                | |            /  __ \           
| | | |_   _ _ __   __ _ _ __ ___   ___  _ __ ___   ___| |_ ___ _ __  | /  \/ __ _ _ __ 
| | | | | | | '_ \ / _` | '_ ` _ \ / _ \| '_ ` _ \ / _ \ __/ _ \ '__| | |    / _` | '__|
| |/ /| |_| | | | | (_| | | | | | | (_) | | | | | |  __/ ||  __/ |    | \__/\ (_| | |   
|___/  \__, |_| |_|\__,_|_| |_| |_|\___/|_| |_| |_|\___|\__\___|_|     \____/\__,_|_|   
        __/ |                                                                           
       |___/  


Authors:
Pedro Mur
Bram van Laarhoven
Tomas Bolt
*/



#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <HX711.h>

//-------------------------------------------------------------------------------------------------
//GLOBAL VARIABLES
//-------------------------------------------------------------------------------------------------

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
HX711 loadCell;



//-------------------------------------------------------------------------------------------------
//FUNCTIONS
//-------------------------------------------------------------------------------------------------


//We have to run this at least once to know the calibration of our load cell
int calibration(){
  if (scale.is_ready()) {
    scale.set_scale();    
    Serial.println("Tare... remove any weights from the scale.");
    delay(5000);
    scale.tare();
    Serial.println("Tare done...");
    Serial.print("Place a known weight on the scale...");
    delay(5000);
    long reading = scale.get_units(10);
    Serial.print("Result: ");
    Serial.println(reading);
  } 
  else {
    Serial.println("HX711 not found.");
  }
  delay(1000);

  return CalibrationFactor;

  //calibration factor will be the (reading)/(known weight) 
}


//-------------------------------------------------------------------------------------------------
//MAIN
//-------------------------------------------------------------------------------------------------
void setup(){
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  //Start LCD and write some stuff
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("EXPO 1");
  lcd.setCursor(0, 1);
  lcd.print("Dynamometer Car");
}

void loop(){
    
}