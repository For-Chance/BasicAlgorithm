# 1100 Mars Numbers

> part 4, 4.0



## 自己解法

- shit code！
- 如果使用getline，那么它前一个也必须是getline或者cin加getchar，不然会读入换行符

```c++
#include <iostream>
using namespace std;

int main()
{
    string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string s2[13] = {"XXX", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++)
    {
        string a;
        getline(cin, a);
        if (isdigit(a[0]))
        {
            int n = stoi(a);
            int n2 = n / 13, n1 = n % 13;
            if (n <= 12)
                cout << s1[n1] << endl;
            else
            {
                cout << s2[n2];
                if (n1 != 0)
                    cout << " " << s1[n1];
                cout << endl;
            }
        }
        else
        {
            if (a.length() > 5)
            {
                string a2 = a.substr(0, 3), a1 = a.substr(4, 3); // 不会有tret
                int num = 0;
                for (int j = 0; j < 13; j++)
                {
                    if (s2[j] == a2)
                        num += j * 13;
                    if (s1[j] == a1)
                        num += j;
                }
                cout << num << endl;
            }
            else
            {
                for (int j = 0; j < 13; j++)
                    if (s1[j] == a)
                    {
                        cout << j << endl;
                        break;
                    }
                    else if (s2[j] == a)
                    {
                        cout << j * 13 << endl;
                        break;
                    }
            }
        }
    }
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
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string s;
int len;
void func1(int t) {
    if (t / 13) cout << b[t / 13];
    if ((t / 13) && (t % 13)) cout << " ";
    if (t % 13 || t == 0) cout << a[t % 13];
}
void func2() {
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (len > 4) s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++) {
        if (s1 == a[j] || s2 == a[j]) t2 = j;
        if (s1 == b[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else
            func2();
        cout << endl;
    }
    return 0;
}
```

