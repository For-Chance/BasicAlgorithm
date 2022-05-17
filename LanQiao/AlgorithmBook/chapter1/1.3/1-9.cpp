// 交换变量(2)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, temp;
    scanf("%d %d", &a, &b);
    b = a + b;
    a = b - a;
    b = b - a;
    printf("%d %d\n", a, b);
    system("pause");
    return 0;
}