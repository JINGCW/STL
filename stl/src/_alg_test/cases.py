import sys
import itertools
import string

#计算字符串相似度
def editDistance(str1, str2):
    len1, len2 = len(str1) + 1, len(str2) + 1
    dp = [[0 for i in range(len2)] for j in range(len1)]
    for i in range(len1):
        dp[i][0] = i
    for j in range(len2):
        dp[0][j] = j
    for i in range(1, len1):
        for j in range(1, len2):
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1]))
    return dp[-1][-1]


while True:
    try:
        print("1/" + str(editDistance(input(), input()) + 1))
    except:
        break
#整型数组合并
while True:
    try:
        n1,s1,n2,s2=input(),list(map(int,input().split())),input(),list(map(int,input().split()))
        print("".join(list(map(str,sorted(list(set(s1+s2)))))))
    except:
        break
#字符串匹配
while True:
    try:
        a,b=set(input()),set(input())
        print ("true" if a&b==a else "false")
    except:
        break

# 统计大写字母个数
while True:
    try:
        s = list(input())
        print(sum([1 if str.isupper(x) else 0 for x in s]))
    except:
        break


# 最长回文
def fake_manacher(s: str):
    if s == s[::-1]:
        return len(s)

    max_len = 0
    for i in range(len(s)):
        if i - max_len >= 1 and s[i - max_len - 1:i + 1] == s[i - max_len - 1:i + 1][::-1]:
            max_len += 2
        if i - max_len >= 0 and s[i - max_len:i + 1] == s[i - max_len:i + 1][::-1]:
            max_len += 1

    return max_len


while True:
    try:
        out = fake_manacher(input())
        if out:
            print(out)
    except:
        break

# 最大连续bit数
while True:
    try:
        s = bin(int(input()))[2:]
        s = s.split('0')
        cnt = 0
        for x in s:
            if x:
                if len(x) > cnt:
                    cnt = len(x)
        print(cnt)
        continue
    except:
        break


# import decimal

def check_length(s: list):
    if len(s) <= 4:
        return 5

    if len(s) >= 8:
        return 25

    return 10


def check_digit_punctuation_char(s: list):
    digit_cnt = 0
    punctuation_cnt = 0
    alpha_cnt = 0
    upper_flag = False
    lower_flag = False
    scores = 0
    for x in s:
        if x in string.digits:
            digit_cnt += 1

        if x in string.punctuation:
            punctuation_cnt += 1

        if x in string.ascii_letters:
            alpha_cnt += 1
            if x in string.ascii_uppercase:
                upper_flag = True
            if x in string.ascii_lowercase:
                lower_flag = True

    if not digit_cnt:
        scores += 0
    elif digit_cnt == 1:
        scores += 10
    else:
        scores += 20

    if not punctuation_cnt:
        scores += 0
    elif punctuation_cnt == 1:
        scores += 10
    else:
        scores += 25

    if not alpha_cnt:
        scores += 0
    elif upper_flag and lower_flag:
        scores += 20
    else:
        scores += 10

    if alpha_cnt and digit_cnt:
        scores += 2
    if punctuation_cnt:
        scores += 1
    if upper_flag and lower_flag:
        scores += 2

    return scores


# 密码强度
while True:
    try:
        s = list(input())
        scores = check_length(s)
        scores += check_digit_punctuation_char(s)
        if scores >= 90:
            print("VERY_SECURE")
        elif scores >= 80:
            print("SECURE")
        elif scores >= 70:
            print("VERY_STRONG")
        elif scores >= 60:
            print("STRONG")
        elif scores >= 50:
            print("AVERAGE")
        elif scores >= 25:
            print("WEAK")
        else:
            print("VERY_WEAK")
    except:
        break

# 扑克牌大小
_map_int_to_AJQK = {
    '14': 'A',
    '11': 'J',
    '12': 'Q',
    '13': 'K',
    '15': '2'
}
while True:
    try:
        s = input()

        if "joker" in s:
            print("joker JOKER")
            continue

        s = s.replace('2', '15').replace('A', '14').replace('J', '11').replace('Q', '12').replace('K', '13')

        left, right = s.split('-')
        left = left.split(' ')
        right = right.split(' ')

        if len(left) != len(right):
            if not len(left) == 4 and not len(right) == 4:
                print("ERROR")
                continue

            possible_bomb = left if len(left) == 4 else right
            mask = [x == possible_bomb[0] for x in possible_bomb]
            if all(mask):
                possible_bomb = [_map_int_to_AJQK[x]
                                 if x in _map_int_to_AJQK else x for x in possible_bomb]

                print(' '.join(possible_bomb))
                continue

            print("ERROR")
            continue

        winner = left if int(left[0]) > int(right[0]) else right
        winner = [_map_int_to_AJQK[x]
                  if x in _map_int_to_AJQK else x for x in winner]
        print(' '.join(winner))
    except:
        break


# 24 点
def calc_24points(data):
    map2 = {'J': '11', 'Q': '12', 'K': '13', 'A': '1'}
    new_data = []
    for d in data:
        if d in map2:
            new_data.append(map2[d])
        else:
            new_data.append(d)

    map1 = {'0': '+', '1': '-', '2': '*', '3': '/'}
    # 生成数字位的排列序列
    for o in (''.join(x) for x in itertools.product(map(str, range(4)), repeat=3)):
        (1775)  # 生成运算符位的可能性组合
        for i in itertools.permutations(range(4), 4):
            temp1 = '((' + new_data[i[0]] + map1[o[0]] + new_data[i[1]] + ')' + map1[o[1]] + new_data[i[2]] + ')' + \
                    map1[o[2]] + new_data[i[3]]
            temp2 = data[i[0]] + map1[o[0]] + data[i[1]] + map1[o[1]] + data[i[2]] + map1[o[2]] + data[i[3]]
            if ('joker' in temp1) or ('JOKER' in temp1):
                print('ERROR')
                return
            elif eval(temp1) == 24:
                print(temp2)
                return
    print('NONE')


for line in sys.stdin:
    data = list(map(str, line.strip().split()))
    calc_24points(data)

# 合法IP
while True:
    try:
        s = input().strip().split('.')
        flag = True

        for i in s:
            if not 0 <= int(i) <= 255:
                flag = False
                print("NO")
        if flag:
            print("YES")

    except:
        break
