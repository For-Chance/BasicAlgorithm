#include <bits/stdc++.h>
using namespace std;
const int inf = 9999999;
class Solution
{
public:
    vector<vector<int>> G;
    int N;
    void floyd(vector<vector<int>> &e)
    {
        // 求到所有点的最短距离
        N = e.size();
        // 初始化
        G = e;
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    }

    int PathLength = 0;
    vector<int> CantGet;
    vector<int> findRoute()
    {
        vector<int> result;
        result.push_back(0);
        vector<bool> visit(N, false);
        visit[0] = true;

        int nowin = 0;
        for (int i = 0; i < N; i++)
        {
            // 前往下一个最近的且没有访问过的点
            int minj = -1, mindis = inf;
            for (int j = 0; j < N; j++)
                if (visit[j] == false && G[nowin][j] < mindis)
                {
                    minj = j;
                    mindis = G[nowin][j];
                }
            if (minj == -1)
                break;
            result.push_back(minj);
            PathLength += mindis;
            visit[minj] = true;
            nowin = minj;
        }

        for (int i = 0; i < N; i++)
            if (visit[i] == false)
                CantGet.push_back(i);
        return result;
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
    solution.floyd(e);
    vector<int> result = solution.findRoute();
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < result.size(); i++)
            cout << " " << result[i];
    }
    cout << endl;
    if (solution.CantGet.size() == 0)
        cout << solution.PathLength << endl;
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