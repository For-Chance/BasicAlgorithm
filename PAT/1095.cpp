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