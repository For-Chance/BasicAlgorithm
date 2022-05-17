#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <algorithm>
int N, K, allNames;
vector<string> name;                // 每个人的名字索引
map<int, int> w;                    // 存放每个人的权重，前一个是名字的索引
vector<vector<int>> gangs;          // 存放帮派，放名字的索引
bool v[10001][10001], visit[10001]; // 邻接矩阵以及判断
map<string, int> res;

void dfs(int node, int index)
{
    visit[node] = true;
    gangs[index].push_back(node);
    for (int i = 0; i < allNames; i++)
        if (visit[i] == false && v[node][i] == true)
            dfs(i, index);
}

int main()
{
    cin >> N >> K;
    string N1, N2;
    int time;
    for (int i = 0; i < N; i++)
    {
        cin >> N1 >> N2 >> time;
        int x1, x2;
        auto pos1 = find(name.begin(), name.end(), N1);
        if (pos1 == name.end())
        {
            name.push_back(N1);
            x1 = name.size() - 1;
            w.insert(make_pair(x1, time));
        }
        else
        {
            x1 = pos1 - name.begin();
            w[x1] += time;
        }
        auto pos2 = find(name.begin(), name.end(), N2);
        if (pos2 == name.end())
        {
            name.push_back(N2);
            x2 = name.size() - 1;
            w.insert(make_pair(x2, time));
        }
        else
        {
            x2 = pos2 - name.begin();
            w[x2] += time;
        }
        v[x1][x2] = v[x2][x1] = true;
    }
    // 挑选帮派(两个人也算上)
    allNames = name.size();
    for (int i = 0; i < allNames; i++)
    {
        if (visit[i] == true)
            continue;
        visit[i] = true;
        vector<int> a;
        a.push_back(i);
        gangs.push_back(a);
        int index = gangs.size() - 1;
        auto x = gangs.begin() + index;
        for (int j = 0; j < allNames; j++)
            if (visit[j] == false && v[i][j] == true)
                dfs(j, index);
        if (gangs[index].size() <= 2)
        {
            gangs.erase(x);
            continue;
        }
        int score = 0;
        for (int j = 0; j < gangs[index].size(); j++)
            score += w[gangs[index][j]];
        if ((score / 2) <= K)
            gangs.erase(x);
    }
    int gsize = gangs.size();
    cout << gsize << endl;
    if (gsize != 0)
    {
        for (int i = 0; i < gsize; i++)
        {
            int max = -1, maxj = -1;
            for (int j = 0; j < gangs[i].size(); j++)
                if (w[gangs[i][j]] > max)
                {
                    max = w[gangs[i][j]];
                    maxj = gangs[i][j];
                }
            res.insert(make_pair(name[maxj], gangs[i].size()));
        }
        for (auto it = res.begin(); it != res.end(); it++)
            cout << it->first << " " << it->second << endl;
    }

    system("pause");
    return 0;
}