// Score UVa1585
// AC

// start: 2022-01-23 11:43:41
// end: 2022-01-23 11:58:57
// details:     1.easy

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 80
char s[maxn + 1];
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &s);
        int score = 0, O_con = 0;
        int s_len = strlen(s);
        for (int i = 0; i < s_len; i++)
        {
            if (s[i] == 'O')
            {
                O_con++;
                score += O_con;
            }
            else
            {
                O_con = 0;
            }
        }
        printf("%d\n", score);
    }
    system("pause");
    return 0;
}