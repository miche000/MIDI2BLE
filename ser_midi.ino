void OnConnected1() {
  //ledBlink();
  blinkOn();
}

void OnDisconnected1() {
  //ledBlink();
  blinkOff();
}

void handleNoteOn1(byte channel, byte pitch, byte velocity){
  #ifdef DEBUG 
  Serial.print("Note On  - CH: ");
  Serial.print(channel);
  Serial.print(" PITCH: ");
  Serial.print(pitch);
  Serial.print(" VEL: ");
  Serial.print(velocity);
  Serial.println();
  ledBlink();
  #endif

  SERMIDI.sendNoteOn(pitch, velocity, channel);

}

void handleNoteOff1(byte channel, byte pitch, byte velocity){
  #ifdef DEBUG 
  Serial.print("Note Off - CH: ");
  Serial.print(channel);
  Serial.print(" PITCH: ");
  Serial.print(pitch);
  Serial.print(" VEL: ");
  Serial.print(velocity);
  Serial.println();
  ledBlink();
  #endif
  
  SERMIDI.sendNoteOff(pitch, velocity, channel);

}

void handlePitchBend1( byte channel, int pitch){
  #ifdef DEBUG 
  Serial.print("PB - CH: ");
  Serial.print(channel);
  Serial.print(" PITCH: ");
  Serial.print(pitch);
  Serial.println();
  #endif

  SERMIDI.sendPitchBend(pitch, channel);
}

void handleAfterTouchPoly1(byte channel, byte note, byte velocity){
  #ifdef DEBUG 
  Serial.print("AT - CH: ");
  Serial.print(channel);
  Serial.print(" note: ");
  Serial.print(note);
  Serial.print(" BYTE2: ");
  Serial.print(velocity);
  Serial.println();
  #endif

  SERMIDI.sendAfterTouch(note, velocity, channel);
}

void handleAfterTouchChannel1(byte channel, byte velocity){
  #ifdef DEBUG 
  Serial.print("AT - CH: ");
  Serial.print(channel);
  Serial.print(" BYTE1: ");
  Serial.print(velocity);
  Serial.println();
  #endif

  SERMIDI.sendAfterTouch(velocity, channel);
}

void handleControlChange1(byte channel, byte byte1, byte byte2){
  
  #ifdef DEBUG 
  Serial.print("CC - CH: ");
  Serial.print(channel);
  Serial.print(" BYTE1: ");
  Serial.print(byte1);
  Serial.print(" BYTE2: ");
  Serial.print(byte2);
  Serial.println();
  #endif

  SERMIDI.sendControlChange( byte1, byte2, channel);
}

void handleStart1(){
  #ifdef DEBUG 
  Serial.print("Start");
  Serial.println();
  ledBlink();
  #endif
  
  SERMIDI.sendStart();
}

void handleContinue1(){
  #ifdef DEBUG 
  Serial.print("Continue");
  Serial.println();
  ledBlink();
  #endif

  SERMIDI.sendStart();
}

void handleStop1(){
  #ifdef DEBUG 
  Serial.print("Stop");
  Serial.println();
  ledBlink();
  #endif

  SERMIDI.sendStop();
}