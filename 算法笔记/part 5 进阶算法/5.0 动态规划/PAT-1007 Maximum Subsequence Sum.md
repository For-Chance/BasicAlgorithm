# 1007 Maximum Subsequence Sum

> part 5, 5.0



## 题意理解

- 给一串序列，求其最大子序列和

### INPUT

```
10
-10 1 2 3 4 -5 -23 3 7 -21
```

### OUTPUT

```
10 1 4
```



## 自己解法

- 动态规划，dp[i]记录0-i子序列的最大子序列和，边界就是d[i]=v[i]，所以
  $$
  dp[i] = max(v[i],dp[i-1]+v[i])
  $$

```c++
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int N;
    cin >> N;
    vector<int> v(N), dp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int maxdp = -1, start, end, maxstart, maxend;
    dp[0] = v[0];
    for (int i = 1; i < N; i++)
    {
        if (v[i] < dp[i - 1] + v[i])
        {
            dp[i] = dp[i - 1] + v[i];
            end = i;
        }
        else
        {
            dp[i] = v[i];
            start = i;
        }
        if (dp[i] > maxdp)
        {
            maxdp = dp[i];
            maxstart = start;
            maxend = end;
        }
    }
    if (maxdp < 0)
        cout << 0 << " " << 0 << " " << N - 1 << endl;
    else
        cout << maxdp << " " << maxstart << " " << maxend << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}
```

