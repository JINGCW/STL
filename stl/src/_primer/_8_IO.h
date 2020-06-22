#ifndef STANDARD_TEMPLATE_LIBRARIES__8_IO_H
#define STANDARD_TEMPLATE_LIBRARIES__8_IO_H

#include <iostream>
#include <vector>

using namespace std;

struct person_info{
    string name;
    vector<string> phones;
};

void save_person_info();

#endif //STANDARD_TEMPLATE_LIBRARIES__8_IO_H
