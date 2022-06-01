# 1111 Online Map

> part 4, 4.4



## 题意理解

- 找出距离和用时最短的路径
- 最后一个没超时，但是过不了

### Sample Input 1:

```in
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
```

### Sample Output 1:

```out
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
```

### Sample Input 2:

```in
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
```



## 自己解法

- 基本的Dijstra算法套路

```c++
#include <bits/stdc++.h>
using namespace std;
const int inf = 9999999;
class Solution
{
public:
    vector<int> Djistra_dis(vector<vector<vector<int>>> &v, int &source, int &dest)
    {
        int N = v.size();
        vector<int> dis(N, inf);
        vector<int> pre(N, source);
        vector<bool> visit(N, false);
        dis[source] = 0;
        for (int i = 0; i < N; i++)
        {
            int mindis = inf, minj = -1;
            for (int j = 0; j < N; j++)
                if (mindis > dis[j] && visit[j] == false)
                {
                    mindis = dis[j];
                    minj = j;
                }
            if (minj == -1)
                break;
            visit[minj] = true;
            for (int j = 0; j < N; j++)
            {
                if (v[minj][j][0] != inf && visit[j] == false)
                {
                    if (dis[j] > dis[minj] + v[minj][j][0])
                    {
                        dis[j] = dis[minj] + v[minj][j][0];
                        pre[j] = minj;
                    }
                    else if (dis[j] == dis[minj] + v[minj][j][0])
                    {
                        dis[j] == dis[minj] + v[minj][j][0];
                        int temp = pre[j];
                        int res1 = tracebackTime(v, pre, j, source, 0);
                        pre[j] = minj;
                        int res2 = tracebackTime(v, pre, j, source, 0);
                        if (res1 < res2)
                            pre[j] = temp;
                    }
                }
            }
        }
        vector<int> result;
        result.push_back(dis[dest]);
        traceback(pre, dest, source, result);
        return result;
    }

    vector<int> Djistra_time(vector<vector<vector<int>>> &v, int &source, int &dest)
    {
        int N = v.size();
        vector<int> cost(N, inf);
        vector<int> pre(N, source);
        vector<bool> visit(N, false);
        cost[source] = 0;
        for (int i = 0; i < N; i++)
        {
            int mindis = inf, minj = -1;
            for (int j = 0; j < N; j++)
                if (mindis > cost[j] && visit[j] == false)
                {
                    mindis = cost[j];
                    minj = j;
                }
            if (minj == -1)
                break;
            visit[minj] = true;
            for (int j = 0; j < N; j++)
            {
                if (v[minj][j][0] != inf && visit[j] == false)
                {
                    if (cost[j] > cost[minj] + v[minj][j][1])
                    {
                        cost[j] = cost[minj] + v[minj][j][1];
                        pre[j] = minj;
                    }
                }
                else if (cost[j] == cost[minj] + v[minj][j][0])
                {
                    cost[j] == cost[minj] + v[minj][j][0];
                    int temp = pre[j];
                    int res1 = tracebackTime(v, pre, j, source, 0);
                    pre[j] = minj;
                    int res2 = tracebackTime(v, pre, j, source, 0);
                    if (res1 < res2)
                        pre[j] = temp;
                }
            }
        }
        vector<int> result;
        result.push_back(cost[dest]);
        traceback(pre, dest, source, result);
        return result;
    }

    void traceback(vector<int> &pre, int now, int &target, vector<int> &result)
    {
        if (now == target)
        {
            result.push_back(now);
            return;
        }
        traceback(pre, pre[now], target, result);
        result.push_back(now);
    }

    int tracebackTime(vector<vector<vector<int>>> &v, vector<int> &pre, int now, int &target, int cost)
    {
        if (now == target)
        {
            return cost;
        }
        return tracebackTime(v, pre, pre[now], target, cost + v[pre[now]][now][1]);
    }

    int tracebackDis(vector<vector<vector<int>>> &v, vector<int> &pre, int now, int &target, int cost)
    {
        if (now == target)
        {
            return cost;
        }
        return tracebackDis(v, pre, pre[now], target, cost + v[pre[now]][now][0]);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    // 创建一个 N*N*2 的矩阵
    vector<vector<vector<int>>> v(N, vector<vector<int>>(N, vector<int>(2, inf)));
    int v1, v2, one_way, length, time;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> one_way >> length >> time;
        if (one_way == 0)
        {
            v[v1][v2][0] = v[v2][v1][0] = length;
            v[v1][v2][1] = v[v2][v1][1] = time;
        }
        else
        {
            v[v1][v2][0] = length;
            v[v1][v2][1] = time;
        }
    }
    int source, dest;
    cin >> source >> dest;
    Solution solution;
    vector<int> res1, res2;
    res1 = solution.Djistra_dis(v, source, dest);
    res2 = solution.Djistra_time(v, source, dest);
    bool flag = true;
    if (res1.size() != res2.size())
        flag = false;
    if (flag == true)
    {
        int n = res1.size();
        for (int i = 1; i < n; i++)
        {
            if (res1[i] != res2[i])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag == false)
    {
        cout << "Distance = " << res1[0] << ": " << res1[1];
        for (int i = 2; i < res1.size(); i++)
            cout << " -> " << res1[i];
        cout << endl;
        cout << "Time = " << res2[0] << ": " << res2[1];
        for (int i = 2; i < res2.size(); i++)
            cout << " -> " << res2[i];
    }
    else
    {
        cout << "Distance = " << res1[0] << "; ";
        cout << "Time = " << res2[0] << ": " << res2[1];
        for (int i = 2; i < res2.size(); i++)
            cout << " -> " << res2[i];
    }
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 思想是一样的

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 999999999;
int dis[510], Time[510], e[510][510], w[510][510], dispre[510],Timepre[510], weight[510],NodeNum[510];
bool visit[510];
vector<int> dispath, Timepath, temppath;
int st, fin, minnode = inf;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == st) return ;
    dfsdispath(dispre[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == st) return ;
    dfsTimepath(Timepre[v]);
}
int main() {
    fill(dis, dis + 510, inf);
    fill(Time, Time + 510, inf);
    fill(weight, weight + 510, inf);
    fill(e[0], e[0] + 510 * 510, inf);
    fill(w[0], w[0] + 510 * 510, inf);
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b, flag, len, t;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
        e[a][b] = len;
        w[a][b] = t;
        if(flag != 1) {
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    scanf("%d %d", &st, &fin);
    dis[st] = 0;
    for(int i = 0; i < n; i++)
        dispre[i] = i;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                } else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]) {
                    weight[v] = weight[u] + w[u][v];
                    dispre[v] = u;
                }
            }
        }
    }
    dfsdispath(fin);
    Time[st] = 0;
    fill(visit, visit + 510, false);
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && minn > Time[j]) {
                u = j;
                minn = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && w[u][v] != inf) {
                if(w[u][v] + Time[u] < Time[v]) {
                    Time[v] = w[u][v] + Time[u];
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                } else if(w[u][v] + Time[u] == Time[v]&&NodeNum[u]+1<NodeNum[v]) {
                    Timepre[v]=(u);
                    NodeNum[v]=NodeNum[u]+1;
                }
            }
        }
    }
    dfsTimepath(fin);
    printf("Distance = %d", dis[fin]);
    if(dispath == Timepath) {
        printf("; Time = %d: ", Time[fin]);
    } else {
        printf(": ");
        for(int i = dispath.size() - 1; i >= 0; i--) {
            printf("%d", dispath[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", Time[fin]);
    }
    for(int i = Timepath.size() - 1; i >= 0; i--) {
        printf("%d", Timepath[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}
```

