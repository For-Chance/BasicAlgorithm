# 1070 Mooncake

> part 5, 5.1



## 题意理解

- 背包问题
  - 求最大利益
- 贪心

### Sample Input:

```in
3 200
180 150 100
7.5 7.2 4.5
```

### Sample Output:

```out
9.45
```



## 自己解法

- 自己写的快排都不快，能用C++的特性就用C++的特性

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int amounts[1000];
float prices[1000], key[1000];

void exchange_int(int *A, int i, int j)
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void exchange_float(float *A, int i, int j)
{
    float t = A[i];
    A[i] = A[j];
    A[j] = t;
}

// 实现对 p 到 r 的原址重排
int PARTITION(int p, int r)
{
    // 将最后一个元素插入到正确位置
    // 左边都比它大，右边的都小
    float x = key[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (key[j] >= x)
        {
            i++;
            exchange_float(key, i, j);
            exchange_float(prices, i, j);
            exchange_int(amounts, i, j);
        }
    }
    exchange_float(key, i + 1, r);
    exchange_float(prices, i + 1, r);
    exchange_int(amounts, i + 1, r);
    return i + 1;
}

void QUICKSORT(int p, int r)
{
    if (p < r)
    {
        int q = PARTITION(p, r);
        QUICKSORT(p, q - 1);
        QUICKSORT(p + 1, r);
    }
}

int main()
{
    int N, D;
    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        cin >> amounts[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
        key[i] = prices[i] / amounts[i];
    }
    // 快速排序
    QUICKSORT(0, N - 1);
    double total_prices = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (D > amounts[i])
        {
            D -= amounts[i];
            total_prices += prices[i];
        }
        else
        {
            total_prices += prices[i] * (double(D) / double(amounts[i]));
            break;
        }
    }
    printf("%.2f\n", total_prices);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 太久没写了，都忘记了可以用结构体


```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake{
    float num, price, unit;
};
int cmp(mooncake a, mooncake b) {
    return a.unit > b.unit;
}
int main() {
    int n, need;
    cin >> n >> need;
    vector<mooncake> a(n);
    for (int i = 0; i < n; i++) scanf("%f", &a[i].num);
    for (int i = 0; i < n; i++) scanf("%f", &a[i].price);
    for (int i = 0; i < n; i++) a[i].unit = a[i].price / a[i].num;
    sort(a.begin(), a.end(), cmp);
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        if (a[i].num <= need) {
            result = result + a[i].price;
        } else {
            result = result + a[i].unit * need;
            break;
        }
        need = need - a[i].num;
    }
    printf("%.2f",result);
    return 0;
}
```

