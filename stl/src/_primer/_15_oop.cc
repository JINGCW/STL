#include "_15_oop.h"

double print_total(ostream &os, const Quote &item, size_t n)
{
    double out = item.net_price(n);
    os << "isbn: " << item.isbn()
       << " sold: " << n << " total due: " << out << endl;
    return out;
}
