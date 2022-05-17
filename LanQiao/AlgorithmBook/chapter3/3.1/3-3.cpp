// 蛇形填数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n, a[8][8], max, m = 1, i, j, circle = 0;
    scanf("%d", &n);
    max = n * n;
    memset(a, 0, sizeof(a));
    i = -1;
    j = n;
    while (m <= max)
    {
        circle++;
        i++;
        j--;
        // 一次循环到最外一圈
        // 依次四个循环是 下 左 上 右 的穷尽
        while (i < n - circle)
            a[i++][j] = m++;
        while (j > circle - 1)
            a[i][j--] = m++;
        while (i > circle - 1)
            a[i--][j] = m++;
        while (j < n - circle)
            a[i][j++] = m++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
            printf("%d\t", a[i][j]);
        printf("%d\n", a[i][j]);
    }
    system("pause");
    return 0;
}