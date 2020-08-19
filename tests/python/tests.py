from . import _pybind11_ex

def test_pybind11_add():
    return _pybind11_ex.add(6,6)
