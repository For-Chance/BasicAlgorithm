# 1002 A+B for Polynomials

> part 1, 1.1



## 自己解法

- 使用两个map去存储数据

```c++
#include <iostream>
using namespace std;
#include <map>
#include <algorithm>
#include <iomanip>

int main()
{
    map<int, float, greater<int>> p1;
    int n1;
    cin >> n1;
    while (n1--)
    {
        int N;
        float aN;
        cin >> N;
        cin >> aN;
        p1.insert(make_pair(N, aN));
    }
    map<int, float, greater<int>> p2;
    int n2;
    cin >> n2;
    while (n2--)
    {
        int N;
        float aN;
        cin >> N;
        cin >> aN;
        p2.insert(make_pair(N, aN));
    }

    for (map<int, float>::iterator it = p2.begin(); it != p2.end(); it++)
    {
        map<int, float>::iterator pos = p1.find(it->first);
        if (pos != p1.end())
        {
            pos->second += it->second;
            if (pos->second == 0.0)
                p1.erase(pos->first);
        }
        else
            p1.insert(make_pair(it->first, it->second));
    }

    cout << p1.size();
    for (map<int, float>::iterator it = p1.begin(); it != p1.end(); it++)
        cout << " " << it->first << " " << fixed << setprecision(1) << it->second;
    cout << endl;

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 直接用一个大c数组去存储最终的结果，相对而言更加简洁

```c++
#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};
    int m, n, t;
    float num;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (c[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
```



## 总结

- 注意，值为0不输出