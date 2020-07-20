#include <new>
#include "_19_special.h"

using namespace std;

namespace spec_19
{
    Screen &Screen::move(directions dr)
    {
        return (this->*menu[dr])();
    }

//    void screen_menu()
//    {
//        Screen::action_type Screen::menu[]{
//                &Screen::home,
//                &Screen::forward,
//                &Screen::back,
//                &Screen::up,
//                &Screen::down,
//        };
//    }
    Token &Token::operator=(int i)
    {
        if (tok == STR)sval.~string();
        ival = i;
        tok = INT;
        return *this;
    }

    Token &Token::operator=(const string &s)
    {
        if (tok == STR)
            sval = s;
        else
            new(&sval)string(s);
        tok = STR;
        return *this;
    }

    void Token::copy_union(const Token &t)
    {
        switch (t.tok)
        {
            case INT:
                ival = t.tok;
                break;
            case CHAR:
                cval = t.tok;
                break;
            case DBL:
                dval = t.tok;
                break;
            case STR:
                new(&sval)string(t.sval);
                break;
        }
    }

    Token &Token::operator=(const Token &t)
    {
        if (t.tok != STR && tok == STR)
            sval.~string();

        if (t.tok == STR && tok == STR)
            sval = t.sval;
        else
            copy_union(t);
        tok = t.tok;
        return *this;
    }
}
