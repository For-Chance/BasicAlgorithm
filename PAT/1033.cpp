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