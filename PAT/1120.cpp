#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<int> getFriend(vector<string> &nums)
    {
        int n = nums.size();
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int value = 0;
            for (int j = 0; j < nums[i].length(); j++)
                value += nums[i][j] - '0';
            auto pos = s.find(value);
            if (pos == s.end())
                s.insert(value);
        }
        return s;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<string> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    set<int> result = solution.getFriend(nums);
    cout << result.size() << endl;
    for (auto it = result.begin(); it != result.end(); it++)
    {
        if (it == result.begin())
            cout << *it;
        else
            cout << " " << *it;
    }
    cout << endl;
    system("pause");
    return 0;
}