void handleNoteOn(byte channel, byte pitch, byte velocity){
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

  MIDI.sendNoteOn(pitch, velocity, channel);

}

void handleNoteOff(byte channel, byte pitch, byte velocity){
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
  
  MIDI.sendNoteOff(pitch, velocity, channel);

}

void handlePitchBend( byte channel, int pitch){
  #ifdef DEBUG 
  Serial.print("PB - CH: ");
  Serial.print(channel);
  Serial.print(" PITCH: ");
  Serial.print(pitch);
  Serial.println();
  #endif

  MIDI.sendPitchBend(pitch, channel);
}

void handleAfterTouchPoly(byte channel, byte note, byte velocity){
  #ifdef DEBUG 
  Serial.print("AT - CH: ");
  Serial.print(channel);
  Serial.print(" note: ");
  Serial.print(note);
  Serial.print(" BYTE2: ");
  Serial.print(velocity);
  Serial.println();
  #endif

  MIDI.sendAfterTouch(note, velocity, channel);
}

void handleAfterTouchChannel(byte channel, byte velocity){
  #ifdef DEBUG 
  Serial.print("AT - CH: ");
  Serial.print(channel);
  Serial.print(" BYTE1: ");
  Serial.print(velocity);
  Serial.println();
  #endif

  MIDI.sendAfterTouch(velocity, channel);
}

void handleControlChange(byte channel, byte byte1, byte byte2){
  
  #ifdef DEBUG 
  Serial.print("CC - CH: ");
  Serial.print(channel);
  Serial.print(" BYTE1: ");
  Serial.print(byte1);
  Serial.print(" BYTE2: ");
  Serial.print(byte2);
  Serial.println();
  #endif

  MIDI.sendControlChange( byte1, byte2, channel);
}

void handleStart(){
  #ifdef DEBUG 
  Serial.print("Start");
  Serial.println();
  ledBlink();
  #endif
  
  MIDI.sendStart();
}

void handleContinue(){
  #ifdef DEBUG 
  Serial.print("Continue");
  Serial.println();
  ledBlink();
  #endif

  MIDI.sendStart();
}

void handleStop(){
  #ifdef DEBUG 
  Serial.print("Stop");
  Serial.println();
  ledBlink();
  #endif

  MIDI.sendStop();
}