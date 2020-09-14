--
-- server.lua -- echo server using SDL_net
--

--local net	= require "SDL.net"
local this_net	= require "net"

-- Init this_net4
this_net.init()

-- Bind a socket
local addr = this_net.resolveHost(nil, 5959)
local s = this_net.openTcp(addr)

-- Create a set
local set = this_net.set(32)

-- Add the socket for accepting clients
set:add(s)

-- Store all clients too
local clients = { }

while true do
	local n = set:checkSockets(-1)

	if n > 0 then
		if s:ready() then
			local c = s:accept()
			if c then
				print("New client")
				table.insert(clients, c)
				set:add(c)
			end
		else
			for i, c in ipairs(clients) do
				if c:ready() then
					local value, n = c:recv(128)
	
					if not value then
						print("Client disconnected")
						set:del(c)
						table.remove(clients, i)
					else
						print(value)
					end
				end
			end
		end
	end
end

-- Close everything
this_net.quit()
