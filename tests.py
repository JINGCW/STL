# import pybind11_main
import pybind11_example as bind_ex
try:
    import cPickle as pickle#use cPickle on python2.7
except ImportError:
    import pickle


def test_class_pet():
    pet = bind_ex.Pet("hehe")
    print(pet.get_name())
    pet.set_name("new_pet")
    print(pet.get_name())
    print(pet.__repr__)
    dog=bind_ex.Dog("Molly")
    print(dog.bark())
    p = bind_ex.pet_store()
    # p.bark()
    p2 = bind_ex.pet_store2()
    print(p2.bark())
    print('--------------------------')
    class_pet=bind_ex.class_Pet("lucky",bind_ex.class_Pet.cat)
    print(class_pet.kind)
    bind_ex.print_dict({'a':1,'b':2})
    #pickle
    p=bind_ex.Pickleable("test_value")
    p.set_extra(15)
    print(pickle.dumps(p,2))

    return


if __name__ == '__main__':
    # print(bind_ex.__doc__)
    # print(bind_ex.add(6, 6))
    test_class_pet()
