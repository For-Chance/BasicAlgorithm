# 1039 Course List for Student

> part 4, 4.0



## 自己解法

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    int N, K;
    cin >> N >> K;
    map<string, vector<int>> m;
    for (int i = 0; i < K; i++)
    {
        int index, n;
        cin >> index >> n;
        for (int j = 0; j < n; j++)
        {
            string name;
            cin >> name;
            auto pos = m.find(name);
            if (pos == m.end())
            {
                vector<int> n;
                n.push_back(index);
                m.insert(make_pair(name, n));
            }
            else
                pos->second.push_back(index);
        }
    }
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        auto pos = m.find(name);
        if (pos == m.end())
            cout << name << " " << 0 << endl;
        else
        {
            sort(pos->second.begin(), pos->second.end());
            cout << pos->first << " " << pos->second.size();
            for (int j = 0; j < pos->second.size(); j++)
                cout << " " << pos->second[j];
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
```



## 大神解法

- 柳神
- 这里是用了hash，**使用hash(26\*26\*26\*10+10)将学生姓名变为int型，然后存储在vector里面**

```c++
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int getid(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
 
int main() {
    int n, k, no, num, id = 0;
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for(int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getid(name);
            v[id].push_back(no);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        id = getid(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %lu", name, v[id].size());
        for(int j = 0; j < v[id].size(); j++)
            printf(" %d", v[id][j]);
        printf("\n");
    }
    return 0;
}
```

