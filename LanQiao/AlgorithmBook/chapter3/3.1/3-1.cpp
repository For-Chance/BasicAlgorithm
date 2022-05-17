// 逆序输出

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[100], i = 0;
    while (scanf("%d", &a[i]) == 1)
    {
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
    system("pause");
    return 0;
}