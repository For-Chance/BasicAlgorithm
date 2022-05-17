#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d\n", int('1')); // 49
    printf("%d\n", int('a')); // 97
    printf("%d\n", int('A')); // 65
    char s[100];
    printf("%s\n", s);
    system("pause");
    return 0;
}