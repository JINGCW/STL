#include <list>
#include <deque>
#include <array>
#include <string>
#include <vector>
#include <forward_list>
#include "_9_sequential_container.h"

using namespace std;

void container_init_stub()
 {
    list<string >authors={"milton","shakespeare","austen"};
    vector<const char*>articles={"a","an","the"};

    /*success:type match*/
//     list<string> list2(authors);
//     const list<string> &clist(authors);//no copy
    /*fail:container type mismatch*/
//    deque<string> author_deque(authors);
    /*fail:container type mismatch*/
//    vector<string> words(articles);
    /*success:convert Elem char* to string*/
    forward_list<string> words(articles.begin(), articles.end());
}
