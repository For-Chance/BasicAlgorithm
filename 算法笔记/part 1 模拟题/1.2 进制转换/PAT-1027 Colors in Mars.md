# 1027 Colors in Mars

> part 1, 1.2



## 自己解法

```c++
#include <iostream>
using namespace std;

void printColor(int c)
{
    int qu, re;
    qu = c / 13;
    re = c % 13;
    char repColor[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    cout << repColor[qu] << repColor[re];
}

int main()
{
    int R, G, B;
    cin >> R >> G >> B;
    cout << "#";
    printColor(R);
    printColor(G);
    printColor(B);
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <cstdio>
using namespace std;
int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}
```



## 总结

- 很简单的一题了
