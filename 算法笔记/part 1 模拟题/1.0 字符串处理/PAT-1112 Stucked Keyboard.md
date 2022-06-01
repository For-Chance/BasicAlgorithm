# 1112 Stucked Keyboard

> part 1, 1.0



## 题意理解

- 键盘某些键卡住了，按一次重复k次，要求找出可能的键，并且输出正确的字符串顺序。可能的键要求按照被发现的顺序输出～

### Sample Input:

```in
3
caseee1__thiiis_iiisss_a_teeeeeest
```

### Sample Output:

```out
ei
case1__this_isss_a_teest
```



## 自己解法

- 写得很乱，并且只能过三

```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fixedUp(int k, string str)
    {
        unordered_set<char> hashtable;
        int n = str.length();
        int nowCharCount = 1;
        char nowChar = str[0];
        for (int i = 1; i < n; i++)
        {
            if (str[i] == nowChar)
            {
                nowCharCount++;
                if (nowCharCount == k)
                {
                    nowCharCount = 0;
                    if (hashtable.find(nowChar) == hashtable.end())
                        hashtable.insert(nowChar);
                    continue;
                }
                if (i + 1 < n && str[i] != str[i + 1])
                {
                    auto pos = hashtable.find(nowChar);
                    if (pos != hashtable.end())
                        hashtable.erase(pos);
                }
            }
            else
            {
                nowCharCount = 1;
                nowChar = str[i];
                auto pos = hashtable.find(nowChar);
                if (pos != hashtable.end())
                    hashtable.erase(pos);
            }
        }
        string res1 = "";
        for (auto it = hashtable.begin(); it != hashtable.end(); it++)
            res1 += *it;
        string res2 = "";
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            auto pos = hashtable.find(str[i]);
            if (pos == hashtable.end())
            {
                cnt = 0;
                res2 += str[i];
            }
            else
            {
                cnt++;
                if (cnt == k)
                {
                    res2 += str[i];
                    cnt = 0;
                }
            }
        }
        return {res1, res2};
    }
};

int main()
{
    int N;
    cin >> N;
    string str;
    cin >> str;
    Solution solution;
    vector<string> res = solution.fixedUp(N, str);
    cout << res[0] << endl
         << res[1] << endl;
    system("pause");
    return 0;
}
```



## 大神解法

```c++

```