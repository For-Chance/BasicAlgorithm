#include <bits/stdc++.h>
using namespace std;
const int inf = 9999999;

class Solution
{
public:
    bool isRight(vector<vector<bool>> &e, vector<int> &nums)
    {
        int N = nums.size();
        vector<bool> visit(N + 1, false);
        visit[0] = true;
        visit[nums[0]] = true;
        int start = nums[0];
        for (int i = 1; i < N; i++)
        {
            if (e[nums[i - 1]][nums[i]] == false)
            {
                if (dfs(e, start, nums[i]) == true)
                    return false;
                start = nums[i];
                visit[nums[i]] = true;
            }
            if (visit[nums[i]] == true)
                return false;
            visit[nums[i]] = true;
        }
        for (int i = 0; i <= N; i++)
            if (visit[i] == false)
                return false;
        return true;
    }

    bool dfs(vector<vector<bool>> &e, int source, int dest)
    {
        if (e[source][dest] == true)
            return true;
        for (int i = 0; i < N; i++)
            if (e[source][i] == true)
                if (dfs(e, i, dest) == true)
                    return true;
        return false;
    }
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> e(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = true;
    }
    Solution solution;
    for (int i = 0; i < K; i++)
    {
        vector<int> nums(N);
        for (int i = 0; i < N; i++)
            cin >> nums[i];
        bool res = solution.isRight(e, nums);
        if (res)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    system("pause");
    return 0;
}