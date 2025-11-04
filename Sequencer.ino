bool channel_1 = false;
bool channel_2 = false;
bool channel_3 = false;

void checkButton_SEQ_MODE(){
  for (int i = 0; i < 4; i++) {

  lastbuttonState[i] = buttonState[i];
  buttonState[i] = digitalRead(buttons[i]);
  if(lastbuttonState[i] == LOW and buttonState[i] == HIGH){
    buttonOn[checkChannelButton_SEQ_MODE()][i] = !buttonOn[checkChannelButton_SEQ_MODE()][i];
    delay(5); }}
    }
void checkLed_SEQ_MODE(){
  for (int i = 0; i < 4; i++) {
if(currentStep == i){
    analogWrite(leds[i], 255);}
  else if(buttonOn[checkChannelButton_SEQ_MODE()][i] == true) {
    analogWrite(leds[i], 100);}
    else{
    analogWrite(leds[i], 0);}

    }}

int checkChannelButton_SEQ_MODE(){
  digitalWrite(channelLeds[channelDisplayed], HIGH);
  Serial.println(channelDisplayed);
channelLastButtonState = channelButtonState;
  channelButtonState = digitalRead(37);
  if(channelLastButtonState == LOW and channelButtonState == HIGH){
    digitalWrite(channelLeds[channelDisplayed], LOW);

    channelDisplayed += 1;
        delay(5); }

  if(channelLastButtonState == HIGH and channelButtonState == LOW){
        delay(5); }

    if(channelDisplayed > 2){
      channelDisplayed = 0;}
    return channelDisplayed;
    }
    

void notePlay_SEQ_MODE(){
usbMIDI.sendNoteOff(36, 0, 1);
usbMIDI.sendNoteOff(38, 0, 1);
usbMIDI.sendNoteOff(42, 0, 1);
channel_1 = false;
channel_2 = false;
channel_3 = false;
if (buttonOn[0][currentStep] == true){
      usbMIDI.sendNoteOn(36, 127, 1);
      channel_1 = true;}
if (buttonOn[1][currentStep] == true){
      usbMIDI.sendNoteOn(38, 127, 1);
      channel_2 = true;}
if (buttonOn[2][currentStep] == true){
      usbMIDI.sendNoteOn(42, 127, 1);
      channel_3 = true;}}



void sequence_SEQ_MODE(){
  if (millis() > lastStepTime + getTempo()) {

    lastStepTime = millis();
    currentStep += 1;

  if (currentStep == 4) {
    currentStep = 0;}    
        notePlay_SEQ_MODE();

 }}
 
 
 void checkChannelButton(){
    digitalWrite(channelLeds[0], LOW);
    digitalWrite(channelLeds[1], LOW);
    digitalWrite(channelLeds[2], LOW);

  if(channel_1 == true){
    digitalWrite(channelLeds[0], HIGH);}
    if(channel_2 == true){
    digitalWrite(channelLeds[1], HIGH);}
    if(channel_3 == true){
    digitalWrite(channelLeds[2], HIGH);}}

