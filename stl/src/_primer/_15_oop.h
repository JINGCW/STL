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
    virtual double net_price(size_t) const override;
};

#endif //STANDARD_TEMPLATE_LIBRARIES__15_OOP_H
