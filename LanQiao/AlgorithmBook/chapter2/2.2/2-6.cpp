// 近似计算

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n = 0;
    double sum = 0.0;
    do
    {
        if (n % 2 == 0)
            sum = sum + 1.0 / (2 * n + 1);
        else
            sum = sum - 1.0 / (2 * n + 1);
        n++;
    } while (1.0 / (2 * n + 1) >= 1e-6);
    printf("%.8f\n", sum);
    printf("%.8f\n", M_PI / 4.0);
    system("pause");
    return 0;
}