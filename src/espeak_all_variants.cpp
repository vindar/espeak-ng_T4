/**
* Add all the voices variants (does not take much space)
**/
#include <Arduino.h> // for PROGMEM

// the namespace will prevent a linker error if user reloads a variant.
namespace espeak_all_variants
{

#include "data/voices/!v/Andrea.h"
#include "data/voices/!v/Andy.h"
#include "data/voices/!v/Annie.h"
#include "data/voices/!v/AnxiousAndy.h"
#include "data/voices/!v/Denis.h"
#include "data/voices/!v/Diogo.h"
#include "data/voices/!v/Gene.h"
#include "data/voices/!v/Gene2.h"
#include "data/voices/!v/Henrique.h"
#include "data/voices/!v/Hugo.h"
#include "data/voices/!v/Jacky.h"
#include "data/voices/!v/Lee.h"
#include "data/voices/!v/Mario.h"
#include "data/voices/!v/Michael.h"
#include "data/voices/!v/Mr_serious.h"
#include "data/voices/!v/Nguyen.h"
#include "data/voices/!v/RicishayMax.h"
#include "data/voices/!v/RicishayMax2.h"
#include "data/voices/!v/RicishayMax3.h"
#include "data/voices/!v/Storm.h"
#include "data/voices/!v/Tweaky.h"
#include "data/voices/!v/anika.h"
#include "data/voices/!v/anikaRobot.h"
#include "data/voices/!v/antonio.h"
#include "data/voices/!v/aunty.h"
#include "data/voices/!v/belinda.h"
#include "data/voices/!v/boris.h"
#include "data/voices/!v/croak.h"
#include "data/voices/!v/ed.h"
#include "data/voices/!v/f1.h"
#include "data/voices/!v/f2.h"
#include "data/voices/!v/f3.h"
#include "data/voices/!v/f4.h"
#include "data/voices/!v/f5.h"
#include "data/voices/!v/fast.h"
#include "data/voices/!v/grandma.h"
#include "data/voices/!v/grandpa.h"
#include "data/voices/!v/gustave.h"
#include "data/voices/!v/iven.h"
#include "data/voices/!v/iven2.h"
#include "data/voices/!v/iven3.h"
#include "data/voices/!v/john.h"
#include "data/voices/!v/kaukovalta.h"
#include "data/voices/!v/klatt.h"
#include "data/voices/!v/klatt2.h"
#include "data/voices/!v/klatt3.h"
#include "data/voices/!v/klatt4.h"
#include "data/voices/!v/linda.h"
#include "data/voices/!v/m1.h"
#include "data/voices/!v/m2.h"
#include "data/voices/!v/m3.h"
#include "data/voices/!v/m4.h"
#include "data/voices/!v/m5.h"
#include "data/voices/!v/m6.h"
#include "data/voices/!v/m7.h"
#include "data/voices/!v/m8.h"
#include "data/voices/!v/marcelo.h"
#include "data/voices/!v/max.h"
#include "data/voices/!v/michel.h"
#include "data/voices/!v/miguel.h"
#include "data/voices/!v/norbert.h"
#include "data/voices/!v/pablo.h"
#include "data/voices/!v/pablo2.h"
#include "data/voices/!v/paul.h"
#include "data/voices/!v/pedro.h"
#include "data/voices/!v/quincy.h"
#include "data/voices/!v/rob.h"
#include "data/voices/!v/robert.h"
#include "data/voices/!v/robosoft3.h"
#include "data/voices/!v/robosoft4.h"
#include "data/voices/!v/robosoft5.h"
#include "data/voices/!v/robosoft6.h"
#include "data/voices/!v/robosoft7.h"
#include "data/voices/!v/robosoft8.h"
#include "data/voices/!v/sandro.h"
#include "data/voices/!v/shelby.h"
#include "data/voices/!v/steph.h"
#include "data/voices/!v/steph2.h"
#include "data/voices/!v/steph3.h"
#include "data/voices/!v/travis.h"
#include "data/voices/!v/victor.h"
#include "data/voices/!v/whisper.h"
#include "data/voices/!v/whisperf.h"
#include "data/voices/!v/zac.h"

} // namespace

#include "speak_lib.h"

#define ESPEAK_REGISTER_VARIANT(NAME) { espeak_RegisterVoiceVariant( #NAME , espeak_all_variants::espeak_ng_data_voices__v_##NAME , espeak_all_variants::espeak_ng_data_voices__v_##NAME##_len); }

