#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend ostream &print(ostream &, Sales_data &);

    friend istream &read(istream &, Sales_data &);

//    friend Sales_data &combine(const Sales_data &);
public:
    Sales_data() = default;

    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(const string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(istream &);

    string isbn() const;

    Sales_data &combine(const Sales_data &rhs);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

//public:

    double avg_price() const;
};

string Sales_data::isbn() const { return this->bookNo; }

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

Sales_data::Sales_data(istream &is) {
    read(is, *this);
}

ostream &print(ostream &os, Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
//       << endl;
    return os;
}


Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data out = lhs;//copy lhs's data to sum.
    out.combine(rhs);
    return out;
}

class Window_mgr;

class Screen {
public:
    friend Window_mgr;
//    friend void Window_mgr::clear(screen_idx);//must be declare before class Screen.
    using pos=string::size_type;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }//implicit inline
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
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;

    void do_display(ostream &os) const { os << contents; }
};

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

void Screen::some_member() const {
    ++access_ctr;
}

inline
Screen &Screen::move(pos r, pos c) {
    pos row = width * r;
    cursor = row + c;
    return *this;
}

char Screen::get(pos ht, pos wd) const {
    pos row = width * ht;
    return contents[row + wd];
}

class Window_mgr {
public:
    using screen_idx=vector<Screen>::size_type;

    void clear(screen_idx);

    screen_idx add_screen(const Screen &);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(screen_idx i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr::screen_idx Window_mgr::add_screen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

int main() {
    return 0;
}
