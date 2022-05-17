# 1024 Palindromic Number

> part 3, 3.2



## 自己解法

- 2 3 WA，有知道的告诉我

```c++
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string add(string n)
{
    string m = n;
    reverse(m.begin(), m.end());
    int s = 0, d;
    string res = "";
    for (int i = n.size() - 1; i >= 0; i--)
    {
        d = (n[i] - '0') + (m[i] - '0') + s;
        s = d / 10;
        res.append(to_string(d % 10));
    }
    if (s != 0)
        res.append(to_string(s));
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string N;
    int K, i;
    cin >> N >> K;
    for (i = 1; i <= K; i++)
    {
        N = add(N);
        string M = N;
        reverse(M.begin(), M.end());
        if (N == M || i == K)
            break;
    }
    cout << N << endl
         << i << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <algorithm>
using namespace std;
string s;
void add(string t) {
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++) {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
}
int main() {
    int cnt, i;
    cin >> s >> cnt;
    for(i = 0; i <= cnt; i++) {
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t || i == cnt) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}
```

