// 3n+1问题
// 题目要求 n<=10^9

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n2, count = 0;
    scanf("%d", &n2);
    // 使用64位的
    long long n = n2;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        if (n != 1)
            printf("%d->", n);
        else
            printf("%d\n", n);
        count++;
    }
    printf("%d\n", count);
    system("pause");
    return 0;
}