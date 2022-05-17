# 1064 Complete Binary Search Tree

> part 4, 4.3



## 自己解法

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int x, N;
int t[1000], s[1000];

void inOrder(int root)
{
    if (root >= N)
        return;
    inOrder(2 * root + 1);
    s[root] = t[x++];
    inOrder(2 * root + 2);
}

int main()
{
    x = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> t[i];
    sort(t, t + N);
    inOrder(0);
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << s[i];
        else
            cout << s[i];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- **总得概括来说，已知中序，从根节点开始中序遍历，按中序数组给出的顺序依次将值填入level数组对应的下标中，输出level数组可得层序遍历。**
  **1. 因为二叉搜索树的中序满足：是一组序列的从小到大排列，所以只需将所给序列排序即可得到中序数组in**
  **2. 假设把树按从左到右、从上到下的顺序依次编号，根节点为0，则从根结点root = 0开始中序遍历，root结点的左孩子下标是root\*2+1，右孩子下标是root\*2+2**

  **3. 因为是中序遍历，所以遍历结果与中序数组in中的值从0开始依次递增的结果相同，即in[t++]（t从0开始），将in[t++]赋值给level[root]数组**
  **4. 因为树是按从左到右、从上到下的顺序依次编号的，所以level数组从0到n-1的值即所求的层序遍历的值，输出level数组即可～**

```c++
#include <iostream>
#include <algorithm>
using namespace std;
int in[1010], level[1010], n, t = 0;
void inOrder(int root) {
    if (root >= n) return ;
    inOrder(root * 2 + 1);
    level[root] = in[t++];
    inOrder(root * 2 + 2);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    sort(in, in + n);
    inOrder(0);
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}
```

