#ifndef STANDARD_TEMPLATE_LIBRARIES__13_COPY_MANAGE_H
#define STANDARD_TEMPLATE_LIBRARIES__13_COPY_MANAGE_H

#include <string>
#include <set>
#include <memory>

using namespace std;

class LikeValue
{
public:
    LikeValue(const string &s = string()) :
            ps(new string(s)), i(0)
    {}

    LikeValue(const LikeValue &p) :
            ps(new string(*p.ps)), i(0)
    {}

    LikeValue &operator=(const LikeValue &);

    ~LikeValue()
    {
        delete ps;
    }

private:
    string *ps;
    int i;
};

class LikePointer
{
public:
    LikePointer(const string &s = string()) :
            ps(new string(s)), i(0), use(new size_t(1))
    {}

    LikePointer(const LikePointer &p) :
            ps(p.ps), i(p.i), use(p.use)
    { ++*use; }

    LikePointer &operator=(const LikePointer &);

//    LikePointer &operator=(LikePointer);

    ~LikePointer();

private:
    string *ps;
    int i;
    size_t *use;//ref count
};

class Folder;

class Message
{
    friend class Folder;

    explicit Message(const string &s = "") :
            contents(s)
    {}//folders implicit init to empty set.
    Message(const Message &);

    Message &operator=(const Message &);

    ~Message();

    void save(Folder &);

    void remove(Folder &);

private:
    string contents;
    set<Folder *> folders;

    void add_to_folders(const Message &);

    void remove_from_folders();
};

class _Str_vector
{
public:
    _Str_vector() :
            elements(nullptr), first_free(nullptr), cap(nullptr)
    {}

    _Str_vector(const _Str_vector &);

    _Str_vector(_Str_vector &&) noexcept;

    _Str_vector &operator=(const _Str_vector &);
    _Str_vector &operator=(_Str_vector &&)noexcept ;

    ~_Str_vector();

    void push_back(const string &);

    size_t size() const
    { return elements - first_free; }

    size_t capacity() const
    { return elements - cap; }

    string *begin() const
    { return elements; }

    string *end() const
    { return first_free; }

private:
    allocator<string> alloc;//allocate elements.
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }

    void free();

    void reallocate();

    pair<string *, string *> alloc_n_copy(const string *, const string *);

    string *elements;
    string *first_free;
    string *cap;
};

#endif //STANDARD_TEMPLATE_LIBRARIES__13_COPY_MANAGE_H
