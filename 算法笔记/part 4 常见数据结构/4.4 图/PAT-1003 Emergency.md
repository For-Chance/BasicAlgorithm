# 1003 Emergency

> part 4, 4.4



## 自己解法

- 

```c++
#include <iostream>
using namespace std;
#include <algorithm>
const int inf = 999999999;
int n, m, c1, c2;
int weight[510], e[510][510], dis[510], w[510], num[510];
bool visit[510];

int main()
{
    // 输入
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    fill(e[0], e[0] + 510 * 510, inf);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    // 赋初值
    fill(dis, dis + 510, inf);
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    // 寻找最短路径
    // 第一次的最短路径是自己
    for (int i = 0; i < n; i++)
    {
        // dis 查找
        int min = -1, mindis = inf;
        for (int j = 0; j < n; j++)
            if (dis[j] < mindis && visit[j] == false)
            {
                min = j;
                mindis = dis[j];
            }
        // 如果在dis中没有找到最短路径也就说都找完了，visit都是true，这时候break
        if (min == -1)
            break;
        visit[min] = true;
        // 更新 dis w num
        for (int j = 0; j < n; j++)
            if (e[min][j] != inf && visit[j] == false)
            {
                if (dis[j] > dis[min] + e[min][j])
                {
                    // 本来直接联通j的路径小于通过min再联通j的路径
                    // dis直接更新
                    // 救援队的数量w相当于min的救援队(根据min联通的救援队有多条)再加上自身的救援队
                    // 路径数量是到min的路径数量(在这个条件下，min到j就是一条)；
                    dis[j] = dis[min] + e[min][j];
                    w[j] = w[min] + weight[j];
                    num[j] = num[min];
                }
                else if (dis[j] == dis[min] + e[min][j])
                {
                    // 有路径相等
                    // dis 不更新
                    // w和num更新
                    // 救援队是在点上，路径是在线上，在线上的可以直接加
                    // 路径数量加上到min的路径数量
                    // 救援队的数量相当于多了个点min，
                    num[j] += num[min];
                    // 注意min是刚刚所选的dis中最小的，并设置了visit，因此它的w是包含其他所有已经visit的了
                    if (w[j] < w[min] + weight[j])
                        w[j] = w[min] + weight[j];
                }
            }
    }
    cout << num[c2] << " " << w[c2] << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 用一遍Dijkstra算法～救援小组个数相当于点权，用Dijkstra求边权最小的最短路径的条数，以及这些最短路径中点权最大的值～dis[i]表示从出发点到i结点最短路径的路径长度，num[i]表示从出发点到i结点最短路径的条数，w[i]表示从出发点到i点救援队的数目之和～当判定dis[u] + e\[u][v] < dis[v]的时候，不仅仅要更新dis[v]，还要更新num[v] = num[u], w[v] = weight[v] + w[u]; 如果dis[u] + e\[u][v] == dis[v]，还要更新num[v] += num[u]，而且判断一下是否权重w[v]更小，如果更小了就更新w[v] = weight[v] + w[u]; 

```c++
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]); // 这里的weight是能到的救援队的数量，不是路径
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) { // 寻找尚未visit的点中距离原始节点最小的，为u，距离为minn
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) { // 如果尚未visit并且与u相连
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}
```

