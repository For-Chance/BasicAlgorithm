// Tex Quotes, UVa 272

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int c, q = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%s", q ? "``" : "''");
            q = !q;
        }
        else
        {
            printf("%c", c);
        }
    }
    system("pause");
    return 0;
}