#include <iostream>
#include <string>
#include <vector>
#include <cstdbool>
//#include <istream>

#include "_7_class.h"

using namespace std;

Sales_data::Sales_data(const Sales_data &origin) :
        bookNo(origin.bookNo), units_sold(origin.units_sold), revenue(origin.revenue)
{
//    bookNo(origin.bookNo);
//    units_sold(origin.units_sold);
//    revenue(origin.revenue);
//    return *this;
}


Sales_data &Sales_data::operator=(const Sales_data &rhs)
//= default;
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
//    return combine(rhs);
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << "*** book isbn: " << item.isbn() << " -"
       << " units_sold " << item.units_sold << " -"
       << " revenue " << item.revenue << " -"
       << " avg_price " << item.avg_price() << " ***";
    return os;
}

istream &operator>>(istream &in, Sales_data &item)
{
    double price;
    in >> item.bookNo >> item.units_sold >> price;
    if (in)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return in;
}


string Sales_data::isbn() const
{ return this->bookNo; }

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    cout << "***" << item.bookNo << " " <<
         item.units_sold << " " << item.revenue <<
         "+++" << endl;

    return is;
}

//Sales_data::Sales_data(istream &is) {
//    read(is, *this);
//}

ostream &print(ostream &os, Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
//       << endl;
    return os;
}


Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data out = lhs;//copy lhs's data to sum.
    out.combine(rhs);
    return out;
}

class Window_mgr;

class Screen
{
public:
    friend Window_mgr;
//    friend void Window_mgr::clear(screen_idx);//must be declare before class Screen.
    using pos=string::size_type;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c)
    {}

    char get() const
    { return contents[cursor]; }//implicit inline
    inline char get(pos ht, pos wd) const;//explicit inline
    Screen &move(pos r, pos c);//can be set inline later
    void some_member() const;

    Screen &set(char);

    Screen &set(pos, pos, char);

    //overload display function according obj is const or not.
    /* ex:Screen s1(5,3)
     * const Screen s2(5,3)
     * s1.set('#').display(cout)//call no const version
     * s2.display(cout)//call const version
     * */
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;

    void do_display(ostream &os) const
    { os << contents; }
};

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

void Screen::some_member() const
{
    ++access_ctr;
}

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = width * r;
    cursor = row + c;
    return *this;
}

char Screen::get(pos ht, pos wd) const
{
    pos row = width * ht;
    return contents[row + wd];
}

class Window_mgr
{
public:
    using screen_idx=vector<Screen>::size_type;

    void clear(screen_idx);

    screen_idx add_screen(const Screen &);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(screen_idx i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr::screen_idx Window_mgr::add_screen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

//constexpr constructor
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b)
    {}

    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o)
    {}

    constexpr bool any()
    { return hw || io || other; }

    void set_hw(bool b)
    { hw = b; }

    void set_other(bool b)
    { other = b; }

    void set_io(bool b)
    { io = b; }

private:
    bool hw;
    bool io;
    bool other;
};

//class Account
//{
//public:
//    void calculate()
//    { amount = amount * interest_rate; }
//
//    static double rate()
//    { return interest_rate; }
//
//    static void rate(double);
//
//private:
//    string owner;
//    double amount;
//
//    static double interest_rate;
//
//    static double init_rate();
//
//    static constexpr int period = 30;//inner initialize.
//    double daily_tbl[period];
//};

//void Account::rate(double new_rate)
//{
//    interest_rate = new_rate;
//}

//define and init static member
//double Account::interest_rate = init_rate();
//constexpr int Account::period;//define

#ifdef RUN_MAIN
int main() {
    return 0;
}
#endif
