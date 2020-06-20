bool J12_Cut        = true;
const int Array_Size    = 52;
byte Datalog_Bytes[Array_Size];
byte GB[10] = {0x46, 0x00, 0x67, 0x00, 0x8E, 0x00, 0xB8, 0x00, 0x52, 0xDE};

void Connect() {
  Serial.begin(38400);
}

/*void Disconnect() {
  Serial.end();
}*/

bool GetJ12Cut() {
  J12_Cut = true;
  Serial.write((byte) 171);
  if ((int) Serial.read() != 205) J12_Cut = false;
  return J12_Cut;
}

void GetData(){
  while(Serial.available())
    for (int i = 0; i < Array_Size; i++)
      Datalog_Bytes[i] = Serial.read();
      
  Serial.flush();
  Serial.write(" ");
}

void SetTranny(int ThisTranny) {
  TrannyType = ThisTranny;
  if (ThisTranny == 0) {
    GB[0] = 0x46;
    GB[1] = 0x00;
    GB[2] = 0x67;
    GB[3] = 0x00;
    GB[4] = 0x8E;
    GB[5] = 0x00;
    GB[6] = 0xB8;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB[10] = {0x46, 0x00, 0x67, 0x00, 0x8E, 0x00, 0xB8, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 1) {
    GB[0] = 0x42;
    GB[1] = 0x00;
    GB[2] = 0x5D;
    GB[3] = 0x00;
    GB[4] = 0x87;
    GB[5] = 0x00;
    GB[6] = 0xB6;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x42, 0x00, 0x5D, 0x00, 0x87, 0x00, 0xB6, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 2) {
    GB[0] = 0x46;
    GB[1] = 0x00;
    GB[2] = 0x64;
    GB[3] = 0x00;
    GB[4] = 0x91;
    GB[5] = 0x00;
    GB[6] = 0xB8;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x46, 0x00, 0x64, 0x00, 0x91, 0x00, 0xB8, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 3) {
    GB[0] = 0x48;
    GB[1] = 0x00;
    GB[2] = 0x71;
    GB[3] = 0x00;
    GB[4] = 0xAA;
    GB[5] = 0x00;
    GB[6] = 0xE3;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x48, 0x00, 0x71, 0x00, 0xAA, 0x00, 0xE3, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 4) {
    GB[0] = 0x46;
    GB[1] = 0x00;
    GB[2] = 0x6E;
    GB[3] = 0x00;
    GB[4] = 0x9A;
    GB[5] = 0x00;
    GB[6] = 0xC4;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x46, 0x00, 0x6E, 0x00, 0x9A, 0x00, 0xC4, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 5) {
    GB[0] = 0x48;
    GB[1] = 0x00;
    GB[2] = 0x71;
    GB[3] = 0x00;
    GB[4] = 0xB2;
    GB[5] = 0x00;
    GB[6] = 0xD6;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x48, 0x00, 0x71, 0x00, 0xB2, 0x00, 0xD6, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 6) {
    GB[0] = 0x47;
    GB[1] = 0x00;
    GB[2] = 0x6E;
    GB[3] = 0x00;
    GB[4] = 0x9E;
    GB[5] = 0x00;
    GB[6] = 0xC3;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x47, 0x00, 0x6E, 0x00, 0x9E, 0x00, 0xC3, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 7) {
    GB[0] = 0x47;
    GB[1] = 0x00;
    GB[2] = 0x6E;
    GB[3] = 0x00;
    GB[4] = 0x9E;
    GB[5] = 0x00;
    GB[6] = 0xC9;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x47, 0x00, 0x6E, 0x00, 0x9E, 0x00, 0xC9, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 8) {
    GB[0] = 0x4A;
    GB[1] = 0x00;
    GB[2] = 0x7B;
    GB[3] = 0x00;
    GB[4] = 0xAF;
    GB[5] = 0x00;
    GB[6] = 0xE0;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x4A, 0x00, 0x7B, 0x00, 0xAF, 0x00, 0xE0, 0x00, 0x52, 0xDE};
  } else if (ThisTranny == 9) {
    GB[0] = 0x4B;
    GB[1] = 0x00;
    GB[2] = 0x7D;
    GB[3] = 0x00;
    GB[4] = 0xBC;
    GB[5] = 0x00;
    GB[6] = 0xED;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x4B, 0x00, 0x7D, 0x00, 0xBC, 0x00, 0xED, 0x00, 0x52, 0xDE};
  } else if (ThisTranny > 9) {
    GB[0] = 0x46;
    GB[1] = 0x00;
    GB[2] = 0x67;
    GB[3] = 0x00;
    GB[4] = 0x8E;
    GB[5] = 0x00;
    GB[6] = 0xB8;
    GB[7] = 0x00;
    GB[8] = 0x52;
    GB[9] = 0xDE;
    //GB = {0x46, 0x00, 0x67, 0x00, 0x8E, 0x00, 0xB8, 0x00, 0x52, 0xDE};
    TrannyType = 0;
  }
}

