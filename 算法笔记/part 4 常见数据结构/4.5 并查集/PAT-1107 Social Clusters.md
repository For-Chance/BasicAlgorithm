# 1107 Social Clusters

> part 4, 4.5



## 题意理解

- **有n个人，每个人喜欢k个活动，如果两个人有任意一个活动相同，就称为他们处于同一个社交网络。求这n个人一共形成了多少个社交网络～**
- 新加入一个人，看是否在目前的圈子，如果有，那么就加入，如果没有，就新增一个

### Sample Input:

```in
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
```

### Sample Output:

```out
3
4 3 1
```



## 自己解法

- 基本的Dijstra算法套路
- 手生，写费了一个代码

```c++
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
const int inf = 99999;
struct node
{
    string name;
    int happiness, distance;
    int total_happiness;
};

vector<node> v(210);
int e[210][210], pre[210];
bool visit[210];
string result;
int length;

void dfs(int j)
{
    if (j == 0)
    {
        result += v[0].name;
        return;
    }
    dfs(pre[j]);
    result += "->" + v[j].name;
    length++;
}

int main()
{
    int N, K;
    cin >> N >> K >> v[0].name;
    v[0].happiness = 0;
    v[0].distance = 0;
    v[0].total_happiness = 0;
    int dest, count = 1;
    for (int i = 1; i < N; i++)
    {
        cin >> v[i].name >> v[i].happiness;
        v[i].distance = inf;
        v[i].total_happiness = v[i].total_happiness;
        if (v[i].name == "ROM")
            dest = i;
    }
    fill(e[0], e[0] + 210 * 210, inf);
    for (int i = 0; i < N; i++)
    {
        string str1, str2;
        int c;
        cin >> str1 >> str2 >> c;

        // e[a][b] = e[b][a] = c;
    }
    fill(pre, pre + 210, 0);
    // dijkstra
    for (int i = 0; i < N; i++)
    {
        int minj = -1, mindis = inf;
        for (int j = 0; j < N; j++)
        {
            if (mindis > v[j].distance && visit[j] == false)
            {
                minj = j;
                mindis = v[j].distance;
            }
        }
        if (minj == -1)
            break;
        visit[minj] = true;
        for (int j = 0; j < N; j++)
        {
            if (e[minj][j] != inf && visit[j] == false)
            {
                if (v[j].distance > v[minj].distance + e[minj][j])
                {
                    v[j].distance = v[minj].distance + e[minj][j];
                    pre[j] = minj;
                    v[j].total_happiness = v[j].happiness + v[minj].total_happiness;
                    if (j == dest)
                        count = 1;
                }
                else if (v[j].distance == v[minj].distance + e[minj][j])
                {
                    if (v[j].total_happiness < v[j].happiness + v[minj].total_happiness)
                    {
                        pre[j] = minj;
                        v[j].total_happiness = v[j].happiness + v[minj].total_happiness;
                        if (j == dest)
                            count++;
                    }
                }
            }
        }
    }
    cout << count << " " << v[dest].distance << " " << v[dest].distance << " ";
    result = "";
    length = 0;
    dfs(dest);
    cout << length << endl
         << result << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 思想是一样的

```c++
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int inf = 999999999;
int e[205][205], weight[205], dis[205];
bool visit[205];
vector<int> pre[205], temppath, path;
map<string, int> m;
map<int, string> m2;
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {
    temppath.push_back(v);
    if(v == 1) {
        int value = 0;
        for(int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if(value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if(value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for(int i = 1; i < n; i++) {
        cin >> s >> weight[i+1];
        m[s] = i+1;
        m2[i+1] = s;
    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    dis[1] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}
```

