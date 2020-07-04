#ifndef STANDARD_TEMPLATE_LIBRARIES__TEMPLATES_H
#define STANDARD_TEMPLATE_LIBRARIES__TEMPLATES_H

#include <stdexcept>

using namespace std;

template<class T, int _Init_size = 100>
class _Stack_template
{
//    enum
//    {
//        ssize = 10
//    };
    T stack[_Init_size];
    int top;
public:
    _Stack_template() : top(0)
    {}

    void push(const T &i)
    {
        stack[top++] = i;
    }

    int pop()
    {
        return stack[--top];
    }

    int length() const
    { return top; }

    int cap() const
    { return _Init_size ;}
};

template<class T>
class Array
{
    enum
    {
        ssize = 100
    };
    T _arr[ssize];
public:
    T &operator[](int index);
//    {
//        if (index < 0 || index >= ssize)
//            throw out_of_range("index out of range")
//        return _arr[index];
//    }
};

template<class T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || index >= ssize)
        throw out_of_range("index out of range");
    return _arr[index];
}

#endif //STANDARD_TEMPLATE_LIBRARIES__TEMPLATES_H
