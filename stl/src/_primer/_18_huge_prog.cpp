#include "_18_huge_prog.h"

template<typename T>
_Exception<T>::_Exception(initializer_list<T> il) try :
        data(make_shared<vector<T>>(il))
{

} catch (const bad_alloc &err)
{
    cout << err.what() << endl;
}
