// 阶乘之和
// 输出后6位

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, fac = 1, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
        sum += fac;
    }
    printf("%d\n", sum % 1000000);
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
    system("pause");
    return 0;
}