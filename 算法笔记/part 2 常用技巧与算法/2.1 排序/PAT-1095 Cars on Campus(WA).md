# 1095 Cars on Campus

> part 2, 2.1



## 自己解法


```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct parking
{
    string pNumber;
    int h, m, s;
    int timestamp, duration;
    int status; // 0->in, 1->out
};

bool cmp(parking a, parking b)
{
    return a.pNumber != b.pNumber ? a.pNumber < b.pNumber : (a.timestamp != b.timestamp ? a.timestamp < b.timestamp : (a.status < b.status));
}

bool cmp2(parking a, parking b)
{
    return a.timestamp < b.timestamp;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<parking> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].pNumber;
        scanf("%d:%d:%d", &v[i].h, &v[i].m, &v[i].s);
        v[i].timestamp = v[i].s + 60 * v[i].m + 60 * 60 * v[i].h;
        string status;
        cin >> status;
        if (status == "in")
            v[i].status = 0;
        else
            v[i].status = 1;
    }
    sort(v.begin(), v.end(), cmp);

    // 删除所有不配对的
    for (vector<parking>::iterator it = v.begin(); it < v.end() - 1; it++)
    {
        if ((*it).status == 0 && (*(it + 1)).status == 1 && (*it).pNumber == (*(it + 1)).pNumber)
        {
            (*it).duration = (*(it + 1)).timestamp - (*it).timestamp;
            it++;
            continue;
        }
        v.erase(it);
        it--; // 注意这里删了一个it相当于后移了一个，要减掉
    }
    if ((*(v.end() - 1)).status == 0)
        v.pop_back();

    // 再按时间排序, 再输入 check 的时间段边计算就行
    sort(v.begin(), v.end(), cmp2);

    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].pNumber << " ";
        printf("%02d:%02d:%02d ", v[i].h, v[i].m, v[i].s);
        cout << v[i].duration << " " << v[i].status << endl;
    }

    int v_size = v.size(), count = 0, pos = 0, longest;
    vector<parking> l;
    for (int i = 0; i < K; i++)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int timestamp = ss + 60 * mm + 60 * 60 * hh;
        while (v[pos].timestamp <= timestamp)
        {
            if (v[pos].status == 0)
            {
                count++;
                if (longest <= v[pos].duration)
                {
                    longest = v[pos].duration;
                    l.push_back(v[pos]);
                }
            }
            else
                count--;
            pos++;
        }
        cout << count << endl;
    }

    int l_size = l.size();
    for (int i = 0; i < l_size; i++)
        cout << l[i].pNumber << " ";
    printf("%02d:%02d:%02d\n", longest / 3600, longest % 3600 / 60, longest % 60);

    system("pause");
    return 0;
}
```

- 写崩溃了

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <algorithm>

struct parking
{
    string pNumber;
    int h, m, s;
    int timestamp;
    int status; // 0->in, 1->out
};

bool cmp(parking a, parking b)
{
    return a.pNumber != b.pNumber ? a.pNumber < b.pNumber : (a.timestamp != b.timestamp ? a.timestamp < b.timestamp : (a.status < b.status));
}

