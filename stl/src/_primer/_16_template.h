//#ifndef STANDARD_TEMPLATE_LIBRARIES__16_TEMPLATE_H
//#define STANDARD_TEMPLATE_LIBRARIES__16_TEMPLATE_H
//
//#include <vector>
//#include <string>
//#include <memory>
//#include <iostream>
//#include <type_traits>
//#include <utility>
//
//#include "_7_class.h"
//
//
//using namespace std;
////extern class Sales_data;
//
//template<typename T>
//int compare(const T &left, const T &right)
//{
////    if (left == right)return 0;
////    if (left < right)return -1;
//    if (less<T>()(left, right))return 1;
//    if (less<T>()(right, left))return -1
//    return 0;
//}
//
//template<typename T, typename F=less<T>>
//int compare(const T &left, const T &right, F f = F())
//{
//    if (f(left, right))return 1;
//    if (f(right, left))return -1
//    return 0;
//}
//
//template<typename>
//class Blob;
//
//template<typename T>
//bool operator==(const Blob<T> &, const Blob<T> &);
//
//
//template<typename T>
//class Blob
//{
//    friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
//
//public:
//    using value_type=T;
//    using size_type=typename vector<T>::size_type;
//
//    Blob() : data(make_shared<vector<T>>())
//    {
//
//    }
//
//    Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il))
//    {
//
//    }
//
//    size_type size() const
//    { return data->size(); }
//
//    bool empty() const
//    { return data->empty(); }
//
//    void push_back(const T &t)
//    { data->push_back(t); }
//
//    void push_back(T &&t)
//    { data->push_back(std::move(t)); }
//
//    void pop_back();
//
//    T &back();
//
//    T &operator[](size_type);
//
//private:
//    shared_ptr<vector<T>> data;
//
//    void check(size_type i, const string &msg) const;
//};
//
//class
//Debug_delete
//{
//public:
//    Debug_delete(ostream &s = cerr) : os(s)
//    {}
//
//    template<typename T>
//    void operator()(T *p)
//    {
//        os << "deleting unique_ptr" << endl;
//        delete p;
//    }
//
//private:
//    ostream &os;
//};
//
//template<typename It>
////auto fcn(It beg, It end) -> remove_reference_t<decltype(*beg)>
//auto fcn(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
//{
//
//    return *beg;
//}
//
//template<typename T>
//ostream &print(ostream &os, const T &t)
//{
//    return os << t;
//}
//
//template<typename T, typename ...Args>
//ostream &print(ostream &os, const T &t, const Args &...rest)
//{
//    os << t << ", ";
//    print(os, rest...);
//}
//
//namespace std
//{
//    template<>
//    struct hash<Sales_data>
//    {
//        using result_type=size_t;
//        using argument_type=Sales_data;
//
//        size_t operator()(const Sales_data &s) const;
//    };
//
//    size_t hash<Sales_data>::operator()(const Sales_data &s) const
//    {
//        return hash<string>()(s.bookNo) ^
//               hash<unsigned>()(s.units_sold) ^
//               hash<double>()(s.revenue);
//    }
//}
//
//
//#endif //STANDARD_TEMPLATE_LIBRARIES__16_TEMPLATE_H
