#include <iostream>
#include "_8_IO.h"

using namespace std;

void manage_io_state(istream &is) {
    is.setstate(is.rdstate() & ~is.failbit & ~is.badbit);
//    cin.tie(nullptr);
}

void save_person_info(istream)