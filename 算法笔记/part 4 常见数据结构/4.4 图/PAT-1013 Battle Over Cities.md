# 1013 Battle Over Cities

> part 4, 4.4



## 自己解法

- 看懂了柳神后写的

```c++
#include <iostream>
using namespace std;
bool v[1001][1001], visit[1001];
int N, M, K;

// node表示当前开始dfs的节点
void dfs(int node)
{
    visit[node] = true;
    for (int i = 1; i <= N; i++)
        if (v[node][i] == true && visit[i] == false) // 尚未访问过,并且直接链接的点
            dfs(i);
}

int main()
{
    cin >> N >> M >> K;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v[a][b] = v[b][a] = true; // 注意这里没有填对角线上的，不过应该可以通过visit过滤掉这些
    }
    for (int i = 0; i < K; i++)
    {
        fill(visit, visit + 1000, false);
        cin >> a;
        int count = 0;
        visit[a] = true;
        for (int j = 1; j <= N; j++)
            if (visit[j] == false)
            {
                dfs(j);
                count++;
            }
        // 图的性质：a个非连通图之间只需要a-1个通路即可全部联通
        cout << count - 1 << endl;
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- 添加的最少的路线，就是他们的连通分量数-1，因为当a个互相分立的连通分量需要变为连通图的时候，只需要添加a-1个路线，就能让他们相连。所以这道题就是求去除了某个结点之后其他的图所拥有的连通分量数

  使用邻接矩阵存储，对于每一个被占领的城市，去除这个城市结点，就是把它标记为已经访问过，这样在深度优先遍历的时候，对于所有未访问的结点进行遍历，就能求到所有的连通分量的个数～记得因为有很多个要判断的数据，每一次输入被占领的城市之前要把visit数组置为false～

```c++
#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
```

