#include "_14_operator.h"
#include <map>
#include <iostream>
#include <string>
#include <functional>

using namespace std;

struct abs
{
    int operator()(int val) const
    {
        return val < 0 ? -val : val;
    }
};

class
_Print_string
{
public:
    _Print_string(ostream &os = cout, char c = ' ') :
            os(os), sep(c)
    {}

    void operator()(const string &s)
    { os << s << sep; }

private:
    ostream &os;
    char sep;
};

int add(int a, int b)
{ return a + b; }

static map<string, function<int(int, int)>> binops = {
        {"+", add},

};

class
_Small_int
{
public:
    _Small_int(int i = 0) : val(i)
    {
        if (i < 0 || i > 255)
            throw out_of_range("bad small int value");
    }

private:
    size_t val;
};
