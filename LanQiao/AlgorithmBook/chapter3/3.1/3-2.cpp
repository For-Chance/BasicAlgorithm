// 开灯问题

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, k, a[1000], i, j;
    memset(a, 0, sizeof(0));
    scanf("%d %d", &n, &k);
    for (i = 1; i <= k; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j % i == 0)
            {
                a[j] = !a[j];
            }
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (a[j] == 0)
            printf("%d ", j);
    }
    printf("\n");
    system("pause");
    return 0;
}