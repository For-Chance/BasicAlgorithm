# PAT-1057 Stack

> part 5, 5.1



## 题意理解

- stack 的功能加上 peekMedian 的功能，要输出中位数

### Sample Input:

```in
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

```

### Sample Output:

```out
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid

```



## 自己解法

- 分块，晴神的解法

```c++
#include <iostream>
using namespace std;
#include <stack>
#include <string.h>
const int sqrN = 317;

stack<int> v;
int block[sqrN];   // 这里标号是 0-316，因此向下取整就行, 317 * 317 = 100489
int table[100490]; // 记录对应下标有几个数字

int main()
{
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    int N;
    cin >> N;
    string s;
    int a, K;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> a;
            v.push(a);
            block[a / sqrN]++;
            table[a]++;
        }
        else if (s[1] == 'o')
        {
            if (v.size() == 0)
                cout << "Invalid" << endl;
            else
            {
                a = v.top();
                cout << a << endl;
                v.pop();
                block[a / sqrN]--;
                table[a]--;
            }
        }
        else
        {
            K = v.size();
            if (K == 0)
            {
                cout << "Invalid" << endl;
                continue;
            }
            else if (K % 2 == 1)
                K = (K + 1) / 2;
            else
                K = K / 2;
            int idx = 0, num = 0, sum = 0; // 块号 和 最后的数字 和 第几大
            while (sum + block[idx] < K)
                sum += block[idx++];
            num = idx * sqrN; // 块内的第一个编号
            while (sum + table[num] < K)
                sum += table[num++];
            cout << num << endl;
        }
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- ==树状数组==
- **用排序查询的方法会超时～用树状数组，即求第k = (s.size() + 1) / 2大的数。查询小于等于x的数的个数是否等于k的时候用二分法更快～**


```c++
#include <cstdio>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
```

