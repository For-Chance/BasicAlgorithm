// 鸡兔同笼
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // a 表示 鸡，b 表示兔子
    int n, m, a, b;
    int flag = 1;
    scanf("%d %d", &n, &m);
    a = (4 * n - m) / 2.0;
    b = (m - 2 * n) / 2.0;
    if (a == int(a) && b == int(b) && a >= 0 && b >= 0)
        printf("%d %d\n", a, b);
    else
        printf("No answer\n");
    system("pause");
    return 0;
}