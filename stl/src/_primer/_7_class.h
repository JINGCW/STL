#ifndef STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H
#define STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H

#include <iostream>
#include "_7_class.h"
#include "_16_template.h"

using namespace std;

template<typename T>
class std::hash;

class Sales_data
{
    friend class std::hash<Sales_data>;

    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend ostream &print(ostream &, Sales_data &);

    friend istream &read(istream &, Sales_data &);

//    friend Sales_data &combine(const Sales_data &);
public:
//    Sales_data() = default;
    Sales_data() : Sales_data("", 0, 0)
    {

    }

//    Sales_data(const string &s = "") : bookNo(s) {}
    explicit Sales_data(const string &s) : Sales_data(s, 0, 0)
    {

    }

//    Sales_data(const string &s, unsigned n, double p) :
//            bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const string &s, unsigned n, double p)
    {
        bookNo = s;
        units_sold = n;
        revenue = n * p;
    }//another way

//    explicit Sales_data(istream &);
    explicit Sales_data(istream &is) : Sales_data()
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
