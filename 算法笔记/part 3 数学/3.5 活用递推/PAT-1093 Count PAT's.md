# 1093 Count PAT's

> part 3, 3.5



## 自己解法

- 本来说是啥活用递归，但是我不懂为啥要用递归hhh，我的思路和柳神一模一样，他的还要更简洁

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    string s;
    cin >> s;
    long long count = 0, cP = 0, cA = 0, cT = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P')
            cP++;
        else if (s[i] == 'A')
            cA++;
        else
            cT++;
    long long iP = 0, iT = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P')
            iP++;
        else if (s[i] == 'T')
            iT++;
        else
            count = (count + iP * (cT - iT)) % 1000000007;
    cout << count << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length(), result = 0, countp = 0, countt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'T')
            countt++;
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'P') countp++;
        if (s[i] == 'T') countt--;
        if (s[i] == 'A') result = (result + (countp * countt) % 1000000007) % 1000000007;
    }
    cout << result;
    return 0;
}
```

