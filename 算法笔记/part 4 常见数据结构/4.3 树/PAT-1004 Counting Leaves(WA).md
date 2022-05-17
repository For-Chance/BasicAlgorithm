# 1004 Counting Leaves	

> part 4, 4.3



## 自己解法

- hierarchy 层次结构
- 圆括号
  `vector<int> v(n)`：圆括号是构造函数，表示1个容量为n的vector
  方括号
  `vector<int> v[n]`:**表示n个vector** v ，二维数组
  相当于 `vector<vector<int > > v(n)；`二维数组

```c++
#include <iostream>
using namespace std;
#include <vector>

vector<int> v[100];
int book[100] = {0}, maxdepth = -1; // book标记每一层有多少个叶子节点，maxdepth记录最大的深度，方便之后的输出

void dfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
    }
    else
        for (int i = 0; i < v[index].size(); i++)
            dfs(v[index][i], depth + 1);
}

int main()
{
    int N, M;
    cin >> N >> M;
    int nodeID, k, c;
    for (int i = 0; i < M; i++)
    {
        cin >> nodeID >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            v[nodeID].push_back(c);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= maxdepth; i++)
        if (i != 0)
            cout << " " << book[i];
        else
            cout << book[i];
    cout << endl;
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int book[100], maxdepth = -1;
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
    return 0;
}
```

