# 1008 Elevator

> part 3, 3.0



## 自己解法

- 较为简单

```c++
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n, e;
    cin >> n;
    int d[100];
    int s = 0, cost = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        cost += ((s < e) ? (6 * (e - s)) : (4 * (s - e))) + 5;
        s = e;
    }
    cout << cost << endl;
    system("pause");
    return 0;
}
```



## 大神解法

```c++
#include <iostream>
using namespace std;
int main() {
    int a, now = 0, sum = 0;
    cin >> a;
    while(cin >> a) {
        if(a > now)
            sum = sum + 6 * (a - now);
        else
            sum = sum + 4 * (now - a);
        now = a;
        sum += 5;
    }
    cout << sum;
    return 0;
}
```