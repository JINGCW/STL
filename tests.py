# import pybind11_main
import pybind11_example


def test_class_pet():
    pet = pybind11_example.Pet("hehe")
    print(pet.get_name())
    pet.set_name("new_pet")
    print(pet.get_name())
    print(pet.__repr__)
    dog=pybind11_example.Dog("Molly")
    print(dog.bark())
    p = pybind11_example.pet_store()
    # p.bark()
    p2 = pybind11_example.pet_store2()
    print(p2.bark())
    print('--------------------------')
    class_pet=pybind11_example.class_Pet("lucky",pybind11_example.class_Pet.cat)
    print(class_pet.kind)
    return


if __name__ == '__main__':
    print(pybind11_example.__doc__)
    print(pybind11_example.add(6, 6))
    test_class_pet()
