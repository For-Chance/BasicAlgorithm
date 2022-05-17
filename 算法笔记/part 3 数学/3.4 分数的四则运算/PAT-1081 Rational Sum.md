# 1081 Rational Sum

> part 3, 3.4



## 自己解法

- numerator 分子；denominator 分母
- 这里并没有用到辗转相除法
- 关键是 line 42 ，每隔一段时间就约分

```c++
#include <iostream>
using namespace std;
#include <string.h>

int d[100000];

void getF()
{
    memset(d, 1, sizeof(d));
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i * i < 100000; i++)
        for (int j = 2; j * i < 100000; j++)
            if (i * j < 100000)
                d[i * j] = 0;
}

void reduce(long long &b, long long &c)
{
    long long min = (b > c) ? c : b;
    if (min > 50000)
        min = 50000;
    for (int i = 2; i < min; i++)
        while (b % i == 0 && c % i == 0)
        {
            b = b / i;
            c = c / i;
        }
}

int main()
{
    int N, d[2];
    cin >> N;
    long long a = 0, b = 0, c = 1;
    getF();
    for (int i = 0; i < N; i++)
    {
        scanf("%d/%d", &d[0], &d[1]);
        b = b * d[1] + c * d[0];
        c = c * d[1];
        if (b > 100000 || c > 100000)
            reduce(b, c);
    }
    if (b > c)
    {
        a = b / c;
        b = b % c;
    }
    reduce(b, c);
    if (b == 0)
        cout << a << endl;
    else if (b != 0 && a != 0)
        cout << a << " " << b << "/" << c << endl;
    else if (a == 0 && b != 0)
        cout << b << "/" << c << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- ==gcd求最大公约数的方法！==：辗转相除法定理：两个整数的最大公约数等于其中较小的那个数和两数相除余数的最大公约数。

- 先根据分数加法的公式累加，后分离出整数部分和分数部分
  分子和分母都在长整型内，所以不能用int存储，否则有一个测试点不通过
  一开始一直是浮点错误，按理来说应该是出现了/0或者%0的情况，找了半天也不知道错在哪里
  后来注意到应该在累加的时候考虑是否会超出long long的范围，所以在累加每一步之前进行分子分母的约分处理，然后就AC了～
  以及：abs()在stdlib.h头文件里面

  应该还要考虑整数和小数部分都为0时候输出0的情况，但是测试用例中不涉及，所以如果没有最后两句也是可以AC的（PS：据说更新后的系统已经需要考虑全零的情况了～）

```c++
#include <iostream>
#include <cstdlib>
using namespace std;
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
int main() {
    long long n, a, b, suma = 0, sumb = 1, gcdvalue;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + suma * b;
        sumb = b * sumb;
        gcdvalue = gcd(suma, sumb);
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;
    }
    long long integer = suma / sumb;
    suma = suma - (sumb * integer);
    if(integer != 0) {
        printf("%lld", integer);
        if(suma != 0) printf(" ");
    }
    if(suma != 0)
        printf("%lld/%lld", suma, sumb);
    if(integer == 0 && suma == 0)
        printf("0");
    return 0;
}
```

