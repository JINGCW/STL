#include <fstream>
//#include <iostream>

#include "stl/src/_primer/_7_class.h"
#include "stl/src/_primer/_6_function.h"
#include "stl/src/_primer/_8_IO.h"
#include "stl/src/_primer/_9_sequential_container.h"
#include "stl/src/_primer/_12_dy_mem.h"
#include "stl/src/_primer/_17_stdlib.h"

//using namespace std;

//extern vector<vector<Sales_data>> _files;
//extern vector<Sales_data> _file;
//extern vector<vector<Sales_data>>* _files;

void stores_sales_search()
{
    string file_path = "stores_sales_search.txt";
    vector<vector<Sales_data>>* _files=_read_files_from_txt(file_path);
//    _read_files_from_txt(file_path);
//    using namespace stdlib;
//    vector<vector<Sales_data>> files{
//            {Sales_data("a", 1, 20.0), Sales_data("b", 2, 22.0)},
//            {Sales_data("c", 1, 23.0), Sales_data("a", 4, 24.0)},
//            {Sales_data("b", 5, 25.0), Sales_data("b", 6, 26.0)},
//            {Sales_data("a", 1, 27.0), Sales_data("b", 2, 28.0)},
//    };
    cout << "input the store book you want to search...\n"
            "-------------------------------" << endl;
    if (_files->empty())
        cout << "_files is empty" << endl;
    else
        cout << "_files is not empty" << endl;

//    for (auto it=_files->cbegin();it!=_files->cend();++it)
//    {
//        for (auto iit = it->cbegin(); iit != it->cend(); ++iit)
//            cout << "8888888"<<*iit << endl;
//    }

//    for (const auto &_file_:*_files)
//    {
//        cout << "?????????????" << endl;
//
//        cout << "%%%" << _file_[0] << "%%%" << endl;
//
//        for (const auto &e:_file_)
//            cout << "+++" << e << "+++" << endl;
//    }
    cout << "---------------------------" << endl;
    print_search_out(cin, cout, *_files);
}

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
//    mini_text_query();
    stores_sales_search();
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
