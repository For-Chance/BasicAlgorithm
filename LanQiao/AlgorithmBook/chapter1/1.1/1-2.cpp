// 计算并输出8/5的值，结果保留小数点后1位

#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("%.1f\n", 8.0/5.0);
    printf("%.2f\n", 8.0/5.0);
    printf("%.1f\n", 8/5);
    printf("%d\n", 8/5);
    system("pause");
    return 0;
}