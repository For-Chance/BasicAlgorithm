# 1069 The Black Hole of Numbers

> part 3, 3.0



## 自己解法

- 输入是0-10000

```c++
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

void calBlack(string N)
{
    int N_size = N.size();
    if (N_size != 4)
    {
        string x0 = "";
        x0.assign(4 - N_size, '0');
        N.append(x0);
    }
    sort(N.begin(), N.end());
    string M = N;
    reverse(M.begin(), M.end());
    int Nnum = stoi(N);
    int Mnum = stoi(M);
    int black = Mnum - Nnum;
    printf("%04d - %04d = %04d\n", Mnum, Nnum, black);
    if (!(Mnum == Nnum || black == 6174))
        calBlack(to_string(black));
}

int main()
{
    string N;
    cin >> N;
    calBlack(N);

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a, char b) {return a > b;}
int main() {
    string s;
    cin >> s;
    s.insert(0, 4 - s.length(), '0');
    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        int result = stoi(a) - stoi(b);
        s = to_string(result);
        s.insert(0, 4 - s.length(), '0');
        cout << a << " - " << b << " = " << s << endl;
    } while (s != "6174" && s != "0000");
    return 0;
}
```

