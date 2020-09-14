--
-- keyboard.lua -- process keyboard states
--

local SDL	= require "SDL"

SDL.init {
	SDL.flags.Video
}

SDL.createWindow {
	title	= "QM_Keyboard",
	width	= 650,
	height	= 450
}

local keys = SDL.getKeyboardState()
print(keys)
--SDL.delay(1000*5)
while true do
	SDL.pumpEvents()

	if keys[SDL.scancode.Return] then
		print("Return pressed")
	end
	if keys[SDL.scancode.Escape] then
		print("Exiting!")
		break
	end

	--SDL.delay(1000)
	SDL.delay(10)
end
