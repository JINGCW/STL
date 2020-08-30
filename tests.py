# import pybind11_main
import pybind11_example as bind_ex

try:
    import cPickle as pickle  # use cPickle on python2.7
except ImportError:
    import pickle


def test_class_pet():
    pet = bind_ex.Pet("hehe")
    print(pet.get_name())
    pet.set_name("new_pet")
    print(pet.get_name())
    print(pet.__repr__)
    dog = bind_ex.Dog("Molly")
    print(dog.bark())
    p = bind_ex.pet_store()
    # p.bark()
    p2 = bind_ex.pet_store2()
    print(p2.bark())
    print('--------------------------')
    class_pet = bind_ex.class_Pet("lucky", bind_ex.class_Pet.cat)
    print(class_pet.kind)
    bind_ex.print_dict({'a': 1, 'b': 2})
    # pickle
    p = bind_ex.Pickleable("test_value")
    p.set_extra(15)
    print(pickle.dumps(p, 2))

    return


def temp():
    def handle_drink(num: int, deal_n: int = 0):
        if num < 2:
            return deal_n
        if num == 2:
            deal_n += 1
            return deal_n

        multiplier_3 = num // 3
        deal_n += multiplier_3
        return handle_drink(multiplier_3 + num % 3, deal_n=deal_n)

        # while True:

    n = int(input())
    out = [n]
    while n != 0:
        n = int(input())
        out.append(n)
    for x in out[:-1]:
        print(handle_drink(x))
    # return out


def lua_games_test():
    from ctypes import windll,WinDLL,CDLL

    dll = windll.LoadLibrary('./game/libgames.dll')
    # dll = WinDLL('./game/libgames.dll')
    # dll = CDLL('./game/libgames.dll')
    print(dll)
    print(dll.lobject_interface)
    # this_Object = dll.this_Object()
    # return this_Object.hello()
    # print(dll.add(3,4))
    # print(dll.nothing_c_char())
    # print(dll.nothing())


if __name__ == '__main__':
    print(lua_games_test())
# print(bind_ex.__doc__)
# print(bind_ex.add(6, 6))
# test_class_pet()
# print(temp())
