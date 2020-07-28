#include "_templates.h"
#include <cassert>

using namespace std;


namespace this_templates
{
    template<typename T, template<typename, typename> class Container>
    template<typename T2, template<typename, typename> class Con2>
    _this_class<T, Container> &_this_class<T, Container>
    ::operator=(const _this_class<T2, Con2> &op2)
    {
        _container.clear();
        _container.insert(_container.begin(), op2._container.begin(),
                op2._container.end());
        return *this;
    }

    template<typename T, template<typename, typename> class Container>
    void _this_class<T, Container>::push(const T &e)
    {
        _container.push_back(e);
    }

    template<typename T, auto init_size, typename Container>
    template<typename T2, auto init_size2, typename Container2>
    Stack<T, init_size, Container> &Stack<T, init_size, Container>
    ::operator=(Stack<T2, init_size2, Container2> const &op2)
    {
        Stack<T2, init_size2, Container2> tmp(op2);
        _data.clear();
        while (!tmp.empty())
        {
            _data.push_front(tmp.top());
            tmp.pop();
        }
        return *this;
    }

    template<auto val, typename T=decltype(val)>
    T foo();

    template<int _val, typename T>
    T add_value(T x)
    {
        return x + _val;
    }

    template<typename T>
    using deque_stack = Stack<T, 8, deque<T>>;

    template<typename T, auto init_size, typename Container>
    void Stack<T, init_size, Container>::push(const T &elem)
    {
//        static_assert(!_data.empty(), "_data must not be empty.");
//        _data.push_back(elem);// append copy of an element.
        assert(capacity < init_size);
        _data[capacity] = elem;
        ++capacity;
    }

    template<typename T, auto init_size, typename Container>
    void Stack<T, init_size, Container>::pop()
    {
        static_assert(!_data.empty(), "_data must not be empty.");
//        _data.pop_back();// remove last element.
        --capacity;
    }

    template<typename T, auto init_size, typename Container>
    const T &Stack<T, init_size, Container>::top() const
    {
        static_assert(!_data.empty(), "_data must not be empty.");
//        return _data.back();// return copy of last element.
        return _data[capacity - 1];
    }

    void Stack<string>::push(const string &elem)
    {
        data.push_back(elem);
    }

    const string &Stack<string>::top() const
    {
        assert(!data.empty());
        return data.back();
    }

    void Stack<string>::pop()
    {
        assert(!data.empty());
        data.pop_back();
    }

    template<typename T>
    void Stack<T *>::push(T *elem)
    {
        data.push_back(elem);
    }

    template<typename T>
    T *Stack<T *>::pop()
    {
        assert(!data.empty());
        T *tmp = data.back();
        data.pop_back();
        return tmp;
    }

    template<typename T>
    T *Stack<T *>::top() const
    {
        assert(!data.empty());
        return data.back();
    }
}
