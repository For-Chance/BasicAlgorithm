# 1001 A+B Format

> part 1, 1.0

## 自己解法

```c++
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        cout << s[i];
        if ((len - i - 1) % 3 == 0 && len - i - 1 != 0 && s[i] != '-')
            cout << ',';
    }
    cout << "\n";
    return 0;
}
```



## 大神解法

```c++
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        cout << s[i];
        if (s[i] == '-') continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
    }
    return 0;
}
```



## 总结

- **string**类型，to_string()
- 从后向前看，每三个且不是最后一个和不是符号就加逗号