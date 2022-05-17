// Digit Generator, UVa1583
// Answer Wrong

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100001

int main()
{
    int res[maxn];
    for (int i = 0; i < maxn; i++)
    {
        int p, sum_p = 0;
        p = i;
        while (p / 10)
        {
            sum_p += p % 10;
            p = p / 10;
        }
        res[i] = i + sum_p + p;
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 多余的操作可以减缓循环次数
        int flag = 0;
        for (int i = (n <= 81 ? 0 : n - 81); i <= n; i++)
            if (res[i] == n)
            {
                printf("%d\n", i);
                flag = 1;
                break;
            }
        if (flag == 0)
            printf("0\n");
    }
    system("pause");
    return 0;
}