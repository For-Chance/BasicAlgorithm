// WERTYU, UVa10082

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[] = "QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
    int c;
    while ((c = getchar()) != EOF)
    {
        int i, flag = 0;
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == c)
            {
                putchar(s[i - 1]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            putchar(c);
    }
    system("pause");
    return 0;
}