# 1044 Shopping in Mars

> part 2, 2.0



## 自己解法(滑动窗口)

- 2,5 TO 4 WA -> 算法不够高效

```c++
#include <iostream>
using namespace std;
#include <vector>
#define maxn 100000
int d[maxn];

int main()
{
    int N, M;
    cin >> N >> M;
    int nearliest = 100000000;
    // 用 vector 存储最靠近M的不用考虑越界的问题
    vector<string> near;
    for (int i = 0; i < N; i++)
        cin >> d[i];
    int start = 0, end = 0, res = 0;
    int flag = 0; // flag == 0 表示还没找到等于M的序列
    while (start != N - 1)
    {
        if (res < M)
        {
            res += d[end];
            if (end < N)
                end++;
            continue;
        }
        else if (res == M)
        {
            cout << start + 1 << "-" << end << endl;
            flag = 1;
            res += d[end];
            if (end < N)
                end++;
        }
        else
        {
            if (flag == 0)
            {
                if (res < nearliest)
                {
                    nearliest = res;
                    vector<string>().swap(near);
                    near.push_back(to_string(start + 1) + "-" + to_string(end));
                }
                else if (res == nearliest)
                    near.push_back(to_string(start + 1) + "-" + to_string(end));
            }
            res -= d[start];
            start++;
        }
    }
    if (flag == 0)
        for (vector<string>::iterator it = near.begin(); it < near.end(); it++)
            cout << *it << endl;

    system("pause");
    return 0;
}
```



## 大神解法(二分法)

- 柳神

```c++
#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int &j, int &tempsum) {
    int left = i, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        if(sum[mid] - sum[i-1] >= m)
            right = mid;
        else
            left = mid + 1;
    }
    j = right;
    tempsum = sum[j] - sum[i-1];
}
int main() {
    scanf("%d%d", &n, &m);
    sum.resize(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int minans = sum[n];
    for(int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        if(tempsum > minans) continue;
        if(tempsum >= m) {
            if(tempsum < minans) {
                resultArr.clear();
                minans = tempsum;
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    for(int i = 0; i < resultArr.size(); i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i+1]);
    return 0;
}
```

