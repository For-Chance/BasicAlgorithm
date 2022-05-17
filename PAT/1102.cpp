#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

struct node
{
    int left = -1;
    int right = -1;
} n[10];

vector<int> in;
map<int, int> level;

// root是n[]的下标，也是具体代表的值
void getlevel(int root, int index)
{
    level[index] = root;
    if (n[root].left == -1 && n[root].right == -1)
        return;
    if (n[root].left != -1)
        getlevel(n[root].left, 2 * index + 1);
    if (n[root].right != -1)
        getlevel(n[root].right, 2 * index + 2);
}

void getin(int root)
{
    if (n[root].left == -1 && n[root].right == -1)
    {
        in.push_back(root);
        return;
    }
    if (n[root].left != -1)
        getin(n[root].left);
    in.push_back(root);
    if (n[root].right != -1)
        getin(n[root].right);
}

int main()
{
    int N;
    cin >> N;
    char c1, c2;
    vector<int> root(N, 1);
    for (int i = 0; i < N; i++)
    {
        // 输入这就把node变成镜像；
        cin >> c1 >> c2;
        if (isdigit(c2))
        {
            n[i].left = c2 - '0';
            root[c2 - '0'] = 0;
        }
        if (isdigit(c1))
        {
            n[i].right = c1 - '0';
            root[c1 - '0'] = 0;
        }
    }
    auto begin = find(root.begin(), root.end(), 1);
    int j = begin - root.begin();
    getlevel(j, 0);
    getin(j);
    for (auto it = level.begin(); it != level.end(); it++)
        if (it != level.begin())
            cout << " " << it->second;
        else
            cout << it->second;
    cout << endl;
    for (int i = 0; i < N; i++)
        if (i != 0)
            cout << " " << in[i];
        else
            cout << in[i];
    cout << endl;
    system("pause");
    return 0;
}