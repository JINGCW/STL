////#include <fstream>
////#include <iostream>
////#pragma once
////#pragma comment(lib, "_primer.dll")
//
//#include <iostream>
//#include <string>
//
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
//using namespace std;
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
//int main(int argc, char **argv)
//{
////    stores_sales_search();
////    cout << "******************"<<
////    Math::add(3, 5) << endl;
////    mini_text_query();
////    stores_sales_search();
////    regex_match();
////    getter_test();
////    change_container();
////    vector<string> input = reinterpret_cast<const vector<basic_string<char>> &>(argv);
////for(const auto &e:static_cast<vector<string >>(argv))
////    string file_path;
////    while(argv>>file_path)
//
////    if (size(*++argv)!=0)
////    {
////    cout << static_cast<string>(*++argv) << endl;
////    const string file_path(static_cast<string>(argv[1]));
////    } else
////        file_path = "test.txt";
//
////    ifstream file("test.txt");
////    cout << file_path << endl;
////    ifstream file(file_path);
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
////    save_person_info();
////    cout << game_over_head +
////            game_over1 +
////            game_over2 +
////            game_over3 +
////            game_over4 +
////            game_over5 +
////            game_over_tail
////         << endl;
//    int out = min_multiplier(1, 7);
////    static_assert(out==7,"yes");
//    cout << "hello world" << endl;
//    return 0;
//}

//#include<iomanip>//setprecision
#include<iostream>
#include<string>
//#include<iterator>
//#include <utility>
#include <vector>
//#include <set>
//#include <memory>
//#include <algorithm>
//#include <stack>
#include <map>
//#include <numeric>
//#include <regex>
#include <math.h>

using namespace std;

//static map<string, int> _map;

int n_m_steps(int n, int m)
{
    if (n == 0 | m == 0)
        return 1;

    return n_m_steps(n - 1, m) + n_m_steps(n, m - 1);
}

int main(int argc, char **argv)
{
    string
    string manaStr = "$#";
    for (int i = 0; i < s.size(); i++) //首先构造出新的字符串
    {
        manaStr += s[i];
        manaStr += '#';
    }
    vector<int> rd(manaStr.size(), 0);//用一个辅助数组来记录最大的回文串长度，注意这里记录的是新串的长度，原串的长度要减去1
    int pos = 0, mx = 0;
    int start = 0, maxLen = 0;
    for (int i = 1; i < manaStr.size(); i++)
    {
        rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
        while (i + rd[i] < manaStr.size() && i - rd[i] > 0 &&
               manaStr[i + rd[i]] == manaStr[i - rd[i]])//这里要注意数组越界的判断，源代码没有注意，release下没有报错
            rd[i]++;
        if (i + rd[i] > mx) //如果新计算的最右侧端点大于mx,则更新pos和mx
        {
            pos = i;
            mx = i + rd[i];
        }
        if (rd[i] - 1 > maxLen)
        {
            start = (i - rd[i]) / 2;
            maxLen = rd[i] - 1;
        }
    }
}
