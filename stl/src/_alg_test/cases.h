#ifndef _CASES_H
#define _CASES_H

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <regex>
#include <numeric>
#include <math.h>

using namespace std;

//template <typename T>
class Node
{
public:
    ~Node()
    {}

    Node() = default;

    Node(Node *head) :
            data(head->data), prev(head->prev), next(head->next), child(head->child)
    {}

//    static Node *flatten(Node *head);

//    static Node *build_nodes();

    int data;
    Node *prev;
    Node *next;
    Node *child;
};

#endif //_CASES_H
