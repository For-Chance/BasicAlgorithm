# 1041 Be Unique

> part 2, 2.2



## 自己解法

- 注意看好输入的数字的范围，下面第10行写成10000就会有段错误


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <string.h>

int main()
{
    int N;
    cin >> N;
    int d[10001];
    memset(d, 0, 10001);
    vector<int> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
        d[s[i]]++;
    }
    int j;
    for (j = 0; j < N; j++)
        if (d[s[j]] == 1)
            break;
    if (j == N)
        cout << "None" << endl;
    else
        cout << s[j] << endl;

    system("pause");
    return 0;
}
```





## 大神解法

- 柳神

```c++
#include <cstdio>
using namespace std;
int a[100001], m[100000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(m[a[i]] == 1) {
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}
```

