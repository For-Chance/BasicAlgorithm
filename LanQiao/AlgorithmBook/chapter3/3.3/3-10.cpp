// Circular Sequence, UVa 1584
//

// start: 2022-01-23 10:16:57
// end: give up halfway
// details:     1. take minutes to finish the encode problem
//              2. understand wrongly to the problem

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define maxn 100
// s 是用于存储最小字典序的
char c[maxn + 1], s[maxn + 1], temp[maxn + 1];
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", &c);
        strcpy(s, c);
        int c_len = strlen(c);
        for (int i = 0; i < c_len; i++)
        {
            for (int j = 0; j < c_len; j++)
            {
                int index = (i + j) % c_len;
                if (int(c[index]) < int(s[j]))
                    ;
            }
        }
        printf("%s\n", s);
    }

    system("pause");
    return 0;
}