#ifndef STANDARD_TEMPLATE_LIBRARIES__12_DY_MEM_H
#define STANDARD_TEMPLATE_LIBRARIES__12_DY_MEM_H

#include <utility>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
    friend class StrBlobPtr;

//    StrBlobPtr begin(){ return StrBlobPtr(*this); }
//    StrBlobPtr end(){
//        auto out = StrBlobPtr(*this, data->size());
//        return out;
//    }

    using size_type=vector<string>::size_type;

    StrBlob();

    StrBlob(initializer_list<string> il);

    size_type size() const
    { return data->size(); }

    bool empty() const
    { return data->empty(); }

    void push_back(const string &t)
    { data->push_back(t); }

    void pop_back();

    string &front();

    string &back();

private:
    shared_ptr<vector<string >> data;

    void check(size_type i, const string &msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0)
    {}

    StrBlobPtr(StrBlob &a, size_t sz) :
            wptr(a.data), curr(sz)
    {};

    string &deref() const;

    StrBlobPtr &incr();

private:
    shared_ptr<vector<string >> check(size_t, const string &) const;

    weak_ptr<vector<string >> wptr;
    size_t curr;
};

class QueryResult;

class TextQuery
{
//    friend class QueryResult;
public:
    using line_no=vector<string>::size_type;

    TextQuery(ifstream &);

    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string >> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

ostream &print(ostream &os, const QueryResult &qr);

class QueryResult
{
    using line_no=TextQuery::line_no;

    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s, shared_ptr<set<line_no >> p, shared_ptr<vector<string >> f) :
            sought(s), lines(p), file(f)
    {}

private:
    string sought;
    shared_ptr<set<line_no >> lines;//line number
    shared_ptr<vector<string >> file;//input text file
};

#endif //STANDARD_TEMPLATE_LIBRARIES__12_DY_MEM_H
