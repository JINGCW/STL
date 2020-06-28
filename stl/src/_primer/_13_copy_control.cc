#include "_13_copy_control.h"

LikeValue &LikeValue::operator=(const LikeValue &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

LikePointer::~LikePointer()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

LikePointer &LikePointer::operator=(const LikePointer &rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

LikePointer &LikePointer::operator=(LikePointer rhs)
{
    swap(*this, rhs);
    return *this;
}

void _Str_vector::push_back(const string &s)
{
    check_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *>
_Str_vector::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void _Str_vector::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements; alloc.destroy(--p));
        alloc.deallocate(elements, cap - elements);
    }
}

_Str_vector::_Str_vector(const _Str_vector &s)
{
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

_Str_vector::~_Str_vector()
{
    free();
}

_Str_vector &
_Str_vector::operator=(const _Str_vector &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void
_Str_vector::reallocate()
{
    auto new_capacity = size() ? size() * 2 : 1;
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

_Str_vector::_Str_vector(_Str_vector &&s) noexcept:
        elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

_Str_vector &_Str_vector::operator=(const _Str_vector &&rhs)noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
