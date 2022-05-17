# 1090 Highest Price in Supply Chain

> part 4, 4.3



## 自己解法

- 理解好题意就不难

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
double P, r;
int maxdepth = -1, count = 0;

vector<int> v[100000];

void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth > maxdepth)
        {
            maxdepth = depth;
            count = 1;
        }
        else if (depth == maxdepth)
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
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int k, begin;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k == -1)
            begin = i;
        else
            v[k].push_back(i);
    }
    bfs(begin, 0);
    printf("%.2f %d\n", P * pow(r, maxdepth), count);
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n, maxdepth = 0, maxnum = 0, temp, root;
vector<int> v[100010];
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        if(maxdepth == depth)
            maxnum++;
        if(maxdepth < depth) {
            maxdepth = depth;
            maxnum = 1;
        }
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(temp == -1)
            root = i;
        else
            v[temp].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d", p * pow(1 + r/100, maxdepth), maxnum);
    return 0;
}
```

