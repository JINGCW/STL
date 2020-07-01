#ifndef STANDARD_TEMPLATE_LIBRARIES__17_STDLIB_H
#define STANDARD_TEMPLATE_LIBRARIES__17_STDLIB_H

#include <tuple>
#include <string>
#include <vector>
#include <list>
//#include <iterator>
#include <algorithm>

#include "_7_class.h"


using namespace std;

namespace _stdlib
{
    static tuple<size_t, size_t, size_t> three_d;//all 0
    static tuple<string, vector<double>, int, list<int>>
            some_value{"constants", {1.3, 3.45}, 4, {0, 1, 2}};
    //
    auto item = make_tuple("0993", 3, 20.00);
//    auto book = get<0>(item);
    auto cnt = get<1>(item);
    auto price = get<2>(item) / cnt;
//    get<2>(item) *=0.8;
    using trans=decltype(item);
    tuple_element<1, trans>::type cnt2 = get<1>(item);
    //
    using matches=
    tuple<
            vector<Sales_data>::size_type,
            vector<Sales_data>::const_iterator,
            vector<Sales_data>::const_iterator
    >;
    vector<matches >find_book(const vector<vector<Sales_data>>&files,
            const string&book)
    {
        vector<matches> out;
        for (auto it=files.cbegin();it!=files.cend();++it)
        {
            auto found=
        }
        equal_range()
    }
}


#endif //STANDARD_TEMPLATE_LIBRARIES__17_STDLIB_H
