--
-- joystick.lua -- joystick management
--
package.path="D:/c_repo/cpp_prime/game/sdl"

local SDL	= require "SDL"
print(SDL.flags.Joystick)


local ret, err = SDL.init { SDL.flags.Joystick }
if not ret then
	error(err)
end
print(SDL.joystickOpen)
print('******************')
-- Try to open the first joystick
local joy, err = SDL.joystickOpen(0)
if not joy then
	error(err)
end
--print(joy)
--print(err)

print(string.format("Joystick 0: %s", joy:name()))
print(string.format("    buttons: %d", joy:numButtons()))
print(string.format("    hats: %d", joy:numHats()))
print(string.format("    axes: %d", joy:numAxes()))
print(string.format("    balls: %d", joy:numBalls()))

while true do
	for e in SDL.pollEvent() do
		if e.type == SDL.event.Quit then
			break
		elseif e.type == SDL.event.JoyAxisMotion then
			print(string.format("axis %d: %d", e.axis, e.value))
		elseif e.type == SDL.event.JoyBallMotion then
			print(string.format("ball motion %d: %d, %d", e.ball, e.xrel, e.yrel))
		elseif e.type == SDL.event.JoyButtonDown then
			print(string.format("button down: %d", e.button))
		elseif e.type == SDL.event.JoyButtonUp then
			print(string.format("button up: %d", e.button))
		end
	end
end
