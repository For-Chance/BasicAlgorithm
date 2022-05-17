// 圆柱体的表面积

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double r, h, s;
    scanf("%lf %lf", &r, &h);
    s = M_PI * r * r * 2.0 + 2.0 * M_PI * r * h;
    printf("Area = %.3f\n", s);
    system("pause");
    return 0;
}