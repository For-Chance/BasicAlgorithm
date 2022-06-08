#include <bits/stdc++.h>
using namespace std;
const int inf = 999999;
// 写一半发现自己写错了
class Solution
{
public:
    vector<int> dis;
    vector<vector<int>> e;
    void Dijstra(vector<vector<int>> &e, int source)
    {
        e = e;
        int N = e.size();
        dis = vector<int>(N, inf);
        vector<bool> visit(N, false);
        dis[source] = 0;
        for (int i = 0; i < N; i++)
        {
            int mindis = inf, minj = -1;
            for (int j = 0; j < N; j++)
                if (visit[j] == false && dis[j] < mindis)
                {
                    mindis = dis[j];
                    minj = j;
                }
            if (minj == -1)
                break;
            visit[minj] = true;
            for (int j = 0; j < N; j++)
                if (e[minj][j] != inf && visit[j] == false)
                    if (dis[j] > dis[minj] + e[minj][j])
                        dis[j] = dis[minj] + e[minj][j];
        }
    }

    int pathLength = 0;
    vector<int> CantGet;
    vector<int> findRoute()
    {
        vector<int> result;
        result.push_back(0);
        int N = dis.size();
        vector<int> visit(N, false);
        visit[0] = true;
        int next, mindis = 999999;
        int nowin = 0;
        while (1)
        {
            bool flag = true;
            if (nowin == 0)
            {
                int mini = -1, mindis = inf;
                for (int i = 0; i < N; i++)
                    if (visit[i] == false)
                        if (mindis > dis[i])
                        {
                            mindis = dis[i];
                            mini = i;
                        }
                        else if (mindis == dis[i] && i < mini)
                            mini = i;
                if (mini == -1)
                {
                    flag = false;
                    break;
                }
                result.push_back(mini);
                pathLength += mindis;
                nowin = mini;
            }
            else
            {
                // 先找周围最小的
            }

            if (!flag)
                break;
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> e(N + 1, vector<int>(N + 1, inf));
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = c;
    }
    Solution solution;
    solution.Dijstra(e, 0);
    vector<int> result = solution.findRoute();
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < result.size(); i++)
            cout << " " << result[i];
    }
    cout << endl;
    if (solution.CantGet.size() == 0)
        cout << solution.pathLength << endl;
    else
    {
        cout << solution.CantGet[0];
        for (int i = 1; i < solution.CantGet.size(); i++)
            cout << " " << solution.CantGet[i];
    }
    cout << endl;
    system("pause");
    return 0;
}