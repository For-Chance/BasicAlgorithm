# 1059 Prime Factors

> part 3, 3.3



## 自己解法

```c++

```



## 大神解法

- 柳神
- **根号int的最大值不会超过50000，先建立个50000以内的素数表，然后从2开始一直判断是否为它的素数，如果是就将a=a/i继续判断i是否为a的素数，判断完成后输出这个素数因子和个数，用state判断是否输入过因子，输入过就要再前面输出“\*”**

```c++
#include <cstdio>
#include <vector>
using namespace std;
vector<int> prime(50000, 1);
int main() {
    for(int i = 2; i * i < 50000; i++)
        for(int j = 2; j * i < 50000; j++)
            prime[j * i] = 0;
    long int a;
    scanf("%ld", &a);
    printf("%ld=", a);
    if(a == 1) printf("1");
    bool state = false;
    for(int i = 2; i < 50000 && a >= 2; i++) {
        int cnt = 0, flag = 0;
        while(prime[i] == 1 && a % i == 0) {
            cnt++;
            a = a / i;
            flag = 1;
        }
        if(flag) {
            if(state) printf("*");
            printf("%d", i);
            state = true;
        }
        if(cnt >= 2) printf("^%d", cnt);
    }
    if (a > 1) printf("%s%ld", state ? "*" : "", a);
    return 0;
}
```

