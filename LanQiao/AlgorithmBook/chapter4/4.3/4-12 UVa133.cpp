// The Dole Queue
// AC

/*
start: 2022-01-24 21:35:24
end: 2022-01-24 23:16:01
details:     
    1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 20;
bool p[20];
int n, k, m;
int left; // 剩下的人

int go(int i, int cir, int km)
{
    while (km--)
    {
        do
        {
            // 第一次要当作是刚刚踢出去的那个位置
            i = (i + cir + n - 1) % n + 1;
        } while (!p[i]);
    }
    return i;
}

int main()
{
    while (scanf("%d%d%d", &n, &k, &m) && (n || k || m))
    {
        left = n;
        for (int i = 1; i <= n; i++)
            p[i] = 1;
        // 初始化取它们前面的那位
        int qA = n, qB = 1;
        while (left)
        {
            qA = go(qA, 1, k);
            qB = go(qB, -1, m);
            printf("%3d", qA);
            left--;
            p[qA] = 0;
            if (p[qB])
            {
                printf("%3d", qB);
                left--;
                p[qB] = 0;
            }
            if (left)
                printf(",");
        }
        printf("\n");
    }

    system("pause");
    return 0;
}