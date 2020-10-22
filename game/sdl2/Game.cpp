#include "Game.h"

Game::type Game::_instance = nullptr;

bool Game::is_key_down(SDL_Scancode key)
{
    {
        if (this_m_key_state != 0)
        {
            if (this_m_key_state[key])
                return true;
            return false;
        }

        return true;
    }
}

void Game::jump(SDL_Event &event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
//        if (event.button.button==sdl_button_)
        //    jump_height = 32 * height + 24.0f;
        jump_height = 200;
//    current_jump_height = 0;
        current_jump_speed = start_jump_speed;

        if (current_jump_height <= jump_height)
        {
            jump_state = 1;
            current_jump_height += gravity;
            if (current_jump_height > jump_height)
                current_jump_height = jump_height;
        } else
        {
            jump_state = 0;
            current_jump_height -= gravity;
            if (current_jump_height < 0)
                current_jump_height = 0;
        }
    }
}

void Game::keyboard_event_handle()
{
    auto object = InputHandler::instance();

    if (object->is_key_down(SDL_SCANCODE_LEFT))
        m_velocity.set_x(m_velocity.get_x() - 2);
    if (object->is_key_down(SDL_SCANCODE_RIGHT))
        m_velocity.set_x(m_velocity.get_x() + 2);
    if (object->is_key_down(SDL_SCANCODE_UP))
        m_velocity.set_y(m_velocity.get_y() - 2);
    if (object->is_key_down(SDL_SCANCODE_DOWN))
        m_velocity.set_y(m_velocity.get_y() + 2);
}

void Game::update(size_t n_sheets)
{
    m_vector2d.reset();
    InputHandler::instance()->update();
    keyboard_event_handle();
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
//    m_velocity += m_acceleration;
    if (InputHandler::instance()->get_mouse_button_state(LEFT))
        m_velocity.set_x(m_velocity.get_x() + 2);
    if (InputHandler::instance()->get_mouse_button_state(RIGHT))
        m_velocity.set_x(m_velocity.get_x() - 2);
    m_vector2d += m_velocity;

#undef Game_DEBUG_m_vector2d
#ifdef Game_DEBUG_m_vector2d
    cout << "m_vector2d.x: " << m_vector2d.get_x() << "                "
         << "m_vector2d.y: " << m_vector2d.get_y() << endl;
#endif
//    mb_dest_rectangle.x = mb_src_rectangle.x;//control rectangle move
//    SDL_Delay(100);
    m_game_state_machine->update();
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
    this_m_key_state = SDL_GetKeyboardState(nullptr);

    if (SDL_PollEvent(&event))
    {
        if (is_key_down(SDL_SCANCODE_RETURN))
            m_game_state_machine->change(new PlayerState());

        switch (event.type)
        {
            case SDL_QUIT:
                mb_running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                InputHandler::instance()->handle_event(event);
                break;
            case SDL_MOUSEBUTTONUP:
                InputHandler::instance()->handle_event(event);
                break;
            default:
                break;
        }
    }
}

void Game::clean()
{
    InputHandler::instance()->clean();

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
                         static_cast<int >(m_vector2d.get_x()),
                         static_cast<int >(m_vector2d.get_y()),
                         200, 128,
                         M_curr_row, M_curr_frame,
                         mb_renderer);
    m_game_state_machine->render();

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

    std::string fileName = "assets/ico2.bmp";
    SDL_Surface *loadedSurface = SDL_LoadBMP(fileName.c_str());
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));

    SDL_SetWindowIcon(mb_window, loadedSurface);
    SDL_FreeSurface(loadedSurface);
//    M_texture_mgr.load("assets/char9.bmp", "animate", mb_renderer);
    singleton.load("assets/char9.bmp", "animate", mb_renderer);
    cout << "game_states " << MENU << endl;
    // ---- Game State
    m_curr_game_state = MENU;
    m_game_state_machine = new Game_fsm();
    m_game_state_machine->change(new MenuState());
    // ---- Game State
    m_music = new Music();
    m_music->PlayMusic(Music::mOVERWORLD);
    return true;
}
