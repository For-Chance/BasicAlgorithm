#include <iostream>
using namespace std;
#include <algorithm>
float payPm[24] = {0.0};
float payPd = 0.0;

struct call
{
    string name;
    int MM, dd, HH, mm;
    int timestamp;
    int status; // 0 表示 off-line, 1 表示 on-line
} d[1000];

// 由题目意思可知，排序应该是用户名字>月>时间
bool Comparer(call a, call b)
{
    // // 注释这样写是做不到排序的
    // if (a.name == b.name)
    //     return a.timestamp < a.timestamp;
    // else
    //     return a.name < b.name;
    return a.name == b.name ? a.timestamp < b.timestamp : a.name < b.name;
}

float printBill(int one, int zero)
{
    printf("%02d:%02d:%02d %02d:%02d:%02d %d ", d[one].dd, d[one].HH, d[one].mm, d[zero].dd, d[zero].HH, d[zero].mm, (d[zero].timestamp - d[one].timestamp));
    float bill = 0.0;
    if (d[zero].dd != d[one].dd)
        bill += payPd * (d[zero].dd - d[one].dd - 1); // 这里 PAT 数据有问题
    bill += payPm[d[one].HH] * (60 - d[one].mm);
    bill += payPm[d[zero].HH] * d[zero].mm;
    int start = d[one].HH + 1;
    int end = d[zero].HH;
    while (start != end)
    {
        bill += payPm[start] * 60;
        start++;
        if (start == 24)
            start = 0;
    }
    printf("$%.2f\n", bill);
    return bill;
}

int main()
{
    for (int i = 0; i < 24; i++)
    {
        float pay;
        cin >> pay;
        payPm[i] = pay / 100.0;
        payPd += pay * 0.6; // 实际上是*60/100
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> d[i].name;
        string strline;
        scanf("%d:%d:%d:%d", &d[i].MM, &d[i].dd, &d[i].HH, &d[i].mm);
        d[i].timestamp = d[i].mm + d[i].HH * 60 + d[i].dd * 24 * 60; // 所有数据都是某一个月的
        cin >> strline;
        if (strline[1] == 'n')
            d[i].status = 1;
        else
            d[i].status = 0;
    }
    sort(d, d + N, Comparer);
    // 输出逻辑
    // 依名字->同名找第一个1->找到0，输出，找到1把这个当作起始1
    int one, zero;       // 标记1和0
    int flag;            // flag 为 1 表示在找1，为0表示在找0
    string tagname = ""; // 标记目前的名字
    float total = 0.0;
    for (int i = 0; i < N; i++)
    {
        if (d[i].name != tagname)
        {
            tagname = d[i].name;
            flag = 1;
            one = -1;
            zero = -1;
            if (i != 0)
                printf("Total amount: $%.2f\n", total);
            total = 0.0;
            cout << d[i].name;
            printf(" %02d\n", d[i].MM);
        }
        if (flag == 1)
        {
            if (d[i].status != 1)
                continue;
            one = i;
            flag = 0;
        }
        else
        {
            if (d[i].status == 1)
                one = i;
            else
            {
                zero = i;
                total += printBill(one, zero);
                flag = 1;
            }
        }
    }
    printf("Total amount: $%.2f\n", total);
    // for (int i = 0; i < N; i++)
    // {
    //     cout << d[i].name;
    //     printf(" %02d:%02d:%02d:%02d ", d[i].MM, d[i].dd, d[i].HH, d[i].mm);
    //     cout << d[i].status;
    //     cout << endl;
    // }

    system("pause");
    return 0;
}