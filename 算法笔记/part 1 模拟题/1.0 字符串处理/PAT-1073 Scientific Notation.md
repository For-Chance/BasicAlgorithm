# 1073 Scientific Notation

> part 1, 1.0



## 自己解法

```c++
#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s;
    cin >> s;
    string snum1 = "", snum2 = ""; // 表示前后两个数字
    int pos_split = s.find("E");
    int s_len = s.length();
    snum1 = s.substr(0, pos_split);
    snum2 = s.substr(pos_split + 1);
    int num2 = stoi(snum2);
    // 把sum1 继续拆分
    string sign = snum1.substr(0, 1);
    sign = (sign == "+") ? "" : "-";
    string b_dim = snum1.substr(1, 1);
    string a_dim = snum1.substr(3);
    string result = "";
    int shift_pos = 0; // 移动的位数
    if (num2 >= 0)
    {
        int a_dim_len = a_dim.length();
        if (num2 >= a_dim_len)
        {
            string s_zero;
            s_zero.assign(num2 - a_dim_len, '0');
            result += sign + b_dim + a_dim + s_zero;
        }
        else
            result += sign + b_dim + a_dim.substr(0, num2) + "." + a_dim.substr(num2);
    }
    else
    {
        string s_zero;
        s_zero.assign((-num2) - 1, '0');
        result += sign + "0." + s_zero + b_dim + a_dim;
    }
    cout << result << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') i++;
    string t = s.substr(1, i-1);
    int n = stoi(s.substr(i+1));
    if (s[0] == '-') cout << "-";
    if (n < 0) {
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    } else {
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}
```



## 总结

- 由输入字符串不超过9999，则无法将其直接转为数字，而是在字符串之间进行转换
- 指数绝对值不超过9999，其可以转换为int
- stoi(string s): string 转 int
- 顺理成章的逻辑，不难