# 1021 Deepest Root

> part 4, 4.4



## 自己解法

- acyclic 无环的
- 只有两个AC

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int N;
bool v[10001][10001], visit[10001];
vector<int> dr;

// 注意题目说了图是无环的；
void dfs(int node)
{
    visit[node] = true;
    int flag = 0;
    for (int i = 1; i <= N; i++)
        if (visit[i] == false && v[node][i] == true)
        {
            flag = 1;
            dfs(i);
        }
    if (!flag)
        dr.push_back(node);
}

int main()
{
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        v[a][b] = v[b][a] = true;
    }
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        visit[i] = true;
        int flag = 0;
        for (int j = 1; j <= N; j++)
            if (visit[j] == false && v[i][j] == true)
            {
                dfs(j);
                flag = 1;
            }
        if (flag == 1)
            count++;
    }
    if (count > 1)
        printf("Error: %d components\n", count);
    else
    {
        sort(dr.begin(), dr.end());
        for (int i = 0; i < dr.size(); i++)
            cout << dr[i] << endl;
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- **首先深度优先搜索判断它有几个连通分量。如果有多个，那就输出Error: x components，如果只有一个，就两次深度优先搜索，先从一个结点dfs后保留最高高度拥有的结点们，然后从这些结点中的其中任意一个开始dfs得到最高高度的结点们，这两个结点集合的并集就是所求**

```c++
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> temp;
void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for(int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
```

