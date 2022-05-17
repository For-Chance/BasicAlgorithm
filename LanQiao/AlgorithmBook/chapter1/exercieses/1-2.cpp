// 温度

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int f;
    scanf("%d", &f);
    printf("%.3f\n", (5 * (f - 32)) / 9.0);
    system("pause");
    return 0;
}