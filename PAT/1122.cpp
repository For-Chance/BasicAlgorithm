#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCycle(vector<vector<bool>> &e, vector<int> &nums, int N)
    {
        int n = nums.size();
        if (n != N + 1)
            return false;
        if (n == 0)
            return false;
        if (nums[0] != nums[n - 1])
            return false;
        bool flag = false;
        unordered_set<int> hadin;
        hadin.insert(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (e[nums[i]][nums[i - 1]] == false)
                return false;
            hadin.insert(nums[i]);
        }
        if (hadin.size() != N)
            return false;
        return true;
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
    Solution solution;
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int k;
        cin >> k;
        vector<int> nums(k);
        for (int j = 0; j < k; j++)
            cin >> nums[j];
        if (solution.isCycle(e, nums, N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}