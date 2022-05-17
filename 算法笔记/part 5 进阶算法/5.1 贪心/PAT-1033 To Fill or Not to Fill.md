# 1033 To Fill or Not to Fill

> part 5, 5.1



## 题意理解

- 给出油箱Cmax，运行距离D，每公里耗油Davg，路上加油站数量N，然后N行，每行是油费与出发点距离。求最少油费，不可能到达则输出最远距离
- 开始油箱是空的

### Sample Input 1:

```in
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
```

### Sample Output 1:

```out
749.17
```

### Sample Input 2:

```
50 1300 12 2
7.10 0
7.00 600
```

### Sample Output 2:

```
The maximum travel distance = 1200.00
```



## 自己解法

- 从起点往前考虑，每次都是局部最优
  - 在能到达的加油站中每次都选择最便宜的加到恰好到达后一个局部最优
  - 没有能到达的加油站，就是加满然后到达最远

- 这是错误的思想导致错误的编程

```c++
#include <iostream>
using namespace std;
#include <map>
double maxdis, maxD = 0.0, minCost = 0.0; // maxdis 是一桶油能跑的最远，maxD 是能跑的最远距离
double Cmax, D, Davg;
int N;
map<double, double> s;

// begin是station的距离,注意是迭代器
void goBest(map<double, double>::iterator begin)
{
    if (begin == --s.end())
    {
        maxD = D;
        minCost += begin->second * (D - begin->first) / Davg;
        printf("%.2f\n", minCost);
        return;
    }
    double gomax = begin->first + maxdis;
    auto it = begin;
    it++;
    double minC = 1000000.0;
    auto minS = begin;
    for (; it->first <= gomax && it != s.end(); it++)
        if (it->second < minC)
        {
            minS = it;
            minC = it->second;
        }
    if (minS == begin)
    {
        printf("The maximum travel distance = %.2f\n", maxD + maxdis);
        return;
    }
    else
    {
        maxD = minS->first;
        minCost += begin->second * (maxD - begin->first) / Davg;
        goBest(minS);
    }
}

int main()
{

    cin >> Cmax >> D >> Davg >> N;
    maxdis = Cmax * Davg;
    double a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        s.insert(make_pair(b, a));
    }
    // 排除最后一站到不了的情况，不然会被干扰
    if ((--s.end())->first + maxdis < D)
        printf("The maximum travel distance = %.2f\n", (--s.end())->first + maxdis);
    else
        goBest(s.begin());
    system("pause");
    return 0;
}
```

- 正确的思路

  - 列出能到达的加油站中
    - 如果有加油站比现在的便宜，就加油恰好直到那个加油站
    - 如果没有一个加油站比现在的便宜，就将现在的油加满，然后去到下一个没那么便宜的加油站
    - 所有的加油前需要计算，现在能够加的油量和离终点还有的距离，如果够的话就不用加满
  - 没有能到达的加油站，就是加满然后到达最远
- 仍有一个没过，和柳神的思想是一模一样的

```c++
#include <iostream>
using namespace std;
#include <map>
double maxdis, maxD = 0.0, minCost = 0.0; // maxdis 是一桶油能跑的最远，maxD 是能跑的最远距离
double Cmax, D, Davg;
int N;
map<double, double> s;

// begin是station的距离,注意是迭代器, restTank 是到达这个点后油箱油量能跑的距离
void goBest(map<double, double>::iterator begin, double restTank)
{
    if (begin == --s.end())
    {
        maxD = D;
        minCost += begin->second * (D - begin->first) / Davg;
        printf("%.2f\n", minCost);
        return;
    }
    double gomax = begin->first + maxdis;
    auto minS = begin;
    auto it = begin;
    it++;
    for (; it->first <= gomax && it != s.end(); it++)
        if (it->second < begin->second)
        {
            // 只要遇到比现在的油价低的，就直接恰好到那里
            minS = it;
            break;
        }
    if (it == s.end())
    {
        // 没有一个加油站
        printf("The maximum travel distance = %.2f\n", maxD + maxdis);
        return;
    }
    else if (minS == begin)
    {
        // 后一站没有比它便宜，直接加满,然后跑去一个相对小的站
        maxD = gomax;
        minCost += begin->second * (maxdis - restTank) / Davg;
        double minC = 1000000.0;
        it = begin;
        it++;
        for (; it->first <= gomax && it != s.end(); it++)
            if (it->second < minC)
            {
                minS = it;
                minC = it->second;
            }
        goBest(minS, gomax - minS->first);
    }
    else
    {
        // 存在加油站比现在便宜,只加到恰好跑到那个加油站
        maxD = minS->first;
        minCost += begin->second * (maxD - begin->first - restTank) / Davg;
        goBest(minS, 0.0);
    }
}

int main()
{

    cin >> Cmax >> D >> Davg >> N;
    maxdis = Cmax * Davg;
    double a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        s.insert(make_pair(b, a));
    }
    // 排除第一站不是0的情况
    if (s.begin()->first != 0.0)
    {
        printf("The maximum travel distance = 0.00\n");
    }
    // 排除最后一站到不了的情况，不然会被干扰
    else if ((--s.end())->first + maxdis < D)
        printf("The maximum travel distance = %.2f\n", (--s.end())->first + maxdis);
    else
        goBest(s.begin(), 0.0);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 分析：贪心算法。
  1. 假设增加一个目的地处的加油站，距离为目的地的距离，价格为0，考虑从0距离开始能否到达最后一个加油站的问题
  2. 因为先开始没有油，所以如果所有的加油站距离都没有等于0的，那么说明车哪也去不了，直接输出并return
  3. 将加油站按照距离dis从小到大排序
  4. 先去第一个加油站，设置变量nowdis表示当前所在的距离，maxdis是能够到达的最大距离，nowprice是当前的站点的价格，totalPrice是总的价格。

- 贪心思想：
  - 寻找比自己距离远的，到能够到达的最大距离之间的加油站，看他们的油价。如果找到了更低价格的油价，就加油到刚好能到达那个加油站的距离的油，然后去那个更低价格的加油站（有更低的我一分都不想多花在别的距离上，只加到刚好满足更低价格的加油站的距离就行，那样以后的路程我就可以以更低的价格行驶啦）
  - 如果找不到更低的，就找尽可能低的油价的加油站，在当前加油站加满油之后过去。因为想要让路程上使用的尽可能是低价的油，既然没有比当前更低价格的了，就让油箱加到最大值，这样能保证利益最大化，保证最大的距离使用的是便宜的油。


```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}
int main() {
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
    if(sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while(nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if(sta[i].dis <= nowdis) continue;
            if(sta[i].price < nowprice) {
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].price < minPrice) {
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if(flag == 0 && minPrice != inf) {
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;     
        }
        if(flag == 0 && minPrice == inf) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}
```

