// 数据统计

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, min = 100000, max = -100000, sum = 0, count = 0;
    while (scanf("%d", &n) == 1)
    {
        count++;
        if (n < min)
            min = n;
        if (n > max)
            max = n;
        sum += n;
    }
    printf("%d %d %.3f\n", min, max, (double)sum / count);
    system("pause");
    return 0;
}