#include <Arduino.h>
#include <Wire.h>
#include "BD3702.h"

BD3702::BD3702(){
    Wire.begin();
}

void BD3702::setInitial_1(int sw1, int sw2, int sw3){
           switch(sw1){
              case 0: sw1 = 0b00000000;break;
              case 1: sw1 = 0b00000001;break;
              case 2: sw1 = 0b00000010;break;
              case 3: sw1 = 0b00000011;break;
}
           switch(sw2){
              case 0: sw2 = 0b00000000;break;
              case 1: sw2 = 0b00010000;break;
              case 2: sw2 = 0b00100000;break;
              case 3: sw2 = 0b00110000;break;
}
           switch(sw3){
              case 0: sw3 = 0b00000000;break;
              case 1: sw3 = 0b10000000;break;
}
           writeWire(INITIAL_SETUP_1, 0b01000100 + sw1 + sw2 + sw3); 
}


void BD3702::setInitial_2(int sub_f, int sub_out, int l_metr){
           switch(sub_f){
              case 0: sub_f = 0b00000000;break;
              case 1: sub_f = 0b00000001;break;
              case 2: sub_f = 0b00000010;break;
              case 3: sub_f = 0b00000011;break;
}
           switch(sub_out){
              case 0: sub_out = 0b00000000;break;
              case 1: sub_out = 0b00010000;break;
              case 2: sub_out = 0b00100000;break;
              case 3: sub_out = 0b00110000;break;
}
          switch(l_metr){
              case 0: l_metr = 0b00000000;break;
              case 1: l_metr = 0b01000000;break;
}
           writeWire(INITIAL_SETUP_2, sub_f + sub_out + l_metr);
}


void BD3702::setInitial_3(int loud_f){
            switch(loud_f){
              case 0: loud_f = 0b00000001;break;
              case 1: loud_f = 0b00001001;break;
              case 2: loud_f = 0b00010001;break;
              case 3: loud_f = 0b00011001;break;
}                 
           writeWire(INITIAL_SETUP_3, loud_f);
}


void BD3702::setIn(int in, int in_type){
           switch(in){
             case 0: in = 0b00000000;break;  
             case 1: in = 0b00000001;break; 
             case 2: in = 0b00000010;break; 
             case 3: in = 0b00000011;break;
             case 4: in = 0b00001010;break;
             case 5: in = 0b00001011;break; 
             case 6: in = 0b00000110;break;
             case 7: in = 0b00001000;break;    
             case 8: in = 0b00001001;break;
}  
          switch(in_type){
             case 0: in_type = 0b00000000;break;
             case 1: in_type = 0b10000000;break;
} 
             writeWire(INPUT_SELECT, in + in_type); 
}


void BD3702::setIn_gain(int in_gain, int mute){
            switch(mute){
               case 0: mute = 0b00000000;break;
               case 1: mute = 0b10000000;break;
   }
            writeWire(INPUT_GAIN, in_gain + mute); 
   }


void BD3702::setVol(int vol){
            if(vol > 0){vol = 128 - vol;}
            if(vol <= 0){vol = abs(vol) + 128;}
            writeWire(VOLUME_GAIN, vol); 
}


void BD3702::setFront_1(int front_1){
            if(front_1 > 0){front_1 = 128 - front_1;}
            if(front_1 <= 0){front_1 = abs(front_1) + 128;}
            writeWire(FADER_1_FRONT, front_1); 
}

void BD3702::setFront_2(int front_2){
            if(front_2 > 0){front_2 = 128 - front_2;}
            if(front_2 <= 0){front_2 = abs(front_2) + 128;}         
            writeWire(FADER_2_FRONT, front_2); 
}


void BD3702::setRear_1(int rear_1){
            if(rear_1 > 0){rear_1 = 128 - rear_1;}
            if(rear_1 <= 0){rear_1 = abs(rear_1) + 128;}
            writeWire(FADER_1_REAR, rear_1); 
}

void BD3702::setRear_2(int rear_2){
            if(rear_2 > 0){rear_2 = 128 - rear_2;}
            if(rear_2 <= 0){rear_2 = abs(rear_2) + 128;}
            writeWire(FADER_2_REAR, rear_2); 
}

void BD3702::setSub(int sub){ 
            if(sub > 0){sub = 128 - sub;}
            if(sub <= 0){sub = abs(sub) + 128;}
            writeWire(FADER_SUB, sub); 
}


void BD3702::setMix_gain(int mix_g){
            if(mix_g > 0){mix_g = 128 - mix_g;}
            if(mix_g <= 0){mix_g = abs(mix_g) + 128;}
            writeWire(MIXING, mix_g); 
}


void BD3702::setBass_setup(int bass_q, int bass_f){
            switch(bass_q){
               case 0: bass_q = 0b00000000;break;
               case 1: bass_q = 0b00000001;break;
               case 2: bass_q = 0b00000010;break;
               case 3: bass_q = 0b00000011;break;  
}
            switch(bass_f){
               case 0: bass_f = 0b00000000;break;
               case 1: bass_f = 0b00010000;break;
               case 2: bass_f = 0b00100000;break;
               case 3: bass_f = 0b00110000;break;  
}
            writeWire(BASS_SETUP, bass_q + bass_f); 
}


void BD3702::setMiddle_setup(int mid_q, int mid_f){
            switch(mid_q){
               case 0: mid_q = 0b00000000;break;
               case 1: mid_q = 0b00000001;break;
               case 2: mid_q = 0b00000010;break;
               case 3: mid_q = 0b00000011;break;  
}
            switch(mid_f){
               case 0: mid_f = 0b00000000;break;
               case 1: mid_f = 0b00010000;break;
               case 2: mid_f = 0b00100000;break;
               case 3: mid_f = 0b00110000;break;  
}
            writeWire(MIDDLE_SETUP, mid_q + mid_f); 
}


void BD3702::setTreble_setup(int treb_q, int treb_f){
            switch(treb_q){
               case 0: treb_q = 0b00000000;break;
               case 1: treb_q = 0b00000001;break; 
}
            switch(treb_f){
               case 0: treb_f = 0b00000000;break;
               case 1: treb_f = 0b00010000;break;
               case 2: treb_f = 0b00100000;break;
               case 3: treb_f = 0b00110000;break;  
}
            writeWire(TREBLE_SETUP, treb_q + treb_f); 
}


void BD3702::setBass_gain(int bass_gain){
                 if(bass_gain>0){bass_gain = bass_gain + 0b00000000;}                     
                 if(bass_gain<=0){bass_gain = abs(bass_gain) + 0b10000000;}  
               writeWire(BASS_GAIN, bass_gain);   
}

void BD3702::setMiddle_gain(int mid_gain){
                 if(mid_gain>0){mid_gain = mid_gain + 0b00000000;}                     
                 if(mid_gain<=0){mid_gain = abs(mid_gain) + 0b10000000;}  
               writeWire(MIDDLE_GAIN, mid_gain);   
}

void BD3702::setTreble_gain(int treb_gain){
                 if(treb_gain>0){treb_gain = treb_gain + 0b00000000;}                     
                 if(treb_gain<=0){treb_gain = abs(treb_gain) + 0b10000000;}  
               writeWire(TREBLE_GAIN, treb_gain);   
}


void BD3702::setLoudness_gain(int loud_gain){
               writeWire(LOUDNESS_GAIN, loud_gain);  
}

void BD3702::setInitial_4(){
           writeWire(INITIAL_SETUP_4, 0b00110000);  
}

void BD3702::writeWire(char a, char b){
  Wire.beginTransmission(BD3702_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
