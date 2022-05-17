# 1062 Talent and Virtue

> part 2, 2.1



## 自己解法

- 认真读题！(惨痛教训)


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class person
{
public:
    person(int ID, int V, int T, int H)
    {
        this->ID = ID;
        this->V = V;
        this->T = T;
        this->sum = V + T;
        if (V >= H && T >= H)
            this->flag = 1;
        else if (V >= H && T < H)
            this->flag = 2;
        else if (V < H && V >= T)
            this->flag = 3;
        else
            this->flag = 4;
    }

    int ID;
    int V, T;
    int sum, flag; // flag = 1 是 sages(V>=H,T>=H)，flag = 2 是 nobleman(V>=H,T<H), flag = 3 是 foolman(T=<V<H)
};

bool cmp(person a, person b)
{
    return a.flag != b.flag ? a.flag < b.flag : (a.sum != b.sum ? a.sum > b.sum : (a.V != b.V ? a.V > b.V : a.ID < b.ID));
}

int main()
{
    int N, L, H;
    cin >> N >> L >> H;
    vector<person> v;
    for (int i = 0; i < N; i++)
    {
        int ID, V, T;
        cin >> ID >> V >> T;
        if (V >= L && T >= L)
        {
            person p(ID, V, T, H);
            v.push_back(p);
        }
    }
    sort(v.begin(), v.end(), cmp);
    int v_size = v.size();
    cout << v_size << endl;
    for (int i = 0; i < v_size; i++)
        cout << v[i].ID << " " << v[i].V << " " << v[i].T << endl;

    system("pause");
    return 0;
}
```





## 大神解法

- 柳神

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int num, de, cai;
};
int cmp(struct node a, struct node b) {
    if ((a.de + a.cai) != (b.de + b.cai))
        return (a.de + a.cai) > (b.de + b.cai);
    else if (a.de != b.de)
        return a.de > b.de;
    else
        return a.num < b.num;
}
int main() {
    int n, low, high;
    scanf("%d %d %d", &n, &low, &high);
    vector<node> v[4];
    node temp;
    int total = n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &temp.num, &temp.de, &temp.cai);
        if (temp.de < low || temp.cai < low)
            total--;
        else if (temp.de >= high && temp.cai >= high)
            v[0].push_back(temp);
        else if (temp.de >= high && temp.cai < high)
            v[1].push_back(temp);
        else if (temp.de < high && temp.cai < high && temp.de >= temp.cai)
            v[2].push_back(temp);
        else
            v[3].push_back(temp);
    }
    printf("%d\n", total);
    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end(), cmp);
        for (int j = 0; j < v[i].size(); j++)
            printf("%d %d %d\n", v[i][j].num, v[i][j].de, v[i][j].cai);
    }
    return 0;
}
```

