# 1065 A+B and C (64bit)

> part 1, 1.1



## 自己解法(未全对)

- sum 如果溢出了，那么一定大于 2^63, 或者小于-2^63, 也就是一定是大于C或者小于C
- 看了好多，用cin输入的最后一个案例都WA

```c++
#include <iostream>
using namespace std;

int main()
{
    long long A, B, C;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A >> B >> C;
        cout << "Case #" << i << ": ";
        long long sum = A + B;
        if (A > 0 && B > 0 && sum < 0)
            cout << "true" << endl;
        else if (A < 0 && B < 0 && sum >= 0)
            cout << "false" << endl;
        else
        {
            if (sum > C)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- scanf神来之笔

```c++
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i + 1);
        } else if(a < 0 && b < 0 && sum >= 0){
            printf("Case #%d: false\n", i + 1);
        } else if(sum > c) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
```



## 总结

- [cin与scanf的区别](https://blog.csdn.net/liuchuo/article/details/52109211): 如果读取的数溢出，cin得到两数之间最大值，而scanf得到溢出后的值

