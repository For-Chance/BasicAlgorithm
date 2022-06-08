#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> tree;
    unordered_map<int, int> map;
    void insert_nums(vector<int> &nums)
    {
        tree = nums;
        int N = nums.size();
        for (int i = 1; i < N; i++)
        {
            int index = i;
            int pre_index = index / 2;
            while (pre_index >= 1 && tree[pre_index] < tree[index])
            {
                swap(tree[index], tree[pre_index]);
                index = pre_index;
                pre_index = index / 2;
            }
        }
        for (int i = 1; i < N; i++)
            map[tree[i]] = i;
    }

    int isRight(string q)
    {
        return 1;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> nums[i];
    Solution solution;
    solution.insert_nums(nums);
    for (int i = 0; i < M; i++)
    {
        string q;
        cin >> q;
        cout << solution.isRight(q);
    }
    Solution solution;
    system("pause");
    return 0;
}