# 1042 Shuffling Machine

> part 1, 1.1



## 自己解法

- 暴力法
- order 用于保存输入的顺序指令序列
- a 为实际进行操纵的数组
- b 为辅助操作的数组

```c++
#include <iostream>
using namespace std;
#define n 54

int order[n] = {0};
int a[n] = {0};
int b[n] = {0};

void func()
{
    for (int i = 0; i < n; i++)
        a[order[i] - 1] = b[i];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

int main()
{
    string repCards[n] = {""};
    string repLetter[5] = {"S", "H", "C", "D"};
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= 13; j++)
        {
            int pos = i * 13 + j - 1;
            repCards[pos] = repLetter[i] + to_string(j);
        }
    repCards[52] = "J1";
    repCards[53] = "J2";

    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> order[i];
        a[i] = i;
        b[i] = i;
    }

    for (int i = 0; i < k; i++)
        func();
    cout << repCards[a[0]];
    for (int i = 1; i < n; i++)
        cout << " " << repCards[a[i]];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 本质上和我的是一样的，scan，start，end三个数组

```c++
#include <cstdio>
using namespace std;
int main() {
    int cnt;
    scanf("%d", &cnt);
    int start[55], end[55], scan[55];
    for(int i = 1; i < 55; i++) {
        scanf("%d", &scan[i]);
        end[i] = i;
    }
    for(int i = 0; i < cnt; i++) {
        for(int j = 1; j < 55; j++)
            start[j] = end[j];
        for(int k = 1; k < 55; k++)
            end[scan[k]] = start[k];
    }
    char c[6] = {"SHCDJ"};
    for(int i = 1; i < 55; i++) {
        end[i] = end[i] - 1;
        printf("%c%d", c[end[i]/13], end[i]%13+1);
        if(i != 54) printf(" ");
    }
    return 0;
}
```



