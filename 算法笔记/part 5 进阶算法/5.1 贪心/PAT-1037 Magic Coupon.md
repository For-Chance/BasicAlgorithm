# 1037 Magic Coupon

> part 5, 5.1



## 题意理解

- 给出优惠卷数Nc，和对应的价格，产品Np和对应的价格，一章优惠卷数任意对应一个产品，尽可能地赚钱

### Sample Input:

```in
4
1 2 4 -1
4
7 6 -2 -3
```

### Sample Output:

```out
43
```



## 自己解法

- 两个数列按正负分成四个数列，绝对值越大越靠前
  - 然后从大到小，正乘正，负乘负

- 严格来说可以算是贪心

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int Nc, Np;
vector<int> NcP, NcN, NpP, NpN; // 分别代表两列的正数、负数

bool cmp(int a, int b)
{
    return abs(a) > abs(b);
}

int main()
{
    cin >> Nc;
    int a;
    for (int i = 0; i < Nc; i++)
    {
        cin >> a;
        if (a >= 0)
            NcP.push_back(a);
        else
            NcN.push_back(a);
    }
    cin >> Np;
    for (int i = 0; i < Np; i++)
    {
        cin >> a;
        if (a >= 0)
            NpP.push_back(a);
        else
            NpN.push_back(a);
    }
    sort(NcN.begin(), NcN.end(), cmp);
    sort(NcP.begin(), NcP.end(), cmp);
    sort(NpP.begin(), NpP.end(), cmp);
    sort(NpN.begin(), NpN.end(), cmp);
    int money = 0;
    for (int i = 0; i < NcN.size() && i < NpN.size(); i++)
        money += NcN[i] * NpN[i];
    for (int i = 0; i < NpP.size() && i < NcP.size(); i++)
        money += NpP[i] * NcP[i];
    cout << money << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神


```c++
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int m, n, ans = 0, p = 0, q = 0;
    scanf("%d", &m);
    vector<int> v1(m);
    for(int i = 0; i < m; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n);
    vector<int> v2(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v2[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while(p < m && q < n && v1[p] < 0 && v2[q] < 0) {
        ans += v1[p] * v2[q];
        p++; q++;
    }
    p = m - 1, q = n - 1;
    while(p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0) {
        ans += v1[p] * v2[q];
        p--; q--;
    }
    printf("%d", ans);
    return 0;
}
```

