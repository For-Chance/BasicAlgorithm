# 1083 List Grades

> part 2, 2.1



## 自己解法

- 太简单了，10分钟不到就好了


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct stu
{
    string name, ID;
    int grade;
};

bool cmp(stu a, stu b)
{
    return a.grade > b.grade;
}

int main()
{
    int N;
    cin >> N;
    vector<stu> s(N);
    for (int i = 0; i < N; i++)
        cin >> s[i].name >> s[i].ID >> s[i].grade;
    int g1, g2;
    cin >> g1 >> g2;
    sort(s.begin(), s.end(), cmp);
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].grade > g2)
            continue;
        if (s[i].grade < g1)
            break;
        flag = 1;
        cout << s[i].name << " " << s[i].ID << endl;
    }
    if (!flag)
        cout << "NONE" << endl;
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
struct stu {
    char name[12];
    char id[12];
    int grade;
};
int cmp1(stu a, stu b) {
    return a.grade > b.grade;
}
int main() {
    int n, low, high, cnt = 0;
    scanf("%d", &n);
    vector<stu> v(n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", v[i].name, v[i].id, &v[i].grade);
    }
    scanf("%d %d", &low, &high);
    for(int i = 0; i < n; i++) {
        if(v[i].grade < low || v[i].grade > high) {
            v[i].grade = -1;
        } else {
            cnt++;
        }
    }
    sort(v.begin(), v.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%s %s\n", v[i].name, v[i].id);
    }
    if(cnt == 0)
        printf("NONE");
    return 0;
}
```


