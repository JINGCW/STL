#include <fstream>
#include <iostream>
#include "stl/src/_primer/_7_class.h"
#include "stl/src/_primer/_6_function.h"
#include "stl/src/_primer/_8_IO.h"
#include "stl/src/_primer/_9_sequential_container.h"
#include "stl/src/_primer/_12_dy_mem.h"

using namespace std;

int main(int argc, char *argv[])
{
//    getter_test();
//    change_container();
//    vector<string> input = reinterpret_cast<const vector<basic_string<char>> &>(argv);
    ifstream file("test.txt");
    TextQuery tq(file);
    string input;
    while (cin >> input)
        print(cout, tq.query(input));
//    save_person_info();
    return 0;
}
