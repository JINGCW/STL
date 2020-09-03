local example_module = require("libExample")

print(example_module)

example_module.say_hello()
local avg, sum = example_module.average(1, 2, 3, 4)

print(avg)
print(sum)

--local my_mathlib = require("my_math") --my_math 是一个dll或so，由下面的.c生成
--
--print(my_mathlib)
--print(my_mathlib.my_sin(3.14))
--print(my_mathlib.my_cos(3.14))
