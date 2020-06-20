//#####################################################
//#####################################################
//#####################################################
/*
 * THIS WORKS BY DATALOGGING ECTUNE ISR V3 PROTOCOL VIA
 * THE ARDUINO SERIAL PORT. THIS WORKS WITH 2X BUTTONS 
 * NAVIGATION ONLY. IT ONLY WORKS FOR THE 20X04 LCD
 * 
 *  ####################################################
 *    ALL CREDITS GOES TO :
 * -Calvin Baank for the ISR Protocol
 * -Thatguy
*/
//#####################################################
//#####################################################
//#####################################################

//Load Modules
#include "Wire.h"
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <EEPROM.h>

//Set Inputs
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int TopButton = 9;
const int BottomButton = 8;

//Screen Settings
const int ScreenMaxIndex = 35;  //Maximum datalog values
int ScreenCurrentIndex = 0;
int ScreenIndex[8];       //Display Index for 8x values
bool ScreenOption = false;

//Options Vars
const String VersionStr = "V1.0.0";
int Timeout = 200;
int Injectors_Size = 240;
int mBarSeaLevel = 1013;
byte TrannyType = 5;
byte O2Input = 0;
byte MapValue = 0;
byte UseCelcius = 1;
byte UseKMH = 1;
bool EcuConnected = false;

//#####################################################

void setup() {
  //Initialize Screen Indexes
  for (int i=0; i<8; i++) ScreenIndex[i] = i;

  //Initialize Buttons Pinout
  pinMode(TopButton,INPUT_PULLUP);  
  pinMode(BottomButton,INPUT_PULLUP);

  //Start LCD Display
  lcd.begin(20, 4);
  StartScreen();
  lcd.clear();

  //Initialize Connection/Optinos
  Connect();
  LoadOptions();
}

//#####################################################

void loop() {
  delay(Timeout);

  //Screens Loop
  if (!ScreenOption) {
    if (!EcuConnected) SetJ12Screen();
    if (EcuConnected) Display();
  }
  else DisplayOptions();
}

