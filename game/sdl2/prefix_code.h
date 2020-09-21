#ifndef _PREFIX_CODE_H
#define _PREFIX_CODE_H

#define SDL_MAIN_HANDLED

/*define Game_DEBUG to print*/
//#define Game_DEBUG

#define Game_DEBUG_m_vector2d

/*fixed frames per second*/
constexpr unsigned FPS = 60;

const unsigned DELAY_INTERVAL = 10000.0f / FPS;
#define fixed_frames_ps_begin frame_begin=SDL_GetTicks();
#define fixed_frames_ps_end frame_interval = SDL_GetTicks() - frame_begin;\
                if (frame_interval<DELAY_INTERVAL)\
                SDL_Delay(DELAY_INTERVAL - frame_interval);

#endif //_PREFIX_CODE_H
