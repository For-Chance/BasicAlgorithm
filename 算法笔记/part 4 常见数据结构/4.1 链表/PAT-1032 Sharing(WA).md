# 1032 Sharing

> part 4, 4.1



## 自己解法

- 一个地址只能导向一个地址，因此两个地址可以指向相同的地址，但是一个地址却不能指向不同的地址
- 3 TO 5 WA

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct node
{
    char n;
    int back;
} l[100000];

string getword(int s)
{
    int addr = s;
    string a = "";
    while (l[addr].back != -1)
    {
        a += l[addr].n;
        addr = l[addr].back;
    }
    a += l[addr].n;
    return a;
}

int main()
{
    int s1, s2, N;
    cin >> s1 >> s2 >> N;
    int address;
    for (int i = 0; i < N; i++)
    {
        cin >> address;
        cin >> l[address].n >> l[address].back;
    }
    string w1 = getword(s1);
    string w2 = getword(s2);
    reverse(w1.begin(), w1.end());
    reverse(w2.begin(), w2.end());
    int i = 0;
    for (; i < w1.length(); i++)
        if (w1[i] != w2[i])
            break;
    if (i == 0)
        cout << -1 << endl;
    else
    {
        int index = w1.length() - i; // 标识了w1的第几个单词是sharing的开头
        int addr = s1, j;
        for (j = 0; j < index; j++)
            addr = l[addr].back;
        printf("%05d\n", addr);
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- **遍历第一条链表，将访问过的结点的flag都标记为true，当遍历第二条结点的时候，如果遇到了true的结点就输出并结束程序，没有遇到就输出-1**
- ==太秒了==

```c++
#include <cstdio>
using namespace std;
struct NODE {
    char key;
    int next;
    bool flag;
}node[100000];
int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for(int i = s1; i != -1; i = node[i].next)
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
```

