# 1031 Hello World for U

> part 1, 1.5



## 自己解法

- 注意字符数组的初始化，如果不是用memset初始化，而是使用char c\[30][30] = {' '}的话，PAT测试会报错

```c++
#include <iostream>
using namespace std;
#include <string.h>

int main()
{
    string s;
    cin >> s;
    int N = s.length();
    int n1 = (N + 2) / 3;
    int n3 = n1, n2 = (N + 2) - 2 * n1;
    char c[30][30];
    memset(c, ' ', sizeof(c));
    int i = 0;
    for (int j = 0; j < n1; j++)
    {
        c[j][0] = s[i];
        i++;
    }
    for (int j = 1; j < n2 - 1; j++)
    {
        c[n1 - 1][j] = s[i];
        i++;
    }
    for (int j = n3 - 1; j >= 0; j--)
    {
        c[j][n2 - 1] = s[i];
        i++;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
            cout << c[i][j];
        cout << endl;
    }

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char c[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n = strlen(c) + 2;
    int n1 = n / 3, n2 = n / 3 + n % 3, index = 0;
    for(int i = 0; i < n1; i++) u[i][0] = c[index++];
    for(int i = 1; i <= n2 - 2; i++) u[n1-1][i] = c[index++];
    for(int i = n1 - 1; i >= 0; i--) u[i][n2-1] = c[index++];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) 
            printf("%c", u[i][j]);
        printf("\n");
    }
    return 0;
}
```

