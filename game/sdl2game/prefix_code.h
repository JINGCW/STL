#ifndef _PREFIX_CODE_H
#define _PREFIX_CODE_H
#pragma once

//#define SDL_MAIN_HANDLED

using M_Integer = const int;
using M_Uint8 = unsigned char;
using M_Uint16 = unsigned short;
using M_Uint32 = unsigned;
using M_Uint64 = unsigned long long;

M_Integer M_fps = 60;//frames per second

M_Integer M_delay_time = 1000.0f / M_fps;

#define frame_delay_begin M_frame_begin = SDL_GetTicks();

#define frame_delay_end M_frame_interval = SDL_GetTicks() - M_frame_begin;\
                if (M_frame_interval < M_delay_time)\
                    SDL_Delay(static_cast<M_Uint32>(M_delay_time - M_frame_interval));


#endif //_PREFIX_CODE_H
