#ifndef STANDARD_TEMPLATE_LIBRARIES__15_OOP_H
#define STANDARD_TEMPLATE_LIBRARIES__15_OOP_H

#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Quote
{
public:
    Quote() = default;

    Quote(string s, double sales_price) :
            book_no(std::move(s)), price(sales_price)
    {}

    string isbn() const
    { return book_no; }

    virtual double net_price(size_t n) const
    {
        return n * price;
    }

    virtual ~Quote() = default;

private:
    string book_no;

protected:
    double price = 0.0;
};

class
Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;

    Bulk_quote(const string &s, double p, size_t qty, double disc) :
            Quote(s, p), min_qty(qty), discount(disc)
    {};

    double net_price(size_t) const override;//virtual limit is not a must.

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif //STANDARD_TEMPLATE_LIBRARIES__15_OOP_H
