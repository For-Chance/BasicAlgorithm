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