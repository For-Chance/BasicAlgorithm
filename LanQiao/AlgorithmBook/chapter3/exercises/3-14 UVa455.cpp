// Periodic String, UVa455
//

// start: 2022-01-23 14:20:33
// end: give up
// details:     1.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxs 80
char s[maxs];
char base[maxs];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &s);
        int s_len = strlen(s);
        // seq 用于记录目前所检查到的字符对应base的位置，count用来记录前面所重复的次数
        int k = 0, seq = 0, count = 1;
        for (int i = 0; i < s_len; i++)
        {
            if (count == 1) // 第一次顺序
            {
                if (base[0] == s[i])
                {
                    // flag = 1 表示还在第一次顺序，flag=0表示应该进入下一次顺序
                    int flag = 0;
                    for (int j = 1; j < k; j++)
                        if (base[j] != s[i + j])
                        {
                            flag = 1;
                            break;
                        }
                    if (flag == 1)
                    {
                        base[seq] = s[i];
                        k++;
                        seq++;
                    }
                    else
                    {
                        seq = 0;
                        count++;
                    }
                }
                else
                {
                    // 在第一次顺序
                    base[seq] = s[i];
                    k++;
                    seq++;
                }
            }
            else
            {
            }
        }
    }
    system("pause");
    return 0;
}