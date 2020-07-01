#include "_16_template.h"

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (i>=data->size())
        throw out_of_range(msg);
}

template <typename T>T & Blob<T>::back()
{
    check(0, "back on empty");
    return data->back();
}

template <typename T>void Blob<T>::pop_back()
{
    check(0, "pop_back on empty");
    return data->pop_back();
}

template <typename T>
T & Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &)
{
    return false;
}
