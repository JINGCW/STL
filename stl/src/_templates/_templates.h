#ifndef __TEMPLATES_H
#define __TEMPLATES_H

#include <type_traits>
#include <iterator>
#include <vector>
#include <deque>
#include <array>
#include <iostream>


using namespace std;
/*
 Fold Expression Evaluation
 --------------------------------------------------------------------
|( ... op pack ) ((( pack1 op pack2 ) op pack3 ) ... op pa            |
|--------------------------------------------------------------------
|( pack op ... ) ( pack1 op ( ... ( packN-1 op packN )))              |
| --------------------------------------------------------------------
|( init op ... op pack ) ((( init op pack1 ) op pack2 ) ... op packN  |
| --------------------------------------------------------------------
|( pack op ... op init ) ( pack1 op ( ... ( packN op init )))         |
 --------------------------------------------------------------------
 */

namespace this_templates
{
    template<typename...Args>
    void print(Args...args);

    template<std::size_t ...idx, typename T>
    void idx_print(T const &lst)
    {
        print(lst[idx]...);
    }

    template<typename T, typename...Args>
    constexpr bool is_homogeneous(T, Args...)
    {
        //isHomogeneous(43, -1, "hello")
        //std::is_same<int,int>::value && std::is_same<int,char const*>::value
        return (is_same<T, Args>::value&& ...);
    }

    template<typename... T>
    void double_print(T const &...args)
    {
        print(args + args...);
    }

    template<typename... T>
    void one_print(T const &...args)
    {
        print(args + 1 ...);
    }

    template<typename T>
    class add_space
    {
        T const &ref;
    public:
        add_space(T const &r) :
                ref(r)
        {}

        friend ostream &operator<<(ostream &os, add_space<T> s)
        {
            return os << s.ref << ' ';
        }
    };

    template<typename ...Args>
    void print(Args const &...args)
    {
//        (cout<<...<<args) << endl;
/* add_space(args) use class template argument deduction to have the effect
 * of add_space<Args>(args), which for each argument creates an add_space object
 * that refers to the passed argument and adds a space when it is used in output expression.
 */
        (cout<<...<<add_space(args)) << endl;
    }

//    template<typename T=int>
    struct Node
    {
        int val;
        Node *left, *right;

        Node(int i = 0) :
                val(i), left(nullptr), right(nullptr)
        {}
    };

    template<typename T, typename ...Types>
    Node *traverse(T root, Types...rest)
    {
        return (root->*...->*rest);
    }

    void traverse_test()
    {
        auto left = &Node::left;
        auto right = &Node::right;

        Node *root = new Node(0);
        root->left = new Node(1);
        root->left->right = new Node(2);
        // traverse binary tree
        Node *node = traverse(root, left, right);
    }

    template<typename ...Types>
    auto fold_sum(Types...Args)
    {
        return (...+Args);// ((arg1+arg2)+arg3)...
    }

//( ... op pack ) ((( pack1 op pack2 ) op pack3 ) ... op packN
//( pack op ... ) ( pack1 op ( ... ( packN-1 op packN )))
//( init op ... op pack ) ((( init op pack1 ) op pack2 ) ... op packN )
//( pack op ... op init ) ( pack1 op ( ... ( packN op init )))
    void print()
    {}// end recursive, when parameter pack is empty
    template<typename T, typename ...Types>
    void print(T first, Types...Args)
    {
        cout << "Number of remaining Types: " << sizeof...(Types) << endl;
        cout << "Number of remaining Args: " << sizeof...(Args) << endl;
        cout << first << '\n';
        if (sizeof...(Args) > 0)
            print(Args...);
    }

    template<decltype(auto) N>// which allows initialized N as a reference
    class C
    {
    };

    //templatized aggregates
    template<typename T>
    struct value_comment
    {
        T value;
        string comment;
    };
    //since c++17, deduction guide
    value_comment(char const *, char const *)->value_comment<string>;
//    value_comment vc2={"hello","world"};

    template<typename T1, typename T2>
    class this_class
    {
    };

    template<typename T>
    class this_class<T, T>
    {
    };// partial specification
    template<typename T>
    class this_class<T, int>
    {
    };//partial specification, second parameter is int
    template<typename T1, typename T2>
    class this_class<T1 *, T2 *>
    {
    };//partial, both para is pointer
    //ambiguous-> this_class<int*,int*>m, matches this_class<T,T> and this_class<T1*,T2*>
    //resolve above
    template<typename T>
    class this_class<T *, T *>
    {
    };

    template<typename T, auto init_size = 8, typename Container=array<T, init_size> >
    class Stack;

    template<typename T, std::size_t init_size>
    ostream &operator<<(ostream &os, Stack<T, init_size> const &);

    template<typename T, auto init_size, typename Container>
    class Stack
    {
    public:
        using size_type = decltype(init_size);

    private:

        friend ostream &operator
        <<<T>(ostream &, Stack<T, init_size> const &);

        static_assert(is_default_constructible<T>::value,
                      "Stack requires default-constructible elements");

        Container _data;
        size_type capacity;

    public:
        Stack() : capacity(init_size)
        {}

        Stack(Stack const &rhs);// copy constructor
        Stack(T const &rt) : _data({rt})
        {}

        //Stack string_stack="bottom"; //Stack<char const*>deduced since c++17
        // but not char const[7].
        Stack(T elem)// initialize stack with one element by value
                : _data({move(elem)})
        {}

        Stack &operator=(Stack const &);// assignment operator

        void push(T const &elem);

        void pop();

        T const &top() const;

        bool empty() const
        {
//            return _data.empty();
            return capacity == 0;
        }

        void rep(ostream &os) const
        {
            for (T const &e:_data)
                os << e << " ";
            os << endl;
        }

        auto size() const
        { return capacity; }

//        friend ostream &operator<<(ostream&os,Stack<T>const&s)
//        {
//            s.rep(os);
//            return os;
//        }
    };

    Stack(char const *)->Stack<string>;

    template<typename T>
    bool operator==(Stack<T> const &lhs, Stack<T> const &rhs);

    template<>
    class Stack<string>
    {
        deque<string> data;
    public:
        void push(string const &elem);

        void pop();

        string const &top() const;

        bool empty() const
        {
            return data.empty();
        }
    };

    template<typename T>
    class Stack<T *>
    {
        vector<T *> data;
    public:
        void push(T *);

        T *pop();

        T *top() const;

        bool empty() const
        {
            return data.empty();
        }
    };

//    template<typename T1, typename T2, typename RT=decay_t<decltype(T1())>>
    template<typename T1, typename T2, typename RT=common_type_t<T1, T2>>
    RT max(T1 a, T2 b)
    {
        b < a ? a : b;
    };

    template<typename T1, typename T2>
    common_type_t<T1, T2> max(T1 a, T2 b) //-> typename decay<decltype(true ? a : b)>::type
    {

        return b < a ? a : b;
    }


    template<class Iter1, class Iter2>
    void iter_swap(Iter1 iter1, Iter2 iter2)
    {
//        true_type
        typename Iter1::value_type tmp = *iter1;
        *iter1 = *iter2;
        *iter2 = tmp;
    }

}

#endif //__TEMPLATES_H
