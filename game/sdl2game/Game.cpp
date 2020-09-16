#include "Game.h"

void MGame::update(std::size_t n_sheets) {
    auto nth_sheets = static_cast<int>((SDL_GetTicks() / 100) % n_sheets);
    cout << "nth_sheets: " << nth_sheets << endl;

    if (nth_sheets >= 4) {
        m_src_rect.y = 130;
        m_src_rect.x = nth_sheets % 4 * 128;
    }else
    {
        m_src_rect.x = 128 * nth_sheets;
        m_src_rect.y = 0;
    }
    SDL_Delay(100);
}

void MGame::animating_sprite_sheet(const string &file, std::size_t n_sheets) {
    auto surface = SDL_LoadBMP(file.c_str());
//    auto surface = IMG_Load(file.c_str());

    m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_FreeSurface(surface);

    m_dest_rect.w=m_src_rect.w = 128;
    m_dest_rect.h=m_src_rect.h = 200;
    SDL_RenderCopyEx(m_renderer, m_texture, &m_src_rect, &m_dest_rect ,
                     0, nullptr, SDL_FLIP_NONE);
}

void MGame::texture_shown() {
    SDL_Surface *surface = SDL_LoadBMP("assets/vine_top.bmp");
//    SDL_Surface *surface = IMG_Load("assets/vine_top.bmp");
    m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_src_rect.w, &m_src_rect.h);
    m_dest_rect.x = m_src_rect.x = 0;
    m_dest_rect.y = m_src_rect.y = 0;
    m_dest_rect.w = m_src_rect.w;
    m_dest_rect.h = m_src_rect.h;
    SDL_RenderCopy(m_renderer, m_texture, &m_src_rect, &m_dest_rect);

    SDL_FreeSurface(surface);
}

void MGame::handle_events() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_running = false;
                break;
            default:
                break;
        }
    }
}

void MGame::clean() {
    cout << "cleaning game...\n";
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

void MGame::render() {
    //clean the renderer to draw the color
    SDL_RenderClear(m_renderer);
//    texture_shown();
    animating_sprite_sheet();
    //draw the screen
    SDL_RenderPresent(m_renderer);
}


bool MGame::init(const char *title, int xpos, int ypos, int height, int width, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        cout << "SDL init succeed..." << endl;
        m_window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
        if (m_window) {
            cout << "window creation succeed..." << endl;
            m_renderer = SDL_CreateRenderer(m_window, -1, 0);
            if (m_renderer) {
                cout << "renderer creation succeed..." << endl;
                SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
//                SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
            } else {
                cout << "renderer creation faild!\n";
                return false;
            }
        } else {
            cout << "window creation faild\n";
            return false;
        }
    } else {
        cout << "SDL init failed!\n";
        return false;
    }

    cout << "init success\n";
    m_running = true;
    texture_shown();
    return true;
}
