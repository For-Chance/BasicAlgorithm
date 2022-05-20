#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int max = -1;
        while (left != right)
        {
            int area = (right - left) * min(height[left], height[right]);
            if (max < area)
            {
                max = area;
            }
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    int res = solution.maxArea(height);
    cout << res << endl;
    system("pause");
    return 0;
}