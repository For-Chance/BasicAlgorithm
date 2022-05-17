// 7744问题(1)(2)
// 输出所有形如aabb的4位完全平方数

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, m, a, b, c, d;
    for (i = 32; i < 100; i++)
    {
        m = i * i;
        a = m / 1000;
        b = (m / 100) % 10;
        c = (m % 100) / 10;
        d = (m % 100) % 10;
        if (a == b && c == d)
            printf("%d\n", m);
    }
    system("pause");
    return 0;
}