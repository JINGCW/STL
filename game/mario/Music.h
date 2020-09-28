#ifndef _MUSIC_H
#define _MUSIC_H
#pragma once

#include <SDL_mixer.h>
#include <vector>

#include "header.h"


class Music {
    vector<Mix_Music *> vMusic;
    vector<Mix_Chunk *> vChunk;
    int Volume;
public:
    Music();

    ~Music();

    bool music_stopped;
    enum eMusic {
        mNOTHING,
        mOVERWORLD,
        mOVERWORLDFAST,
        mUNDERWORLD,
        mUNDERWORLDFAST,
        mUNDERWATER,
        mUNDERWATERFAST,
        mCASTLE,
        mCASTLEFAST,
        mLOWTIME,
        mSTAR,
        mSTARFAST,
        mSCORERING,
    };
    eMusic curr_music;
    enum eChunk {
        cCOIN,
        cBLOCKBREAK,
        cBLOCKHIT,
        cBOOM,
        cBOWSERFALL,
        cBRIDGEBREAK,
        cBULLETBILL,
        cDEATH,
        cFIRE,
        cFIREBALL,
        cGAMEOVER,
        cINTERMISSION,
        cJUMP,
        cJUMPBIG,
        cLEVELEND,
        cLOWTIME,
        cMUSHROOMAPPER,
        cMUSHROOMMEAT,
        cONEUP,
        cPASUE,
        cPIPE,
        cRAINBOOM,
        cSHOT,
        cSHRINK,
        cSTOMP,
        cSWIM,
        cVINE,
        cCASTLEEND,
        cPRINCESSMUSIC,
    };

    void changeMusic(bool musicByLevel, bool forceChange);

    void PlayMusic();

    void PlayMusic(eMusic musicID);

    void StopMusic();

    void PauseMusic();

    void PlayChunk(eChunk chunkID);

    Mix_Music *loadMusic(std::string fileName);

    Mix_Chunk *loadChunk(std::string fileName);

    // -- get & set

    int getVolume();

    void setVolume(int iVolume);
};


#endif //_MUSIC_H
