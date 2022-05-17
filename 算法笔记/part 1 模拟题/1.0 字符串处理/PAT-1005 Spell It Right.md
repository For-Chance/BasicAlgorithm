# 1005 Spell It Right

> part 1, 1.0

## 自己解法

```c++
#include <iostream>
using namespace std;
int main()
{
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string n;
    cin >> n;
    int len = n.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += n[i] - '0';
    }
    string s_sum = to_string(sum);
    int len_sum = s_sum.length();
    for (int j = 0; j < len_sum; j++)
    {
        cout << s[s_sum[j] - '0'];
        if (j != len_sum - 1)
            cout << " ";
    }
    cout << "\n";
    // system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
using namespace std;
int main() {
    string a;
    cin >> a;
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
        sum += (a[i] - '0');
    string s = to_string(sum);
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << arr[s[0] - '0'];
    for (int i = 1; i < s.length(); i++)
        cout << " " << arr[s[i] - '0'];
    return 0;
}
```



## 总结

- 输入$N<10^{100}$，因此用字符串存放输入