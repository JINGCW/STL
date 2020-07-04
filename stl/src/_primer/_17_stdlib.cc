//#include <string>

#include "_17_stdlib.h"

//using namespace std;

//static auto _files=new(vector<vector<Sales_data>>);
//template<typename T>
bool valid(const smatch &t)
{
    if (t[1].matched)
        return t[3].matched && (t[4].matched == 0 || t[4].str() == " ");
    return !t[3].matched && t[4].str() == t[6].str();
}

void regex_match(const string &text)
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch out;

    if (regex_search(text, out, r))
        cout << out.str() << "\n-----------------" << endl;

//    regex r2("[[:alnum:]]+\\.(cpp|cc|cxx)$", regex::icase);
    regex r2("([[:alnum:]]+)\\.(cpp|cc|cxx)$", regex::icase);
    cmatch out2;
    if (regex_search("myfile.cc", out2, r2))
        cout << out2.str() << "\n-----------------" << endl;


    for (sregex_iterator it(text.begin(), text.end(), r), end_it;
         it != end_it; ++it)
    {
        auto pos = it->prefix().length();
        cout << "length of prefix is :" << pos << endl;
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos)
             << "\n\t\t>>> " << it->str() << " <<<\n"
             << it->suffix().str().substr(0, 40)
             << endl;
//        cout << it->str() << "\n-----------------" << endl;
        cout << "input phone number you want to searching ..." << endl;

        string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        regex r_phone(phone);
        smatch m_phone;
        string s_phone;
        //replace
        string fmt = "$2.$5.$7";//ddd.ddd.dddd
        string ex_phone_number = "(908) 555-1800";
        cout << regex_replace(ex_phone_number, r_phone, fmt) << endl;
        //replace
        while (getline(cin, s_phone))
        {
            for (sregex_iterator it(s_phone.begin(), s_phone.end(), r_phone), end_it;
                 it != end_it; ++it)
                if (valid(*it))
                    cout << "phone matching :" << it->str() << endl;
        }
    }
}


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

            _file->push_back(Sales_data(isbn, number, price));
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
