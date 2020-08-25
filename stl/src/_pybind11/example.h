#ifndef this_pybind11_example
#define this_pybind11_example

#include <pybind11/pybind11.h>
#include <string>
#include <iostream>
//#include <mutex>
//#include <map>

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

void print_dict(const py::dict &dict)
{
    for (auto item:dict)
        cout << "key=" << string(py::str(item.first))
             << ", value=" << string(py::str(item.second)) << endl;
}

/*Accepting *args and **kwargs*/
void generic(const py::args &args, const py::kwargs &kwargs)
{
    //do something with args
    if (kwargs)
        //do somthing with kwargs
        ;
}
/*default arguments revisited*/
/*
 * py::class_<MyClass>("MyClass")
 * .def("myFunction", py::arg("arg") = SomeType(123));
 *
 * py::class_<MyClass>("MyClass")
 * .def("myFunction", py::arg_v("arg", SomeType(123), "SomeType(123)"));
 *
 * py::class_<MyClass>("MyClass")
 * .def("myFunction", py::arg("arg") = (SomeType *) nullptr);
 */
class Animal
{
public:
    virtual ~Animal()
    {};

    virtual string go(size_t n) = 0;

    virtual string name()
    { return "unknown"; }
};

class Py_animal : public Animal
{
public:
    /* Inherit the constructors */
    using Animal::Animal;

    /* Trampoline (need one for each virtual function) */
    string go(size_t n) override
    {
        PYBIND11_OVERLOAD_PURE(
                string,//return type
                Animal,//parent class
                go,/* Name of function in C++ (must match Python name) */
                n//arguments
        );
    }

    string name() override
    {PYBIND11_OVERLOAD(string, Animal, name,); }
};


class animal_dog : public Animal
{
public:
    string go(size_t n) override
    {
        string out;
        for (auto i = 0; i < n; ++i)
            out += bark() + " ";
        return out;
    }

    virtual string bark()
    { return "woof!"; }
};

class Py_animal_dog : public animal_dog
{
public:
    using animal_dog::animal_dog;

    string go(size_t n) override
    {
        PYBIND11_OVERLOAD(string, animal_dog, go, n);
    }

    string bark() override
    {PYBIND11_OVERLOAD(string, animal_dog, bark,); }

    string name() override
    {PYBIND11_OVERLOAD(string, animal_dog, name,); }
};

string call_go(Animal *animal)
{
    return animal->go(3);
}
/*
 * template <class AnimalBase = Animal> class PyAnimal : public AnimalBase {
 * public:
 *  using AnimalBase::AnimalBase; // Inherit constructors
 *  std::string go(int n_times) override { PYBIND11_OVERLOAD_PURE(std::string, AnimalBase, go, n_times); }
 *  std::string name() override { PYBIND11_OVERLOAD(std::string, AnimalBase, name, ); }
 *  };
 * template <class DogBase = Dog> class PyDog : public PyAnimal<DogBase> {
 * public:
    using PyAnimal<DogBase>::PyAnimal; // Inherit constructors
    // Override PyAnimal's pure virtual go() with a non-pure one:
    std::string go(int n_times) override { PYBIND11_OVERLOAD(std::string, DogBase, go, n_times); }
    std::string bark() override { PYBIND11_OVERLOAD(std::string, DogBase, bark, ); }
};

py::class_<Animal, PyAnimal<>> animal(m, "Animal");
py::class_<Dog, PyDog<>> dog(m, "Dog");
py::class_<Husky, PyDog<Husky>> husky(m, "Husky");
// ... add animal, dog, husky definitions
*/
//Custom constructors
class Custom_constructor
{
private:
    Custom_constructor(int v):
    value(v){}//private constructor
public:
    //factory function
    static Custom_constructor create(int a)
    { return Custom_constructor(a); }

private:
    int value;
};

//Pickling support
class Pickleable
{
public:
    Pickleable(const string &v) :
            m_value(v)
    {}

    const string &value() const
    { return m_value; }

    void set_extra(int v)
    { m_extra = v; }

    int extra()const
    { return m_extra; }

private:
    string m_value;
    int m_extra = 0;
};

PYBIND11_MODULE(pybind11_example, m)
{
    m.doc() = "pybind11 example plugin";//origin module docstring
    //Pickling support
    py::class_<Pickleable>(m, "Pickleable")
            .def(py::init<string>())
            .def("value", &Pickleable::value)
            .def("extra",&Pickleable::extra)
            .def("set_extra",&Pickleable::set_extra)
            .def(py::pickle(
                    [](const Pickleable&p){//__getstate__
                        /*return a tuple that fully encodes the state of the object*/
                        return py::make_tuple(p.value(),p.extra());
                    },
                    [](const py::tuple& t){//__setstate__
                        if(t.size()!=2)
                            throw runtime_error("Invalide state!");
                        /*create new c++ instance*/
                        Pickleable p_(t[0].cast<string>());
                        /*set any additional state*/
                        p_.set_extra(t[1].cast<int>());
                        return p_;
                    }
                    ));
    py::class_<Custom_constructor>(m, "Custom_constructor")
            .def(py::init(&Custom_constructor::create));
    //combining virtual function and inheritance
    //override virtual functions in Python
    py::class_<Animal, Py_animal/*trampoline*/>(m, "Animal")
            .def(py::init<>())
            .def("go", &Animal::go);
    py::class_<animal_dog, Animal>(m, "animal_dog")
            .def(py::init<>());
    m.def("call_go", &call_go);

    m.def("bark_with_none", [](Dog *dog) -> string {
        if (dog)return "woof with none";
        return "no dog";
    }, py::arg("dog").none(true));
    //Non-converting arguments
    m.def("floats_only", [](float f) { return 0.5 * f; }, py::arg("f").noconvert());
    m.def("floats_prefered", [](float f) { return 0.5 * f; }, py::arg("f"));

    m.def("print_dict", &print_dict);
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
            .value("cat", class_Pet::Kind::cat)
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
