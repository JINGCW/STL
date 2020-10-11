/*==============================================================================
Play Stream Example
Copyright (c), Firelight Technologies Pty, Ltd 2004-2020.

This example shows how to simply play a stream such as an MP3 or WAV. The stream
behaviour is achieved by specifying FMOD_CREATESTREAM in the call to 
System::createSound. This makes FMOD decode the file in realtime as it plays,
instead of loading it all at once which uses far less memory in exchange for a
small runtime CPU hit.
==============================================================================*/
#include "fmod.hpp"
#include "common.h"

#include <iostream>

using namespace std;

int FMOD_Main() {
    FMOD::System *system;
    FMOD::Sound *sound, *sound_to_play, *rabbit;
    FMOD::Channel *channel = 0;
    FMOD_RESULT result;
    unsigned int version;
    void *extradriverdata = 0;
    int numsubsounds;

    Common_Init(&extradriverdata);

    /*
        Create a System object and initialize.
    */
    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    if (version < FMOD_VERSION) {
        Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
    }

    result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
    ERRCHECK(result);

    /*
        This example uses an FSB file, which is a preferred pack format for fmod containing multiple sounds.
        This could just as easily be exchanged with a wav/mp3/ogg file for example, but in this case you wouldnt need to call getSubSound.
        Because getNumSubSounds is called here the example would work with both types of sound file (packed vs single).
    */
//    result = system->createStream(Common_MediaPath("wave_vorbis.fsb"), FMOD_LOOP_NORMAL | FMOD_2D, 0, &sound);
    result = system->createStream(Common_MediaPath("DLC_music.fsb"), FMOD_DEFAULT | FMOD_LOOP_OFF, 0, &sound);
//    result = system->createStream(Common_MediaPath("dontstarve.fev"), FMOD_LOOP_NORMAL | FMOD_2D, 0, &sound);
    ERRCHECK(result);
    result = system->createStream(Common_MediaPath("rabbit.fsb"), FMOD_LOOP_NORMAL | FMOD_3D, 0, &rabbit);
    ERRCHECK(result);

//    result = sound->getNumSubSounds(&numsubsounds);
//    ERRCHECK(result);
//
//    if (numsubsounds)
//    {
//        sound->getSubSound(0, &sound_to_play);
//        ERRCHECK(result);
//    }
//    else
//    {
//        sound_to_play = sound;
//    }
//
//    /*
//        Play the sound.
//    */
//    result = system->playSound(sound_to_play, 0, false, &channel);
//    ERRCHECK(result);

    /*
        Main loop.
    */
//#define toggle_music bool paused;\
//    result = channel->getPaused(&paused);\
//    ERRCHECK(result);\
//    result = channel->setPaused(!paused);\
//    ERRCHECK(result);
#define toggle_music
    do {
        Common_Update();
//        result = sound->getNumSubSounds(&numsubsounds);
//        ERRCHECK(result);
//        cout << "BTN_ACTION1 numsubsounds " << numsubsounds << endl;
//        Common_Draw("BTN_ACTION1 numsubsounds %d", numsubsounds);

        if (Common_BtnPress(BTN_ACTION1)) {
            toggle_music
//            bool paused;
//            channel->getPaused(&paused);
//            if (!paused)
//                channel->setPaused(true);
//            FMOD::Sound *renew_music;
//            sound->getSubSound(0, &renew_music);

            result = sound->getNumSubSounds(&numsubsounds);
            ERRCHECK(result);
            if (numsubsounds) {
//                cout << "BTN_ACTION1 numsubsounds" <<numsubsounds<< endl;
                sound->getSubSound(0, &sound_to_play);
//            result = system->playSound(sound_to_play, 0, false, &channel);

                ERRCHECK(result);
            } else {
                sound_to_play = sound;
            }
            result = system->playSound(sound_to_play, 0, false, &channel);
//            result = system->playSound(renew_music, 0, false, &channel);
            ERRCHECK(result);
        }
        if (Common_BtnPress(BTN_ACTION2)) {
            toggle_music
            result = rabbit->getNumSubSounds(&numsubsounds);
            ERRCHECK_fn(result, __FILE__, __LINE__);
            if (numsubsounds) {
                rabbit->getSubSound(0, &sound_to_play);
                ERRCHECK(result);
            }
            result = system->playSound(sound_to_play, 0, false, &channel);
            ERRCHECK(result);
        }

        result = system->update();
        ERRCHECK(result);

        {
            unsigned int ms = 0;
            unsigned int lenms = 0;
            bool playing = false;
            bool paused = false;
            int channelsplaying = 0;

            if (channel) {
                FMOD::Sound *currentsound = 0;

                result = channel->isPlaying(&playing);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE)) {
                    ERRCHECK(result);
                }

                result = channel->getPaused(&paused);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE)) {
                    ERRCHECK(result);
                }

                result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE)) {
                    ERRCHECK(result);
                }

                channel->getCurrentSound(&currentsound);
                if (currentsound) {
//                    result = sound_to_play->getLength(&lenms, FMOD_TIMEUNIT_MS);
                    result = currentsound->getLength(&lenms, FMOD_TIMEUNIT_MS);
                    if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE)) {
                        ERRCHECK(result);
                    }
                }
            }

            system->getChannelsPlaying(&channelsplaying, nullptr);

            Common_Draw("==================================================");
            Common_Draw("Play Stream Example.");
            Common_Draw("Copyright (c) Firelight Technologies 2004-2020.");
            Common_Draw("==================================================");
            Common_Draw("");
//            Common_Draw("Press %s to toggle pause", Common_BtnStr(BTN_ACTION1));
            Common_Draw("Press %s to play a mono sound (DLC_music)", Common_BtnStr(BTN_ACTION1));
            Common_Draw("Press %s to play a mono sound (rabbit)", Common_BtnStr(BTN_ACTION2));
//            Common_Draw("Press %s to play a stereo sound (fxs)", Common_BtnStr(BTN_ACTION3));
            Common_Draw("Press %s to quit", Common_BtnStr(BTN_QUIT));
            Common_Draw("");
            Common_Draw("Time %02d:%02d:%02d/%02d:%02d:%02d : %s", ms / 1000 / 60, ms / 1000 % 60, ms / 10 % 100,
                        lenms / 1000 / 60, lenms / 1000 % 60, lenms / 10 % 100,
                        paused ? "Paused " : playing ? "Playing" : "Stopped");
            Common_Draw("Channels Playing %d", channelsplaying);
        }

        Common_Sleep(50);
    } while (!Common_BtnPress(BTN_QUIT));

    /*
        Shut down
    */
    result = sound->release();  /* Release the parent, not the sound that was retrieved with getSubSound. */
    ERRCHECK(result);
    result = rabbit->release();
    ERRCHECK(result);

    result = system->close();
    ERRCHECK(result);
    result = system->release();
    ERRCHECK(result);

    Common_Close();

    return 0;
}
