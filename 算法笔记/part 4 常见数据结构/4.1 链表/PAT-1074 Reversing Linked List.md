# 1074 Reversing Linked List

> part 4, 4.1



## 自己解法

- 链表有套路的
  - 使用struct存储地址数据
  - 如果要排序，struct里面需要加一个address的地址属性，否则用下标标识就好了
  - 输入的node很有可能不合格，要先跑一遍链表，用struct中的flag标识

- 关键在这个 cmp 排序函数

```c++
#include <iostream>
using namespace std;
#include <algorithm>
int K, ct = 0;

struct node
{
    int address;
    int value;
    int next;
    bool flag;
    int rank;
} l[100000];

// 如果 a 或者 b 中的 flag 有false的，就把false的移到后面
bool cmp(node a, node b)
{
    if (!a.flag || !b.flag)
        return a.flag > b.flag;
    else
    {
        if ((a.rank / K) == (b.rank / K))
            if ((a.rank / K) == ct / K)
                return a.rank < b.rank;
            else
                return a.rank > b.rank;
        else
            return (a.rank / K) < (b.rank / K);
    }
    return a.rank < b.rank;
}

int main()
{
    int s, N;
    cin >> s >> N >> K;
    int addr;
    for (int i = 0; i < N; i++)
    {
        cin >> addr;
        l[addr].address = addr;
        cin >> l[addr].value >> l[addr].next;
        l[addr].flag = false;
    }
    int a = 0;
    for (int i = s; i != -1; i = l[i].next)
    {
        l[i].flag = true;
        l[i].rank = a++;
        ct++;
    }
    sort(l, l + 100000, cmp);
    int i;
    for (i = 0; i < ct - 1; i++)
        printf("%05d %d %05d\n", l[i].address, l[i].value, l[i + 1].address);
    printf("%05d %d %d\n", l[i].address, l[i].value, -1);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 柳神这样也可以，但是感觉还是使用struct更加清晰明了

```c++
#include <iostream>
using namespace std;
int main() {
    int first, k, n, sum = 0;
    cin >> first >> n >> k;
    int temp, data[100005], next[100005], list[100005], result[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < sum; i++) result[i] = list[i];
    for (int i = 0; i < (sum - sum % k); i++)
        result[i] = list[i / k * k + k - 1 - i % k];
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
    return 0;
}
```

