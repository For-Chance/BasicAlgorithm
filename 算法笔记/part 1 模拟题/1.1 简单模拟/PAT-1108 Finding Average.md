# 1108 Finding Average

> part 1, 1.1



## 题意理解

- 输出合法字符的平均值

### Sample Input 1:

```in
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
```

### Sample Output 1:

```out
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
```

### Sample Input 2:

```in
2
aaa -9999
```

### Sample Output 2:

```out
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
```



## 自己解法

- 第三点没过

```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const double errorvalue = -10000.0;
    void findAverage(vector<string> &nums)
    {
        int n = nums.size();
        double sum = 0.0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            double value = getLegal(nums[i]);
            if (value == errorvalue)
                cout << "ERROR: " << nums[i] << " is not a legal number" << endl;
            else
            {
                cnt++;
                sum += value;
            }
        }
        if (cnt > 1)
            printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
        else if (cnt == 1)
            printf("The average of 1 number is %f\n", sum);
        else
            printf("The average of 0 numbers is Undefined\n");
    }

    double getLegal(string str)
    {
        // 不合法返回errorvalue
        int len = str.length();
        double value = 0;
        // 找到小数点
        int cnt_dot = 0, index_dot = len;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '.')
            {
                cnt_dot++;
                index_dot = i;
            }
        }
        if (cnt_dot > 1)
            return errorvalue;
        if (len - index_dot - cnt_dot > 2)
            return errorvalue;
        for (int i = 0; i < index_dot; i++)
        {
            if (str[i] == '-')
                continue;
            if (!isalnum(str[i]))
                return errorvalue;
            if (str[i] - '0' > 9)
                return errorvalue;
            value += (str[i] - '0') * pow(10, index_dot - i - 1);
        }
        for (int i = index_dot + 1; i < len; i++)
        {
            if (!isalnum(str[i]))
                return errorvalue;
            if (str[i] - '0' > 9)
                return errorvalue;
            value += (str[i] - '0') * pow(10, index_dot - i);
        }
        if (value > 1000)
            return errorvalue;
        if (str[0] == '-')
            value = -value;
        return value;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<string> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    solution.findAverage(nums);
    system("pause");
    return 0;
}
```



## 大神解法

- sscanf() – 从一个字符串中读进与指定格式相符的数据
- sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中

```c++
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++)
            if(a[j] != b[j]) flag = 1;
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}
```
