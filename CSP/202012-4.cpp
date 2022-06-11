#include <bits/stdc++.h>
using namespace std;
const int inf = 999999;

class Solution
{
public:
    int getMaxTime(vector<vector<bool>> &demand, vector<vector<int>> &e, int &N, int &M, int &K)
    {
        }
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> demand(N, vector<bool>(K));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
        {
            bool flag;
            cin >> flag;
            demand[i][j] = flag; // i酒店 对 j食材 的需求
        }
    vector<vector<int>> e(N + 1, vector<int>(N + 1, inf));
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = e[v][u] = w;
    }
    Solution solution;
    cout << solution.getMaxTime(demand, e, N, M, K);
    system("pause");
    return 0;
}