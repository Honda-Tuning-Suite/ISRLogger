//Buttons Vars
#define ON 1
#define OFF 0
volatile int buttonTop = 0;
volatile int buttonBottom = 0;
volatile int buttonDual = 0;
unsigned long last_interrupt_time=0;
int debouncing = 50;

//Apply Buttons
void GetButtonStates() {
  if (buttonTop == ON) ApplyTop();
  if (buttonBottom == ON) ApplyBottom();
  if (buttonDual == ON) ApplyDual();
}

void ApplyTop() {
  //Increase Index
  ScreenIndex[ScreenCurrentIndex]++;

  //Check If the Index is not already been in use
  for (int i=0; i<8; i++)
    if (i != ScreenCurrentIndex)
      if(ScreenIndex[ScreenCurrentIndex] == ScreenIndex[i])
        ScreenIndex[ScreenCurrentIndex]++;
      
  if(ScreenIndex[ScreenCurrentIndex] > ScreenMaxIndex) ScreenIndex[ScreenCurrentIndex] = 1;
  buttonTop=OFF;
}

void ApplyBottom() {
  //Switch to the next lines
  ScreenCurrentIndex++;
  if(ScreenIndex[ScreenCurrentIndex] > (8 - 1)) ScreenCurrentIndex = 0;
  buttonBottom=OFF;
}

void ApplyDual() {
  if (ScreenOption) ScreenOption = false;
  else ScreenOption = true;
}

//###########################################################################################################
//###########################################################################################################
//###########################################################################################################
//Get States
void GetButtonTopState() {
  if (digitalRead(TopButton) == LOW) {
    if (!EcuConnected)
      EcuConnected = true;
    else {
      unsigned long interrupt_time = millis();  
      if (buttonTop == OFF && (interrupt_time - last_interrupt_time > debouncing)) {
        delay(30);
        if (digitalRead(BottomButton) == LOW) buttonDual = ON;
        else buttonTop=ON;
        last_interrupt_time = interrupt_time;
      }
    }
  }
}

void GetButtonBottomState() {
  if (digitalRead(BottomButton) == LOW) {
    if (!EcuConnected)
      EcuConnected = true;
    else {
      unsigned long interrupt_time = millis();  
      if (buttonBottom == OFF && (interrupt_time - last_interrupt_time > debouncing)) {
        delay(30);
        if (digitalRead(TopButton) == LOW) buttonDual = ON;
        else buttonBottom=ON;
        last_interrupt_time = interrupt_time;
      }
    }
  }
}
