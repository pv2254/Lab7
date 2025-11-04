bool KB_buttonState[] = {LOW, LOW, LOW, LOW};
bool KB_lastbuttonState[] = {LOW, LOW, LOW, LOW};
int inst_num = 2;


void note_KB_(int val, int note, int inst){

KB_lastbuttonState[val] = KB_buttonState[val];
KB_buttonState[val] = digitalRead(buttons[val]);
if(KB_buttonState[val] == HIGH and KB_lastbuttonState[val] == LOW ){
analogWrite(leds[val], 100);
usbMIDI.sendNoteOn(note, 127, inst);}
delay(5); 
if(KB_lastbuttonState[val] == HIGH and KB_buttonState[val] == LOW){
analogWrite(leds[val], 0);
usbMIDI.sendNoteOff(note, 0, inst);
delay(5); }}


int instCheck(){

instLastButtonState = instButtonState;
  instButtonState = digitalRead(37);
  if(instLastButtonState == LOW and instButtonState == HIGH){
    

    inst_num += 1;
        delay(5); }

  if(instLastButtonState == HIGH and instButtonState == LOW){
        delay(5); }

    if(inst_num > 4){
      inst_num = 2;}
    return inst_num;
    }

void _KB_() {
int current_Inst = instCheck();
note_KB_(0, 60, current_Inst) ;
note_KB_(1, 63, current_Inst);
note_KB_(2, 67,current_Inst);
note_KB_(3, 70,current_Inst);}


