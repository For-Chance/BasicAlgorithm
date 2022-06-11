#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool flag; // 0 表示目录，1表示文件
    int size;
    unordered_set<node *> child;
    string name;
};

class Solution
{
public:
    node *root;
    void build()
    {
        root->flag = 0;
        root->size = 0;
        root->name = "";
        root->child = unordered_set<node *>(0);
    }

    bool C(string path, int size)
    {
        node *root = dfs_C(path, 0, root);
        if (root == nullptr)
            return false;
    }

    node *dfs_C(string path, int index, node *parents)
    {
        // index 表示path中指向斜杠的位置
        int nameLength = 0;
        int i;
        for (i = index + 1; i < path.length(); i++)
            if (path[i] != '/')
                nameLength++;
        string name = path.substr(index + 1, nameLength);

        // 文件
        if (i == path.length())
        {
            node *file;
            file->name = name;
            file->flag = 1;
            return file;
        }
        // 目录
    }

    bool R(string path)
    {
    }

    bool Q(string path, int LD, int LR)
    {
    }
};

int main()
{
    Solution solution;
    solution.build();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char order;
        bool res = false;
        cin >> order;
        if (order == 'C')
        {
            string path;
            int size;
            cin >> path >> size;
            res = solution.C(path, size);
        }
        else if (order == 'R')
        {
            string path;
            cin >> path;
            res = solution.R(path);
        }
        else if (order == 'Q')
        {
            string path;
            int LD, LR;
            cin >> path >> LD >> LR;
            res = solution.Q(path, LD, LR);
        }
        cout << (res ? 'Y' : 'N') << endl;
    }
    system("pause");
    return 0;
}