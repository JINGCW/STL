#include "Music.h"

Music::Music() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    vMusic.push_back(loadMusic("overworld"));
    vMusic.push_back(loadMusic("overworld-fast"));
    vMusic.push_back(loadMusic("underground"));
    vMusic.push_back(loadMusic("underground-fast"));
    vMusic.push_back(loadMusic("underwater"));
    vMusic.push_back(loadMusic("underwater-fast"));
    vMusic.push_back(loadMusic("castle"));
    vMusic.push_back(loadMusic("castle-fast"));
    vMusic.push_back(loadMusic("lowtime"));
    vMusic.push_back(loadMusic("starmusic"));
    vMusic.push_back(loadMusic("starmusic-fast"));
    vMusic.push_back(loadMusic("scorering"));

    vChunk.push_back(loadChunk("coin"));
    vChunk.push_back(loadChunk("blockbreak"));
    vChunk.push_back(loadChunk("blockhit"));
    vChunk.push_back(loadChunk("boom"));
    vChunk.push_back(loadChunk("bowserfall"));
    vChunk.push_back(loadChunk("bridgebreak"));
    vChunk.push_back(loadChunk("bulletbill"));
    vChunk.push_back(loadChunk("death"));
    vChunk.push_back(loadChunk("fire"));
    vChunk.push_back(loadChunk("fireball"));
    vChunk.push_back(loadChunk("gameover"));
    vChunk.push_back(loadChunk("intermission"));
    vChunk.push_back(loadChunk("jump"));
    vChunk.push_back(loadChunk("jumpbig"));
    vChunk.push_back(loadChunk("levelend"));
    vChunk.push_back(loadChunk("lowtime"));
    vChunk.push_back(loadChunk("mushroomappear"));
    vChunk.push_back(loadChunk("mushroomeat"));
    vChunk.push_back(loadChunk("oneup"));
    vChunk.push_back(loadChunk("pause"));
    vChunk.push_back(loadChunk("shrink"));
    vChunk.push_back(loadChunk("rainboom"));
    vChunk.push_back(loadChunk("shot"));
    vChunk.push_back(loadChunk("shrink"));
    vChunk.push_back(loadChunk("stomp"));
    vChunk.push_back(loadChunk("swim"));
    vChunk.push_back(loadChunk("vine"));
    vChunk.push_back(loadChunk("castleend"));
    vChunk.push_back(loadChunk("princessmusic"));

    setVolume(100);
    curr_music = mNOTHING;
}

Music::~Music() {
    for (auto vm:vMusic)
        Mix_FreeMusic(vm);
    vMusic.clear();

    for (auto vc:vChunk)
        Mix_FreeChunk(vc);
    vChunk.clear();
}

void Music::PlayMusic(eMusic musicID) {
    if (musicID != mNOTHING) {
        Mix_PlayMusic(vMusic[musicID - 1], -1);
        curr_music = musicID;
        music_stopped = false;
    } else {
        StopMusic();
        curr_music = mNOTHING;
    }
}

void Music::PlayMusic() {
    if (curr_music != mNOTHING) {
        Mix_PlayMusic(vMusic[curr_music - 1], 0);
        music_stopped = false;
    } else {
        StopMusic();
    }
}

void Music::StopMusic() {
    if (!music_stopped) {
        Mix_HaltMusic();
        music_stopped = true;
    }
}

void Music::PauseMusic() {
    if (Mix_PausedMusic() == 1) {
        Mix_ResumeMusic();
        music_stopped = false;
    } else {
        Mix_PauseMusic();
        music_stopped = true;
    }
}

void Music::PlayChunk(eChunk chunkID) {
    Mix_VolumeChunk(vChunk[chunkID], Volume);
    Mix_PlayChannel(-1, vChunk[chunkID], 0);
}

Mix_Chunk *Music::loadChunk(std::string fileName) {
    fileName = "files/sounds/" + fileName + ".wav";
    return Mix_LoadWAV(fileName.c_str());
}

Mix_Music *Music::loadMusic(std::string fileName) {
    fileName = "files/sounds/" + fileName + ".wav";
    return Mix_LoadMUS(fileName.c_str());
}

void Music::setVolume(int iVolume) {
    Volume = iVolume;
}

int Music::getVolume() {
    return Volume;
}
