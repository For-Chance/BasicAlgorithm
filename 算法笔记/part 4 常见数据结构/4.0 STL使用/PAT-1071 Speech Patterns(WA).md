# 1071 Speech Patterns

> part 4, 4.0



## 自己解法

- alphanumerical 字母数字混合的； lexicographically 字母顺序

```c++

```



## 大神解法

- 柳神
- **[0-9 A-Z a-z]可以简写为cctype头文件里面的一个函数isalnum**

```c++
#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1){
            if(t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;
    return 0;
}
```