long Long2Bytes(byte ThisByte1, byte ThisByte2) {
  return (long) ((long) ThisByte2 * 256 + (long) ThisByte1);
}

float GetTemperature(byte ThisByte) {
  float ThisTemp = (float) ThisByte / 51;
  ThisTemp = (0.1423*pow(ThisTemp,6)) - (2.4938*pow(ThisTemp,5))  + (17.837*pow(ThisTemp,4)) - (68.698*pow(ThisTemp,3)) + (154.69*pow(ThisTemp,2)) - (232.75*ThisTemp) + 284.24;
  ThisTemp = ((ThisTemp - 32)*5)/9;

  if (UseCelcius == 0)
    ThisTemp = ThisTemp * 1.8 + 32.0;
  
  return ThisTemp;
  /*if (UseCelcius)
    return round(double_Temperature[(int) ThisByte]);
  return round(GetTemperatureF(double_Temperature[(int) ThisByte]));*/
}

double GetVolt(byte ThisByte) {
  return round(((double) ThisByte * 0.0196078438311815) * 100) / 100;
}

float GetDuration(int ThisInt) {
  return (float) ThisInt * 3.20000004768372 / 1000.0;
}

byte GetActivated(byte ThisByte, int ThisPos, bool Reversed) {
  int bitArray[8];
  for (int i=0; i < 8; ++i ) {
    bitArray[i] = ThisByte & 1;
    ThisByte = ThisByte >> 1;
  }

  if (Reversed)
    return bitArray[ThisPos] ? (byte) 0 : (byte) 1;
  return bitArray[ThisPos] ? (byte) 1 : (byte) 0;
}

float GetInstantConsumption(){
  float hundredkm = ((60 / GetVss()) * 100) / 60;     //minutes needed to travel 100km
  float fuelc = (hundredkm * ((Injectors_Size / 100) * GetDuty())) / 1000;     
  return constrain(fuelc, 0.0001, 50.0);
}

float GetDuty(){
  return ((float) GetRpm() * (float) GetInj()) / 1200;
}

float GetValueHG(int ThisInt) {
  return (float) round(((double) ThisInt * 0.02952999) * 10) / 10;
}

unsigned int GetEct(){
  return GetTemperature(Datalog_Bytes[0]);
}

unsigned int GetIat(){
  return GetTemperature(Datalog_Bytes[1]);                  
}

float GetO2(){
  if (O2Input == 0) return round((float) GetVolt(Datalog_Bytes[2]) * 100) / 100;//O2Byte = Datalog_Bytes[2];
  if (O2Input == 1) return round((float) GetVolt(Datalog_Bytes[24]) * 100) / 100;//O2Byte = Datalog_Bytes[24];
  if (O2Input == 2) return round((float) GetVolt(Datalog_Bytes[44]) * 100) / 100;//O2Byte = Datalog_Bytes[44];   //byte_25
  if (O2Input == 3) return round((float) GetVolt(Datalog_Bytes[45]) * 100) / 100;//O2Byte = Datalog_Bytes[45]; 
  //return round((float) GetVolt(O2Byte) * 100) / 100;
  //return ((2 * (float) O2Byte[2]) + 10) / 10f;
}

unsigned int GetBaro(){
  return (int) round((double) ((int) Datalog_Bytes[3] / 2 + 24) * 7.221 - 59.0);
}

float GetMap(){
  int ThisInt = (int) Datalog_Bytes[4];
  //if (MapValue == 0) return ((float) ThisInt * 2041) / 255;  //(1764/255) * (float) ThisInt;
  if (MapValue == 0) return 6.9176 * (float) ThisInt;
  else if (MapValue == 1) return (float) (ThisInt / 1000);
  else if (MapValue == 2) return (float) round(-((double) GetValueHG(mBarSeaLevel) + (double) GetValueHG(ThisInt)) * 10) / 10;
  else if (MapValue == 3) return GetValueHG(ThisInt);
  else if (MapValue == 4) return (float) round(((double) (ThisInt - mBarSeaLevel) * 0.0145037695765495) * 100) / 100; //GetValuePSI(ThisInt);
  else if (MapValue == 5) return (float) round((double) ThisInt * 0.1); //GetValueKPa(ThisInt);
  else return 0;

  //float mapRaw = Datalog_Bytes[4];
  //return (1764/255)*mapRaw;
}

unsigned int GetTps(){
  return (int) round(((double) Datalog_Bytes[5] - 25.0) / 2.04);
  //return constrain((0.4716  * Datalog_Bytes[5]) - 11.3184, 0, 100);    
}

