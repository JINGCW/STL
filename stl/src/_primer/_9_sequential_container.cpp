#include <list>
#include <deque>
#include <array>
#include <string>
#include <vector>
#include <forward_list>
#include <iostream>
#include "_9_sequential_container.h"

using namespace std;

void container_init_stub() {
    list<string> authors = {"milton", "shakespeare", "austen"};
    cout << "authors: " << authors.size() << " "
         << authors.max_size() << endl;
    vector<const char *> articles = {"a", "an", "the"};

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

void recursive_insert() {
    string word;
    list<string> lst;
    auto iter = lst.begin();

    while (cin >> word)
        iter = lst.insert(iter, word);
}

void change_container() {
    vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto iter = iv.begin();
    while (iter != iv.end()) {
        if (*iter % 2) {
            iter = iv.insert(iter, *iter);
            iter += 2;
        } else
            iter = iv.erase(iter);
    }
    for (const auto &e:iv) {
        cout << e << endl;
    }
}
