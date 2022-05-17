// Palindromes, UVa401
// Accepted

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // 镜像队列
    char Cha[] = "AEHIJLMOSTUVWXYZ12358";
    char Rev[] = "A3HILJMO2TUVWXY51SEZ8";
    char s[1024];
    while (scanf("%s", &s) != EOF)
    {
        int isPal = 1, isMir = 1;
        int len = strlen(s);
        for (int i = 0; i < len / 2.0; i++)
        {
            if (s[i] == s[len - i - 1] && isPal == 1)
                isPal = 1;
            else
                isPal = 0;

            if (isMir == 0)
                break;
            int index = -1;
            for (int j = 0; j < strlen(Cha); j++)
            {
                // 这样使用标志变量的话，只要存在的话，那么就会保证index和isMir=1跳出循环
                if (s[i] == Cha[j])
                {
                    index = j;
                    isMir = 1;
                    break;
                }
                isMir = 0;
            }
            if (s[i] == Cha[index] && index != -1 && s[len - i - 1] == Rev[index] && isMir == 1)
                isMir = 1;
            else
                isMir = 0;
        }
        if (isPal == 1 && isMir == 1)
            printf("%s -- is a mirrored palindrome.\n\n", s);
        else if (isPal == 0 && isMir == 1)
            printf("%s -- is a mirrored string.\n\n", s);
        else if (isPal == 1 && isMir == 0)
            printf("%s -- is a regular palindrome.\n\n", s);
        else
            printf("%s -- is not a palindrome.\n\n", s);
    }
    system("pause");
    return 0;
}