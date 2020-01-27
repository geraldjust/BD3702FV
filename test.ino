#include <BD3702.h>
  BD3702 bd;

void setup() {
  audio();
}

void loop() {}

void audio(){
    // Advanced switch time of Mute === 0.6 1.0 1.4 3.2 ms = int 0...3
    // Advanced switch time of Input gain/Volume/Tone/Fader/Loudness === 4.7 7.1 11.2 14.4 ms = int 0...3
    // Advanced switch ON/OFF === OFF ON = int 0...1    
  bd.setInitial_1(0, 0, 0); // 0x01
    // Subwoofer LPF fc === OFF 55Hz 85 Hz 120Hz = int 0...3
    // Subwoofer Output Select === LPF Front Rear Prohibition = int 0...3
    // Level Meter RESET === HOLD RESET = int 0...1
  bd.setInitial_2(0, 0, 0); // 0x02  
    // Loudness fo === 250Hz 400Hz 800Hz Prohibition = int 0...3
  bd.setInitial_3(0); // 0x03
    // Input Selector === A B C D_single E1_single E2_single D_diff E_full_diff Input_SHORT = int 0...8 
  bd.setIn(0, 0); // 0x05
    // Input Gain === 0...20 dB = int 0...20
    // MUTE ON/OFF === OFF ON = int 0...1    
  bd.setIn_gain(0, 0); // 0x06
    // VOL === -79...+15 dB = int -79...15
  bd.setVol(0); // 0x20
    // FADER FRONT 1CH === -79...+15 dB = int -79...15
  bd.setFront_1(0); // 0x28
    // FADER FRONT 2CH === -79...+15 dB = int -79...15
  bd.setFront_2(0); // 0x29
    // FADER REAR 1CH === -79...+15 dB = int -79...15
  bd.setRear_1(0); // 0x2A
    // FADER REAR 2CH === -79...+15 dB = int -79...15
  bd.setRear_2(0); // 0x2B
    // FADER SUB === -79...+15 dB = int -79...15
  bd.setSub(0); // 0x2C
    // Mixing Gain === -79...+7 dB = int -79...7
  bd.setMix_gain(0); // 0x30
    // Bass Q factor === 0.5 1.0 1.5 2.0 = int 0...3
    // Bass fo === 60Hz 80Hz 100Hz 120Hz = int 0...3
  bd.setBass_setup(0, 0); // 0x41
    // Middle Q factor === 0.75 1.0 1.25 1.5 = int 0...3
    // Middle fo === 500Hz 1kHz 1.5kHz 2.5kHz = int 0...3
  bd.setMiddle_setup(0, 0); // 0x44
    // Treble Q factor === 0.75 1.25 = int 0...1
    // Treble fo === 7.5kHz 10kHz 12.5kHz 15kHz = int 0...3
  bd.setTreble_setup(0, 0); // 0x47
    // Bass Gain === -20...+20 dB = int -20...20
  bd.setBass_gain(0); // 0x51
    // Middle Gain === -20...+20 dB = int -20...20
  bd.setMiddle_gain(0); // 0x54
    // Treble Gain === -20...+20 dB = int -20...20
  bd.setTreble_gain(0); // 0x57
    // Loudness Gain === 0...20 dB = int 0...20
  bd.setLoudness_gain(0); // 0x75
    // Setup 4 = not param
  bd.setInitial_4();
  }
