//#include <string>

#include "_17_stdlib.h"

//using namespace std;

//static auto _files=new(vector<vector<Sales_data>>);


vector<vector<Sales_data>> *_read_files_from_txt(const string &path)
{
//    vector<vector<Sales_data>> files;
//    vector<Sales_data> file;
    string line;
    ifstream fd(path);
//    delete _files;

    while (getline(fd, line))
    {
        cout << "++++" << line << "++++" << endl;

        auto _file = make_shared<vector<Sales_data>>();
        istringstream line_stream(line);
        string isbn;
        unsigned number;
        double price;

        while (line_stream >> isbn && line_stream >> number && line_stream >> price)
        {
//            cout << "***" << isbn << " " << number << " " << price << "***" << endl;
//            _file->push_back(Sales_data(line_stream));
//            auto item = Sales_data(isbn, number, price);

//            cout << "///////////////////" << item << endl;

            _file->push_back(Sales_data(isbn,number,price));
//            for (const auto &e:*_file)
//            {
//                cout << "&&&&&&&&&&&&&&&&&" << e << endl;
//            }
        }
        _files->push_back(*_file);
//        if (_files->empty())
//            cout << "_files is empty";
//        else
//            cout << "_files is not empty";
//        cout << endl;
//        for (auto it = _files->cbegin(); it != _files->cend(); ++it)
//        {
//            for (auto iit = it->cbegin(); iit != it->cend(); ++iit)
//                cout << "8888888" << *iit << endl;
//        }
    }
//    for (const auto &_file_:*_files)
//    {
//        cout << "?????????????" << endl;
//
////        cout << "%%%" << _file_[0] << "%%%" << endl;
//
//        for (const auto &e:_file_)
//            cout << "+++" << e << "+++" << endl;
//    }
    return _files;
//    return files;
}

bool less_sales_data(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

vector<matches> find_book(const vector<vector<Sales_data>> &files,
                          const string &isbn)
{
    vector<matches> out;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(), isbn, less_sales_data);
        if (found.first != found.second)
        {
            out.emplace_back(it - files.cbegin(), found.first, found.second);
        }
    }

    return out;
}

void print_search_out(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
    string search;
    while (cin >> search)
    {
        cout << "your input search value is : " << search << endl;

        auto found = find_book(files, search);
        if (found.empty())
        {
            cout << search << " not found in any stores" << endl;
            continue;
        }
        for (const auto &e:found)
            os << "store " << get<0>(e) << " sales: " //<< endl;
               << accumulate(get<1>(e), get<2>(e), Sales_data(search)) << endl;
    }
}
