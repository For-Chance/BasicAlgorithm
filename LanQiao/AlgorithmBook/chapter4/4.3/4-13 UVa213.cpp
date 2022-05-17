// Message Decoding
//

/*
start: 2022-01-25 08:53:38
end:
details:     
    1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 保存解码信息
char encode[8][1 << 8]; // 1<<8 表示1的二进制数左移八位，就是2的8次方,前面的只用 1-7
int getEncode()
{
    memset(encode, ' ', sizeof(encode));
    encode[1][0] = readchar(); // 使用readchar那么如果开始就是空格或者tab是不读的
    char ch;
    int len = 1, v = 0;
    while ((ch = getchar()) != EOF)
    {
        encode[len][v];
        v++;
        if (v = (1 << len) - 1)
        {
            len++;
            v = 0;
        }
    }
}

char readchar()
{
    while (1)
    {
        char ch;
        ch = scanf("%c", &ch);
        if (ch != ' ' && ch != '\n' && ch != '\t')
            return ch;
    }
}

int main()
{
    while (getEncode())
    {
        /* code */
    }

    system("pause");
    return 0;
}