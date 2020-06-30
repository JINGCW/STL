#include "_15_oop.h"

double print_total(ostream &os, const Quote &item, size_t n)
{
    double out = item.net_price(n);
    os << "isbn: " << item.isbn()
       << " sold: " << n << " total due: " << out << endl;
    return out;
}

double Bulk_quote::net_price(size_t n) const
{
//    if (n >= 3)
//        return n * (1 - discount) *;
//
//    return ::Disc_quote::net_price(n);
    return 0.0;
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;

    for (auto iter = items.cbegin();
         iter != items.cend();
         iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "total sales " << sum << endl;
    return sum;
}

Bulk_quote *Bulk_quote::clone() &&
{
    return new Bulk_quote(std::move(*this));
}

ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

inline Query::Query(const string &s) : q(new Word_query(s))
{}

inline Query operator~(const Query &operand)
{
    return Query(shared_ptr<Query_base>(new Not_query(operand)));
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return Query(shared_ptr<Query_base>(new And_query(lhs, rhs)));
}
