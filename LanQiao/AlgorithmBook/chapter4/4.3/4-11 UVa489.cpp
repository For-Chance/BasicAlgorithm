// Hangman Judge
//

/*
start: 2022-01-24 20:07:34
end: give up
details:     
    1. the explain of the problem
        (1) win - guess all letters before lose
        (2) lose - guess some letter once again, or wrong letters are to 7
        (3) chinkened out - not win or not lose
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxl 100
char s[maxl], g[maxl];

int removeDul(int len)
{
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        for (int k = 0; k <= j; k++)
        {
            if (s[i] == s[k])
                break;
            if (k == j)
            {
                s[j] = s[i];
                s[i] = ' ';
            }
        }
    }
    return j;
}

int guess(char c, int s_len)
{
    // flag = 0表示猜对了，= -1表示猜错了, -7表示猜到了重复的
    int flag = 0;
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == c)
        {
            flag = 0;
            s[i] = ' ';
            break;
        }
        else if (s[i] == ' ')
        {
            flag = -7;
            break;
        }
        else
        {
            flag = -1;
        }
    }
    return flag;
}

int count_s(int s_len)
{
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] != ' ')
            return 0;
    }
    return 1;
}

void getResult(int r)
{
    switch (r)
    {
    case 0:
        printf("You chickened out.\n");
        break;
    case 1:
        printf("You win.\n");
        break;
    case -1:
        printf("You lose.\n");
        break;
    }
}

int main()
{
    int round;
    while (scanf("%d%s%s", &round, s, g) == 3 && round != -1)
    {
        int result, chance = 7;
        int s_len = strlen(s), g_len = strlen(g);
        s_len = removeDul(s_len);
        for (int i = 0; i < g_len; i++)
        {
            chance += guess(g[i], s_len);
            if (chance <= 0)
            {
                result = -1;
                break;
            }
        }
        if (chance > 0 && count_s(s_len))
            result = 1;
        else
            result = 0;
        printf("Round %d\n", round);
        getResult(result);
    }
    system("pause");
    return 0;
}