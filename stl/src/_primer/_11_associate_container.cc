#include "_11_associate_container.h"
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include "_7_class.h"
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void _words_count()
{
    map<string, size_t> words_count;
    string word;
    while (cin >> word)
    {
        ++words_count[word];
    }
    for (const auto &e:words_count)
        cout << e.first << " occurs" << e.second
             << ((e.second > 1) ? " times" : " time");
    cout << endl;

    //set
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    string s;
    while (cin >> s)
    {
        if (exclude.find(s) == exclude.end())
            ++words_count[s];
    }
    for (const auto &e:words_count)
        cout << e.first << " occurs" << e.second
             << ((e.second > 1) ? " times" : " time");
    cout << endl;

    //key-value value initialization.
    map<string, string> authors = {
            {"Joyce",  "James"},
            {"Austen", "Jane"},
    };

    //pair
    auto map_it = words_count.begin();
    //*map_it is a ref point to pair<const string,size_t> obj
    cout << map_it->first;
    cout << " " << map_it->second;
    ++map_it->second;//can change elem //(value).
}

//bool compare_isbn(const Sales_data&lhs,const Sales_data&rhs)
//{
//    return lhs.isbn() < rhs.isbn();
//}

const string &_transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    return s;
}

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = build_map(map_file);
    string text;

    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool first_word = true;

        while (stream >> word)
        {
            if (first_word)
                first_word = false;
            else
                cout << " ";
            cout << _transform(word, trans_map);
        }
        cout << endl;
    }
}

size_t hasher(const Sales_data &sd)
{
//    return hash<string>()(sd.isbn());
    return 0;
}

bool eqOp(const Sales_data&lhs,const Sales_data&rhs)
{
//    return lhs.isbn() == rhs.isbn();
    return true;
}

using SD_multiset=unordered_multimap<Sales_data, decltype(hasher) *, decltype(eqOp) *>;

//SD_multiset book_store(42, hasher, eqOp);
