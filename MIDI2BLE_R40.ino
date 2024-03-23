#include <Arduino.h>
//#include <BLEMidi.h>
#include <MIDI.h>

#include <BLEMIDI_Transport.h>
//#include <hardware/BLEMIDI_ESP32.h>
#include <hardware/BLEMIDI_ESP32_NimBLE.h>

//#define DEBUG

struct MySettings : public midi::DefaultSettings {
  static const long BaudRate = 31250;
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial2, SERMIDI, MySettings)

BLEMIDI_CREATE_INSTANCE("MIDI2BLE", MIDI)

void ledBlink(){
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
}

void blinkOn(){
  digitalWrite(LED_BUILTIN, LOW);
}

void blinkOff(){
  digitalWrite(LED_BUILTIN, HIGH);
}





void setup() {
  Serial.begin(115200);
  Serial.println("Initializing bluetooth");
  MIDI.begin(MIDI_CHANNEL_OMNI);
  SERMIDI.begin(MIDI_CHANNEL_OMNI);
  //BLEMidiServer.begin("MIDI2BLE");
  Serial.println("Waiting for connections...");
  //BLEMidiServer.enableDebugging();  // Uncomment if you want to see some debugging output from the library (not much for the server class...)



  SERMIDI.setHandleNoteOn            (handleNoteOn); 
  SERMIDI.setHandleNoteOff           (handleNoteOff);
  SERMIDI.setHandleStart             (handleStart); 
  SERMIDI.setHandleStop              (handleStop);
  SERMIDI.setHandleContinue          (handleContinue);
  SERMIDI.setHandlePitchBend         (handlePitchBend);
  SERMIDI.setHandleAfterTouchPoly    (handleAfterTouchPoly);
  SERMIDI.setHandleAfterTouchChannel (handleAfterTouchChannel);
  SERMIDI.setHandleControlChange     (handleControlChange);

  MIDI.setHandleNoteOn            (handleNoteOn1); 
  MIDI.setHandleNoteOff           (handleNoteOff1);
  MIDI.setHandleStart             (handleStart1); 
  MIDI.setHandleStop              (handleStop1);
  MIDI.setHandleContinue          (handleContinue1);
  MIDI.setHandlePitchBend         (handlePitchBend1);
  MIDI.setHandleAfterTouchPoly    (handleAfterTouchPoly1);
  MIDI.setHandleAfterTouchChannel (handleAfterTouchChannel1);
  MIDI.setHandleControlChange     (handleControlChange1);

  BLEMIDI.setHandleConnected(OnConnected1);
  BLEMIDI.setHandleDisconnected(OnDisconnected1);

  pinMode(LED_BUILTIN, OUTPUT);
  ledBlink();
  ledBlink();
}

void loop() {
  SERMIDI.read();
  MIDI.read();

}