// 3n+1问题(有bug)
// 题目要求 n<=10^9
// 当n=987654321时，出现了溢出
// 注意int的范围是 -2^31——2^32-1 ,位于一个负10位数和正10位数之间

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);
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