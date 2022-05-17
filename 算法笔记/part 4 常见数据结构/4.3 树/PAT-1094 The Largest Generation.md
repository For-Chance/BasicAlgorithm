# 1094 The Largest Generation

> part 4, 4.3



## 自己解法

- dfs和bfs都可以做

```c++
#include <iostream>
using namespace std;
#include <vector>
int count[100];

vector<int> v[101];

void bfs(int index, int depth)
{
    if (count[depth] == -1)
        count[depth] = 0;
    else
        count[depth]++;
    if (v[index].size() == 0)
        return;
    else
        for (int i = 0; i < v[index].size(); i++)
            bfs(v[index][i], depth + 1);
}

int main()
{
    int N, M;
    cin >> N >> M;
    int index, k, c;
    for (int i = 0; i < M; i++)
    {
        cin >> index >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            v[index].push_back(c);
        }
    }
    bfs(1, 1);
    int ix, maxGen = -1;
    for (int i = 1; count[i] != 0; i++)
        if (count[i] > maxGen)
        {
            ix = i;
            maxGen = count[i];
        }
    cout << maxGen << " " << ix << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- bfs，写的有点乱，不如dfs清晰

```c++
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];
int level[100];
int book[100];
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        book[level[index]]++;
        for(int i = 0; i < v[index].size(); i++) {
            level[v[index][i]] = level[index] + 1;
            q.push(v[index][i]);
        }
        
    }
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}
```

