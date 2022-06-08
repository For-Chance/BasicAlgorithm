#include <bits/stdc++.h>
using namespace std;
const int inf = 999999;
class Solution
{
public:
    vector<int> findMaxSolution(vector<vector<int>> &e)
    {
        int N = e.size();
        vector<vector<int>> Distance(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            Distance[i] = Dijstra(e, i);
        int maxdis = -1, maxi = -1;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (maxdis < Distance[i][j] && Distance[i][j] != inf)
                {
                    maxdis = Distance[i][j];
                    maxi = i;
                }
                else if (maxdis = Distance[i][j] && Distance[i][j] != inf)
                    maxi = min(maxi, i);
        return {maxi, maxdis};
    }

    vector<int> Dijstra(vector<vector<int>> &e, int source)
    {
        int N = e.size();
        vector<int> dis(N, inf);
        vector<bool> visit(N, false);
        dis[source] = 0;
        for (int i = 0; i < N; i++)
        {
            int mindis = inf, minj = -1;
            for (int j = 0; j < N; j++)
                if (mindis > dis[j] && visit[j] == false)
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
        return dis;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> e(N + 1, vector<int>(N + 1, inf));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    Solution solution;
    vector<int> result = solution.findMaxSolution(e);
    cout << result[0] << " " << result[1] << endl;
    system("pause");
    return 0;
}