// 三整数排序(1)(2)(3)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // a 表示 鸡，b 表示兔子
    int a, b, c, temp;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    printf("%d %d %d\n", a, b, c);
    system("pause");
    return 0;
}