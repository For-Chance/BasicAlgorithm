# 1010 Radix

> part 2, 2.0



## 自己解法(二分法)

- 3,4,5,7,10,11 WA -> 只有tag所指定到的那个数有进制2-36的限制，而另一个数的进制是不限的
- 1 WA, 7 TO -> 查找算法不够高效
- 6,8,10,12,13 WA -> 二分法未考虑转换为10进制的数会溢出，最终的数为负数（第47行）
- 注意有可能产生溢出，使用long long类型

```c++
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <math.h>

int getnum(char c)
{
    // 0-9 a-z 获得数字
    if (int(c) >= '0' && int(c) <= '9')
        return int(c) - '0';
    else
        return int(c) - 'a' + 10;
}

long long getdec(string N, int r)
{
    // 将 N 字符串转换为 r 进制输出匹配的10进制数
    long long dec = 0;
    int len_n = N.length();
    // 对 N 进行翻转，更方便一些
    reverse(N.begin(), N.end());
    for (int i = 0; i < len_n; i++)
    {
        int num = getnum(N[i]);
        dec += num * pow(r, i);
        if (num >= r)
            return -1;
    }
    return dec;
}

long long guessRadix(long long dec, string N)
{
    string N_copy = N;
    sort(N_copy.begin(), N_copy.end(), greater<char>());
    long long low = getnum(N_copy[0]) + 1;
    long long high = max(dec, low);
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long dec2 = getdec(N, mid);
        if (dec == dec2)
        {
            return mid;
        }
        else if (dec2 > dec || dec2 < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    long long dec_N1, dec_N2, res;
    if (tag == 1)
    {
        dec_N1 = getdec(N1, radix);
        res = guessRadix(dec_N1, N2);
    }
    else
    {
        dec_N2 = getdec(N2, radix);
        res = guessRadix(dec_N2, N1);
    }
    if (res == -1)
        cout << "Impossible" << endl;
    else
        cout << res << endl;
    system("pause");
    return 0;
}
```



## 大神解法(二分法)

- 柳神
- convert函数：给定一个数值和一个进制，将它转化为10进制。转化过程中可能产生溢出
- find_radix函数：找到令两个数值相等的进制数。在查找的过程中，需要使用二分查找算法，如果使用当前进制转化得到数值比另一个大或者小于0，说明这个进制太大
- isdigit() 判断是否是数字
- max_element() 获得字符串中最大的字符

```c++
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}
```

