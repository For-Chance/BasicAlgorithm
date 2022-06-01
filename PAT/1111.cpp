#include <bits/stdc++.h>
using namespace std;
const int inf = 9999999;
class Solution
{
public:
    vector<int> Djistra_dis(vector<vector<vector<int>>> &v, int &source, int &dest)
    {
        int N = v.size();
        vector<int> dis(N, inf);
        vector<int> pre(N, source);
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
            {
                if (v[minj][j][0] != inf && visit[j] == false)
                {
                    if (dis[j] > dis[minj] + v[minj][j][0])
                    {
                        dis[j] = dis[minj] + v[minj][j][0];
                        pre[j] = minj;
                    }
                    else if (dis[j] == dis[minj] + v[minj][j][0])
                    {
                        dis[j] == dis[minj] + v[minj][j][0];
                        int temp = pre[j];
                        int res1 = tracebackTime(v, pre, j, source, 0);
                        pre[j] = minj;
                        int res2 = tracebackTime(v, pre, j, source, 0);
                        if (res1 < res2)
                            pre[j] = temp;
                    }
                }
            }
        }
        vector<int> result;
        result.push_back(dis[dest]);
        traceback(pre, dest, source, result);
        return result;
    }

    vector<int> Djistra_time(vector<vector<vector<int>>> &v, int &source, int &dest)
    {
        int N = v.size();
        vector<int> cost(N, inf);
        vector<int> pre(N, source);
        vector<bool> visit(N, false);
        cost[source] = 0;
        for (int i = 0; i < N; i++)
        {
            int mindis = inf, minj = -1;
            for (int j = 0; j < N; j++)
                if (mindis > cost[j] && visit[j] == false)
                {
                    mindis = cost[j];
                    minj = j;
                }
            if (minj == -1)
                break;
            visit[minj] = true;
            for (int j = 0; j < N; j++)
            {
                if (v[minj][j][0] != inf && visit[j] == false)
                {
                    if (cost[j] > cost[minj] + v[minj][j][1])
                    {
                        cost[j] = cost[minj] + v[minj][j][1];
                        pre[j] = minj;
                    }
                }
                else if (cost[j] == cost[minj] + v[minj][j][0])
                {
                    cost[j] == cost[minj] + v[minj][j][0];
                    int temp = pre[j];
                    int res1 = tracebackTime(v, pre, j, source, 0);
                    pre[j] = minj;
                    int res2 = tracebackTime(v, pre, j, source, 0);
                    if (res1 < res2)
                        pre[j] = temp;
                }
            }
        }
        vector<int> result;
        result.push_back(cost[dest]);
        traceback(pre, dest, source, result);
        return result;
    }

    void traceback(vector<int> &pre, int now, int &target, vector<int> &result)
    {
        if (now == target)
        {
            result.push_back(now);
            return;
        }
        traceback(pre, pre[now], target, result);
        result.push_back(now);
    }

    int tracebackTime(vector<vector<vector<int>>> &v, vector<int> &pre, int now, int &target, int cost)
    {
        if (now == target)
        {
            return cost;
        }
        return tracebackTime(v, pre, pre[now], target, cost + v[pre[now]][now][1]);
    }

    int tracebackDis(vector<vector<vector<int>>> &v, vector<int> &pre, int now, int &target, int cost)
    {
        if (now == target)
        {
            return cost;
        }
        return tracebackDis(v, pre, pre[now], target, cost + v[pre[now]][now][0]);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    // 创建一个 N*N*2 的矩阵
    vector<vector<vector<int>>> v(N, vector<vector<int>>(N, vector<int>(2, inf)));
    int v1, v2, one_way, length, time;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2 >> one_way >> length >> time;
        if (one_way == 0)
        {
            v[v1][v2][0] = v[v2][v1][0] = length;
            v[v1][v2][1] = v[v2][v1][1] = time;
        }
        else
        {
            v[v1][v2][0] = length;
            v[v1][v2][1] = time;
        }
    }
    int source, dest;
    cin >> source >> dest;
    Solution solution;
    vector<int> res1, res2;
    res1 = solution.Djistra_dis(v, source, dest);
    res2 = solution.Djistra_time(v, source, dest);
    bool flag = true;
    if (res1.size() != res2.size())
        flag = false;
    if (flag == true)
    {
        int n = res1.size();
        for (int i = 1; i < n; i++)
        {
            if (res1[i] != res2[i])
            {
                flag = false;
                break;
            }
        }
    }
    if (flag == false)
    {
        cout << "Distance = " << res1[0] << ": " << res1[1];
        for (int i = 2; i < res1.size(); i++)
            cout << " -> " << res1[i];
        cout << endl;
        cout << "Time = " << res2[0] << ": " << res2[1];
        for (int i = 2; i < res2.size(); i++)
            cout << " -> " << res2[i];
    }
    else
    {
        cout << "Distance = " << res1[0] << "; ";
        cout << "Time = " << res2[0] << ": " << res2[1];
        for (int i = 2; i < res2.size(); i++)
            cout << " -> " << res2[i];
    }
    cout << endl;
    system("pause");
    return 0;
}