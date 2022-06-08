#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *left, *right, *p;
};

class Solution
{
public:
    node *insert(node *root, int value, int index)
    {
        if (root == nullptr)
        {
            root = new node();
            root->value = value;
            root->left = root->right = nullptr;
            return root;
        }
        else
        {
            stack<bool> stk;
            while (index != 1)
            {
                stk.push(index % 2);
                index /= 2;
            }
            while (!stk.empty())
            {
                if (stk.top() == 0)
                    root = root->left;
                else
                    root = root->right;
            }
        }
    }

    node *insert_nums(vector<int> &nums)
    {
        node *root = nullptr;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            root = insert(root, nums[i], i);
        return root;
    }

    bool isRight(node *root, string q)
    {
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    Solution solution;
    node *root = solution.insert_nums(nums);
    for (int i = 0; i < M; i++)
    {
        string q;
        cin >> q;
        cout << solution.isRight(root, q);
    }
    system("pause");
    return 0;
}