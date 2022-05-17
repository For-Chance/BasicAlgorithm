# 1006 Sign In and Sign Out

> part 1, 1.3



## 自己解法

```c++
#include <iostream>
using namespace std;
#include <string>

int main()
{
    int M;
    cin >> M;
    string earliest, latest;
    int e[3] = {24}, l[3] = {0};
    while (M--)
    {
        string name;
        int sh, sm, ss, eh, em, es;
        cin >> name;
        scanf("%d:%d:%d %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);

        if (sh < e[0] || (sh == e[0] && sm < e[1]) || (sh == e[0] && sm == e[1] && ss < e[2]))
        {
            earliest = name;
            e[0] = sh;
            e[1] = sm;
            e[2] = ss;
        }
        if (eh > l[0] || (eh == l[0] && em > l[1]) || (eh == l[0] && em == l[1] && es > l[2]))
        {
            latest = name;
            l[0] = eh;
            l[1] = em;
            l[2] = es;
        }
    }
    cout << earliest << " " << latest << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, minn = INT_MAX, maxn = INT_MIN;
    scanf("%d", &n);
    string unlocked, locked;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        int tempIn = h1 * 3600 + m1 * 60 + s1;
        int tempOut = h2 * 3600 + m2 * 60 + s2;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = t;
        }
        if (tempOut > maxn) {
            maxn = tempOut;
            locked = t;
        }
    }
    cout << unlocked << " " << locked;
    return 0;
}
```



## 总结

- string 类型只能用 cin输入，而不能用scanf输入
