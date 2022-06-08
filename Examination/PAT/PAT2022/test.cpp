#include <bits/stdc++.h>
using namespace std;
const int inf = 9999999;

class Solution
{
public:
    void Dijstra(vector<vector<int>> &e, int source)
    {
        int N = e.size();
        vector<bool> visit(N, false);
        vector<int> dis(N, inf);
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
            for (int j = 0; j < N; j++)
                if (e[minj][j] != inf && visit[j] == false)
                    if (dis[j] > e[minj][j] + dis[j])
                        dis[j] = e[minj][j] + dis[j];
        }
    }
};

int main()
{

    Solution solution;
    system("pause");
    return 0;
}