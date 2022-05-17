# 1099 Build A Binary Search Tree

> part 4, 4.3



## 自己解法

- 排序后就是中序遍历
- 没写好

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int N, ind = 0;
int s[100], e[100];
vector<int> v[100];
void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        e[index] = s[ind++]; // index标识lever order的下标，ind标识输入排序的下标
        return;
    }
    else
        for (int i = 0; i < v[index].size(); i++)
        {
            bfs(v[index][i], depth + 1);
            e[index] = s[ind++];
        }
}
int main()
{
    cin >> N;
    int k1, k2;
    for (int i = 0; i < N; i++)
    {
        cin >> k1 >> k2;
        if (k1 != -1)
            v[i].push_back(k1);
        if (k2 != -1)
            v[i].push_back(k2);
    }
    for (int i = 0; i < N; i++)
        cin >> s[i];
    sort(s, s + N);
    bfs(0, 0);
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << e[i];
        else
            cout << e[i];
    cout << endl;
    system("pause");
    return 0;
}
```

- 模仿柳神

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int ind, maxDepth;
struct node
{
    int data, left, right;
} l[101];
int p[101];
vector<int> v[100];

void dfs(int index, int depth)
{
    maxDepth = max(maxDepth, depth);
    if (l[index].left != -1)
        dfs(l[index].left, depth + 1);
    l[index].data = p[ind];
    ind++;
    if (l[index].right != -1)
        dfs(l[index].right, depth + 1);
}

int main()
{
    ind = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> l[i].left >> l[i].right;
    for (int i = 0; i < N; i++)
        cin >> p[i];
    sort(p, p + N);
    dfs(0, 0);
    v[0].push_back(0);
    for (int i = 0; i <= maxDepth; i++)
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i != 0)
                cout << " " << l[v[i][j]].data;
            else
                cout << l[v[i][j]].data;
            if (l[v[i][j]].left != -1)
                v[i + 1].push_back(l[v[i][j]].left);
            if (l[v[i][j]].right != -1)
                v[i + 1].push_back(l[v[i][j]].right);
        }
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 1.用结构体data，left，right表示这棵树的结构，a数组存树的信息，b数组存这棵树节点的所有data，根据输入可知树a[i]的left和right～
- 因为是二叉搜索树，所以中序遍历这棵树得到的结点顺序应该是给出的数值序列从小到大的排列顺序，所以把数值序列排序后，可以在中序遍历的时候直接赋值当前a[root].data～同时可得知树的最大层数maxLevel的值～
- 二维数组v用来存储每一层的结点下标，一共有0到maxLevel层。用for循环从0开始一层层遍历v，就可以得到下一层的l和r，遍历过程中可以输出每个结点对应的data值a[v[i][j]].data～

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt, b[100], maxLevel;
struct node {
    int data, l, r;
}a[110];
vector<int> v[100];
void dfs(int root, int level) {
    maxLevel = max(level, maxLevel);
    if (a[root].l != -1) dfs(a[root].l, level + 1);
    a[root] = {b[cnt++], a[root].l, a[root].r};
    if (a[root].r != -1) dfs(a[root].r, level + 1);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n);
    dfs(0, 0);
    v[0].push_back(0);
    for (int i = 0; i <= maxLevel; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (i != 0) cout << " ";
            cout << a[v[i][j]].data;
            if(a[v[i][j]].l != -1) v[i+1].push_back(a[v[i][j]].l);
            if(a[v[i][j]].r != -1) v[i+1].push_back(a[v[i][j]].r);
        }
    }
    return 0;
}
```

