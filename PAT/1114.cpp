#include <bits/stdc++.h>
using namespace std;

struct DATA
{
    int id, fid, mid, num, area;
    vector<int> cid;
};

struct node
{
    int id, people;
    double num, area;
    bool flag = false;
};

struct family
{
    int id, num;
    double avgNum, avgAreas;
};

class Solution
{
public:
    vector<family> getProperty(vector<DATA> &data)
    {
        int N = data.size();
        vector<bool> visit(10000, false);
        vector<int> child(10000);
        // 先将父节点设置为自己
        for (int i = 0; i < 10000; i++)
            child[i] = i;
        for (int i = 0; i < N; i++)
        {
            visit[data[i].id] = true;
            if (data[i].fid != -1)
            {
                visit[data[i].fid] = true;
                Union(child, data[i].fid, data[i].id);
            }
            if (data[i].mid != -1)
            {
                visit[data[i].mid] = true;
                Union(child, data[i].mid, data[i].id);
            }
            int k = data[i].cid.size();
            for (int j = 0; j < k; j++)
            {
                visit[data[i].cid[j]] = true;
                Union(child, data[i].cid[j], data[i].id);
            }
        }
        unordered_map<int, family> m;
        for (int i = 0; i < N; i++)
        {
            int id = child_find(child, data[i].id);
            auto pos = m.find(id);
            if (pos != m.end())
            {
                pos->second.avgNum += data[i].num;
                pos->second.avgAreas += data[i].area;
            }
            else
            {
                family res;
                res.id = id;
                res.num = 1;
                res.avgNum = data[i].num;
                res.avgAreas = data[i].area;
                m[i] = res;
                pos = m.find(i);
            }
            if (data[i].fid != -1)
                pos->second.num++;
            if (data[i].mid != -1)
                pos->second.num++;
            pos->second.num += data[i].cid.size();
        }
        vector<family> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            it->second.avgNum = it->second.avgNum / it->second.num;
            it->second.avgAreas = it->second.avgAreas / it->second.num;
            result.push_back(it->second);
        }
        return result;
    }

    int child_find(vector<int> &child, int x)
    {
        // 寻找x的最小子孩子
        // 退出的时候child[x]为-1
        while (x != child[x])
            x = child[x];
        return x;
    }

    void Union(vector<int> &child, int a, int b)
    {
        int faA = child_find(child, a);
        int faB = child_find(child, b);
        if (faA > faB)
            child[faA] = faB;
        else if (faA < faB)
            child[faB] = faA;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<DATA> data(N);
    for (int i = 0; i < N; i++)
    {
        cin >> data[i].id >> data[i].fid >> data[i].mid;
        int k;
        cin >> k;
        data[i].cid = vector<int>(k);
        for (int j = 0; j < k; j++)
            cin >> data[i].cid[j];
        cin >> data[i].num >> data[i].area;
    }
    Solution solution;
    vector<family> m = solution.getProperty(data);
    int family_num = m.size();
    cout << family_num << endl;
    for (int i = 0; i < family_num; i++)
        printf("%04d %d %.3f %.3f\n", m[i].id, m[i].num, m[i].avgNum, m[i].avgAreas);
    system("pause");
    return 0;
}