# 1063 Set Similarity

> part 4, 4.0



## 自己解法

- 一开始第二个循环里面写了三个循环，然后发现最后一个过不了，就将三个循环优化为一个循环，就过了

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    int N, M;
    cin >> N;
    vector<map<int, int>> n(N); // map的集合
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        map<int, int> m;
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            map<int, int>::iterator pos = m.find(x);
            if (pos == m.end())
                m.insert(make_pair(x, 1));
            else
                pos->second++;
        }
        n[i] = m;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        int count = 0;
        map<int, int> m = n[a - 1];
        for (map<int, int>::iterator it = n[b - 1].begin(); it != n[b - 1].end(); it++)
        {
            map<int, int>::iterator pos = m.find(it->first);
            if (pos == m.end())
                m.insert(make_pair(it->first, 1)); // 找不到是0
            else
            {
                pos->second = 0; // 找得到就是0
                count++;
            }
        }
        double rate = double(count) / m.size() * 100;
        printf("%.1f%\n", rate);
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 用set确实更快

```c++
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, m, k, temp, a, b;
    scanf("%d", &n);
    vector<set<int>> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        set<int> s;
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int nc = 0, nt = v[b-1].size();
        for(auto it = v[a-1].begin(); it != v[a-1].end(); it++) {
            if(v[b-1].find(*it) == v[b-1].end())
                nt++;
            else
                nc++;
        }
        double ans = (double)nc / nt * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}
```

