# 1025 PAT Ranking

> part 2, 2.1



## 自己解法(未全对)

- 4 WA，但是牛客网中可以全对


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

struct test
{
    long long number;
    int grade;
    int loc;
    int rank[2] = {0};
};

bool allRank(test a, test b)
{
    return a.grade == b.grade ? a.number < b.number : a.grade > b.grade;
}

bool locRank(test a, test b)
{
    return a.loc != b.loc ? a.loc < b.loc : (a.grade == b.grade ? a.number < b.number : a.grade > b.grade);
}

int main()
{
    vector<test> allTests;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            long long number;
            int grade;
            scanf("%lld %d", &number, &grade);
            test d;
            d.number = number;
            d.grade = grade;
            d.loc = i + 1;
            allTests.push_back(d);
        }
    }
    vector<test>::iterator z = allTests.begin();
    sort(allTests.begin(), allTests.end(), locRank);
    for (vector<test>::iterator it = z; it != allTests.end(); it++)
    {
        if ((*it).loc != (*(it - 1)).loc)
            z = it;
        if ((*it).grade != (*(it - 1)).grade || it == z)
            (*it).rank[1] = it - z + 1;
        else
            (*it).rank[1] = (*(it - 1)).rank[1];
    }
    z = allTests.begin();
    sort(allTests.begin(), allTests.end(), allRank);
    for (vector<test>::iterator it = z; it != allTests.end(); it++)
        if ((*it).grade != (*(it - 1)).grade || it == z)
            (*it).rank[0] = it - z + 1;
        else
            (*it).rank[0] = (*(it - 1)).rank[0];
    cout << allTests.size() << endl;
    for (vector<test>::iterator it = allTests.begin(); it != allTests.end(); it++)
    {
        printf("%lld", it->number);
        cout << " " << it->rank[0] << " " << it->loc << " " << it->rank[1] << endl;
    }
    system("pause");
    return 0;
}
```





## 大神解法

- 柳神
- 此处这种情况下边输入边赋值locarank，值得效仿

```c++
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct student {
    long long int no;
    int score, finrank, loca, locarank;
};
bool cmp1(student a, student b) {
    return a.score != b.score ? a.score > b.score : a.no < b.no;
}
int main() {
    int n, m;
    scanf("%d", &n);
    vector<student> fin;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &m);
        vector<student> v(m);
        for(int j = 0; j < m; j++) {
            scanf("%lld %d", &v[j].no, &v[j].score);
            v[j].loca = i;
        }
        sort(v.begin(), v.end(), cmp1);
        v[0].locarank = 1;
        fin.push_back(v[0]);
        for(int j = 1; j < m; j++) {
            v[j].locarank = (v[j].score == v[j - 1].score) ? (v[j - 1].locarank) : (j + 1);
            fin.push_back(v[j]);
        }
    }
    sort(fin.begin(), fin.end(), cmp1);
    fin[0].finrank = 1;
    for(int j = 1; j < fin.size(); j++)
        fin[j].finrank = (fin[j].score == fin[j - 1].score) ? (fin[j - 1].finrank) : (j + 1);
    printf("%d\n", fin.size());
    for(int i = 0; i < fin.size(); i++)
        printf("%013lld %d %d %d\n", fin[i].no, fin[i].finrank, fin[i].loca, fin[i].locarank);
    return 0;
}
```


