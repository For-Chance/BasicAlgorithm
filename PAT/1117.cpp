#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getNum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > i + 1)
                max++;
        return max;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    Solution solution;
    cout << solution.getNum(nums) << endl;
    system("pause");
    return 0;
}