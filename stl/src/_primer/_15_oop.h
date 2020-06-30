#ifndef STANDARD_TEMPLATE_LIBRARIES__15_OOP_H
#define STANDARD_TEMPLATE_LIBRARIES__15_OOP_H

#include <string>
#include <iostream>
#include <utility>
#include <memory>
#include <set>
#include "_12_dy_mem.h"


using namespace std;

class Quote
{
public:
    Quote() = default;

    Quote(string s, double sales_price) :
            book_no(std::move(s)), price(sales_price)
    {}

    Quote(const Quote &) = default;

    Quote(Quote &&) = default;

    string isbn() const
    { return book_no; }

    virtual double net_price(size_t n) const
    {
        return n * price;
    }

    virtual Quote *clone() const &
    { return new Quote(*this); }

    virtual Quote *clone() &&
    { return new Quote(std::move(*this)); }

    virtual ~Quote() = default;

private:
    string book_no;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;

    Disc_quote(const string &book, double price, size_t qty, double disc) :
            Quote(book, price), quantity(qty), discount(disc)
    {}

    double net_price(size_t) const override = 0;

protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class
Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;

    Bulk_quote(const string &book, double price, size_t qty, double disc) :
            Disc_quote(book, price, qty, disc)
    {}

    Bulk_quote(const Bulk_quote &) = default;

    Bulk_quote(Bulk_quote &&) = default;

    Bulk_quote *clone() const & override
    { return new Bulk_quote(*this); }

    Bulk_quote *clone() && override;
//    { return new Bulk_quote(std::move(*this)); }

    double net_price(size_t) const override;
};

//class
//Bulk_quote : public Quote
//{
//public:
//    Bulk_quote() = default;
//
//    Bulk_quote(const string &s, double p, size_t qty, double disc) :
//            Quote(s, p), min_qty(qty), discount(disc)
//    {};
//
//    double net_price(size_t) const override;//virtual limit is not a must.
//
//private:
//    size_t min_qty = 0;
//    double discount = 0.0;
//};

class Base
{
public:
    Base() = default;

    Base &operator=(const Base &);
};

class D : public Base
{
public:
    D() = default;

    D(const D &d) : Base(d)
    {}

    D(D &&d) : Base(std::move(d))
    {}

    D &operator=(const D &rhs)
    {
        Base::operator=(rhs);
        return *this;
    }

    ~D()
    {

    }
};

class Basket
{
public:
    void add_item(const shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }

    void add_item(const Quote &sale)//copy
    {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }

    void add_item(Quote &&sale)//move
    {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }

    double total_receipt(ostream &os) const;

private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }

    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
};

class Query;

class
Query_base
{
    friend Query;
protected:
    using line_no=TextQuery::line_no;

    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;

    virtual string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);

    friend Query operator|(const Query &, const Query &);

    friend Query operator&(const Query &, const Query &);

public:
    explicit Query(const string &);

    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }

    string rep() const
    {
        return q->rep();
    }

private:
    explicit Query(shared_ptr<Query_base> query) : q(std::move(query))
    {}

    shared_ptr<Query_base> q;
};


class
Word_query : public Query_base
{
    friend class Query;

    explicit Word_query(const string &s) :
            query_word(s)
    {}

    QueryResult eval(const TextQuery &t) const override
    {
        return t.query(query_word);
    }

    string rep() const override
    { return query_word; }


    string query_word;
};

class Not_query : public Query_base
{
    friend Query operator~(const Query &);

    Not_query(const Query &q) : query(q)
    {}

    string rep() const override
    {
        return "~(" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery &) const override;

    Query query;
};

class Binary_query : public Query_base
{
protected:
    Binary_query(const Query &l, const Query &r, string s) :
            lhs(l), rhs(r), op_sym(std::move(s))
    {
    }

    string rep() const override
    {
        return "(" + lhs.rep() + " " + op_sym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;
    string op_sym;
};

class And_query : public Binary_query
{
    friend Query operator&(const Query &, const Query &);

    And_query(const Query &left, const Query &right) :
            Binary_query(left, right, "&")
    {}

    QueryResult eval(const TextQuery &t) const override;
};


class Or_query : public Binary_query
{
    friend Query operator|(const Query &, const Query &);

    Or_query(const Query &left, const Query &right) :
            Binary_query(left, right, "|")
    {}

    QueryResult eval(const TextQuery &t) const override;
};

#endif //STANDARD_TEMPLATE_LIBRARIES__15_OOP_H
