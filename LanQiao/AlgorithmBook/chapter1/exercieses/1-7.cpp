// 年份

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int y;
    scanf("%d", &y);
    if (y % 4 == 0 && y % 100 != 0)
        printf("yes\n");
    else
        printf("no\n");
    system("pause");
    return 0;
}