//  三位数反转（2）

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, m;
    scanf("%d", &a);
    m = (a % 10) * 100 + (a / 10 % 10) * 10 + a / 100;
    printf("%03d\n", m);
    system("pause");
    return 0;
}