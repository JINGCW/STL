#include "cases.h"

static stack<Node *> _stack;
static Node *_tail;

Node *__flatten(Node *head, Node *&tail)
{
    if (!head)
        return head;

    if (!head->next && !head->child)
    {
        if (_stack.empty())
            return head;
        head->next = _stack.top();
        _stack.pop();
    }

    if (head->child)
    {
        _stack.push(head->next);
        head->next->prev = __flatten(head->child, tail);
        head->next = head->child;
        head->child = nullptr;
    }

    return __flatten(head->next, tail);
}

void ___flatten_test()
{
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;
    Node *node5 = new Node;
    Node *node6 = new Node;
    Node *node7 = new Node;

    node1->data = 1;
    node1->next = node2;
    //2
    node2->data = 2;
    node2->prev = node1;
    node2->next = node3;
    node2->child = node4;
    //3
    node3->data = 3;
    node3->prev = node2;
    //4
    node4->data = 4;
    node4->prev = node2;
    node4->next = node5;
    node4->child = node6;
    //5
    node5->data = 5;
    node5->prev = node4;
    //6
    node6->data = 6;
    node6->prev = node4;
    node6->next = node7;
    //7
    node7->data = 7;
    node7->prev = node6;

    _tail = node1->next;
    while (_tail->next)
        _tail = _tail->next;

    auto _ = __flatten(node1, _tail);
    while (node1->next)
    {
        cout << node1->data << endl;
        node1 = node1->next;
    }
    cout << _tail->data << endl;
}

/*distribute_candies*/
vector<int> distribute_candies(int candies, int num_people)
{
    int rest = candies, dist_amount = 1;
    vector<int> out(num_people, 0);

    while (rest > dist_amount)
    {
        rest -= dist_amount;
        out[(dist_amount - 1) % num_people] += dist_amount;
        ++dist_amount;
    }
    out[(dist_amount - 1) % num_people] += rest;

    return out;
}

void char_statistic()
{
    string input;
    while (cin >> input)
    {
        map<char, std::size_t> _map;

        for (auto e:input)
        {
            ++_map[e];
        }
        vector<pair<char, std::size_t>> _vec(_map.begin(), _map.end());
        stable_sort(_vec.begin(), _vec.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
        for (auto &elem:_vec)
            cout << elem.first;
        cout << endl;
    }
}

void sort_int_array_flag()
{
    int arr_len,element,flag;
    vector<int>_vec;

    while (cin>>arr_len)
    {
        while (arr_len--)
        {
            cin >> element;
            _vec.push_back(element);
        }
        cin >> flag;
        stable_sort(_vec.begin(), _vec.endl);
        if (flag==0)
            reverse(_vec.begin(), _vec.end());
        for(const auto&elem:_vec)
            cout << elem;
        cout << endl;
    }
}
