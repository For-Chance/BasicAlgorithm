#include <bits/stdc++.h>
using namespace std;

struct node
{
    int y;
    int result;
};

class Solution
{
public:
    int getTheta(vector<node> &nums)
    {
        set<int> sel;
        int m = nums.size();
        for (int i = 0; i < m; i++)
            sel.insert(nums[i].y);
        int maxTheta = -9999999, maxcnt = 0;
        for (auto it = sel.begin(); it != sel.end(); it++)
        {
            int cnt = 0;
            for (int i = 0; i < m; i++)
                if (nums[i].y < *it && nums[i].result == 0)
                    cnt++;
                else if (nums[i].y >= *it && nums[i].result == 1)
                    cnt++;
            if (maxcnt < cnt)
            {
                maxcnt = cnt;
                maxTheta = *it;
            }
            else if (maxcnt == cnt)
            {
                maxTheta = max(maxTheta, *it);
            }
        }
        return maxTheta;
    }
};

int main()
{
    int m;
    cin >> m;
    vector<node> nums(m);
    for (int i = 0; i < m; i++)
        cin >> nums[i].y >> nums[i].result;
    Solution solution;
    cout << solution.getTheta(nums);
    system("pause");
    return 0;
}