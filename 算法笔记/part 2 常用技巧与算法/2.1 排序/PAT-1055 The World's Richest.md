# 1055 The World's Richest

> part 2, 2.1



## 自己解法

- 2 TO
- 属实是被柳神的分析击中了
- N 是 $10^5$，而 M 小于$10^3$，因此这里主要是排序慢，所以下面这里我即使用了二分查找也很慢。


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

struct person
{
    string name;
    int age;
    int worth;
};

bool cmp(person a, person b)
{
    return a.age < b.age;
}

bool cmp2(person a, person b)
{
    return a.worth != b.worth ? a.worth > b.worth : (a.age != b.age ? a.age < b.age : a.name < b.name);
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<person> ps(N);
    for (int i = 0; i < N; i++)
        cin >> ps[i].name >> ps[i].age >> ps[i].worth;
    sort(ps.begin(), ps.end(), cmp);
    // for (int i = 0; i < N; i++)
    //     cout << ps[i].name << " " << ps[i].age << " " << ps[i].worth << endl;
    vector<person> temp;
    for (int i = 0; i < K; i++)
    {
        temp.clear(); //这种方法不回收空间
        int M, Amin, Amax;
        cin >> M >> Amin >> Amax;
        // 下面这个循环可以用二分替代
        int count = 0;
        int j = 0;
        // if (ps[(j + N) / 2].age < Amin)
        //     j = (j + N) / 2;
        int low = 0, high = N - 1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (ps[mid].age < Amin)
                if (ps[mid + 1].age >= Amin)
                {
                    j = mid + 1;
                    break;
                }
                else
                    low = mid + 1;
            else if (ps[mid].age >= Amin)
                if (ps[mid - 1].age < Amin)
                {
                    j = mid;
                    break;
                }
                else
                    high = mid - 1;
        }
        for (; j < N; j++)
        {
            if (ps[j].age < Amin)
                continue;
            if (ps[j].age > Amax)
                break;
            temp.push_back(ps[j]);
            count++;
        }
        sort(temp.begin(), temp.end(), cmp2);
        cout << "Case #" << i + 1 << ":" << endl;
        if (temp.size() == 0)
        {
            cout << "None" << endl;
            continue;
        }
        int x = min(M, count);
        for (int j = 0; j < x; j++)
        {
            cout << temp[j].name << " " << temp[j].age << " " << temp[j].worth << endl;
        }
    }
    system("pause");
    return 0;
}
```





## 大神解法

- 柳神
- 分析：不能先排序然后根据没一个条件再新建一个数组，对新数组排序的方法，这样测试点2会超时～因为n和m的悬殊太大了，n有10的5次方，m却只有100个。所以先把所有的人按照财富值排序，再建立一个数组book标记每个年龄段拥有的人的数量，遍历数组并统计相应年龄的人数，当当前年龄的人的数量不超过100的时候压入新的数组，否则就不要压入新的数组。因为无论怎样的年龄区间，查询人数都不会超过100个人，所以最多只要取每个年龄的前100个财富值的人到新的数组里面就可，再从这个新的数组里面取符合相应年龄的人的信息～

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct node {
    char name[10];
    int age, money;
};
int cmp1(node a, node b) {
    if(a.money != b.money)
        return a.money > b.money;
    else if(a.age != b.age)
        return a.age < b.age;
    else
        return (strcmp(a.name, b.name) < 0);
}
 
int main() {
    int n, k, num, amin, amax;
    scanf("%d %d", &n, &k);
    vector<node> vt(n), v;
    vector<int> book(205, 0);
    for(int i = 0; i < n; i++)
        scanf("%s %d %d", vt[i].name, &vt[i].age, &vt[i].money);
    sort(vt.begin(), vt.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(book[vt[i].age] < 100) {
            v.push_back(vt[i]);
            book[vt[i].age]++;
        }
    }
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &num, &amin, &amax);
        vector<node> t;
        for(int j = 0; j < v.size(); j++) {
            if(v[j].age >= amin && v[j].age <= amax)
                t.push_back(v[j]);
        }
        if(i != 0) printf("\n");
        printf("Case #%d:", i + 1);
        int flag = 0;
        for(int j = 0; j < num && j < t.size(); j++) {
            printf("\n%s %d %d", t[j].name, t[j].age, t[j].money);
            flag = 1;
        }
        if(flag == 0) printf("\nNone");
    }
    return 0;
}
```

