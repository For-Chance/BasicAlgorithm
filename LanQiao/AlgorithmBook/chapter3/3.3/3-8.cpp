// Master-Mind Hints, UVa 340
// Answer Wrong

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // 用g去标识第几个游戏
    // 用p去标识目前是在哪一个阶段
    // n 是序列长度，i 用来循环控制
    int g = 0, p = 1, n = 0, i = 0;
    // A 统计猜测序列有多少正确，B 统计有多少数字在两个序列都出现过但位置不对
    int A = 0, B = 0;
    // count0 统计序列中有多少0
    int count0 = 0;
    // 答案序列和猜测序列
    int answer[1000], guess[1000];
    memset(answer, 0, sizeof(0));
    int s;
    // 注意 scanf 遇到空格或者就会停下来
    while (scanf("%d", &s) == 1)
    {
        // 第一阶段输入为序列长度 n
        if (p == 1)
        {
            // 第一阶段输入为 0 ，则游戏结束
            if (s == 0)
                break;
            n = s;
            p = 2;
            g++;
            printf("Game %d:\n", g);
        }

        // 第二阶段输入为答案序列
        else if (p == 2)
        {
            answer[i] = s;
            i++;
            // 当第二阶段结束
            if (i == n)
            {
                i = 0;
                p = 3;
            }
        }

        // 第三阶段输入为猜测序列
        else if (p == 3)
        {
            guess[i] = s;
            i++;
            if (s == 0)
                count0++;
            // 当一行猜测序列结束
            // 当猜测序列全0时，这一轮游戏结束，初始化
            if (count0 == n)
            {
                p = 1;
                n = 0;
                count0 = 0;
                i = 0;
                A = 0;
                B = 0;
                memset(answer, 0, sizeof(0));
                continue;
            }
            if (i == n)
            {
                int j, k;
                for (j = 0; j < n; j++)
                    if (guess[j] == answer[j])
                    {
                        A++;
                        // 猜测序列要占位
                        guess[j] = -1;
                    }
                    else
                        for (k = 0; k < n; k++)
                            if (answer[j] == guess[k] && answer[k] != guess[k] && guess[k] != -1)
                            {
                                B++;
                                guess[k] = -1;
                                // break 是为了防止重复
                                break;
                            }
                printf("    (%d,%d)\n", A, B);
                i = 0;
                A = 0;
                B = 0;
            }
        }
    }
    system("pause");
    return 0;
}