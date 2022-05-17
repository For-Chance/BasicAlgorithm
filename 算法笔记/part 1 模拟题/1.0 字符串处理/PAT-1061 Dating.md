# 1061 Dating

> part 1, 1.0

## 题目理解

INPUT: 两对字符串

- 前两个字符串共有且位置相同的第一个大写字母 ABCDEFG 表示 星期几
- 前两个字符串共有且位置相同且在第一个大写字母后边的数字或者大写字母 表示 时
- 后两个字符串共有且位置相同的字母所在位置代表 分

OUTPUT: 约会时间



## 自己解法(未全对)

```c++
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

void getDaynHour(string s1, string s2)
{
    string repDay[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string repHour = "0123456789ABCDEFGHIJKLMN";
    string Day;
    int Hour;
    int flag = 0; // flag = 0 表示 Day 还没找到，不能找 Hour
    for (int i = 0; i < s1.length(); i++)
        for (int j = 0; j < s2.length(); j++)
        {
            if (flag == 1 && s1[i] == s2[j] && i == j && repHour.find(s1[i]) != string::npos)
            {
                Hour = repHour.find(s1[i]);
                break;
            }
            if (s1[i] == s2[j] && i == j && s1[i] - 'A' < 7 && s1[i] - 'A' >= 0 && flag == 0)
            {
                Day = repDay[s1[i] - 'A'];
                flag = 1;
            }
        }
    cout << Day << " ";
    printf("%02d:", Hour);
}

void getMinute(string s3, string s4)
{
    string repMinute = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int Minute;
    for (int i = 0; i < s3.length(); i++)
        for (int j = 0; j < s4.length(); j++)
        {
            if (s3[i] == s4[j] && i == j && repMinute.find(s3[i]) != string::npos)
            {
                Minute = i;
                break;
            }
        }
    printf("%02d", Minute);
}

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    getDaynHour(s1, s2);
    getMinute(s3, s4);
    cout << endl;
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
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    char t[2];
    int pos, i = 0, j = 0;
    while(i < a.length() && i < b.length()) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            break;
        }
        i++;
    }
    i = i + 1;
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length()) {
        if (c[j] == d[j] && isalpha(c[j])) {
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    cout << week[t[0]-'A'];
    printf("%02d:%02d", m, pos);
    return 0;
}
```



## 总结

- 理解清楚题目要求就好