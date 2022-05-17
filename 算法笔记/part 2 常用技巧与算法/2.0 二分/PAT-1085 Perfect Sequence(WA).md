# **1085 Perfect Sequence** 

> part 2, 2.0



## 自己解法

- 


```c++

```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int result = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + result; j < n; j++) {
            if (v[j] <= v[i] * p) {
                temp = j - i + 1;
                if (temp > result)
                    result = temp;
            } else {
                break;
            }
        }
    }
    cout << result;
    return 0;
}
```



## 总结

- vector 相较于数组不需要考虑空间溢出的问题，此时用上面这种方法可以代替数组，更加方便
- 注意当涉及到 10 的九次方时，就需要考虑溢出了，这里 m * p 有可能溢出，所以 p 用 long long