#ifndef STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H
#define STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H

#include <iostream>
#include "_7_class.h"
//#include "_16_template.h"

using namespace std;

//template<class T>class std::hash;
template<class T>class hash;
class Sales_data
{
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);

    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

    friend class std::hash<Sales_data>;

    friend ostream &operator<<(ostream &os, const Sales_data &item);

    friend istream &operator>>(istream &in, Sales_data &item);

    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend ostream &print(ostream &, Sales_data &);

    friend istream &read(istream &, Sales_data &);

//    friend Sales_data &combine(const Sales_data &);
public:
//    Sales_data() = default;
//    Sales_data &operator+(const Sales_data &);

    Sales_data &operator+=(const Sales_data &rhs);

    Sales_data &operator=(const Sales_data &rhs);

    //destructor
    virtual ~Sales_data() = default;

//    string &operator<<(const Sales_data &)const ;
//constructor
    Sales_data(const Sales_data &origin);
//    {
//        bookNo(origin.bookNo);
//        units_sold(origin.bookNo);
//        revenue(origin.revenue);
//    }

//    Sales_data() : Sales_data("", 0, 0)
//    {
//
//    }
    Sales_data() = default;

//    Sales_data(const string &s = "") : bookNo(s) {}
    Sales_data(const string &s) : Sales_data(s, 0, 0)
    {

    }
//    Sales_data(const string s):Sales_data(move(s),0,0)
//    {
//
//    }
//    explicit Sales_data(string s):Sales_data(static_cast<const string&>(move(s)),0,0)
//    {
//
//    }

//    Sales_data(const string &s, unsigned n, double p) :
//            bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const string &s, unsigned n, double p)
    {
        bookNo = s;
        units_sold = n;
        revenue = n * p;
    }//another way

//    explicit Sales_data(istream &);
    Sales_data(istream &is) //: Sales_data()
    {
        read(is, *this);
    }

    string isbn() const;

    Sales_data &combine(const Sales_data &rhs);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

//public:

    double avg_price() const;
};

class Window_mgr;

Sales_data add(const Sales_data &, const Sales_data &);

ostream &print(ostream &, Sales_data &);

istream &read(istream &, Sales_data &);

Sales_data &combine(const Sales_data &);

#endif //STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H
