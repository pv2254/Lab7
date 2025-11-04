int buttons[] = {33, 34, 35, 36};
int channelLeds[] = {38, 39, 40};

int channelButtonPin = 37;
int channelDisplayed = 0;
bool channelButtonState = LOW;
bool channelLastButtonState = LOW;
bool channelButtonON = false;


bool instButtonState = LOW;
bool instLastButtonState = LOW;

bool buttonState[] = {LOW, LOW, LOW, LOW};
bool lastbuttonState[] = {LOW, LOW, LOW, LOW};
bool buttonOn[3][4] = {
  {false, false, false, false},
  {false, false, false, false},
  {false, false, false, false}, };

int leds[]= {5, 7, 9, 11};
int tempo = 0;
int potTempo = 0;

unsigned long lastStepTime = 0;
int currentStep = 0;


int modeSwitchPin = 32;

int x = 0;



void setup() {
Serial.begin(9600);
pinMode(channelButtonPin, INPUT);

for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT);
}

for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
}
}

int getTempo(){
  tempo = analogRead(10);
  potTempo = map(tempo, 0 , 1023, 0, 1000);
  return potTempo;
}


void loop() {
    sequence_SEQ_MODE();

  if(digitalRead(modeSwitchPin) == HIGH){
      x = 0;
  checkButton_SEQ_MODE();
  checkLed_SEQ_MODE();}
  if(digitalRead(modeSwitchPin) == LOW){
  if(x==0){
    analogWrite(leds[0], 0);
    analogWrite(leds[1], 0);
    analogWrite(leds[2], 0);
    analogWrite(leds[3], 0);}
  _KB_();
  checkChannelButton();
  x = 1;}}

