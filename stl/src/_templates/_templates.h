#ifndef __TEMPLATES_H
#define __TEMPLATES_H

#include <type_traits>
#include <iterator>

using namespace std;

namespace this_templates
{
    template<typename T1, typename T2>
    auto max(T1 a, T2 b) -> typename decay<decltype(true ? a : b)>::type
    {
        return b < a ? a : b;
    }

    template<class Iter1, class Iter2>
    void iter_swap(Iter1 iter1, Iter2 iter2)
    {
//        true_type
        typename Iter1::value_type tmp = *iter1;
        *iter1 = *iter2;
        *iter2 = tmp;
    }
}

#endif //__TEMPLATES_H
