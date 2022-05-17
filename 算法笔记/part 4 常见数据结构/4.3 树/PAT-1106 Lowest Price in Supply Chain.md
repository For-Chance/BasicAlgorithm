# 1106 Lowest Price in Supply Chain

> part 4, 4.3



## 自己解法

- 和1090一个模子

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
int minDepth = 1000000, count = 0;

vector<int> v[100000];

void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth < minDepth)
        {
            minDepth = depth;
            count = 1;
        }
        else if (depth == minDepth)
            count++;
        return;
    }
    else
        for (int i = 0; i < v[index].size(); i++)
            bfs(v[index][i], depth + 1);
}

int main()
{
    int N;
    double P, r;
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int k, c;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            v[i].push_back(c);
        }
    }
    bfs(0, 0);
    printf("%.4f %d\n", pow(r, minDepth) * P, count);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100005];
int mindepth = 99999999, minnum = 1;
void dfs(int index, int depth) {
    if(mindepth < depth)
        return ;
    if(v[index].size() == 0) {
        if(mindepth == depth)
            minnum++;
        else if(mindepth > depth) {
            mindepth = depth;
            minnum = 1;
        }
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, k, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[i].push_back(c);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r/100, mindepth), minnum);
    return 0;
}
```

