#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *left, *right;
};

class Solution
{
public:
    vector<int> getSolution(vector<int> &in)
    {
        int N = in.size();
        node *root = build(in, 0, N - 1);
        vector<int> result;
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            result.push_back(temp->value);
            q.pop();
            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
        return result;
    }

    node *build(vector<int> &in, int left, int right)
    {
        if (left > right)
            return nullptr;
        int min = 99999999, mini = -1;
        for (int i = left; i <= right; i++)
            if (min > in[i])
            {
                min = in[i];
                mini = i;
            }
        node *root = new node();
        root->value = min;
        node *lr = build(in, left, mini - 1);
        node *rr = build(in, mini + 1, right);
        root->left = lr;
        root->right = rr;
        return root;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> in(N);
    for (int i = 0; i < N; i++)
        cin >> in[i];
    Solution solution;
    vector<int> result = solution.getSolution(in);
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < N; i++)
            cout << " " << result[i];
    }
    cout << endl;
    system("pause");
    return 0;
}