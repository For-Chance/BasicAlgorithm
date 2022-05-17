# 1043 Is It a Binary Search Tree

> part 4, 4.3



## 自己解法

```c++
#include <iostream>
using namespace std;
#include <vector>

bool isM = false;
vector<int> pre, post;

void getpost(int root, int tail)
{
    int i = root + 1, j = tail;
    if (!isM)
    {
        while (i <= tail && pre[i] < pre[root])
            i++;
        while (j > root && pre[j] >= pre[root])
            j--;
    }
    else
    {
        while (i <= tail && pre[i] >= pre[root])
            i++;
        while (j > root && pre[j] < pre[root])
            j--;
    }
    if (i - j != 1)
        return;
    getpost(root + 1, i - 1);  // 先执行 left 部分，push_back 5 7 6, 然后 push_back 8 11 10
    getpost(j + 1, tail);      // 镜像的话, push_back 11 8 10, 然后 push_back 7 5 6
    post.push_back(pre[root]); // 最后 push_back 8
}

int main()
{
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        pre.push_back(k);
    }
    getpost(0, n - 1);
    if (post.size() != n)
    {
        isM = true;
        post.clear();
        getpost(0, n - 1);
    }
    if (post.size() == n)
    {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; i++)
            printf(" %d", post[i]);
    }
    else
    {
        printf("NO");
    }
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 假设它是二叉搜索树，一开始isMirror为false，根据二叉搜索树的性质将已知的前序转换为后序，转换过程中，如果发现最后输出的后序数组长度不为n，那就设isMirror为true，然后清空后序数组，重新再转换一次（根据镜面二叉搜索树的性质），如果依旧转换后数组大小不等于n，就输出NO否则输出YES
- bool类型默认false(0)
- 前序遍历的基本顺序是：root -> left -> right，而后序遍历的基本顺序是：left -> right -> root。
  所以每个前序序列可以分隔为：root + left + right。
  我们的任务就是将这个结构分隔开，将root放在后面，变成 left + right + root。

```c++
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++; // 这里找到left是[root+1,i)
        while(j > root && pre[root] <= pre[j]) j--; // 这里找到right是(j,tail]
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}
```

