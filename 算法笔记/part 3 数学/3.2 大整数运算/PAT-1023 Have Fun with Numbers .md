# 1023 Have Fun with Numbers

> part 3, 3.2



## 自己解法

- 理解题意
  - permutation：排列
- 注意溢出照样输出

```c++
#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    string n, m = "", x;
    cin >> n;
    string c = n;
    int s = 0, d, flag = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        d = (n[i] - '0') * 2 + s;
        s = d / 10;
        x = to_string(d % 10);
        if (flag == 0 || c.find(x) == string::npos)
            flag = 0;
        else
            c[c.find(x)] = ' ';
        m.append(x);
    }
    if (s != 0)
        m.append(to_string(s));
    reverse(m.begin(), m.end());
    if (flag == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << m << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <cstdio>
#include <string.h>
using namespace std;
int book[10];
int main() {
    char num[22];
    scanf("%s", num);
    int flag = 0, len = strlen(num);
    for(int i = len - 1; i >= 0; i--) {
        int temp = num[i] - '0';
        book[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if(temp >= 10) {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;
    }
    int flag1 = 0;
    for(int i = 0; i < 10; i++) {
        if(book[i] != 0)
            flag1 = 1;
    }
    printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
    if(flag == 1) printf("1");
    printf("%s", num);
    return 0;
}
```

