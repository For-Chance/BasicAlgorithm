#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSolution(vector<vector<bool>> &e, vector<int> &nums)
    {
        int N = e.size();
        int L = nums.size();
        // is direct
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (e[nums[i]][nums[j]] != true)
                    return -1;
        // no missing
        for (int i = 1; i < N; i++)
        {
            if (find(nums.begin(), nums.end(), i) != nums.end())
                continue;
            bool flag2 = true;
            for (int j = 0; j < L; j++)
                if (e[i][nums[j]] != true)
                {
                    flag2 = false;
                    break;
                }
            if (flag2)
                return i;
        }
        return 0;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> e(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = true;
    }
    for (int i = 0; i < N + 1; i++)
        e[i][i] = true;

    int K;
    cin >> K;
    Solution solution;
    for (int i = 0; i < K; i++)
    {
        int L;
        cin >> L;
        vector<int> nums(L);
        for (int j = 0; j < L; j++)
            cin >> nums[j];
        int res = solution.getSolution(e, nums);
        if (res == 0)
            printf("Area %d is OK.", i + 1);
        else if (res == -1)
            printf("Area %d needs help.", i + 1);
        else if (res > 0)
            printf("Area %d may invite more people, such as %d.", i + 1, res);
        cout << endl;
    }
    system("pause");
    return 0;
}