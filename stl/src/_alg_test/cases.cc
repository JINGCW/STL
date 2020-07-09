#include "cases.h"

//最长回文
string longestPalindrome(string s)
{
    string manaStr = "$#";
    for (int i = 0; i < s.size(); i++) //首先构造出新的字符串
    {
        manaStr += s[i];
        manaStr += '#';
    }
    vector<int> rd(manaStr.size(), 0);//用一个辅助数组来记录最大的回文串长度，注意这里记录的是新串的长度，原串的长度要减去1
    int pos = 0, mx = 0;
    int start = 0, maxLen = 0;
    for (int i = 1; i < manaStr.size(); i++)
    {
        rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
        while (i + rd[i] < manaStr.size() && i - rd[i] > 0 &&
               manaStr[i + rd[i]] == manaStr[i - rd[i]])//这里要注意数组越界的判断，源代码没有注意，release下没有报错
            rd[i]++;
        if (i + rd[i] > mx) //如果新计算的最右侧端点大于mx,则更新pos和mx
        {
            pos = i;
            mx = i + rd[i];
        }
        if (rd[i] - 1 > maxLen)
        {
            start = (i - rd[i]) / 2;
            maxLen = rd[i] - 1;
        }
    }
    return s.substr(start, maxLen);
}

//链表展开（二叉树展开）
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

//糖果分发
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

//字符统计
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

//输入整型数组和排序标识，对其元素按照升序或降序进行排序
void sort_int_array_flag()
{
    int arr_len, element, flag;

    while (cin >> arr_len)
    {
        vector<int> _vec;
        while (arr_len--)
        {
            cin >> element;
            _vec.push_back(element);
        }
        cin >> flag;
        stable_sort(_vec.begin(), _vec.end());
        if (flag == 1)
            reverse(_vec.begin(), _vec.end());
        for (const auto &elem:_vec)
            cout << elem << ' ';
        cout << endl;
        _vec.clear();
    }
}

//等差数列,sum=a1*n+n*(n-1)/2*d
void arithmetic_sequence()
{
    int a1 = 2, d = 3, n;
    while (cin >> n)
        cout << a1 * n + n * (n - 1) * d / 2;
//    return a1 * n + n * (n - 1) * d / 2;
}

//自守数
void automorphic_number()
{
    int n;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            string power_ = to_string(i * i);
            string is = to_string(i);
            if (is == power_.substr(power_.size() - is.size(), power_.size()))
                ++cnt;
        }
        cout << cnt << endl;
    }
}

//记负均正
void record_neg_avg_pos()
{
    int n;
    while (cin >> n)
    {
        int element = 0, neg_cnt = 0, sum = 0, sum_size = 0;
        vector<int> _vec;
        while (n-- && cin >> element)
        {
            if (element > 0)
            {
                _vec.push_back(element);
                ++sum_size;
            } else if (element < 0)
                ++neg_cnt;
        }
        for (auto &e:_vec)
            sum += e;
        cout << neg_cnt << ' ' << setiosflags(ios::fixed) << setprecision(1) << (double) sum / sum_size << endl;
    }
}

//表示数字
void mark_number()
{
    string s;

    while (cin >> s)
    {
        for (std::size_t i = 0; i < s.size(); ++i)
        {
            int pos = 0;
            if (isdigit(s[i]))
            {
                s.insert(i, "*");
                ++i;
            }
            while (isdigit(s[i]))
            {
                pos = i + 1;
                ++i;
            }
            if (pos)
                s.insert(pos, "*");
        }

        cout << s << endl;
    }
}

//人名币转换
void money_exchange()
{
    map<char, string> _map({
                                   {'1', "壹"},
                                   {'2', "贰"},
                                   {'3', "叁"},
                                   {'4', "肆"},
                                   {'5', "伍"},
                                   {'6', "陆"},
                                   {'7', "柒"},
                                   {'8', "捌"},
                                   {'9', "玖"},
                                   {'0', "零"},
                           });
    double in;
    cin >> in;
    vector<string> _vec;
    string ins = to_string(in);
    for (auto it = ins.end(); it > ins.begin(); --it)
    {

    }
}

//计票统计
void vote_stat()
{
    int num_candidate, num_votes;

    while (cin >> num_candidate)
    {
        string candidate_name, votes;
        map<string, size_t> _map;
        vector<string> _vec;
        std::size_t invalid_num = 0;

        while (num_candidate-- && cin >> candidate_name)
        {
            _map.insert({candidate_name, 0});
            _vec.push_back(candidate_name);
        }

        cin >> num_votes;

        while (num_votes-- && cin >> votes)
            if (_map.find(votes) != _map.end())
                ++_map[votes];
            else
                ++invalid_num;

        for (const auto &e:_vec)
            cout << e << " : " << _map[e] << endl;
        cout << "Invalid : " << invalid_num;
        cout << endl;
    }

}

//数组3 5倍数，相等
void arr_3_5_equal()
{
    int n;
    while (cin >> n)
    {
        int element;
        vector<int> arr_3;
        vector<int> arr_5;
        int sum3 = 0, sum5 = 0;
        vector<int> rest;
        bool flag = true;

        while (n-- && cin >> element)
        {
            if (!(abs(element) % 3))
                arr_3.push_back(element);

            else if (!(abs(element) % 5))
                arr_5.push_back(element);
            else
            {
                rest.push_back(element);

            }
        }
        stable_sort(rest.begin(), rest.end());
        sum3 = accumulate(arr_3.begin(), arr_3.end(), 0);
        sum5 = accumulate(arr_5.begin(), arr_5.end(), 0);
        int sum_rest = accumulate(rest.begin(), rest.end(), 0);
        flag = abs(sum3 - sum5 + sum_rest) % 2 != 0;

        for (auto it = rest.begin(); it != rest.end(); ++it)
        {
            sum3 = accumulate(arr_3.begin(), arr_3.end(), 0);
            sum5 = accumulate(arr_5.begin(), arr_5.end(), 0);
            if (sum3 == sum5)
            {
//
            } else
            {
                if (sum3 < sum5)
                    if (*it >= 0)
                        arr_3.push_back(*it);
                    else
                        arr_5.push_back(*it);
                else if (*it >= 0)
                    arr_5.push_back(*it);
                else
                    arr_3.push_back(*it);
            }
        }
        if (flag)
            cout << "false" << endl;
        else
            cout << setiosflags(ios::boolalpha)
                 << (accumulate(arr_3.begin(), arr_3.end(), 0) == accumulate(arr_5.begin(), arr_5.end(), 0)) << endl;
    }
}

//字符串找出最长数字串
void string_max_len_digits()
{
    string text;

    while (cin >> text)
    {
        regex r("\\d+");
        vector<string> match_out;
        int len = 0;

        for (sregex_iterator it(text.begin(), text.end(), r), end_it;
             it != end_it; ++it)
        {
            if (it->str().length() > len)
            {
                len = it->str().length();
                match_out.clear();
                match_out.push_back(it->str());
                continue;
            }
            if (it->str().length() == len)
                match_out.push_back(it->str());
        }
        for (const auto &e:match_out)
            cout << e;
        cout << ',' << len << endl;
    }
}

//棋盘n*m，从左上角到右下角总共走法
int n_m_steps(int n, int m)
{
    if (n == 0 | m == 0)
        return 1;

    return n_m_steps(n - 1, m) + n_m_steps(n, m - 1);
}

