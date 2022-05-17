# 1079 Total Sales of Supply Chain

> part 4, 4.3



## 自己解法

- 理解好题意就不难

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
double P, r;
double price = 0;

vector<int> v[100000];
vector<int> retailsPrice(100000);

void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        price += pow(r, depth) * P * retailsPrice[index];
        return;
    }
    else
    {
        for (int i = 0; i < v[index].size(); i++)
            bfs(v[index][i], depth + 1);
    }
}

int main()
{
    int N;
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int k, c;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k != 0)
            for (int j = 0; j < k; j++)
            {
                cin >> c;
                v[i].push_back(c);
            }
        else
            cin >> retailsPrice[i];
    }
    bfs(0, 0);
    printf("%.1f\n", price);
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
struct node {
    double data;
    vector<int> child;
};
vector<node> v;
double ans = 0.0, p, r;
 
void dfs(int index, int depth) {
    if(v[index].child.size() == 0) {
        ans += v[index].data * pow(1 + r, depth);
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++)
        dfs(v[index].child[i], depth + 1);
}
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k == 0) {
            scanf("%lf", &v[i].data);
        } else {
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", ans * p);
    return 0;
}
```

