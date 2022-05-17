# 1086 Tree Traversals Again

> part 4, 4.3



## 自己解法

- 莫名奇妙第一个和最后一个段错误
- 难道真的会有重复的值吗

```c++
#include <iostream>
using namespace std;
#include <stack>
#include <vector>

stack<int> d;
int inOrder[40];
vector<int> postOrder;

// 注意第一个root不是下标是1-N的实数
void getpost(int root, int begin, int end)
{
    if (begin > end)
        return;
    int i = begin;
    for (; i <= end; i++)
        if (inOrder[i] == root)
            break;
    getpost(root + 1, begin, i - 1);
    getpost(root + 1 + i - begin, i + 1, end);
    postOrder.push_back(root);
}

int main()
{
    int N;
    cin >> N;
    string s;
    int k, index = 1;
    // 按顺序就是preOrder, 出栈是inOrder
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> k;
            d.push(k);
        }
        else
        {
            inOrder[index++] = d.top();
            d.pop();
        }
    }
    // 下面就是根据preOrder(1-N), inOrder 得到postOrder就行
    getpost(1, 1, N);
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << postOrder[i];
        else
            cout << postOrder[i];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 她这里加了个key标识value

```c++
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
vector<int> pre, in, post,value;
void postorder(int root, int start, int end) {
    if (start > end) return;
    int i = start;
    while (i < end && in[i] != pre[root]) i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    char str[5];
    stack<int> s;
    int key=0;
    while (~scanf("%s", str)) {
        if (strlen(str) == 4) {
            int num;
            scanf("%d", &num);
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; i++)
        printf(" %d",value[post[i]]);
    return 0;
}
```

