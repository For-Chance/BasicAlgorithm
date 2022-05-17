# 1053 Path of Equal Weight

> part 4, 4.3



## 自己解法

- 倒数第二个段错误，莫名其妙
  

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int S;

vector<int> v[101]; // 等价于 vector<vector<int>>v(100);
vector<int> w(101);
vector<int> path(100000, -1); // 某一次的合格结果
vector<vector<int>> s;      // 存储所有合格结果

void bfs(int index, int depth, int sum)
{
    if (sum > S)
    {
        path[depth] = -1;
        return;
    }
    else if (sum == S)
    {
        if (v[index].size() != 0)
        {
            path[depth] = -1;
            return;
        }
        s.push_back(path);
        path[depth] = -1;
        return;
    }
    else
    {
        if (v[index].size() == 0)
        {
            path[depth] = -1;
            return;
        }
        for (int i = 0; i < v[index].size(); i++)
        {
            path[depth + 1] = v[index][i];
            bfs(v[index][i], depth + 1, sum + w[v[index][i]]);
        }
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    int i = 0;
    while (i < a.size())
    {
        if (w[a[i]] != w[b[i]])
            return w[a[i]] > w[b[i]];
        i++;
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++)
        cin >> w[i];
    int id, cs, c;
    for (int i = 0; i < M; i++)
    {
        cin >> id >> cs;
        for (int j = 0; j < cs; j++)
        {
            cin >> c;
            v[id].push_back(c);
        }
    }
    path[0] = 0;
    bfs(0, 0, w[0]);
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; s[i][j] != -1; j++)
            if (j != 0)
                cout << " " << w[s[i][j]];
            else
                cout << w[s[i][j]];
        cout << endl;
    }
    bfs(0, 0, w[0]);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int target;
struct NODE {
    int w;
    vector<int> child;
};
vector<NODE> v;
vector<int> path;
void dfs(int index, int nodeNum, int sum) {
    if(sum > target) return ;
    if(sum == target) {
        if(v[index].child.size() != 0) return;
        for(int i = 0; i < nodeNum; i++)
            printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++) {
        int node = v[index].child[i];
        path[nodeNum] = node;
        dfs(node, nodeNum + 1, sum + v[node].w);
    }
    
}
int cmp1(int a, int b) {
    return v[a].w > v[b].w;
}
int main() {
    int n, m, node, k;
    scanf("%d %d %d", &n, &m, &target);
    v.resize(n), path.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i].w);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        v[node].child.resize(k);
        for(int j = 0; j < k; j++)
            scanf("%d", &v[node].child[j]);
        sort(v[node].child.begin(), v[node].child.end(), cmp1);
    }
    dfs(0, 1, v[0].w);
    return 0;
}
```