void espeak_RegisterAllVariants()
{
    ESPEAK_REGISTER_VARIANT(Andrea)
    ESPEAK_REGISTER_VARIANT(Andy)
    ESPEAK_REGISTER_VARIANT(Annie)
    ESPEAK_REGISTER_VARIANT(AnxiousAndy)
    ESPEAK_REGISTER_VARIANT(Denis)
    ESPEAK_REGISTER_VARIANT(Diogo)
    ESPEAK_REGISTER_VARIANT(Gene)
    ESPEAK_REGISTER_VARIANT(Gene2)
    ESPEAK_REGISTER_VARIANT(Henrique)
    ESPEAK_REGISTER_VARIANT(Hugo)
    ESPEAK_REGISTER_VARIANT(Jacky)
    ESPEAK_REGISTER_VARIANT(Lee)
    ESPEAK_REGISTER_VARIANT(Mario)
    ESPEAK_REGISTER_VARIANT(Michael)
    ESPEAK_REGISTER_VARIANT(Mr_serious)
    ESPEAK_REGISTER_VARIANT(Nguyen)
    ESPEAK_REGISTER_VARIANT(RicishayMax)
    ESPEAK_REGISTER_VARIANT(RicishayMax2)
    ESPEAK_REGISTER_VARIANT(RicishayMax3)
    ESPEAK_REGISTER_VARIANT(Storm)
    ESPEAK_REGISTER_VARIANT(Tweaky)
    ESPEAK_REGISTER_VARIANT(anika)
    ESPEAK_REGISTER_VARIANT(anikaRobot)
    ESPEAK_REGISTER_VARIANT(antonio)
    ESPEAK_REGISTER_VARIANT(aunty)
    ESPEAK_REGISTER_VARIANT(belinda)
    ESPEAK_REGISTER_VARIANT(boris)
    ESPEAK_REGISTER_VARIANT(croak)
    ESPEAK_REGISTER_VARIANT(ed)
    ESPEAK_REGISTER_VARIANT(f1)
    ESPEAK_REGISTER_VARIANT(f2)
    ESPEAK_REGISTER_VARIANT(f3)
    ESPEAK_REGISTER_VARIANT(f4)
    ESPEAK_REGISTER_VARIANT(f5)
    ESPEAK_REGISTER_VARIANT(fast)
    ESPEAK_REGISTER_VARIANT(grandma)
    ESPEAK_REGISTER_VARIANT(grandpa)
    ESPEAK_REGISTER_VARIANT(gustave)
    ESPEAK_REGISTER_VARIANT(iven)
    ESPEAK_REGISTER_VARIANT(iven2)
    ESPEAK_REGISTER_VARIANT(iven3)
    ESPEAK_REGISTER_VARIANT(john)
    ESPEAK_REGISTER_VARIANT(kaukovalta)
    ESPEAK_REGISTER_VARIANT(klatt)
    ESPEAK_REGISTER_VARIANT(klatt2)
    ESPEAK_REGISTER_VARIANT(klatt3)
    ESPEAK_REGISTER_VARIANT(klatt4)
    ESPEAK_REGISTER_VARIANT(linda)
    ESPEAK_REGISTER_VARIANT(m1)
    ESPEAK_REGISTER_VARIANT(m2)
    ESPEAK_REGISTER_VARIANT(m3)
    ESPEAK_REGISTER_VARIANT(m4)
    ESPEAK_REGISTER_VARIANT(m5)
    ESPEAK_REGISTER_VARIANT(m6)
    ESPEAK_REGISTER_VARIANT(m7)
    ESPEAK_REGISTER_VARIANT(m8)
    ESPEAK_REGISTER_VARIANT(marcelo)
    ESPEAK_REGISTER_VARIANT(max)
    ESPEAK_REGISTER_VARIANT(michel)
    ESPEAK_REGISTER_VARIANT(miguel)
    ESPEAK_REGISTER_VARIANT(norbert)
    ESPEAK_REGISTER_VARIANT(pablo)
    ESPEAK_REGISTER_VARIANT(pablo2)
    ESPEAK_REGISTER_VARIANT(paul)
    ESPEAK_REGISTER_VARIANT(pedro)
    ESPEAK_REGISTER_VARIANT(quincy)
    ESPEAK_REGISTER_VARIANT(rob)
    ESPEAK_REGISTER_VARIANT(robert)
    ESPEAK_REGISTER_VARIANT(robosoft3)
    ESPEAK_REGISTER_VARIANT(robosoft4)
    ESPEAK_REGISTER_VARIANT(robosoft5)
    ESPEAK_REGISTER_VARIANT(robosoft6)
    ESPEAK_REGISTER_VARIANT(robosoft7)
    ESPEAK_REGISTER_VARIANT(robosoft8)
    ESPEAK_REGISTER_VARIANT(sandro)
    ESPEAK_REGISTER_VARIANT(shelby)
    ESPEAK_REGISTER_VARIANT(steph)
    ESPEAK_REGISTER_VARIANT(steph2)
    ESPEAK_REGISTER_VARIANT(steph3)
    ESPEAK_REGISTER_VARIANT(travis)
    ESPEAK_REGISTER_VARIANT(victor)
    ESPEAK_REGISTER_VARIANT(whisper)
    ESPEAK_REGISTER_VARIANT(whisperf)
    ESPEAK_REGISTER_VARIANT(zac)
}

/** end of file */
