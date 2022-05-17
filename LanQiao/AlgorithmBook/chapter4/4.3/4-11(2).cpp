#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100
int left, chance; // 还需要猜left个位置，错chance次后就会输
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch)
{
    int bad = 1;
    // 这里是使用s循环，与ch相同的都会被覆盖，left--
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ch)
        {
            left--;
            s[i] = ' ';
            bad = 0;
        }
    if (bad)
        chance--;
    if (!chance)
        lose = 1; // 机会用尽
    if (!left)
        win = 1; // 全都猜完了
}

int main()
{
    int round;
    while (scanf("%d", &round) && round != -1 && scanf("%s%s", s, s2))
    {
        printf("Round %d\n", round);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); i++)
        {
            guess(s2[i]);
            if (win || lose)
                break;
        }
        if (win)
            printf("You win.\n");
        else if (lose)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
    system("pause");
    return 0;
}