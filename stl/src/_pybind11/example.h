#ifndef this_pybind11_example
#define this_pybind11_example

#include <pybind11/pybind11.h>
#include <string>
#include <iostream>

using namespace std;

namespace py = pybind11;

//template<typename T>
int pybind11_add(int a, int b);

struct Pet
{
    Pet() : name("pet")
    {}

    Pet(const string &name) :
            name(name)
    {}

    void set_name(const string &name_new)
    { name = name_new; }

    const string &get_name() const
    { return name; }

    string name;
};

struct Dog : public Pet
{
    Dog(const string &s) : Pet(s)
    {}

    string bark() const
    {
        cout << "Dog bark " << name << endl;
        return string("woof ") + name;
    }
};

class class_Pet
{
public:
    enum Kind
    {
        dog = 0,
        cat,
        bird
    };

    class_Pet(const string &s, Kind kind_) :
            name(s), age(0), kind(kind_)
    {}

    void set_name(const string &s)
    { name = s; }

    void set_name(int age_new)
    { age = age_new; }

    const string &get_name()
    { return name; }

    Kind kind;
private:
    string name;
    int age;
};

struct polymorphic_pet
{
    virtual ~polymorphic_pet() = default;
};

struct polymorphic_dog : public polymorphic_pet
{
    string bark() const
    { return "polymorphic woof!"; }
};

PYBIND11_MODULE(pybind11_example, m)
{
    m.doc() = "pybind11 example plugin";//origin module docstring

    //add function
    m.def("add", &pybind11_add, "function which add 2 numbers",
          py::arg("a") = 1, py::arg("b") = 2
    );
    m.attr("default answer") = 3;
    py::object world = py::cast("world");
    m.attr("what") = world;

    //Pet class
    py::class_<Pet>(m, "Pet")
            .def(py::init<const string &>())
            .def("set_name", &Pet::set_name)
            .def("get_name", &Pet::get_name)
            .def("__repr__", [](const Pet &a) {
                     return "<pybind11_example.Pet.name" + a.name + ">";
                 }
            )
            .def_readwrite("name", &Pet::name);//def_readonly for const field
    //class_Pet class
    /*
     * dynamic_attr:
     * >>> p = example.Pet()
     * >>> p.name = 'Charly'  # OK, overwrite value in C++
     * >>> p.age = 2  # OK, dynamically add a new attribute
     * >>> p.__dict__  # just like a native Python class
     * {'age': 2}
     * Note that there is a small runtime cost for a class with dynamic attributes.
     * Not only because of the addition of a __dict__,
     * but also because of more expensive garbage collection tracking which
     * must be activated to resolve possible circular references.
     * Native Python classes incur this same cost by default,
     * so this is not anything to worry about. By default, pybind11 classes
     * are more efficient than native Python classes. Enabling dynamic attributes
     * just brings them on par.
     */
    py::class_<class_Pet> class_pet(m, "class_Pet", py::dynamic_attr());
    class_pet.def(py::init<const string &, class_Pet::Kind>())
            .def_property("name", &class_Pet::get_name, (void (class_Pet::*)(const string &)) (&class_Pet::set_name))
            .def("set_name", (void (class_Pet::*)(int)) &class_Pet::set_name, "set age")
            .def("set_name", py::overload_cast<const string &>(&class_Pet::set_name), "set name")
            .def_readwrite("kind", &class_Pet::kind);
    /*
     * >>> p = Pet('Lucy', Pet.Cat)
     * >>> p.type
     * Kind.Cat
     * >>> int(p.type)
     * 1L
     * >>> Pet.Kind.__members__
     * {'Dog': Kind.Dog, 'Cat': Kind.Cat}
     */
    py::enum_<class_Pet::Kind>(class_pet, "Kind")
            .value("dog", class_Pet::Kind::dog)
            .value("cat",class_Pet::Kind::cat)
            .export_values();
    //inheritance
    py::class_<Dog, Pet/*specify c++ parent type*/>(m, "Dog")
            .def(py::init<const string &>())
            .def("bark", &Dog::bark);
    // Return a base pointer to a derived instance
    /*
     * >>> p = example.pet_store()
     * >>> type(p)  # `Dog` instance behind `Pet` pointer
     * Pet          # no pointer downcasting for regular non-polymorphic types
     * >>> p.bark()
     * AttributeError: 'Pet' object has no attribute 'bark'
     */
    m.def("pet_store", []() { return unique_ptr<Pet>(new Dog("Peter")); });
    /*>>> p = example.pet_store2()
     * >>> type(p)
     * PolymorphicDog  # automatically downcast
     * >>> p.bark()
     * u'woof!'
     */
    py::class_<polymorphic_pet>(m, "polymorphic_pet");
    py::class_<polymorphic_dog, polymorphic_pet>(m, "polymorphic_dog")
            .def(py::init<>())
            .def("bark", &polymorphic_dog::bark);
    // Again, return a base pointer to a derived instance
    m.def("pet_store2", []() { return unique_ptr<polymorphic_pet>(new polymorphic_dog()); });

}

#endif
