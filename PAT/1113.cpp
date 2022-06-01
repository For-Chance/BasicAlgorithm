#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> SetPartition(int N, vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n1 = N / 2;

        int S1 = 0, S2 = 0;
        for (int i = 0; i < n1; i++)
            S1 += nums[i];
        for (int i = n1; i < N; i++)
            S2 += nums[i];
        return {(N % 2 == 0) ? 0 : 1, S2 - S1};
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    auto res = solution.SetPartition(N, nums);
    cout << res[0] << " " << res[1] << endl;
    system("pause");
    return 0;
}