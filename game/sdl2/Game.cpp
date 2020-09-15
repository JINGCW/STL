#include "Game.h"
#include <string>
#include <iostream>

using namespace std;

void Game::handle_events()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                mb_running = false;
                break;
            default:
                break;
        }
    }
}

void Game::clean()
{
    cout << "cleaning game..." << endl;
    SDL_DestroyWindow(mb_window);
    SDL_DestroyRenderer(mb_renderer);
    SDL_Quit();
}

void Game::render()
{
    //clear the renderer to draw the color
    SDL_RenderClear(mb_renderer);
    //draw the screen
    SDL_RenderPresent(mb_renderer);
}

bool Game::init(const char *title, int xpos, int ypos, int height,
                int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        cout << "SDL init succeed..." << endl;
        mb_window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
        if (mb_window != 0)
        {
            cout << "window creation succeed..." << endl;
            mb_renderer = SDL_CreateRenderer(mb_window, -1, 0);
            if (mb_renderer != 0)
            {
                cout << "renderer creation succeed..." << endl;
                SDL_SetRenderDrawColor(mb_renderer, 255, 255, 255, 255);
            } else
            {
                cout << "renderer creation failed!" << endl;
                return false;
            }
        } else
        {
            cout << "window creation failed!" << endl;
            return false;
        }
    } else
    {
        cout << "SDL init failed!" << endl;
        return false;
    }

    cout << "init success..." << endl;
    mb_running = true;

    return true;
}