unsigned int GetRpm(){
  //return (int) (1875000/Long2Bytes(Datalog_Bytes[6], Datalog_Bytes[7]));
  return (int) (1851562/Long2Bytes(Datalog_Bytes[6], Datalog_Bytes[7]));  
}

bool GetIgnCut(){
  return (bool) GetActivated(Datalog_Bytes[8], 2, false);
}

bool GetVTSM(){
  return (bool) GetActivated(Datalog_Bytes[8], 3, false);
}

bool GetFuelCut1(){
  return (bool) GetActivated(Datalog_Bytes[8], 4, false);
}

bool GetFuelCut2(){
  return (bool) GetActivated(Datalog_Bytes[8], 5, false);
}

unsigned int GetVss(){
  if (UseKMH == 1)
    return (int) Datalog_Bytes[16];
  return (int) round((float) Datalog_Bytes[16] / 1.6f);
}

double GetInjFV() {
    return round(((double) Long2Bytes(Datalog_Bytes[17], Datalog_Bytes[18]) / 4.0) * 100) / 100;
}

float GetInjectorDuty() {
  return (float) ((double) GetRpm() * (double) GetDuration(Long2Bytes(Datalog_Bytes[17], Datalog_Bytes[18])) / 1200.0);
}

float GetInj(){
  return (float) (Long2Bytes(Datalog_Bytes[17], Datalog_Bytes[18]) / 352);  
}

unsigned int GetIgn(){
  return (0.25 * Datalog_Bytes[19]) - 6;
}

bool GetVTP(){
  return (bool) GetActivated(Datalog_Bytes[21], 3, false);
}

bool GetFanCtrl(){
  return (bool) GetActivated(Datalog_Bytes[22], 4, false);
}

bool GetAtlCtrl(){
  return (bool) GetActivated(Datalog_Bytes[22], 5, false);
}

bool GetMIL(){
  return (bool) GetActivated(Datalog_Bytes[23], 5, false);
}

float GetBattery(){  
  return (26.0 * Datalog_Bytes[25]) / 270.0;
}

bool GetInputFTL(){
  return (bool) GetActivated(Datalog_Bytes[38], 0, false);
}

bool GetInputFTS(){
  return (bool) GetActivated(Datalog_Bytes[38], 1, false);
}

bool GetInputEBC(){
  return (bool) GetActivated(Datalog_Bytes[38], 2, false);
}

bool GetInputBST(){
  return (bool) GetActivated(Datalog_Bytes[38], 7, false);
}

bool GetOutputFTL(){
  return (bool) GetActivated(Datalog_Bytes[39], 0, false);
}

bool GetOutputAntilag(){
  return (bool) GetActivated(Datalog_Bytes[39], 1, false);
}

bool GetOutputFTS(){
  return (bool) GetActivated(Datalog_Bytes[39], 2, false);
}

bool GetOutputBoostCut(){
  return (bool) GetActivated(Datalog_Bytes[39], 3, false);
}

bool GetOutputEBC(){
  return (bool) GetActivated(Datalog_Bytes[39], 4, false);
}

bool GetOutput2ndMap(){
  return (bool) GetActivated(Datalog_Bytes[39], 5, false);
}

bool GetOutputFanCtrl(){
  return (bool) GetActivated(Datalog_Bytes[39], 6, false);
}

bool GetOutputBST(){
  return (bool) GetActivated(Datalog_Bytes[39], 7, false);
}

bool GetLeanProtect(){
  return (bool) GetActivated(Datalog_Bytes[43], 7, false);
}

double GetIACVDuty(){
  return ((double) ((float) Long2Bytes(Datalog_Bytes[49], Datalog_Bytes[50]) / 32768) * 100.0 - 100.0);
}

double GetMapVolt(){
  return GetVolt(Datalog_Bytes[4]);
}

double GetTPSVolt(){
  return GetVolt(Datalog_Bytes[5]);
}

double GetInjDuration(){
  return round(((double) GetDuration((int) Long2Bytes(Datalog_Bytes[17], Datalog_Bytes[18]))) * 100) / 100;
}

unsigned int GetGear(){ 
  if (GetVss() == 0)
    return 0;

  long ThisRatio = (long) (GetVss() * 256) * (long) GetRpm() / (long) 256;
  byte Gear = 0;

  for (int i = 0; i < 4; i++) {
    int ThisIndex = i * 2;
    if (ThisRatio >= GB[ThisIndex]) Gear = i + 1;
    else break;
  }

  return Gear;
}






//################################################################################################################################
//################################################################################################################################
//################################################################################################################################
//REMOVED UNUSED DISPLAY

