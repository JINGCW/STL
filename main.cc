#include <fstream>
#include <iostream>
#include "stl/src/_primer/_7_class.h"
#include "stl/src/_primer/_6_function.h"
#include "stl/src/_primer/_8_IO.h"
#include "stl/src/_primer/_9_sequential_container.h"
#include "stl/src/_primer/_12_dy_mem.h"

using namespace std;

void mini_text_query()
{
    ifstream file("test.txt");
    TextQuery tq(file);
    string input;
    cout << "Welcome to Mini TextQuery Program!\n"
         << "-------------------------------\n"
         << "You can enter the word you want to search...."
         << endl;
    while (cin >> input)
    {
        if (input == "exit")
            break;
        print(cout, tq.query(input));
    }
}

int main(int argc, char **argv)
{
    mini_text_query();
//    getter_test();
//    change_container();
//    vector<string> input = reinterpret_cast<const vector<basic_string<char>> &>(argv);
//for(const auto &e:static_cast<vector<string >>(argv))
//    string file_path;
//    while(argv>>file_path)

//    if (size(*++argv)!=0)
//    {
//    cout << static_cast<string>(*++argv) << endl;
//    const string file_path(static_cast<string>(argv[1]));
//    } else
//        file_path = "test.txt";

//    ifstream file("test.txt");
//    cout << file_path << endl;
//    ifstream file(file_path);
//    TextQuery tq(file);
//    string input;
//    cout << "Welcome to Mini TextQuery Program!\n"
//         << "-------------------------------\n"
//         << "You can enter the word you want to search...."
//         << endl;
//    while (cin >> input)
//    {
//        if (input == "exit")
//            break;
//        print(cout, tq.query(input));
//    }
//    save_person_info();
    return 0;
}
