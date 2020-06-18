#ifndef STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H
#define STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H

#include <iostream>

using namespace std;

class Sales_data;

class Window_mgr;

Sales_data add(const Sales_data &, const Sales_data &);

ostream &print(ostream &, Sales_data &);

istream &read(istream &, Sales_data &);

Sales_data &combine(const Sales_data &);

#endif //STANDARD_TEMPLATE_LIBRARIES__7_CLASS_H
