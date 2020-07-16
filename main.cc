////#include <fstream>
////#include <iostream>
////#pragma once
////#pragma comment(lib, "_primer.dll")
//
#include <iostream>
#include <string>



////#include "stl/src/_primer/_7_class.h"
////#include "stl/src/_primer/_6_function.h"
////#include "stl/src/_primer/_8_IO.h"
////#include "stl/src/_primer/_9_sequential_container.h"
////#include "stl/src/_primer/_12_dy_mem.h"
////#include "stl/src/_primer/_17_stdlib.h"
////#include "stl/src/_primer/utils.h"
////#include "include/utils.h"
//
//
////__declspec(dllimport) class Math;
//
//using namespace std;
//
//
//int min_multiplier(int a, int b)
//{
//    int max = a > b ? a : b;
////    cout << "max and min value is :" << max << min << endl;
//    int min = a > b ? b : a;
//    int i = 1, out;
//    for (; i * max % min != 0; ++i);
//    out = max * i;
////    cout << "min_multiplier out is: " << out << endl;
//    return out;
//}
//
//
using namespace std;

//
////extern vector<vector<Sales_data>> _files;
////extern vector<Sales_data> _file;
////extern vector<vector<Sales_data>>* _files;
//
////void stores_sales_search()
////{
////    string file_path = "stores_sales_search.txt";
////    vector<vector<Sales_data>>* _files=_read_files_from_txt(file_path);
//////    _read_files_from_txt(file_path);
//////    using namespace stdlib;
//////    vector<vector<Sales_data>> files{
//////            {Sales_data("a", 1, 20.0), Sales_data("b", 2, 22.0)},
//////            {Sales_data("c", 1, 23.0), Sales_data("a", 4, 24.0)},
//////            {Sales_data("b", 5, 25.0), Sales_data("b", 6, 26.0)},
//////            {Sales_data("a", 1, 27.0), Sales_data("b", 2, 28.0)},
//////    };
////    cout << "input the store book you want to search...\n"
////            "-------------------------------" << endl;
////    if (_files->empty())
////        cout << "_files is empty" << endl;
////    else
////        cout << "_files is not empty" << endl;
////
//////    for (auto it=_files->cbegin();it!=_files->cend();++it)
//////    {
//////        for (auto iit = it->cbegin(); iit != it->cend(); ++iit)
//////            cout << "8888888"<<*iit << endl;
//////    }
////
//////    for (const auto &_file_:*_files)
//////    {
//////        cout << "?????????????" << endl;
//////
//////        cout << "%%%" << _file_[0] << "%%%" << endl;
//////
//////        for (const auto &e:_file_)
//////            cout << "+++" << e << "+++" << endl;
//////    }
////    cout << "---------------------------" << endl;
////    print_search_out(cin, cout, *_files);
////}
//
////void mini_text_query()
////{
////    ifstream file("test.txt");
////    TextQuery tq(file);
////    string input;
////    cout << "Welcome to Mini TextQuery Program!\n"
////         << "-------------------------------\n"
////         << "You can enter the word you want to search...."
////         << endl;
////    while (cin >> input)
////    {
////        if (input == "exit")
////            break;
////        print(cout, tq.query(input));
////    }
////}
//static const string game_over_head = "                                                        \n";
//static const string game_over1 = "    ■■■      ■      ■      ■■■■      ■■■■  \n";
//static const string game_over2 = "  ■      ■    ■      ■      ■            ■    ■  \n";
//static const string game_over3 = "  ■      ■      ■  ■        ■■■■      ■■■■  \n";
//static const string game_over4 = "  ■      ■      ■  ■        ■            ■■      \n";
//static const string game_over5 = "    ■■■          ■          ■■■■      ■  ■    \n";
//static const string game_over_tail = "                                                        ";
//
int main(int argc, char **argv)
{
//    stores_sales_search();
//    cout << "******************"<<
//    Math::add(3, 5) << endl;
//    mini_text_query();
//    stores_sales_search();
//    regex_match();
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
//    cout << game_over_head +
//            game_over1 +
//            game_over2 +
//            game_over3 +
//            game_over4 +
//            game_over5 +
//            game_over_tail
//         << endl;
//    int out = min_multiplier(1, 7);
//    static_assert(out==7,"yes");
    cout << "hello world" << endl;
    return 0;
}
