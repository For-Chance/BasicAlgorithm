# 1047 Student List for Course

> part 4, 4.0



## 自己解法

- 第二个WA，最后一个TO

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

vector<string> sName;

bool cmp(int a, int b)
{
    return sName[a] < sName[b];
}

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, vector<int>> m;
    for (int i = 0; i < N; i++)
    {
        int k;
        string name;
        cin >> name >> k;
        sName.push_back(name);
        int index;
        for (int j = 0; j < k; j++)
        {
            cin >> index;
            auto pos = m.find(index); // 这里都把index上调了一位
            if (pos == m.end())
            {
                vector<int> n;
                n.push_back(i);
                m.insert(make_pair(index, n));
            }
            else
                pos->second.push_back(i);
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second.size() << endl;
        sort(it->second.begin(), it->second.end(), cmp);
        for (int i = 0; i < it->second.size(); i++)
            cout << sName[it->second[i]] << endl;
    }
    system("pause");
    return 0;
}
```

- 改正了后没有TO，但是第二个依旧WA
- 速度上最主要的变化是cout改为了printf，

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

char sName[40010][5];

bool cmp(int a, int b)
{
    return strcmp(sName[a], sName[b]) < 0;
}

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, vector<int>> m;
    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%s %d\n", &sName[i], &k);
        int index;
        for (int j = 0; j < k; j++)
        {
            cin >> index;
            m[index].push_back(i);
        }
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second.size() << endl;
        sort(it->second.begin(), it->second.end(), cmp);
        for (int i = 0; i < it->second.size(); i++)
            printf("%s\n", sName[it->second[i]]);
    }
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
#include <string.h>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}
```

