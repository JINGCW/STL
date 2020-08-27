--在 Lua 里，最主要的线程是协同程序（coroutine）。它跟线程（thread）差不多，
--拥有自己独立的栈、局部变量和指令指针，可以跟其他协同程序共享全局变量和其他大部分东西。
--
--线程跟协程的区别：线程可以同时多个运行，而协程任意时刻只能运行一个，
--并且处于运行状态的协程只有被挂起（suspend）时才会暂停。

print("hello world")

function hello()
    print(type("hello world"))
    print(type(type))
    print(type(print))
    print(type(true))
    print(type(nil))
    --[[represent a block of string]]
    html = [[
<html>
<head></head>
<body>
    <a href="http://www.runoob.com/">菜鸟教程</a>
</body>
</html>
]]
    print(html)
    --string concat
    print(6 .. 8)
    print("jflaj" .. 89)
    len="fajklfjakl"
    print(#len)
end

--hello()
function lua_table()
    print(len)

    local table_empty={}
    local table_init_direct={"dog","cat"}

    for k,v in pairs(table_init_direct) do
        print(k .. ":" .. v)
    end
    --pirnt(gettable_event(table_init_direct,0))

end

lua_table()
