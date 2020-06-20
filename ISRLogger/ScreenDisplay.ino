void Display() {
  GetData();
  GetButtonTopState();
  GetButtonBottomState();
  GetButtonStates();
  execScreen();
}

void execScreen(){
  //Running 8x Loop for 20x04 Display
  for (int i=0; i<8; i++) {
    //Get Text Index
    int ThisScreenIndex = ScreenIndex[i];
    
    //Set Text
    String Text = "";
    if (ThisScreenIndex == 0) Text += "RPM:" + String(GetRpm());
    if (ThisScreenIndex == 1) Text += "ECT:" + String(GetEct()) + "C";
    if (ThisScreenIndex == 2) Text += "IAT:" + String(GetIat()) + "C";
    if (ThisScreenIndex == 3) Text += "TPS:" + String(GetTps()) + "%";
    if (ThisScreenIndex == 4) Text += "O2:" + String(GetO2());
    if (ThisScreenIndex == 5) Text += "IGN:" + String(GetIgn());
    if (ThisScreenIndex == 6) Text += "INJ:" + String(GetInj()) + "ms";
    if (ThisScreenIndex == 7) Text += "FUEL:" + String(GetInstantConsumption()) + "L";
    if (ThisScreenIndex == 8) Text += "DTY:" + String(GetInjectorDuty());
    if (ThisScreenIndex == 9) Text += "MAP:" + String(GetMap());
    if (ThisScreenIndex == 10) Text += "VSS:" + String(GetVss()) + "kmh";
    if (ThisScreenIndex == 11) Text += "Gear:" + String(GetGear());
    if (ThisScreenIndex == 12) Text += "BATT:" + String(GetBattery());
    if (ThisScreenIndex == 13) Text += "VTSM:" + String(GetVTSM());
    if (ThisScreenIndex == 14) Text += "ICUT:" + String(GetIgnCut());
    if (ThisScreenIndex == 15) Text += "FCUT:" + String(GetFuelCut1());
    if (ThisScreenIndex == 16) Text += "FCUT2:" + String(GetFuelCut2());
    if (ThisScreenIndex == 17) Text += "INJFV:" + String(GetInjFV());
    if (ThisScreenIndex == 18) Text += "INJD:" + String(GetInjDuration());
    if (ThisScreenIndex == 19) Text += "VTP:" + String(GetVTP());
    if (ThisScreenIndex == 20) Text += "FCTRL:" + String(GetFanCtrl());
    if (ThisScreenIndex == 21) Text += "ACTRL:" + String(GetAtlCtrl());
    if (ThisScreenIndex == 22) Text += "MIL:" + String(GetMIL());
    if (ThisScreenIndex == 23) Text += "FTLI:" + String(GetInputFTL());
    if (ThisScreenIndex == 24) Text += "FTSI:" + String(GetInputFTS());
    if (ThisScreenIndex == 25) Text += "EBCI:" + String(GetInputEBC());
    if (ThisScreenIndex == 26) Text += "BSTI:" + String(GetInputBST());
    if (ThisScreenIndex == 27) Text += "FTLO:" + String(GetOutputFTL());
    if (ThisScreenIndex == 28) Text += "ATLG:" + String(GetOutputAntilag());
    if (ThisScreenIndex == 29) Text += "FTSO:" + String(GetOutputFTS());
    if (ThisScreenIndex == 30) Text += "BSTCT:" + String(GetOutputBoostCut());
    if (ThisScreenIndex == 31) Text += "EBCO:" + String(GetOutputEBC());
    if (ThisScreenIndex == 32) Text += "2MAP:" + String(GetOutput2ndMap());
    if (ThisScreenIndex == 33) Text += "FCTRLO:" + String(GetOutputFanCtrl());
    if (ThisScreenIndex == 34) Text += "BSTO:" + String(GetOutputBST());
    if (ThisScreenIndex == 35) Text += "IACV:" + String(GetIACVDuty());

    //POSSIBLE USELESS DATALOGS
    //if (ThisScreenIndex == 00) Text += "   BARO:" + String(GetBaro());
    //if (ThisScreenIndex == 00) Text += "    PSTF:" + String(GetPostFuel());
    //if (ThisScreenIndex == 00) Text += "   SCC.C:" + String(GetSCCChecker());
    //if (ThisScreenIndex == 00) Text += "   ATSF1:" + String(GetATShift1());
    //if (ThisScreenIndex == 00) Text += "   ATSF2:" + String(GetATShift2());
    //if (ThisScreenIndex == 00) Text += "    IGNT:" + String(GetIgnTable());
    //if (ThisScreenIndex == 00) Text += "    PARK:" + String(GetParkN());
    //if (ThisScreenIndex == 00) Text += "    BKSW:" + String(GetBKSW());
    //if (ThisScreenIndex == 00) Text += "    ACC:" + String(GetACC());
    //if (ThisScreenIndex == 00) Text += "    STRT:" + String(GetStart());
    //if (ThisScreenIndex == 00) Text += "    SCC:" + String(GetSCC());
    //if (ThisScreenIndex == 00) Text += "   VTSFB:" + String(GetVTSFeedBack());
    //if (ThisScreenIndex == 00) Text += "    PSP:" + String(GetPSP());
    //if (ThisScreenIndex == 00) Text += "    FPMP:" + String(GetFuelPump());
    //if (ThisScreenIndex == 00) Text += "    IAB:" + String(GetIAB());
    //if (ThisScreenIndex == 00) Text += "   PURGE:" + String(GetPurge());
    //if (ThisScreenIndex == 00) Text += "    AC:" + String(GetAC());
    //if (ThisScreenIndex == 00) Text += "    O2H:" + String(GetO2Heater());
    //if (ThisScreenIndex == 00) Text += "    VTS:" + String(GetVTS());
    //if (ThisScreenIndex == 00) Text += "  ELDV:" + String(GetELDVolt()) + "v";
    //if (ThisScreenIndex == 00) Text += "   ECTFC:" + String(GetECTFC());
    //if (ThisScreenIndex == 00) Text += "    O2S:" + String(GetO2Short());
    //if (ThisScreenIndex == 00) Text += "    O2L:" + String(GetO2Long());
    //if (ThisScreenIndex == 00) Text += "   IATFC:" + String(GetIATFC());
    //if (ThisScreenIndex == 00) Text += "   VEFC:" + String(GetVEFC());
    //if (ThisScreenIndex == 00) Text += "  IATIC:" + String(GetIATIC());
    //if (ThisScreenIndex == 00) Text += "  ECTIC:" + String(GetECTIC());
    //if (ThisScreenIndex == 00) Text += "  GEARIC:" + String(GetGEARIC());
    //if (ThisScreenIndex == 00) Text += "   EBCHi:" + String(GetInputEBCHi());
    //if (ThisScreenIndex == 00) Text += "   GPO1I:" + String(GetInputGPO1());
    //if (ThisScreenIndex == 00) Text += "   GPO2I:" + String(GetInputGPO2());
    //if (ThisScreenIndex == 00) Text += "   GPO3I:" + String(GetInputGPO3());
    //if (ThisScreenIndex == 00) Text += " EBCBDTY:" + String(GetEBCBaseDuty());
    //if (ThisScreenIndex == 00) Text += "  EBCDTY:" + String(GetEBCDuty());
    //if (ThisScreenIndex == 00) Text += "   GPO1O:" + String(GetOutputGPO1());
    //if (ThisScreenIndex == 00) Text += "   GPO2O:" + String(GetOutputGPO2());
    //if (ThisScreenIndex == 00) Text += "   GPO3O:" + String(GetOutputGPO3());
    //if (ThisScreenIndex == 00) Text += "   BSTS2:" + String(GetOutputBSTStage2());
    //if (ThisScreenIndex == 00) Text += "   BSTS3:" + String(GetOutputBSTStage3());
    //if (ThisScreenIndex == 00) Text += "   BSTS4:" + String(GetOutputBSTStage4());
    //if (ThisScreenIndex == 00) Text += "    LEAN:" + String(GetLeanProtect());
    
    //Reset Invalid Char Over Text Lenght
    int ResetLenght = 10 - Text.length();
    for (int i2=0; i2<ResetLenght; i2++) Text += " ";

    //Offset the text (to show 2x value wide rather than only one)
    int Offset = 0;
    int Lines = i;
    if (i == 1)  {
      Lines = 0;
      Offset = 10;
    }
    if (i == 2) Lines = 1;
    if (i == 3) {
      Lines = 1;
      Offset = 10;
    }
    if (i == 4) Lines = 2;
    if (i == 5) {
      Lines = 2;
      Offset = 10;
    }
    if (i == 6) Lines = 3;
    if (i == 7) {
      Lines = 3;
      Offset = 10;
    }
    
    //Print Text
    lcd.setCursor(Offset, Lines);
    lcd.print(Text);
  }
}

