# 1048 Find Coins

> part 2, 2.0



## 自己解法(未全对)

- 2 WA 3,4 TO

- 可恶，直接用find太慢了

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    cin >> N >> M;
    int V1, V2;
    vector<int> d;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        d.push_back(n);
    }
    int flag = 0;
    sort(d.begin(), d.end());
    for (vector<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        int target = M - *it;
        vector<int>::iterator pos = find(d.begin(), d.end(), target);
        if (pos == d.end() || *pos == *it)
            continue;
        cout << *it << " " << *pos << endl;
        flag = 1;
        break;
    }
    if (flag == 0)
        cout << "No Solution" << endl;

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- woc，太秀了，这个输入

```c++
#include <iostream>
using namespace std;
int a[1001];
int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }
    for(int i = 0; i < 1001; i++) {
        if(a[i]) {
            a[i]--;
            if(m > i && a[m-i]) {
                printf("%d %d", i, m - i);
                return 0;
            }
            a[i]++;
        }
    }
    printf("No Solution");
    return 0;
}
```



## 总结

- vector.back() 取最后一个元素
- 若无需计数且输入数限制不大，可以用下标表示数字