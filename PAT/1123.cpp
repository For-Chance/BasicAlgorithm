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
    node *rightRotate(node *root)
    {
        node *y = root->left;
        root->left = y->right;
        y->right = root;
        return y;
    }

    node *leftRotate(node *root)
    {
        node *y = root->right;
        root->right = y->left;
        y->left = root;
        return y;
    }

    node *leftRightRotate(node *root)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    node *rightLeftRotate(node *root)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    int getMaxHeight(node *root)
    {
        if (root == nullptr)
            return 0;
        int l = getMaxHeight(root->left);
        int r = getMaxHeight(root->right);
        return max(l, r) + 1;
    }

    node *insert(node *root, int value)
    {
        if (root == nullptr)
        {
            root = new node();
            root->value = value;
        }
        else if (root->value >= value)
        {
            // 往左子树插入
            root->left = insert(root->left, value);
            int l = getMaxHeight(root->left), r = getMaxHeight(root->right);
            if (l - r >= 2)
                if (value <= root->left->value)
                    root = rightRotate(root);
                else
                    root = leftRightRotate(root);
        }
        else
        {
            // 往右子树插入
            root->right = insert(root->right, value);
            int l = getMaxHeight(root->left), r = getMaxHeight(root->right);
            if (r - l >= 2)
                if (value > root->right->value)
                    root = leftRotate(root);
                else
                    root = rightLeftRotate(root);
        }
        return root;
    }

    bool isComplete = true;
    bool after = false; // 判断出现了 nullptr后是否再出现nullptr
    vector<int> getLevelOrder(node *root)
    {
        vector<int> result;
        queue<node *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            node *temp = queue.front();
            queue.pop();
            result.push_back(temp->value);
            if (temp->left != nullptr)
            {
                if (after)
                    isComplete = false;
                queue.push(temp->left);
            }
            else
                after = true;
            if (temp->right != nullptr)
            {
                if (after)
                    isComplete = false;
                queue.push(temp->right);
            }
            else
                after = true;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int N;
    cin >> N;
    node *root = nullptr;
    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        root = solution.insert(root, value);
    }
    vector<int> result = solution.getLevelOrder(root);
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < result.size(); i++)
            cout << " " << result[i];
    }
    cout << endl
         << (solution.isComplete ? "YES" : "NO") << endl;
    system("pause");
    return 0;
}