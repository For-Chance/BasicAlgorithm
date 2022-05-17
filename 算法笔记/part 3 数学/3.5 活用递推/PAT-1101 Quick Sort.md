# 1101 Quick Sort

> part 3, 3.5



## 自己解法

- pivot 支点，中心点，基准点；
- 题意：找出一个序列中有多少个点，使得左边全部小于它，右边全部大于它
- 我的思路是，生成两个数列，分别代表当前值，之前的左边最大和右边最小，只要当前的数小于左边最大和右边最小即可

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N, min = 2000000000, max = -1;
    cin >> N;
    vector<int> d(N);
    vector<int> rightMin(N);
    vector<int> leftMax(N);
    leftMax[0] = -1;
    rightMin[N - 1] = 2000000000;
    cin >> d[0];
    for (int i = 1; i < N; i++)
    {
        cin >> d[i];
        if (d[i - 1] > max)
            max = d[i - 1];
        leftMax[i] = max;
    }
    for (int i = N - 2; i >= 0; i--)
    {
        if (d[i + 1] < min)
            min = d[i + 1];
        rightMin[i] = min;
    }
    int count = 0;
    vector<int> res;
    for (int i = 0; i < N; i++)
        if (d[i] > leftMax[i] && d[i] < rightMin[i])
            res.push_back(d[i]);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        if (i == 0)
            cout << res[i];
        else
            cout << ' ' << res[i];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <algorithm>
#include <vector>
int v[100000];
using namespace std;
int main() {
    int n, max = 0, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] > max)
            v[cnt++] = b[i];
        if (b[i] > max)
            max = b[i];
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}
```

