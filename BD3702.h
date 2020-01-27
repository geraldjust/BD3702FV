// Александр Лиман
// liman324@yandex.ru
// rcl-radio.ru
// BD3702FV
// http://forum.rcl-radio.ru/viewtopic.php?id=121

#ifndef BD3702_H
#define BD3702_H

#define BD3702_address 0b1000000 

#define INITIAL_SETUP_1        0x01
#define INITIAL_SETUP_2        0x02
#define INITIAL_SETUP_3        0x03
#define INPUT_SELECT           0x05
#define INPUT_GAIN             0x06
#define VOLUME_GAIN            0x20
#define FADER_1_FRONT          0x28
#define FADER_2_FRONT          0x29
#define FADER_1_REAR           0x2A
#define FADER_2_REAR           0x2B
#define FADER_SUB              0x2C
#define MIXING                 0x30
#define BASS_SETUP             0x41
#define MIDDLE_SETUP           0x44
#define TREBLE_SETUP           0x47
#define BASS_GAIN              0x51
#define MIDDLE_GAIN            0x54
#define TREBLE_GAIN            0x57
#define LOUDNESS_GAIN          0x75
#define INITIAL_SETUP_4        0x90

#include <Arduino.h>
class BD3702
{
  public:
    BD3702();
    // Advanced switch time of Mute === 0.6 1.0 1.4 3.2 ms = int 0...3
    // Advanced switch time of Input gain/Volume/Tone/Fader/Loudness === 4.7 7.1 11.2 14.4 ms = int 0...3
    // Advanced switch ON/OFF === OFF ON = int 0...1    
    void setInitial_1(int sw1, int sw2, int sw3); // 0x01
    // Subwoofer LPF fc === OFF 55Hz 85 Hz 120Hz = int 0...3
    // Subwoofer Output Select === LPF Front Rear Prohibition = int 0...3
    // Level Meter RESET === HOLD RESET = int 0...1
        void setInitial_2(int sub_f, int sub_out, int l_metr); // 0x02    
    // Loudness fo === 250Hz 400Hz 800Hz Prohibition = int 0...3
        void setInitial_3(int loud_f); // 0x03
    // Input Selector === A B C D_single E1_single E2_single D_diff E_full_diff Input_SHORT = int 0...8 
        void setIn(int in, int in_type); // 0x05
    // Input Gain === 0...20 dB = int 0...20
    // MUTE ON/OFF === OFF ON = int 0...1    
        void setIn_gain(int in_gain, int mute); // 0x06
    // VOL === -79...+15 dB = int -79...15
        void setVol(int vol); // 0x20
    // FADER FRONT 1CH === -79...+15 dB = int -79...15
        void setFront_1(int front_1); // 0x28
    // FADER FRONT 2CH === -79...+15 dB = int -79...15
        void setFront_2(int front_2); // 0x29
    // FADER REAR 1CH === -79...+15 dB = int -79...15
        void setRear_1(int rear_1); // 0x2A
    // FADER REAR 2CH === -79...+15 dB = int -79...15
        void setRear_2(int rear_2); // 0x2B
    // FADER SUB === -79...+15 dB = int -79...15
        void setSub(int sub); // 0x2C
    // Mixing Gain === -79...+7 dB = int -79...7
        void setMix_gain(int mix_g); // 0x30
    // Bass Q factor === 0.5 1.0 1.5 2.0 = int 0...3
    // Bass fo === 60Hz 80Hz 100Hz 120Hz = int 0...3
        void setBass_setup(int bass_q, int bass_f); // 0x41
    // Middle Q factor === 0.75 1.0 1.25 1.5 = int 0...3
    // Middle fo === 500Hz 1kHz 1.5kHz 2.5kHz = int 0...3
        void setMiddle_setup(int mid_q, int mid_f); // 0x44
    // Treble Q factor === 0.75 1.25 = int 0...1
    // Treble fo === 7.5kHz 10kHz 12.5kHz 15kHz = int 0...3
        void setTreble_setup(int treb_q, int treb_f); // 0x47
    // Bass Gain === -20...+20 dB = int -20...20
        void setBass_gain(int bass_gain); // 0x51
    // Middle Gain === -20...+20 dB = int -20...20
        void setMiddle_gain(int mid_gain); // 0x54
    // Treble Gain === -20...+20 dB = int -20...20
        void setTreble_gain(int treb_gain); // 0x57
    // Loudness Gain === 0...20 dB = int 0...20
        void setLoudness_gain(int loud_gain); // 0x75
    // Setup 4 = not param
        void setInitial_4();

  private:
    void writeWire(char a, char b);
};
    
#endif //BD3702_H