bool cmp2(parking a, parking b)
{
    return a.timestamp < b.timestamp;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<parking> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].pNumber;
        scanf("%d:%d:%d", &v[i].h, &v[i].m, &v[i].s);
        v[i].timestamp = v[i].s + 60 * v[i].m + 60 * 60 * v[i].h;
        string status;
        cin >> status;
        if (status == "in")
            v[i].status = 0;
        else
            v[i].status = 1;
    }
    sort(v.begin(), v.end(), cmp);

    // 删除所有不配对的
    for (vector<parking>::iterator it = v.begin(); it < v.end() - 1; it++)
    {
        if ((*it).status == 0 && (*(it + 1)).status == 1 && (*it).pNumber == (*(it + 1)).pNumber)
        {
            it++;
            continue;
        }
        v.erase(it);
        it--; // 注意这里删了一个it相当于后移了一个，要减掉
    }
    if ((*(v.end() - 1)).status == 0)
        v.pop_back();

    // 再按时间排序, 再输入 check 的时间段边计算就行
    sort(v.begin(), v.end(), cmp2);

    // cout << endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].pNumber << " ";
    //     printf("%02d:%02d:%02d ", v[i].h, v[i].m, v[i].s);
    //     cout << v[i].status << endl;
    // }

    int count = 0, pos = 0, longest = 0;
    vector<string> l;
    map<string, int> d;
    for (int i = 0; i < K; i++)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int timestamp = ss + 60 * mm + 60 * 60 * hh;
        while (v[pos].timestamp <= timestamp)
        {
            map<string, int>::iterator p = find(d.begin(), d.end(), v[pos].pNumber);
            if (v[pos].status == 0)
            {
                count++;
                if (p != d.end())
                    p->second -= v[pos].timestamp;
                else
                    d.insert(make_pair(v[pos].pNumber, -v[pos].timestamp));
            }
            else
            {
                count--;
                if (p != d.end())
                    p->second += v[pos].timestamp;
                else
                    d.insert(make_pair(v[pos].pNumber, +v[pos].timestamp));
            }
            pos++;
        }
        cout << count << endl;
    }
    for (map<string, int>::iterator it = d.begin(); it != d.end(); it++)
        if (longest <= it->second)
            longest = it->second;

    // for (map<string, int>::iterator it = d.begin(); it != d.end(); it++)
    //     if (it->second == longest)
    //         cout << it->first << " ";
    // printf("%02d:%02d:%02d\n", longest / 3600, longest % 3600 / 60, longest % 60);

    system("pause");
    return 0;
}
```



## 大神解法

- 柳神

- 注意：如果一个车多次进入未出，取最后一个值；如果一个车多次out未进入，取第一个值
  一个车可能出入校园好多次，停车的时间应该取之和

  分析：为了简便，应该把小时和分钟都化简成秒数计算比较方便。
  一开始所有车辆的id、时间和是进还是出（进的flag是1，出的flag是-1），对他们排序，先按照车牌号排序，再按照来的时间先后排序。
  此后就能根据这样的排序后的顺序将所有满足条件（合法）的车辆进出记录保存到另一个数组里面。这个数组再按照时间先后排序。
  因为多次询问值，为了避免超时，可以把他们的车辆数cnt数组先算出来。到时候直接取值就会比较快速。cnt[i]表示在i下标的记录的时间点的时候车辆的数量。数量可以由前一个数量+当前车辆的flag得到。
  因为问询的时候是多个时间点按照从小到大的顺序，利用好这点能避免超时。如果上一个查询的index已经被记住，那么下一次就只需要从这个index开始找就可以了，避免重复寻找，浪费时间。

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
struct node {
    char id[10];
    int time;
    int flag = 0;
};
bool cmp1(node a, node b) {
    if(strcmp(a.id, b.id) != 0)
        return strcmp(a.id, b.id) < 0;
    else
        return a.time < b.time;
}
bool cmp2(node a, node b) {
    return a.time < b.time;
}
int main() {
    int n, k, maxtime = -1, tempindex = 0;
    scanf("%d%d\n", &n, &k);
    vector<node> record(n), car;
    for(int i = 0; i < n; i++) {
        char temp[5];
        int h, m, s;
        scanf("%s %d:%d:%d %s\n", record[i].id, &h, &m, &s, temp);
        int temptime = h * 3600 + m * 60 + s;
        record[i].time = temptime;
        record[i].flag = strcmp(temp, "in") == 0 ? 1 : -1;
    }
    sort(record.begin(), record.end(), cmp1);
    map<string, int> mapp;
    for(int i = 0; i < n - 1; i++) {
        if(strcmp(record[i].id, record[i+1].id) == 0 && record[i].flag == 1 && record[i+1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].id] += (record[i+1].time - record[i].time);
            if(maxtime < mapp[record[i].id]) {
                maxtime = mapp[record[i].id];
            }
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(n);
    for(int i = 0; i < car.size(); i++) {
        if(i == 0)
            cnt[i] += car[i].flag;
         else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }
    for(int i = 0; i < k; i++) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j;
        for(j = tempindex; j < car.size(); j++) {
            if(car[j].time > temptime) {
                printf("%d\n", cnt[j - 1]);
                break;
            } else if(j == car.size() - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;
    }
    for(map<string, int>::iterator it = mapp.begin(); it != mapp.end(); it++) {
        if(it->second == maxtime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}
```

