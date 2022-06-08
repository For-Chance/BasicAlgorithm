#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; };

    bool cmp2(vector<int> a, vector<int> b) { return a[1] < b[1]; };

    vector<vector<int>> getLevel(vector<vector<int>> &nums)
    {
        vector<vector<int>> result;
        traceBack(nums, result);
        return result;
    };

    void traceBack(vector<vector<int>> &nums, vector<vector<int>> &result)
    {
        if (nums.size() <= 0)
            return;
        // 找到最小
        int MinPiror = 999999, MinIndex = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i][1] < MinPiror)
            {
                MinPiror = nums[i][1];
                MinIndex = i;
            }
        // 分隔左右
        result.push_back(nums[MinIndex]);
        vector<vector<int>> copy;
        copy.assign(nums.begin(), nums.begin() + MinIndex);
        traceBack(copy, result);
        copy.assign(nums.begin() + MinIndex, nums.end());
        traceBack(copy, result);
    }
};

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> nums(N, vector<int>(2));
    for (int i = 0; i < N; i++)
        cin >> nums[i][0] >> nums[i][1];
    Solution solution;
    vector<vector<int>> result = solution.getLevel(nums);
    if (nums.size() > 0)
    {
        cout << nums[0][0];
        for (int i = 0; i < N; i++)
            cout << " " << nums[i][0];
        cout << endl;
        cout << nums[0][1];
        for (int i = 0; i < N; i++)
            cout << " " << nums[i][1];
        cout << endl;
    }
    system("pause");
    return 0;
}