#include <bits/stdc++.h>
using namespace std;

struct node
{
    string str;
    int left, right;
    int p = 0;
};

class Solution
{
public:
    int root;
    string getRes(vector<node> &tree)
    {
        string res = "";
        root = 1;
        while (tree[root].p != 0)
        {
            root = tree[root].p;
        }
        inOrder(res, root, tree);
        return res;
    }

    void inOrder(string &res, int root, vector<node> &tree)
    {
        if (root == -1)
            return;
        if ((tree[root].left != -1 || tree[root].right != -1) && root != this->root)
            res += '(';
        inOrder(res, tree[root].left, tree);
        res += tree[root].str;
        inOrder(res, tree[root].right, tree);
        if ((tree[root].left != -1 || tree[root].right != -1) && root != this->root)
            res += ')';
    }
};

int main()
{
    int N;
    cin >> N;
    vector<node> tree(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> tree[i].str;
        cin >> tree[i].left >> tree[i].right;
        if (tree[i].left != -1)
            tree[tree[i].left].p = i;
        if (tree[i].right != -1)
            tree[tree[i].right].p = i;
    }

    Solution solution;
    cout << solution.getRes(tree) << endl;
    system("pause");
    return 0;
}