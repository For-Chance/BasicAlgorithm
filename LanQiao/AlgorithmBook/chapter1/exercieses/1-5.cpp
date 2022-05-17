// 打折

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    if ((95 * n) >= 300)
        printf("%.2f\n", 95.0 * n * 0.85);
    else
        printf("%.2f\n", 95.0 * n);
    system("pause");
    return 0;
}