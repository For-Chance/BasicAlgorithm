# Qing-11_3最长不下降子序列

> part 3, 3.0



## 题意理解

- 给定两个公共字符串（或数字序列）A和B，求一个字符串，使得这个字符串是A和B的最长公共部分，例如字符串“sadstory”与“adminsorry”的最长公共子序列为“adsory”，长度为6



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

