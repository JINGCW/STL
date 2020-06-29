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
    if (n >= min_qty)
        return n * (1 - discount) * price;

    return Quote::net_price(n);
}
