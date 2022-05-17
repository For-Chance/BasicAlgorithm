// Ancient Cipher, UVa1339
// WA

// start: 2022-01-24 17:33:261
// end: 2022-01-24 18:28:13
// details:     1. CONVERT: a串中字母数量为1,2,3…的个数是否等于串b中字母数量为1,2,3…的个数, 如：ABBBCCC 与 EJJJZZZ是映射的。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[100], b[100], s[100];
    int count_a[26], count_b[26];
    int p = 1;
    while (scanf("%s", s) != EOF)
    {
        if (p == 1)
        {
            memset(count_a, 0, sizeof(count_a));
            memset(count_b, 0, sizeof(count_b));
            strcpy(a, s);
            int a_len = strlen(a);
            for (int i = 0; i < a_len; i++)
                count_a[a[i] - 'A']++;
            p = 2;
        }
        else
        {
            strcpy(a, s);
            int b_len = strlen(b);
            for (int i = 0; i < b_len; i++)
                count_b[b[i] - 'A']++;
            p = 1;

            int flag = 0;
            for (int j = 0; j < 26; j++)
            {
                if (count_a[j] > 0)
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (count_b[k] > 0 && count_a[j] == count_b[k])
                        {
                            flag = 1;
                            count_a[j] = 0;
                            count_b[k] = 0;
                        }
                    }
                    if (flag == 0)
                        break;
                }
            }
            if (flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    system("pause");
    return 0;
}