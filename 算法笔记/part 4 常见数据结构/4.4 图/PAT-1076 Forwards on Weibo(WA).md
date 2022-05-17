# 1076 Forwards on Weibo

> part 4, 4.4



## 自己解法

- 两个没过

```c++
#include <iostream>
using namespace std;
#include <vector>
int N, maxdepth;
bool v[1001][1001], visit[1001]; // v[a][b] == true 表示，a follows b
vector<int> res;

void dfs(int node, int depth)
{
    if (depth > maxdepth)
        return;
    visit[node] = true;
    res.push_back(node);
    for (int i = 1; i <= N; i++)
        if (v[i][node] == true && visit[i] == false)
            dfs(i, depth + 1);
}

int main()
{
    cin >> N >> maxdepth;
    int k, c;
    for (int i = 1; i <= N; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> c;
            v[i][c] = true;
        }
    }
    int K, C;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        fill(visit, visit + 1001, false);
        cin >> C;
        visit[C] = true;
        res.clear();
        for (int j = 1; j <= N; j++)
            if (v[j][C] == true && visit[j] == false)
                dfs(j, 1);
        cout << res.size() << endl;
    }
    system("pause");
    return 0;
}
```

- 照着柳神写bfs



## 大神解法

- 柳神
- **带层数的广度优先，因为一个用户只能转发一次，所以用inq判断当前结点是否入队过了，如果入队过了就不能重复入队（重复转发消息），inq 邻接表v 都可以使用int只存储id，queue的数据类型必须为node，同时保存它的id和layer层数，控制不超过L层～**

```c++
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, l, m, k;
struct node {
    int id, layer;
};
vector<vector<int>> v;
int bfs(node tnode) {
    bool inq[1010] = {false};
    queue<node> q;
    q.push(tnode);
    inq[tnode.id] = true;
    int cnt = 0;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        int topid = top.id;
        for(int i = 0; i < v[topid].size(); i++) {
            int nextid = v[topid][i];
            if(inq[nextid] == false && top.layer < l) {
                node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
        }
    }
    return cnt;
}
 
int main() {
    scanf("%d %d", &n, &l);
    v.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            v[temp].push_back(i);
        }
    }
    scanf("%d", &k);
    int tid;
    for(int i = 0; i < k; i++) {
        scanf("%d", &tid);
        node tnode = {tid, 0};
        printf("%d\n", bfs(tnode));
    }
    return 0;
}
```

