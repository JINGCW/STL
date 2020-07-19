#ifndef STANDARD_TEMPLATE_LIBRARIES__18_HUGE_PROG_H
#define STANDARD_TEMPLATE_LIBRARIES__18_HUGE_PROG_H

#include <vector>
#include <memory>
//#include <exception>
//#include <stdexcept>
#include <iostream>
#include <new>
//#include <utility>
//#include <bits/shared_ptr.h>

using namespace std;

template<typename T>
class _Exception
{
public:
    _Exception(initializer_list<T>);

private:
    shared_ptr<vector<T>> data;
};

namespace hug_prog
{
    class Base
    {
    public:
        friend bool operator==(const Base &, const Base &);

        virtual double f1(double) noexcept;

        virtual int f2() noexcept(false);

        virtual void f3();

    protected:
        virtual bool equal(const Base &) const;
    };

    class Derived : public Base
    {
        virtual double f1(double) noexcept override;

        virtual int f2() noexcept(false);

        virtual void f3() noexcept;

    protected:
        virtual bool equal(const Base &) const;
    };

    class out_of_stock : public runtime_error
    {
    public:
        explicit out_of_stock(const string &s) :
                runtime_error(s)
        {}
    };

    class isbn_mismatch : public logic_error
    {
    public:
        explicit isbn_mismatch(const string &s) :
                logic_error(s)
        {}

        isbn_mismatch(const string &s, const string &lhs, const string &rhs) :
                logic_error(s), left(lhs), right(rhs)
        {}

        const string left, right;
    };

    namespace NS{
        class Quote{};

        void display(const Quote &);

    }
    class Bulk_item: public NS::Quote{};
    void fake_main(){
        Bulk_item item;
        display(item);
    }
}


#endif //STANDARD_TEMPLATE_LIBRARIES__18_HUGE_PROG_H
