#include "Game.h"


void Game::update(size_t n_sheets)
{
//    int n_sheets_selected = int((SDL_GetTicks() / 100) % n_sheets);
    M_curr_frame = int((SDL_GetTicks() / 100) % n_sheets);
//    cout << "n_sheets_selected" << M_curr_frame << endl;

    if (M_curr_frame >= 4)
    {
//        mb_src_rectangle.y = 200;
//        mb_src_rectangle.x = n_sheets_selected % 4 * 128;
        M_curr_row = 2;
        M_curr_frame %= 4;
    } else
    {
        M_curr_row = 1;
//        mb_src_rectangle.x = n_sheets_selected * 128;
////        mb_src_rectangle.y = 0;
    }
//    m_vector2d.set_x(m_vector2d.get_x() + 1);
//    m_vector2d.set_y(m_vector2d.get_y() + 1);
    m_velocity += m_acceleration;
    m_vector2d += m_velocity;
#ifdef Game_DEBUG_m_vector2d
    cout << "m_vector2d.x: " << m_vector2d.get_x()<<"                "
         << "m_vector2d.y: " << m_vector2d.get_y() << endl;
#endif
//    mb_dest_rectangle.x = mb_src_rectangle.x;//control rectangle move
//    SDL_Delay(100);
}

void Game::animation_sprite_sheet(const char *file)
{
    auto *surface = SDL_LoadBMP(file);
    cout << "target file path: " << file << endl;
//    auto *surface = IMG_Load("assets/11.bmp");
    mb_texture = SDL_CreateTextureFromSurface(mb_renderer, surface);
    SDL_FreeSurface(surface);

//    mb_src_rectangle.x = 100;
//    mb_src_rectangle.y = 100;
//    mb_src_rectangle.w = 480;
    mb_src_rectangle.w = 128;
//    mb_src_rectangle.h = 480;
    mb_src_rectangle.h = 200;
    static auto once_call = [&]() -> int {
        cout << "bmp x is :" << mb_dest_rectangle.x << "\n"
             << "bmp y is :" << mb_dest_rectangle.y << endl;
        return 0;
    }();

    mb_dest_rectangle.w = mb_src_rectangle.w;
    mb_dest_rectangle.h = mb_src_rectangle.h;
//    mb_dest_rectangle.x = mb_dest_rectangle.y = 0;
//    SDL_RenderCopy(mb_renderer, mb_texture, &mb_src_rectangle, &mb_src_rectangle);
    SDL_RenderCopyEx(mb_renderer, mb_texture, &mb_src_rectangle, &mb_dest_rectangle,
                     0, nullptr, SDL_FLIP_NONE);
}

void Game::mario_bmp_show()
{
    SDL_Surface *surface = SDL_LoadBMP("assets/mario.bmp");
    mb_texture = SDL_CreateTextureFromSurface(mb_renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(mb_texture, nullptr, nullptr,
                     &mb_src_rectangle.w, &mb_src_rectangle.h);

    static auto once_call = [&]() -> int {
        cout << "bmp height is :" << mb_src_rectangle.h << "\n"
             << "bmp width is :" << mb_src_rectangle.w << endl;
        return 0;
    }();

    mb_dest_rectangle.x = mb_src_rectangle.x = 0;
    mb_dest_rectangle.y = mb_src_rectangle.y = 0;

    mb_dest_rectangle.x = 140;
    mb_dest_rectangle.y = 150;

    mb_dest_rectangle.w = mb_src_rectangle.w;
    mb_dest_rectangle.h = mb_src_rectangle.h;
    SDL_RenderCopy(mb_renderer, mb_texture,
//                   &mb_src_rectangle, &mb_dest_rectangle);
                   nullptr, nullptr);//make the renderer use entire texture for display.
}

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
//    mario_bmp_show();
//    animation_sprite_sheet();
//    M_texture_mgr.draw("animate", 0, 0, 200, 128,
//                       mb_renderer);
//    singleton.draw("animate", 0, 0, 200, 128,
//                   mb_renderer);
//    M_texture_mgr.draw_frame("animate", 100, 100, 200,
//                             128, M_curr_row, M_curr_frame, mb_renderer);
    singleton.draw_frame("animate",
                         static_cast<uint8_t>(m_vector2d.get_x()),
                         static_cast<uint8_t>(m_vector2d.get_y()),
                         200, 128,
                         M_curr_row, M_curr_frame,
                         mb_renderer);

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
//                SDL_SetRenderDrawColor(mb_renderer, 0, 0, 0, 255);
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
//    M_texture_mgr.load("assets/char9.bmp", "animate", mb_renderer);
    singleton.load("assets/char9.bmp", "animate", mb_renderer);

    return true;
}
