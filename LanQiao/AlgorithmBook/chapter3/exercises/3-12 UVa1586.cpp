// Molar Mass, UVaa 1586
// AC

// start: 2022-01-23 13:19:00
// end: 2022-01-23 13:52:31
// details:     1. not hard

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 80
char s[maxn + 1];

double f(char x)
{
    switch (char(x))
    {
    case 'C':
        return 12.01;
    case 'H':
        return 1.008;
    case 'O':
        return 16.00;
    case 'N':
        return 14.01;
    }
    return 0.00;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &s);
        int i = 0;
        double mass = 0.0;
        while (s[i])
        {
            char c = s[i];
            int d = 0;
            if (int(s[i + 1]) - int('A') < 0 && s[i + 1])
            {
                if (int(s[i + 2]) - int('A') < 0 && s[i + 2])
                {
                    d = (int(s[i + 1]) - int('0')) * 10 + int(s[i + 2]) - int('0');
                    i += 3;
                }
                else
                {
                    d = int(s[i + 1]) - int('0');
                    i += 2;
                }
            }
            else
            {
                // 没有数字
                d++;
                i++;
            }
            mass += d * f(c);
        }
        printf("%.3f\n", mass);
    }
    system("pause");
    return 0;
}