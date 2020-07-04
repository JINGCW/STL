#include <vector>
#include <functional>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include "_7_class.h"
#include <iterator>

using namespace std;

void _find()
{
    vector<int> vec = {1, 2, 34, 5};
    int val = 34;
    auto out = find(vec.cbegin(), vec.cend(), val);
    cout << (*out == 42) << endl;
}

void _equal()
{
    list<const char *> a = {"abcd\0", "jfaklfjalk"};
    vector<string> b = {"jfajfla", "fafa"};
    cout << equal(b.cbegin(), b.cend(), a.cbegin()) << endl;
}

void elim_dups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

bool is_shorter(const string &a, const string &b)
{
    return a.size() < b.size();
}

void _stable_sort(vector<string> &words)
{
    elim_dups(words);
//    stable_sort(words.begin(), words.end(), is_shorter);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    for (const auto &e:words)
        cout << e << " "
             << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    elim_dups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {
        return a.size() >= sz;
    });
    for_each(wc, words.end(),
             [&os, c](const string &s) { os << s << c; });
    os << endl;
}

//void func()
//{
//    size_t v1 = 42;
//    auto f = [v1]()mutable { return ++v1; };
//    v1 = 0;
//    cout << f() << endl;//43
//}
//
//void func2()
//{
//    size_t v1 = 42;
//    auto f = [&v1] { return ++v1; };
//    v1 = 0;
//    cout << f();//1
//}
//
//void func3(vector<int> &vi)
//{
//    transform(vi.begin(), vi.end(), vi.begin(),
//              [](int i) { return i < 0 ? -i : i; });
//    //
//    transform(vi.begin(), vi.end(), vi.begin(),
//              [](int i) -> int { if (i < 0)return -i; else return i; });
//}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void _find_if(vector<string> &words, string::size_type sz)
{
    auto check6 = bind(check_size, std::placeholders::_1, sz);
    auto wc = find_if(words.begin(), words.end(), check6);
    cout << *wc << endl;
}

//void stream_iterator_class_type()
//{
//    istream_iterator<Sales_data> item_iter(cin), eof;
//    ostream_iterator<Sales_data> out_iter(cout, "\n");
//    Sales_data sum = *item_iter++;
//    while (item_iter != eof)
//    {
//        if (item_iter->isbn() == sum.isbn())
//            sum += *item_iter++;
//        else
//        {
//            out_iter = sum;
//            sum = *item_iter++;
//        }
//    }
//    out_iter = sum;
////    out_iter =endl;
//}
