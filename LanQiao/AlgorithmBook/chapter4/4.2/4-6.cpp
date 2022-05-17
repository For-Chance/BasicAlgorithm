// 指针作为参数，交换变量
//

// start: 2022-01-24 17:15:12
// end:
// details:     1.

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a = 2, b = 3;
    swap(&a, &b);
    printf("%d %d\n", a, b);
    system("pause");
    return 0;
}