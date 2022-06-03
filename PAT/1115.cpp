#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

class Solution
{
public:
    vector<int> getLowest2(node *root)
    {
        int low1 = 0, low2 = 0;
        int maxDepth = -1;
        getMaxDepth(root, 0, maxDepth);
        dfs(root, 0, low1, low2, maxDepth);
        return {low1, low2};
    }

    void getMaxDepth(node *root, int depth, int &maxDepth)
    {
        if (root == nullptr)
        {
            if (depth > maxDepth)
                maxDepth = depth;
            return;
        }
        getMaxDepth(root->left, depth + 1, maxDepth);
        getMaxDepth(root->right, depth + 1, maxDepth);
    }

    void dfs(node *root, int depth, int &low1, int &low2, int &maxDepth)
    {
        if (root == nullptr)
            return;
        dfs(root->left, depth + 1, low1, low2, maxDepth);
        dfs(root->right, depth + 1, low1, low2, maxDepth);
        if (depth == maxDepth - 1)
            low1++;
        else if (depth == maxDepth - 2)
            low2++;
    }
};

node *insert_value(node *root, int value)
{
    if (root == nullptr)
    {
        root = new node();
        root->value = value;
        root->left = root->right = nullptr;
    }
    else if (value <= root->value)
        root->left = insert_value(root->left, value);
    else
        root->right = insert_value(root->right, value);
    // 最后返回的一定是原先的root
    return root;
}

int main()
{
    int N;
    cin >> N;
    node *root = nullptr;
    int val;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        root = insert_value(root, val);
    }
    Solution solution;
    vector<int> result = solution.getLowest2(root);
    printf("%d + %d = %d\n", result[0], result[1], result[0] + result[1]);
    system("pause");
    return 0;
}