/*int GetIgnTable(){
  return (0.25 * Datalog_Bytes[20]) - 6;
}

bool GetParkN(){
  return (bool) GetActivated(Datalog_Bytes[21], 0, false);
}

bool GetBKSW(){
  return (bool) GetActivated(Datalog_Bytes[21], 1, false);
}

bool GetACC(){
  return (bool) GetActivated(Datalog_Bytes[21], 2, false);
}

bool GetStart(){
  return (bool) GetActivated(Datalog_Bytes[21], 4, false);
}

bool GetSCC(){
  return (bool) GetActivated(Datalog_Bytes[21], 5, false);
}

bool GetVTSFeedBack(){
  return (bool) GetActivated(Datalog_Bytes[21], 6, false);
}

bool GetPSP(){
  return (bool) GetActivated(Datalog_Bytes[21], 7, false);
}

bool GetFuelPump(){
  return (bool) GetActivated(Datalog_Bytes[22], 0, false);
}

bool GetIAB(){
  return (bool) GetActivated(Datalog_Bytes[22], 2, false);
}

bool GetPurge(){
  return (bool) GetActivated(Datalog_Bytes[22], 6, false);
}

bool GetAC(){
  return (bool) GetActivated(Datalog_Bytes[22], 7, false);
}

bool GetO2Heater(){
  return (bool) GetActivated(Datalog_Bytes[23], 6, false);
}

bool GetVTS(){
  return (bool) GetActivated(Datalog_Bytes[23], 7, false);
}

double GetELDVolt(){
  return GetVolt(Datalog_Bytes[24]);
}

bool GetATShift1(){
  return (bool) GetActivated(Datalog_Bytes[8], 6, false);
}

bool GetATShift2(){
  return (bool) GetActivated(Datalog_Bytes[8], 7, false);
}

double GetECTFC(){
  return GetFC(Datalog_Bytes[26], 128);
}

long GetO2Short(){
  return (long) GetFC(Long2Bytes(Datalog_Bytes[27], Datalog_Bytes[28]), 32768);
}

long GetO2Long(){
  return (long) GetFC(Long2Bytes(Datalog_Bytes[29], Datalog_Bytes[30]), 32768);
}

long GetIATFC(){
  return (long) GetFC(Long2Bytes(Datalog_Bytes[31], Datalog_Bytes[32]), 32768);
}

double GetVEFC(){
  return GetFC(Datalog_Bytes[33], 128);
}

float GetIATIC(){
  return GetIC(Datalog_Bytes[34]);
}

float GetECTIC(){
  return GetIC(Datalog_Bytes[35]);
}

float GetGEARIC(){
  return GetIC(Datalog_Bytes[36]);
}

bool GetInputEBCHi(){
  return (bool) GetActivated(Datalog_Bytes[38], 3, false);
}

bool GetInputGPO1(){
  return (bool) GetActivated(Datalog_Bytes[38], 4, false);
}

bool GetInputGPO2(){
  return (bool) GetActivated(Datalog_Bytes[38], 5, false);
}

bool GetInputGPO3(){
  return (bool) GetActivated(Datalog_Bytes[38], 6, false);
}

double GetEBCBaseDuty(){
  return GetEBC(Datalog_Bytes[40]);
}

double GetEBCDuty(){
  return GetEBC(Datalog_Bytes[41]);
}

bool GetOutputGPO1(){
  return (bool) GetActivated(Datalog_Bytes[43], 0, false);
}

bool GetOutputGPO2(){
  return (bool) GetActivated(Datalog_Bytes[43], 1, false);
}

bool GetOutputGPO3(){
  return (bool) GetActivated(Datalog_Bytes[43], 2, false);
}

bool GetOutputBSTStage2(){
  return (bool) GetActivated(Datalog_Bytes[43], 3, false);
}

bool GetOutputBSTStage3(){
  return (bool) GetActivated(Datalog_Bytes[43], 4, false);
}

bool GetOutputBSTStage4(){
  return (bool) GetActivated(Datalog_Bytes[43], 5, false);
}

bool GetPostFuel(){
  return (bool) GetActivated(Datalog_Bytes[8], 0, false);
}

bool GetSCCChecker(){
  return (bool) GetActivated(Datalog_Bytes[8], 1, false);
}

float GetIC(byte ThisByte) {
  if ((int) ThisByte == 128)
    return 0.0f;
  if ((int) ThisByte < 128)
    return (float) (128 - (int) ThisByte) * -0.25f;
  return (float) ((int) ThisByte - 128) * 0.25f;
}

double GetFC(long ThisByte, long ThisLong) {
  double num = (double) ThisByte / (double) ThisLong;
  //if (CorrectionUnits == "multi")
    return round((num) * 100) / 100;
  //return round(num * 100.0 - 100.0);
}

double GetEBC(byte ThisByte) {
  double num = (double) ThisByte / 2.0;
  if (num > 100.0)
    num = 100.0;
  return round((num * 10)) / 10;
}*/
