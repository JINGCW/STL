#include <iostream>
#include <vector>
#include <stdexcept>
#include <cerrno>
#include <cstdlib>
#include <string>
#include <cstdlib>

using namespace std;

int fact(int val) {
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

string::size_type find_char(const string &s, char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

void error_msg(initializer_list<string> il) {
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        /*initializer_list obj element is const value forever.*/
//        cout << *beg << " ";
        cout << endl;
    }
}

void error_msg(error_code e, initializer_list<string> il) {
    cout << e.message() << ": ";
    for (const auto &elem:il) {
        cout << elem << " ";
        cout << endl;
    }
}

/*varargs*/
void foo(initializer_list<string> il, ...);

void foo(...);

/*varargs*/
string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

char &getter(string &s, string::size_type idx) {
    return s[idx];
}

void getter_test() {
    string s("a value");
    cout << s << endl;
    getter(s, 0) = 'A';
    cout << s << endl;
}

/*return array pointer*/
typedef int arrT[10];
using arr_t=int[10];//equal above
arrT *func(int i);

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) *arr_ptr(int i){
    return (i % 2) ? &odd : &even;//return ptr point to array
}

inline const string &short_string(const string &s1, const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}

inline string &short_string(string &s1,string& s2){
    auto &r = short_string(const_cast<const string &>(s1),
                           const_cast<const string &>(s2));
    return const_cast<string &>(r);
}

void print(const int ia[],size_t size){
#ifndef NDEBUG/*if NDEBUG not define, execute code block between #ifndef and #endif*/
    /*__func__ is compiler defined local static var, store function name*/
    cerr << __func__ << ": array size is " << size
         << ":" << __FILE__ << ":" << __LINE__ << ":" << __TIME__ << ":" << __DATE__
         << endl;
#endif
}

//int main() {
////    cout << fact(5) << endl;
////    getter_test();
//    const int ia[] = {1, 2, 3};
//
//    print(ia,3);
////    EXIT_SUCCESS
//    return 0;
//}
