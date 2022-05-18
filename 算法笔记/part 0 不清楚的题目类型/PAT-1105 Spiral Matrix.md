# 1105 Spiral Matrix

> part 0



## 题意理解

- 给一串数字，将其排列成回转矩阵

### Sample Input:

```in
12
37 76 20 98 76 42 53 95 60 81 58 93
```

### Sample Output:

```out
98 95 93
42 37 81
53 20 76
58 60 76
```



## 自己解法

- 莫名其妙段错误
- 要画图判断一些，还是要先想好再写代码

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    int n, m = sqrt(N) + 1;
    for (; m <= N; m++)
        if (N % m == 0)
        {
            n = N / m;
            break;
        }
    vector<vector<int>> result(m, vector<int>(n));
    int k = m, z = n;
    int row = 0, col = 0, i = 0, level = m / 2 + m % 2;
    for (int j = 0; j < level; j++)
    {

        while (col < n - 1 - j && N != i)
        {
            result[row][col++] = v[i++];
        }
        while (row < m - 1 - j && N != i)
        {
            result[row++][col] = v[i++];
        }
        while (col > j && N != i)
        {
            result[row][col--] = v[i++];
        }
        while (row > j && N != i)
        {
            result[row--][col] = v[i++];
        }
        row++;
        col++;
    }
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < z; y++)
            if (y != z - 1)
                cout << result[x][y] << " ";
            else
                cout << result[x][y] << endl;
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int cmp(int a, int b) {return a > b;}
int main() {
    int N, m, n, t = 0;
    scanf("%d", &N);
    for (n = sqrt((double)N); n >= 1; n--) {
        if (N % n == 0) {
            m = N / n;
            break;
        }
    }
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), cmp);
    vector<vector<int> > b(m, vector<int>(n));
    int level = m / 2 + m % 2;
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
                b[i][j] = a[t++];
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
                b[j][n - 1 - i] = a[t++];
        for (int j = n - i - 1; j >= i && t <= N - 1; j--)
                b[m - 1 - i][j] = a[t++];
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
                b[j][i] = a[t++];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", b[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
```

