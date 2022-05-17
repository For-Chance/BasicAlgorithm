// 数据统计II

#include <stdio.h>
#include <stdlib.h>
#define INF 100000000
int main()
{
    int x, n = 0, min = INF, max = -INF, sum = 0, kcase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        min = INF;
        max = -INF;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            sum += x;
            if (x < min)
                min = x;
            if (x > max)
                max = x;
        }
        if (kcase)
            printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kcase, min, max, (double)sum / n);
    }
    system("pause");
    return 0;
}