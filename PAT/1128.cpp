#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool getResult(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> row(n + 1, false), col(n + 1, false), dia1(2 * n, false), dia2(2 * n, false);
        for (int i = 0; i < n; i++)
        {
            if (row[nums[i]] == true || col[i] == true || dia1[i + nums[i]] == true || dia2[nums[i] - i + n] == true)
                return false;
            row[nums[i]] = true;
            col[i] = true;
            dia1[i + nums[i]] = true;
            dia2[nums[i] - i + n] = true;
        }
        return true;
    }
};

int main()
{
    int N;
    cin >> N;
    Solution solution;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int j = 0; j < n; j++)
            cin >> nums[j];
        if (solution.getResult(nums))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}