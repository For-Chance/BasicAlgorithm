#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int S;

vector<int> v[100]; // 等价于 vector<vector<int>>v(100);
vector<int> w(100);
vector<int> path(10000, -1); // 某一次的合格结果
vector<vector<int>> s;       // 存储所有合格结果

void bfs(int index, int depth, int sum)
{
    if (sum > S)
    {
        path[depth] = -1;
        return;
    }
    else if (sum == S)
    {
        if (v[index].size() != 0)
        {
            path[depth] = -1;
            return;
        }
        s.push_back(path);
        path[depth] = -1;
        return;
    }
    else
    {
        if (v[index].size() == 0)
        {
            path[depth] = -1;
            return;
        }
        for (int i = 0; i < v[index].size(); i++)
        {
            path[depth + 1] = v[index][i];
            bfs(v[index][i], depth + 1, sum + w[v[index][i]]);
        }
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    int i = 0;
    while (i < a.size())
    {
        if (w[a[i]] != w[b[i]])
            return w[a[i]] > w[b[i]];
        i++;
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++)
        cin >> w[i];
    int id, cs, c;
    for (int i = 0; i < M; i++)
    {
        cin >> id >> cs;
        for (int j = 0; j < cs; j++)
        {
            cin >> c;
            v[id].push_back(c);
        }
    }
    path[0] = 0;
    bfs(0, 0, w[0]);
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; s[i][j] != -1; j++)
            if (j != 0)
                cout << " " << w[s[i][j]];
            else
                cout << w[s[i][j]];
        cout << endl;
    }
    bfs(0, 0, w[0]);
    system("pause");
    return 0;
}