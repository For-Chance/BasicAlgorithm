// 韩信点兵

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 0, b = 0, c = 0, x;
    scanf("%d%d%d", &a, &b, &c);
    for (x = 10; x <= 100; x++)
    {
        if (x % 3 == a && x % 5 == b && x % 7 == c)
        {
            printf("%d", x);
            break;
        }
        else if (x == 100)
            printf("noanswer\n");
    }
    system("pause");
    return 0;
}