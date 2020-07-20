#ifndef __19_SPECIAL_H
#define __19_SPECIAL_H

#include <string>
#include <functional>
//#include <iterator>
#include <type_traits>

using namespace std;


namespace spec_19
{
    template<typename IterT, typename DistT>
    void advance(IterT &iter, DistT d)
    {
        if (typeid(typename iterator_traits<IterT>::iterator_category) ==
            typeid(random_access_iterator_tag))
            iter += d;
        else
        {
            if (d >= 0)
            { while (d--)++iter; }
            else
            { while (d++)--iter; }
        }
    }

    enum class open_modes
    {
        input, output, append
    };

    enum color
    {
        yellow, green, red
    };

    enum
    {
        float_prec = 6, double_prec = 10
    };

    enum int_value : unsigned long long
    {
        char_type = 255, short_type = 65535
    };

    class Screen
    {
//        friend void screen_menu();

    public:

        using pos = string::size_type;
        using action_type = char (Screen::*)(Screen::pos, Screen::pos) const;
        using move_mem_pointer_type = Screen &(Screen::*)();

        enum directions
        {
            HOME, FORWARD, BACK, UP, DOWN
        };

        char get_cursor() const
        { return contents[cursor]; }

//        const string Screen::*p_data;
        static const string Screen::*data()
        {
            return &Screen::contents;
        };

        char get(pos, pos) const;

//        char (Screen::*pmf)(Screen::pos, Screen::pos) const;
        Screen &action(Screen &, action_type= &Screen::get);

        Screen &home();

        Screen &forward();

        Screen &back();

        Screen &up();

        Screen &down();

        Screen &move(directions);

    protected:
        string contents;
        pos cursor;
        pos height, width;
    private:
        constexpr static move_mem_pointer_type menu[] = {
                &Screen::home,
                &Screen::forward,
                &Screen::back,
                &Screen::up,
                &Screen::down,
        };
    };

    function<bool(const string &)> fp = &string::empty;
    auto f = mem_fn(&string::empty);

//    auto fb = bind(&string::empty, _1);
    class Token
    {
    public:
        Token() : tok(INT), ival(0)
        {}

        Token(const Token &t) : tok(t.tok)
        { copy_union(t); }

        Token &operator=(const Token &);

        ~Token()
        { if (tok == STR)sval.~string(); }

        Token &operator=(const string &);

        Token &operator=(char);

        Token &operator=(int);

        Token &operator=(double);

    private:
        enum
        {
            INT, CHAR, DBL, STR
        } tok;//discriminate
        union
        {
            char cval;
            int ival;
            double dval;
            string sval;
        };

        void copy_union(const Token &);
    };
}


#endif //__19_SPECIAL_H
