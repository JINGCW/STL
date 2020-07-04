#include "_12_dy_mem.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

static shared_ptr<int> p3 = make_shared<int>(42);
static shared_ptr<string> p4 = make_shared<string>(10, '9');
static shared_ptr<int> p5 = make_shared<int>();
auto p6 = make_shared<vector<string >>();

StrBlob::StrBlob() :
        data(make_shared<vector<string>>())
{
}

StrBlob::StrBlob(initializer_list<string> il) :
        data(make_shared<vector<string >>(il))
{
}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "popback on empty StrBlob");
    return data->pop_back();
}

//weak_ptr
void func()
{
    auto p = make_shared<int>(2);
    weak_ptr<int> wp(p);
    wp.use_count();
    if (shared_ptr<int> np = wp.lock())
    {

    }
}

shared_ptr<vector<string >> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbounded StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];//(*p) is the vector pointed to.
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobptr");
    ++curr;
    return *this;
}

void copy_fill_uninitialized_mem(const vector<int> &vi)
{
    allocator<vector<int>> alloc;
    auto p = alloc.allocate(vi.size() * 2);
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    uninitialized_fill_n(q, vi.size(), 42);
}

TextQuery::TextQuery(ifstream &fd) : file(new vector<string>)
{
    string text;
    while (getline(fd, text))
    {
//        cout << "**" << text << "**" << endl;
        cout << text  << endl;
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
//            cout << "**" << word << "**" << endl;
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
//        cout << "-----" << endl;
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no >> not_found(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, not_found, file);
    return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << endl;
    for (const auto &num:*qr.lines)
    {
//        os << num << endl;
        os << "\t (line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}
