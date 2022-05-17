// 正弦和余弦

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    // n < 360
    int n;
    scanf("%d", &n);
    printf("%.2f\n", sin(n * M_PI / 180));
    printf("%.2f\n", cos(n * M_PI / 180));
    system("pause");
    return 0;
}