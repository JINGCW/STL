#ifndef STANDARD_TEMPLATE_LIBRARIES__17_STDLIB_H
#define STANDARD_TEMPLATE_LIBRARIES__17_STDLIB_H

#include <tuple>
#include <string>
#include <vector>
#include <list>
#include <iostream>
//#include <iterator>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <type_traits>
#include <sstream>
#include <memory>
#include <regex>
#include <random>

#include "_7_class.h"

#define _stdlib_begin namespace stdlib{
#define _stdlib_end }

#define _bitset_begin namespace _bitset_begin{
#define _bitset_end }


using namespace std;


//_stdlib_begin
////    using namespace Sales_data;
//    static tuple<size_t, size_t, size_t> three_d;//all 0
//    static tuple<string, vector<double>, int, list<int>>
//            some_value{"constants", {1.3, 3.45}, 4, {0, 1, 2}};
////
//    auto item = make_tuple("0993", 3, 20.00);
////    auto book = get<0>(item);
//    auto cnt = get<1>(item);
//    auto price = get<2>(item) / cnt;
////    get<2>(item) *=0.8;
//    using trans=decltype(item);
//    tuple_element<1, trans>::type cnt2 = get<1>(item);
//
////
//_stdlib_end

using matches=
tuple<
        vector<Sales_data>::size_type,
        vector<Sales_data>::const_iterator,
        vector<Sales_data>::const_iterator
>;

vector<matches> find_book(const vector<vector<Sales_data>> &files,
                          const string &book);

void print_search_out(istream &in, ostream &os, const vector<vector<Sales_data>> &files);

//_stdlib_begin
//_bitset_begin
//    bitset<32> bitvec(1U);
//    bitset<128> bitvec3(~0ULL);
//_bitset_end

//_stdlib_end
//void _read_files_from_txt(const string &path);
vector<vector<Sales_data>> *_read_files_from_txt(const string &path);

//static auto _files=make_shared<vector<vector<Sales_data>>>();
//static auto _files=new(vector<vector<Sales_data>>);
//vector<vector<Sales_data>>*_files;
static auto _files = new(vector<vector<Sales_data>>);

void regex_match(const string &text= "receipt freind theif receive");

#endif //STANDARD_TEMPLATE_LIBRARIES__17_STDLIB_H
