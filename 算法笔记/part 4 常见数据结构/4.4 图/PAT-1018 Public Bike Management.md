# 1018 Public Bike Management

> part 4, 4.4



## 自己解法

- 还有四个点没过，应该是理解题目意思不到位了，很多地方没说清楚，尤其是最后的needbikes的数量，dfs那一段不要也是四个点没过

```c++
#include <iostream>
using namespace std;
int Cmax, N, Sp, M, perfectC;
int sentbikes, needbikes;
const int inf = 99999999;
int dis[510], pre[510], e[510][510], cb[510], tb[510], prenum[510]; // cb = current bikes tb= avg bikes
bool visit[510];

// node 对于所有的 最短路径
void Dijkstra(int node)
{
    for (int i = 0; i <= N; i++)
    {
        int min = -1, mindis = inf;
        for (int j = 0; j <= N; j++)
            if (dis[j] < mindis && visit[j] == false)
            {
                min = j;
                mindis = dis[j];
            }
        if (min == -1)
            break;
        visit[min] = true;
        for (int j = 0; j <= N; j++)
            if (e[min][j] != inf && visit[j] == false)
                if (dis[min] + e[min][j] < dis[j])
                {
                    dis[j] = dis[min] + e[min][j];
                    pre[j] = min;
                    prenum[j] = prenum[min] + 1; // 注意没有多算了 0 处
                    tb[j] = tb[min] + cb[j];
                }
                else if (dis[j] == dis[min] + e[min][j])
                {
                    double avg1 = double(tb[j]) / (prenum[j]);
                    double avg2 = double(tb[min] + cb[j]) / (prenum[min] + 1);
                    if (abs(avg1 - perfectC) > abs(avg2 - perfectC))
                    {
                        pre[j] = min;
                        prenum[j] = prenum[min] + 1;
                        tb[j] = tb[min] + cb[j];
                    }
                }
    }
}

void adjust(int node)
{
    if (node == 0)
    {
        cout << 0;
        return;
    }
    cb[node] = perfectC;
    adjust(pre[node]);
    cout << "->" << node;
}

void dfs(int node)
{
    visit[node] = true;
    if (cb[node] > Cmax)
    {
        needbikes += cb[node] - perfectC;
        cb[node] = perfectC;
    }
    for (int i = 0; i <= N; i++)
        if (visit[i] == false && e[node][i] != inf)
            dfs(i);
}

int main()
{
    cin >> Cmax >> N >> Sp >> M;
    perfectC = Cmax / 2;
    for (int i = 1; i <= N; i++) // 0没有赋值
        cin >> cb[i];
    int a, b, c;
    fill(e[0], e[0] + 510 * 510, inf);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    fill(dis, dis + 510, inf);
    // pre, tb, prenum 默认为0
    dis[0] = 0;
    Dijkstra(0);
    if (perfectC * (prenum[Sp]) - tb[Sp] > 0)
    {
        sentbikes = perfectC * (prenum[Sp]) - tb[Sp];
        needbikes = 0;
    }
    else
    {
        sentbikes = 0;
        needbikes = tb[Sp] - perfectC * (prenum[Sp]);
    }
    cout << sentbikes << " ";
    adjust(Sp);
    fill(visit, visit + 510, false);
    dfs(0);
    cout << " " << needbikes;
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
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;
void dfs(int v) {
    temppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    for(int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}
```

