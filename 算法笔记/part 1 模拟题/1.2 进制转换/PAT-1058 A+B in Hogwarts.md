# 1058 A+B in Hogwarts

> part 1, 1.2



## 自己解法

- 和柳神一笔，我的简直就是屎山
- 格式化输入！！！！

```c++
#include <iostream>
using namespace std;
#include <string>

void getnum(string s, int a[3])
{
    string al, bl;
    int pos, len;

    pos = s.find('.');
    bl = s.substr(0, pos);
    al = s.substr(pos + 1);
    a[0] = stoi(bl);

    pos = al.find('.');
    bl = al.substr(0, pos);
    al = al.substr(pos + 1);
    a[1] = stoi(bl);
    a[2] = stoi(al);
}

int main()
{
    string A, B;
    int Anum[3] = {0}, Bnum[3] = {0}, num[3] = {0};
    cin >> A >> B;
    getnum(A, Anum);
    getnum(B, Bnum);
    int c1 = 0, c2 = 0;
    num[2] = Anum[2] + Bnum[2];
    if (num[2] >= 29)
    {
        c2 = num[2] / 29;
        num[2] %= 29;
    }
    num[1] = Anum[1] + Bnum[1] + c2;
    if (num[1] >= 17)
    {
        c1 = num[1] / 17;
        num[1] %= 17;
    }
    num[0] = Anum[0] + Bnum[0] + c1;
    cout << num[0] << '.' << num[1] << '.' << num[2] << endl;

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
using namespace std;
int main() {
    int a1, b1, c1, a2, b2, c2, a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    c = c1 + c2;
    b = b1 + b2 + c / 29; c = c % 29;
    a = a1 + a2 + b / 17; b = b % 17;
    printf("%d.%d.%d\n", a, b, c);
    return 0;
}
```


