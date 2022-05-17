# 1052 Linked List Sorting

> part 4, 4.1



## 自己解法

- 注意 s == -1，全为脏数据时；还有一种情况应该是节点不在链表内，这种用排序就不好做了
- 并没有使用链表，当作排序题也可以做

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct node
{
    int addr;
    int value;
    int next;
};

bool cmp(node a, node b)
{
    return a.value < b.value;
}

int main()
{
    int N, s;
    cin >> N >> s;
    vector<node> d(N);
    for (int i = 0; i < N; i++)
        cin >> d[i].addr >> d[i].value >> d[i].next;
    sort(d.begin(), d.end(), cmp);
    if (N == 0 || s == -1)
        cout << 0 << " " << -1 << endl;
    else
    {
        printf("%d %05d\n", N, d[0].addr);
        int i;
        for (i = 0; i < N - 1; i++)
        {
            printf("%05d %d %05d\n", d[i].addr, d[i].value, d[i + 1].addr);
        }
        printf("%05d %d %d\n", d[i].addr, d[i].value, -1);
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- 建立结构体数组，按照从首地址开始的顺序（直到-1）遍历一遍整个链表，将在链表中的结点的flag标记为true，并且统计cnt（有效结点的个数）。（因为有的结点根本不在链表中）

  然后将链表进行排序，如果flag == false就把他们移动到后面（即：reuturn a.flag > b.flag）,最后只输出前cnt个链表的信息～

- ==太秀了==

```c++
#include <iostream>
#include <algorithm>
using namespace std;
struct NODE {
    int address, key, next;
    bool flag;
}node[100000];
int cmp1(NODE a, NODE b) {
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}
int main() {
    int n, cnt = 0, s, a, b, c;
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        node[a] = {a, b, c, false};
    }
    for(int i = s; i != -1; i = node[i].next) {
        node[i].flag = true;
        cnt++;
    }
    if(cnt == 0) {
        printf("0 -1");
    } else {
        sort(node, node + 100000, cmp1);
        printf("%d %05d\n", cnt, node[0].address);
        for(int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].address, node[i].key);
            if(i != cnt - 1)
                printf("%05d\n", node[i + 1].address);
            else
                printf("-1\n");
        }
    }
    return 0;
}
```

