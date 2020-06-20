void SetJ12Screen() {
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("    NOT CONNECTED");
    lcd.setCursor(0,2);
    lcd.print("   IS J12 REMOVED?");
    lcd.setCursor(0,3);
    lcd.print("                ");

    //Get States
    EcuConnected = GetJ12Cut();
    GetButtonTopState();
    GetButtonBottomState();
}
