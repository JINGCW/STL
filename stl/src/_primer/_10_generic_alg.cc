#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void _find()
{
    vector<int> vec = {1, 2, 34, 5};
    int val = 34;
    auto out = find(vec.cbegin(), vec.cend(), val);
    cout << (*out == 42) << endl;
}

void _equal()
{
    list<const char *> a = {"abcd\0", "jfaklfjalk"};
    vector<string> b = {"jfajfla", "fafa"};
    cout << equal(b.cbegin(), b.cend(), a.cbegin()) << endl;
}

void elim_dups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    words.erase(unique_end, words.end());
}

bool is_shorter(const string &a, const string &b)
{
    return a.size() < b.size();
}

void _stable_sort(vector<string> &words)
{
    elim_dups(words);
//    stable_sort(words.begin(), words.end(), is_shorter);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    for (const auto &e:words)
        cout << e << " "
             << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elim_dups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {
        return a.size() >= sz;
    });
    for_each(wc, words.end(),
             [](const string &s) { cout << s << " "; });
    cout << endl;
}
