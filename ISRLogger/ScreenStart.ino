void StartScreen(){
  String T1 = "        HONDA";
  String T2 = "      Datalogger";
  String T3 = "        " + VersionStr;
  String T4 = "    eCtune ISR V3";

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(T1);
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(T2);
  delay(1000);
  lcd.setCursor(0,2);
  lcd.print(T3);
  lcd.setCursor(0,3);
  lcd.print(T4);
  delay(2000);  
}
