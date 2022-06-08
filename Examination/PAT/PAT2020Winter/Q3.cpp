#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    int depth;
    node *parent;
    vector<node *> child;
};

class Solution
{
public:
    unordered_map<int, node *> map;
    node *root;
    void buildTree(vector<string> &tree)
    {
        deepInsert(tree, 0, nullptr);
        buildmap(root);
    };

    void buildmap(node *root)
    {
        map[root->value] = root;
        for (int i = 0; i < root->child.size(); i++)
            buildmap(root->child[i]);
    }

    void deepInsert(vector<string> &tree, int index, node *parent)
    {
        if (index == tree.size())
            return;

        node *nowNode = new node();
        string str = tree[index];
        int depth = str.length() - 4;
        string substr = str.substr(depth, 4);
        int value = stoi(substr);

        nowNode->parent = parent;
        nowNode->value = value;
        nowNode->depth = depth;

        if (index == 0)
        {
            root = nowNode;
            deepInsert(tree, index + 1, nowNode);
        }
        else if (parent->depth == depth - 1)
        {
            parent->child.push_back(nowNode);
            deepInsert(tree, index + 1, nowNode);
        }
        else
        {
            parent = findParent(parent, depth);
            nowNode->parent = parent;
            parent->child.push_back(nowNode);
            deepInsert(tree, index + 1, nowNode);
        }
    }

    node *findParent(node *nd, int &nowdepth)
    {
        if (nd->depth == nowdepth - 1)
            return nd;
        return findParent(nd->parent, nowdepth);
    }

    vector<int> Findfile(int q)
    {
        if (map.find(q) == map.end())
            return {};
        node *found = map[q];
        vector<int> result;
        dfs(result, found);
        return result;
    };

    void dfs(vector<int> &result, node *found)
    {
        if (found->depth == 0)
        {
            result.push_back(found->value);
            return;
        }
        dfs(result, found->parent);
        result.push_back(found->value);
    }
};

int main()
{
    int N;
    scanf("%d\n", &N);
    vector<string> tree(N);
    for (int i = 0; i < N; i++)
        getline(cin, tree[i]);
    Solution solution;
    solution.buildTree(tree);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int q;
        cin >> q;
        vector<int> result = solution.Findfile(q);
        if (result.size() == 0)
            printf("Error: %04d is not found.\n", q);
        else
        {
            printf("%04d", result[0]);
            for (int i = 1; i < result.size(); i++)
                printf("->%04d", result[i]);
            cout << endl;
        }
    }
    system("pause");
    return 0;
}