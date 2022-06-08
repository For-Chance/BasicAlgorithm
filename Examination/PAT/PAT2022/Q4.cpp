#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    vector<node *> child;
};

class Solution
{
public:
    node *root;
    void build(vector<int> &pre, int d)
    {
        int N = pre.size();
        root = insert(pre, d, 0, N - 1);
    }

    node *insert(vector<int> &pre, int d, int left, int right)
    {
        node *root;
        root->value = pre[left];
        int x = right - left;

        for (int i = 0; i < d; i++)
            root->child.push_back(insert(pre, d, depth + 1, i));
    }
};

int main()
{
    int N, d;
    cin >> N >> d;
    vector<int> pre(N);
    for (int i = 0; i < N; i++)
        cin >> pre[i];
    Solution solution;
    solution.build(pre, d);
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int index;
        cin >> index;
        vector<int> result = solution.getIndex(index);
        if (result.size() > 0)
        {
            cout << result[0];
            for (int j = 1; j < result.size(); j++)
                cout << " " << result[i];
        }
    }

    system("pause");
    return 0;
}