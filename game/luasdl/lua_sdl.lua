local sdl_module=require("SDL")
--require "SDL"
print(sdl_module)
print(sdl_module.init(sdl_module.SDL_INIT_EVERYTHING))

function SDL_assert(condition,msg)
    local msg=(msg and msg .. ': ' .. sdl_module.SDL_GetError())
    return assert(condition,msg)
end

local window_x_pos=128
local window_y_pos=128
local window_width=640
local window_height=480
local window_bpp=0
local window_flags=0
--SDL_assert(sdl_module.init(sdl_module.SDL_INIT_EVERYTHING)==true,"Couldn't initialize SDL")
