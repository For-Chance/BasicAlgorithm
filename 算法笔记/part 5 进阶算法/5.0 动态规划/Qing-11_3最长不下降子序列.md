# Qing-11_3最长不下降子序列

> part 3, 3.0



## 题意理解

- 在一个数字序列中，找到一个最长的子序列(可以不连续)，使得这个子序列是不下降的



## 自己解法

```c++
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    cout << "输入序列的个数：" << endl;
    int N;
    cin >> N;
    cout << "请输入一串序列，空格隔开：" << endl;
    vector<int> v(N), dp(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    int maxdp = -1;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i] > v[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[i] + 1;
        maxdp = max(maxdp, dp[i]);
    }
    cout << "最长子序列的个数是:\n"
         << maxdp << endl;
    system("pause");
    return 0;
}
```


