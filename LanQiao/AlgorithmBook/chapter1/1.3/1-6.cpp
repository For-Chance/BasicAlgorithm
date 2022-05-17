//  三位数反转（1）

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d%d%d\n", a % 10, a / 10 % 10, a / 100);
    system("pause");
    return 0;
}