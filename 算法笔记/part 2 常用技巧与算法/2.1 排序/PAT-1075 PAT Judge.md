# 1075 PAT Judge

> part 2, 2.1



## 自己解法(未全对)

- 看了柳神的，还是不太清楚第四个测试哪错了


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// K <= 5
int partial_score[5];

struct person
{
    int uid = -1;
    int rank = 0, total_score = 0;
    int s[5] = {-1, -1, -1, -1, -1};
    bool isshow = false;
};

int countP(person p)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
        if (partial_score[i] == p.s[i])
            count++;
    return count;
}

bool cmp(person a, person b)
{
    if (a.isshow == true && b.isshow == false)
        return true;
    else if (a.isshow == false && b.isshow == true)
        return false;
    else
        return a.total_score != b.total_score ? a.total_score > b.total_score : (countP(a) != countP(b) ? countP(a) > countP(b) : a.uid < b.uid);
}

int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    for (int i = 0; i < K; i++)
        cin >> partial_score[i];
    vector<person> v(N + 1);
    for (int i = 0; i < M; i++)
    {
        int uid, nid, pso;
        cin >> uid >> nid >> pso;
        if (pso == -1)
        {
            if (v[uid].isshow == false)
                continue;
            else
                pso = 0;
        }
        v[uid].uid = uid; // pso == -1和0都为0
        nid--;
        if (v[uid].s[nid] < pso)
        {
            v[uid].isshow = true;
            if (v[uid].s[nid] == -1)
                v[uid].total_score += pso;
            else
                v[uid].total_score += pso - v[uid].s[nid]; // 因为有if条件在，所以 total_score 是不会加上 -1 的
            v[uid].s[nid] = pso;
        }
    }
    sort(v.begin(), v.end(), cmp); // 注意这里sort后从0开始

    for (int i = 0; v[i].isshow != false; i++)
    {
        if (i == 0 || v[i].total_score != v[i - 1].total_score) // 注意 i = 0 放前面
            v[i].rank = i + 1;
        else
            v[i].rank = v[i - 1].rank;
        printf("%d %05d %d", v[i].rank, v[i].uid, v[i].total_score);
        for (int j = 0; j < K; j++)
            if (v[i].s[j] == -1)
                cout << " -";
            else
                cout << " " << v[i].s[j];
        cout << endl;
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
using namespace std;
struct node {
    int rank, id, total = 0;
    vector<int> score;
    int passnum = 0;
    bool isshown = false;
};
bool cmp1(node a, node b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.passnum != b.passnum)
        return a.passnum > b.passnum;
    else
        return a.id < b.id;
}
 
int main() {
    int n, k, m, id, num, score;
    scanf("%d %d %d", &n, &k, &m);
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i++)
        v[i].score.resize(k + 1, -1);
    vector<int> full(k + 1);
    for(int i = 1; i <= k; i++)
        scanf("%d", &full[i]);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &id, &num, &score);
        v[id].id = id;
        v[id].score[num] = max(v[id].score[num], score);
        if(score != -1)
            v[id].isshown = true;
        else if(v[id].score[num] == -1)
            v[id].score[num] = -2;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(v[i].score[j] != -1 && v[i].score[j] != -2)
                v[i].total += v[i].score[j];
            if(v[i].score[j] == full[j])
                v[i].passnum++;
        }
    }
    sort(v.begin() + 1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        v[i].rank = i;
        if(i != 1 && v[i].total == v[i - 1].total)
            v[i].rank = v[i - 1].rank;
    }
    for(int i = 1; i <= n; i++) {
        if(v[i].isshown == true) {
            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
            for(int j = 1; j <= k; j++) {
                if(v[i].score[j] != -1 && v[i].score[j] != -2)
                    printf(" %d", v[i].score[j]);
                else if(v[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}
```

