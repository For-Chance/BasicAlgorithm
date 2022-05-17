# 1054 The Dominant Color

> part 4, 4.0



## 自己解法

- the largest proportional area 比例最大的地区；

```c++
#include <iostream>
using namespace std;
#include <map>

int main()
{
    int M, N;
    cin >> M >> N;
    map<int, int> m;
    int half = M * N / 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            m[x]++;
            if (m[x] > half)
            {
                cout << m[x] << endl;
                return 0;
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
#include <map>
using namespace std;
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    map<int, int> arr;
    int half = m * n / 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            arr[temp]++;
            if(arr[temp] > half) {
                printf("%d", temp);
                return 0;
            }
        }
    }
    return 0;
}
```

