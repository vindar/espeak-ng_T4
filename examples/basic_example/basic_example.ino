// the main library
#include "espeak-ng_T4.h"

// for the french language
#include "espeak-ng-data/lang/roa/fr.h"
#include "espeak-ng-data/fr_dict.h"

// PJRC audio library
#include <Audio.h>


// Teensy audio system
// assume we are using the audio shield
AudioControlSGTL5000 sgtl5000;
AudioOutputI2S     audioOut;
AudioPlayMemory    playmem;
AudioConnection patchCord1(playmem, 0, audioOut, 0);
AudioConnection patchCord2(playmem, 0, audioOut, 1);




const int WAVBUFSIZE = 1000000;
EXTMEM unsigned int audiobuf[WAVBUFSIZE];
short* const wavbuf = (short*)(audiobuf + 1);
int wavbufpos = 0;


int SynthCallback(short* wav, int numsamples, espeak_EVENT* events)
    {
    if (wav == NULL || numsamples == 0)
        {
        unsigned int l = wavbufpos;
        audiobuf[0] = (l | ((0x82) << 24));
        wavbufpos = 0; // reset;
        playmem.play(audiobuf);
        return 0;
        }
    //Serial.printf("Synthese %d\n", numsamples);
    if (numsamples > 0)
        {
        if (wavbufpos + numsamples > WAVBUFSIZE)
            {
            Serial.println("***** Buffer plein *****");
            wavbufpos = 2;
            }
        memcpy(wavbuf + wavbufpos, wav, numsamples * sizeof(short));
        wavbufpos += numsamples;
        }
    /*
    for (int i = 0; events[i].type != espeakEVENT_LIST_TERMINATED; i++)
        {
        if (events[i].type == espeakEVENT_WORD)
            {
            Serial.printf("Mot a %d ms\n", events[i].audio_position);
            }
        }
    */
    return 0;
    }




int buflength = 100, options = 0;
const char* path = "/";
void* user_data = nullptr;
unsigned int* identifier = nullptr;
unsigned int position = 0, end_position = 0, flags = espeakCHARS_UTF8 | espeakSSML;
espeak_POSITION_TYPE position_type = POS_CHARACTER;





void setup() {

    Serial.begin(115200);
    while (!Serial) { delay(10); }

    AudioMemory(16);  // Allocate memory for audio processing

    sgtl5000.enable();      // Enable the audio shield
    sgtl5000.volume(0.5f);  // Set output volume

    espeak_SetMemoryLocation(1); // we want to allocate mmeory in extmem if possible (call this first, before any allocation)
    Serial.printf("eSpeak memory allocation: %s\n", espeak_GetMemoryLocation() ? "EXTMEM" : "DMAMEM");

    espeak_RegisterDict("fr", espeak_ng_data_fr_dict, espeak_ng_data_fr_dict_len);
    espeak_RegisterLang("fr", espeak_ng_data_lang_roa_fr, espeak_ng_data_lang_roa_fr_len);

    espeak_RegisterAllVariants(); // load all the voice vairant, only 50Kb in flash.

    espeak_SetSynthCallback(SynthCallback); // register the callback

    int r = espeak_Initialize(AUDIO_OUTPUT_RETRIEVAL, buflength, nullptr, options); // init the library
    Serial.printf("eSpeak init: %d", r); // should be 0

    espeak_SetVoiceByName("en");

    espeak_SetParameter(espeakRATE, 160, 0); // Set speech rate
    }


char text[] =  u8"Ceci est un test !";


int v = 0; 
void loop()
    {
    v = ((++v) % 5);
    switch (v)
        {
        case 0:
            espeak_SetVoiceByName("fr+f4");
            break;
        case 1:
            espeak_SetVoiceByName("fr+Annie");
            break;
        case 2:
            espeak_SetVoiceByName("fr+f1");
            break;
        case 3:
            espeak_SetVoiceByName("fr+anikaRobot");
            break;
        case 4:
            espeak_SetVoiceByName("fr+robosoft8");
            break;
        }

    Serial.print("eSpeak text: ");
    Serial.println(text);

    elapsedMillis em = 0;
    espeak_Synth(text, buflength, position, position_type, end_position, flags, identifier, user_data);
    Serial.print("eSpeak synth time: ");
    Serial.println(em);

    playmem.play(audiobuf);
    while (playmem.isPlaying())
        {
        delay(10);
        }

    }


/** end of file */
