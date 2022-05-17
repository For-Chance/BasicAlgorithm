// Digit Counting, UVa1225
// AC

// start: 2022-01-23 13:53:49
// end: 2022-01-23 14:17:24
// details:     1. easy
//              2. in memset(), pay attention to the sizeof()

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int count[10];

int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        memset(count, 0, sizeof(count));
        int n, p;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            p = i;
            while (p)
            {
                count[p % 10]++;
                p = p / 10;
            }
        }
        for (int i = 0; i < 10; i++)
            if (i != 9)
                printf("%d ", count[i]);
            else
                printf("%d\n", count[i]);
    }
    system("pause");
    return 0;
}