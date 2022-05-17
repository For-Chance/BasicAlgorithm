# 1102 Invert a Binary Tree

> part 4, 4.3



## 自己解法

- 多熟悉熟悉各种遍历就行hhh，注意levelOrder的性质就行

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

struct node
{
    int left = -1;
    int right = -1;
} n[10];

vector<int> in;
map<int, int> level;

// root是n[]的下标，也是具体代表的值
void getlevel(int root, int index)
{
    level[index] = root;
    if (n[root].left == -1 && n[root].right == -1)
        return;
    if (n[root].left != -1)
        getlevel(n[root].left, 2 * index + 1);
    if (n[root].right != -1)
        getlevel(n[root].right, 2 * index + 2);
}

void getin(int root)
{
    if (n[root].left == -1 && n[root].right == -1)
    {
        in.push_back(root);
        return;
    }
    if (n[root].left != -1)
        getin(n[root].left);
    in.push_back(root);
    if (n[root].right != -1)
        getin(n[root].right);
}

int main()
{
    int N;
    cin >> N;
    char c1, c2;
    vector<int> root(N, 1);
    for (int i = 0; i < N; i++)
    {
        // 输入这就把node变成镜像；
        cin >> c1 >> c2;
        if (isdigit(c2))
        {
            n[i].left = c2 - '0';
            root[c2 - '0'] = 0;
        }
        if (isdigit(c1))
        {
            n[i].right = c1 - '0';
            root[c1 - '0'] = 0;
        }
    }
    auto begin = find(root.begin(), root.end(), 1);
    int j = begin - root.begin();
    getlevel(j, 0);
    getin(j);
    for (auto it = level.begin(); it != level.end(); it++)
        if (it != level.begin())
            cout << " " << it->second;
        else
            cout << it->second;
    cout << endl;
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << in[i];
        else
            cout << in[i];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 二叉树的遍历其实就是bfs的二叉树情况

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, l, r, index, level;
} a[100];
vector<node> v1;
void dfs(int root, int index, int level) {
    if (a[root].r != -1) dfs(a[root].r, index * 2 + 2, level + 1);
    v1.push_back({root, 0, 0, index, level});
    if (a[root].l != -1) dfs(a[root].l, index * 2 + 1, level + 1);
}
bool cmp(node a, node b) {
    if (a.level != b.level) return a.level < b.level;
    return a.index > b.index;
}
int main() {
    int n, have[100] = {0}, root = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        } else {
            a[i].l = -1;
        }
        if (r != "-") {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        } else {
            a[i].r = -1;
        }
    }
    while (have[root] == 1) root++;
    dfs(root, 0, 0);
    vector<node> v2(v1);
    sort(v2.begin(), v2.end(), cmp);
    for (int i = 0; i < v2.size(); i++) {
        if (i != 0) cout << " ";
        cout << v2[i].id;
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++) {
        if (i != 0) cout << " ";
        cout << v1[i].id;
    }
    return 0;
}
```

