// 三角形

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
            printf("yes\n");
        else
            printf("no\n");
    }
    else
    {
        printf("not a triangle\n");
    }
    system("pause");
    return 0;
}