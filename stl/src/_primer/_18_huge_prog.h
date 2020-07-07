#ifndef STANDARD_TEMPLATE_LIBRARIES__18_HUGE_PROG_H
#define STANDARD_TEMPLATE_LIBRARIES__18_HUGE_PROG_H

#include <vector>
#include <memory>
//#include <exception>
//#include <stdexcept>
#include <iostream>
#include <new>
//#include <utility>
//#include <bits/shared_ptr.h>

using namespace std;

template <typename T>
class _Exception
{
public:
    _Exception(initializer_list<T>);
private:
    shared_ptr<vector<T>> data;
};

#endif //STANDARD_TEMPLATE_LIBRARIES__18_HUGE_PROG_H
