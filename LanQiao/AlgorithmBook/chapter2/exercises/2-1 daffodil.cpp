// 水仙花数

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, a, b, c;
    for (int i = 100; i <= 999; i++)
    {
        a = i / 100;
        b = i % 100 / 10;
        c = i % 10;
        if (a * a * a + b * b * b + c * c * c == i)
            printf("%d\n", i);
    }
    system("pause");
    return 0;
}