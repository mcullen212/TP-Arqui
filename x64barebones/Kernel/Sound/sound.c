#include <sound.h>
#include <timer.h>

#define PIT_BASE 1193180

//Play sound using built in speaker
static void play_sound(uint32_t nFrequence) {
 	uint32_t pitLoader; //
 	uint8_t currentPort61;
 
        //Set the PIT to the desired frequency
 	pitLoader = PIT_BASE / nFrequence;
 	outPortSpeaker(0x43, 0xb6);
 	outPortSpeaker(0x42, (uint8_t) (pitLoader) );
 	outPortSpeaker(0x42, (uint8_t) (pitLoader >> 8));
 
        //And play the sound using the PC speaker
 	currentPort61 = inPortSpeaker(0x61);
  	if (currentPort61 != (currentPort61 | 3)) {
 		outPortSpeaker(0x61, currentPort61| 3);
 	}
 }
 
 //make it shutup
static void nosound() {
 	uint8_t tmp = inPortSpeaker(0x61) & 0xFC;
 
 	outPortSpeaker(0x61, tmp);
 }
 
 //Make a beep
 void beep(uint32_t frequency) {
 	 play_sound(frequency);
 	 sleep(200);
 	 nosound();
    
 }



