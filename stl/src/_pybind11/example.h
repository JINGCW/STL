#ifndef this_pybind11_example
#define this_pybind11_example

#include <pybind11/pybind11.h>

namespace py = pybind11;

//template<typename T>
int pybind11_add(int a, int b);

PYBIND11_MODULE(pybind11_example, m)
{
    m.doc() = "pybind11 example plugin";//origin module docstring
    m.def("add", &pybind11_add, "function which add 2 numbers");
}

#endif
