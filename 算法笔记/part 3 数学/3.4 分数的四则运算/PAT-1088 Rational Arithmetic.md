# 1088 Rational Arithmetic

> part 3, 3.4



## 自己解法

- rational numbers：有理数；sum, difference, product and quotient：加减乘除；a pair of parentheses：一对括号
- 见到说 in the rang of long int（$2^{32}$ 和 $10^{10}$），就使用 long long
- 题目看起来复杂，实则逻辑很清晰

```c++
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? abs(a) : gcd(b, a % b); }

void print(ll a, ll b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    ll maxg = gcd(a, b);
    a = a / maxg;
    b = b / maxg;
    ll x = a / b;
    if (x < 0)
        a = -a;
    a = a % b;
    if (a < 0 || x < 0)
        cout << '(';
    if (a == 0) // b = 1时a必为0
        cout << x;
    else if (a != 0 && x != 0)
        cout << x << ' ' << a << '/' << b;
    else
        cout << a << '/' << b;
    if (a < 0 || x < 0)
        cout << ')';
}

void sum(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " + ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * b2 + a2 * b1;
    b1 = b1 * b2;
    print(a1, b1);
    cout << endl;
}

void different(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " - ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * b2 - a2 * b1;
    b1 = b1 * b2;
    print(a1, b1);
    cout << endl;
}

void product(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " * ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * a2;
    b1 = b1 * b2;
    print(a1, b1);
    cout << endl;
}

void quotient(ll a1, ll b1, ll a2, ll b2)
{
    print(a1, b1);
    cout << " / ";
    print(a2, b2);
    cout << " = ";
    a1 = a1 * b2;
    b1 = a2 * b1;
    if (b1 == 0)
        cout << "Inf";
    else
        print(a1, b1);
    cout << endl;
}

int main()
{
    ll a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    sum(a1, b1, a2, b2);
    different(a1, b1, a2, b2);
    product(a1, b1, a2, b2);
    quotient(a1, b1, a2, b2);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <cmath>
using namespace std;
long long a, b, c, d;
long long gcd(long long t1, long long t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}
void func(long long m, long long n) {
    if (m * n == 0) {
        printf("%s", n == 0 ? "Inf" : "0");
        return ;
    }
    bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0));
    m = abs(m); n = abs(n);
    long long x = m / n;
    printf("%s", flag ? "(-" : "");
    if (x != 0) printf("%lld", x);
    if (m % n == 0) {
        if(flag) printf(")");
        return ;
    }
    if (x != 0) printf(" ");
    m = m - x * n;
    long long t = gcd(m, n);
    m = m / t; n = n / t;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");
}
int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d); printf("\n");
    func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d); printf("\n");
    func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");
    func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c);
    return 0;
}
```

