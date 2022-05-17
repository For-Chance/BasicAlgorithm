# 1034 Head of a Gang

> part 4, 4.4



## 自己解法

- 最后有一个按字母排序输出，用map存储，==map会自动排序==
- 本来有一个段错误，第10行由1001改成10001就过了（==有n条通话记录（n<=1000）但是最多会有2000个结点==）

```c++
#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <algorithm>
int N, K, allNames;
vector<string> name;                // 每个人的名字索引
map<int, int> w;                    // 存放每个人的权重，前一个是名字的索引
vector<vector<int>> gangs;          // 存放帮派，放名字的索引
bool v[10001][10001], visit[10001]; // 邻接矩阵以及判断
map<string, int> res;

void dfs(int node, int index)
{
    visit[node] = true;
    gangs[index].push_back(node);
    for (int i = 0; i < allNames; i++)
        if (visit[i] == false && v[node][i] == true)
            dfs(i, index);
}

int main()
{
    cin >> N >> K;
    string N1, N2;
    int time;
    for (int i = 0; i < N; i++)
    {
        cin >> N1 >> N2 >> time;
        int x1, x2;
        auto pos1 = find(name.begin(), name.end(), N1);
        if (pos1 == name.end())
        {
            name.push_back(N1);
            x1 = name.size() - 1;
            w.insert(make_pair(x1, time));
        }
        else
        {
            x1 = pos1 - name.begin();
            w[x1] += time;
        }
        auto pos2 = find(name.begin(), name.end(), N2);
        if (pos2 == name.end())
        {
            name.push_back(N2);
            x2 = name.size() - 1;
            w.insert(make_pair(x2, time));
        }
        else
        {
            x2 = pos2 - name.begin();
            w[x2] += time;
        }
        v[x1][x2] = v[x2][x1] = true;
    }
    // 挑选帮派(两个人也算上)
    allNames = name.size();
    for (int i = 0; i < allNames; i++)
    {
        if (visit[i] == true)
            continue;
        visit[i] = true;
        vector<int> a;
        a.push_back(i);
        gangs.push_back(a);
        int index = gangs.size() - 1;
        auto x = gangs.begin() + index;
        for (int j = 0; j < allNames; j++)
            if (visit[j] == false && v[i][j] == true)
                dfs(j, index);
        if (gangs[index].size() <= 2)
        {
            gangs.erase(x);
            continue;
        }
        int score = 0;
        for (int j = 0; j < gangs[index].size(); j++)
            score += w[gangs[index][j]];
        if ((score / 2) <= K)
            gangs.erase(x);
    }
    int gsize = gangs.size();
    cout << gsize << endl;
    if (gsize != 0)
    {
        for (int i = 0; i < gsize; i++)
        {
            int max = -1, maxj = -1;
            for (int j = 0; j < gangs[i].size(); j++)
                if (w[gangs[i][j]] > max)
                {
                    max = w[gangs[i][j]];
                    maxj = gangs[i][j];
                }
            res.insert(make_pair(name[maxj], gangs[i].size()));
        }
        for (auto it = res.begin(); it != res.end(); it++)
            cout << it->first << " " << it->second << endl;
    }

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 总的来说是一个判断一个图的连通分量的个数，用图的遍历解决，深度优先遍历
  1.因为给的是字母，要用两个map把它们转换成数字，从1开始排列命名所有不同的人的id，存储在两个map里面，一个字符串对应id，一个id对应字符串，方便查找，正好顺便统计了总共的人数idNumber。
  2.建立两个数组，weight和G，分别存储每条边的权值和每个结点的权值，因为这两个题目中都要求得后判断。
  3.用传递引用的方法深度优先dfs，这样传入的参数在dfs后还能保存想要求得的值
  4.遍历过一条边之后就把这条边的权值设为0（ G[u][v] = G[v][u] = 0;）防止出现回路遍历死循环

```c++
#include <iostream>
#include <map>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int idNumber = 1, k;
int stoifunc(string s) {
    if(stringToInt[s] == 0) {
        stringToInt[s] = idNumber;
        intToString[idNumber] = s;
        return idNumber++;
    } else {
        return stringToInt[s];
    }
}
int G[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMember, int &totalweight) {
    vis[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1; v < idNumber; v++) {
        if(G[u][v] > 0) {
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}
void dfsTrave() {
    for(int i = 1; i < idNumber; i++) {
        if(vis[i] == false) {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k)
                ans[intToString[head]] = numMember;
        }
    }
}
int main() {
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = stoifunc(s1);
        int id2 = stoifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfsTrave();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
```

