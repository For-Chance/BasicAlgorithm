# 1020 Tree Traversals

> part 4, 4.3



## 自己解法

- 经典把自己写糊涂了

```c++
#include <iostream>
using namespace std;
#include <vector>

int postOrder[30], inOrder[30];
vector<int> v[30];

// 这里的root标识在postOrder中的最后一名, begin 和 end 标识对应的inOrder的首尾
void getv(int root, int depth, int begin, int end)
{
    // 在对应的inOrder中搜寻root, N不大于30，可以直接搜
    int i = begin;
    for (; i <= end; i++)
        if (inOrder[i] == root)
            break; // 所得 i 为在inOrder中的root，从而把postOrder和inOrder分成两半

    int leftsize = i - begin;
    int rightsize = end - i;
    getv(i - 1, depth + 1, begin, i - 1);
    getv(end - 1, depth + 1, i + 1, end);
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> postOrder[i];
    for (int i = 0; i < N; i++)
        cin >> inOrder[i];
    getv(N - 1, 0, 0, N - 1);
    system("pause");
    return 0;
}
```

- 根据柳神的，自己写了一遍

```c++
#include <iostream>
using namespace std;
#include <map>

int postOrder[30], inOrder[30];
map<int, int> v; // 这里必须用map，不然的话不符合性质

void getv(int root, int begin, int end, int index)
{
    if (begin > end)
        return;
    int i = begin;
    for (; i <= end; i++)
        if (inOrder[i] == postOrder[root])
            break; // 所得 i 为在inOrder中的root，从而把postOrder和inOrder分成两半
    v[index] = postOrder[root];
    getv(root - 1 - (end - i), begin, i - 1, 2 * index + 1); // 注意第一个参数只跟postOrder有关，且只有这个参数与其有关，只能用这个参数与其他计算而来的数(right的大小)组合
    getv(root - 1, i + 1, end, 2 * index + 2);
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> postOrder[i];
    for (int i = 0; i < N; i++)
        cin >> inOrder[i];
    getv(N - 1, 0, N - 1, 0);
    for (auto it = v.begin(); it != v.end(); it++)
        if (it != v.begin())
            cout << " " << it->second;
        else
            cout << it->second;
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 我与柳神的差距就在这个map和index上
- 性质：==完全二叉树的层序遍历的序号，是左节点是2*root+1，右节点是2\*root+2==
- 这里有可能不是完全二叉树，所以使用map更好

```c++
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector<int> post, in;
map<int, int> level;
void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1); // 第一个参数标识root-1-right的长度
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    int n;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 0);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end()) printf(" %d", it->second);
    return 0;
}
```

