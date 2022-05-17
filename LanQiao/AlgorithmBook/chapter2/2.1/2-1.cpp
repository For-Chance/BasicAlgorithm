// 输出 1,2,3,...,n 的值

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("%d\n", i);
    }
    system("pause");
    return 0;
}