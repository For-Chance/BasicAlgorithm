# 1051 Pop Sequence

> part 4, 4.0



## 自己解法

- 

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main()
{
    int N, M, K, flag = 1;
    cin >> N >> M >> K;
    vector<int> d(M + 1);
    stack<int> s;
    for (int i = 0; i < K; i++)
    {
        int pu = 0, size = 0;
        for (int j = 1; j < M; j++)
        {
            cin >> d[j];
            while (pu++ == d[j])
            {
                s.push(pu);
                size++;
            }
            s.pop();
            size--;
        }
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        int current = 1;
        for(int j = 1; j <= n; j++) {
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[current]) {
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
```

