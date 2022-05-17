# 1028 List Sorting

> part 2, 2.1



## 自己解法

- 目前遇到的最简单的排序题


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int C;

struct student
{
    int ID;
    string name;
    int grades;
};

bool cmpC1(student a, student b)
{
    return a.ID < b.ID;
}
bool cmpC2(student a, student b)
{
    return a.name == b.name ? a.ID < b.ID : a.name < b.name;
}
bool cmpC3(student a, student b)
{
    return a.grades == b.grades ? a.ID < b.ID : a.grades < b.grades;
}

int main()
{
    int N;
    cin >> N >> C;
    vector<student> stu(N);
    for (int i = 0; i < N; i++)
        cin >> stu[i].ID >> stu[i].name >> stu[i].grades;
    if (C == 1)
        sort(stu.begin(), stu.end(), cmpC1);
    else if (C == 2)
        sort(stu.begin(), stu.end(), cmpC2);
    else
        sort(stu.begin(), stu.end(), cmpC3);
    for (int i = 0; i < N; i++)
    {
        printf("%06d", stu[i].ID);
        cout << " " << stu[i].name << " " << stu[i].grades << endl;
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
#include <string.h>
using namespace std;
const int maxn = 100001;
struct NODE {
    int no, score;
    char name[10];
}node[maxn];
int c;
int cmp1(NODE a, NODE b) {
    if(c == 1) {
        return a.no < b.no;
    } else if(c == 2) {
        if(strcmp(a.name, b.name) == 0) return a.no < b.no;
        return strcmp(a.name, b.name) <= 0;
    } else {
        if(a.score == b.score) return a.no < b.no;
        return a.score <= b.score;
    }
}
int main() {
    int n;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d %s %d", &node[i].no, node[i].name, &node[i].score);
    sort(node, node + n, cmp1);
    for(int i = 0; i < n; i++)
        printf("%06d %s %d\n", node[i].no, node[i].name, node[i].score);
    return 0;
}
```

