#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> LRU(vector<int> &nums, int N)
    {
        int M = nums.size();
        unordered_map<int, int> m;
        // 插入位置与
        map<int, int> cache;
        vector<int> result;
        for (int i = 0; i < M; i++)
        {
            if (m.size() != N)
            {
                if (m.find(nums[i]) != m.end())
                {
                    auto pos = m.find(nums[i]);
                    cache.erase(pos->second);
                    pos->second = i;
                    cache[i] = pos->first;
                }
                else
                {
                    m[nums[i]] = i;
                    cache[i] = nums[i];
                }
            }
            else
            {
                if (m.find(nums[i]) == m.end())
                {
                    auto pos = cache.begin();
                    result.push_back(pos->second);
                    int x = pos->second;
                    cache.erase(m[x]);
                    m.erase(x);
                    m[nums[i]] = i;
                    cache[i] = nums[i];
                }
                else
                {
                    auto pos = m.find(nums[i]);
                    cache.erase(pos->second);
                    pos->second = i;
                    cache[i] = pos->first;
                }
            }
        }
        return result;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums(M);
    for (int i = 0; i < M; i++)
        cin >> nums[i];
    Solution solution;
    vector<int> result = solution.LRU(nums, N);
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < result.size(); i++)
            cout << " " << result[i];
    }
    system("pause");
    return 0;
}