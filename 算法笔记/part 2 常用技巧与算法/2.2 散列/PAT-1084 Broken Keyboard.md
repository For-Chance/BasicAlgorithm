# 1084 Broken Keyboard

> part 2, 2.2



## 自己解法

- PAT 里面散列的题目都还挺简单的


```c++
#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    string s, v;
    cin >> s >> v;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        int pos = v.find(s[i]);
        if (pos == string::npos && res.find(s[i]) == string::npos)
            res += s[i];
    }

    cout << res << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string s1, s2, ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
            ans += toupper(s1[i]);
    cout << ans;
    return 0;
}
```

