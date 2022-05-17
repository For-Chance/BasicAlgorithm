// Periodic String, UVa455
//

// start: didnt catch
// end: give up
// details:     1.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[5][5];

int main()
{
    // n 记录第几次游戏
    // p 是第几段之中
    int n = 1, p = 1;
    // c 用来保存字符，seq保存存放位置
    int c, seq = 0;
    // flag 是为了防止重复输入空格 1表示有空格了
    int flag = 0, flag_p = 1;
    // i, j保存空格的位置
    int i, j;
    int a, b;
    while ((c = getchar()) != EOF)
    {
        if (flag == 1 && c == ' ')
            continue;
        if (c == '\n')
            continue;
        if (c == 'Z')
            if (seq % 5 == 0)
                c = ' ';
            else
                continue;
        // 第一段是在输入初始矩阵
        if (p == 1)
        {
            a = seq / 5;
            b = seq % 5;
            s[a][b] = c;
            if (c == ' ')
            {
                i = a;
                j = b;
                flag = 1;
            }
            if (seq == 24)
            {
                seq = 0;
                p = 2;
                continue;
            }
            seq++;
        }
        // 第二段是在输入指令
        if (p == 2)
        {
            // a, b 标识用于交换的位置
            int a, b;
            char temp;
            if (c == 'A')
            {
                a = i - 1;
                b = j;
            }
            else if (c == 'B')
            {
                a = i + 1;
                b = j;
            }
            else if (c == 'L')
            {
                a = i;
                b = j - 1;
            }
            else if (c == 'R')
            {
                a = i;
                b = j + 1;
            }
            else if (c == '0')
                p = 3;
            else
                flag_p = 0;
            if (a >= 0 && a <= 4 && b >= 0 && b <= 4 && flag_p == 1)
            {
                temp = s[a][b];
                s[a][b] = s[i][j];
                s[i][j] = temp;
                i = a;
                j = b;
                flag_p = 1;
            }
            else
                flag_p = 0;
        }
        // 第三阶段为输出
        if (p == 3)
        {
            if (flag_p == 1)
            {
                printf("Puzzle #%d:\n", n);
                for (int k = 0; k < 5; k++)
                    for (int l = 0; l < 5; l++)
                    {
                        if (l == 4)
                            printf("%c\n", s[k][l]);
                        else
                            printf("%c ", s[k][l]);
                    }
                printf("\n");
            }
            else
            {
                printf("This puzzle has no final configuration.\n\n");
            }
            p = 1;
            n++;
            seq = 0;
            flag = 0;
            flag_p = 1;
        }
    }
    system("pause");
    return 0;
}