# 1049 Counting Ones

> part 3, 3.0



## 自己解法

- 没搞清楚

```c++
#include <iostream>
using namespace std;
#include <math.h>

int countOnes(string n)
{
    long long sum = 0;
    if (n.size() == 1)
    {
        int a = n[0] - '0';
        if (a >= 1)
            sum++;
    }
    else
    {
        for (int i = 0; i < n.size(); i++)
        {
            int a = n[i] - '0';
            if (a == 0)
                continue;
            else if (a == 1)
                if (i != n.size() - 1)
                    sum += stoi(n.substr(i + 1)) + 1;
                else
                    sum++;
            else
                sum += pow(10, n.size() - i - 1);
            if (i != 0)
                sum += stoi(n.substr(0, i));
        }
    }
    return sum;
}

int main()
{
    string n;
    cin >> n;
    cout << countOnes(n) << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- 分析：这是一道数学问题。从第一位（个位）到最高位，设now为当前位的数字，left为now左边的所有数字构成的数字，right是now右边的所有数字构成的数字。只需要一次次累加对于当前位now来说可能出现1的个数，然后把它们累加即可。a表示当前的个位为1，十位为10，百位为100类推。

  对于now，有三种情况：

  1.now == 0 : 那么 ans += left * a; //因为now==0说明now位只有在left从0~left-1的时候会产生1，所以会产生left次，但是又因为右边会重复从0~999...出现a次

  2.now == 1 : ans += left * a + right + 1;//now = 1的时候就要比上一步多加一个当now为1的时候右边出现0~right个数导致的now为1的次数

  3.now >= 2 : ans += (left + 1) * a;//now大于等于2就左边0~left的时候会在now位置产生1，所以会产生left次，但是又因为右边会重复从0~999...出现a次

```c++
#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}
```
