#include "_18_huge_prog.h"

template<typename T>
_Exception<T>::_Exception(initializer_list<T> il) try :
        data(make_shared<vector<T>>(il))
{

} catch (const bad_alloc &err)
{
    cout << err.what() << endl;
}

namespace hug_prog
{
    bool operator==(const Base &lhs, const Base &rhs)
    {
        return typeid(lhs)== typeid(rhs) && lhs.equal(rhs);
    }

    bool Base::equal(const Base &rhs) const {
        return true;
    }

    bool Derived::equal(const Base &rhs) const {
        auto r = dynamic_cast<const Derived &>(rhs);
        return true;
    }
}
