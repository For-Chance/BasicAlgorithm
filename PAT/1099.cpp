#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int ind, maxDepth;
struct node
{
    int data, left, right;
} l[101];
int p[101];
vector<int> v[100];

void dfs(int index, int depth)
{
    maxDepth = max(maxDepth, depth);
    if (l[index].left != -1)
        dfs(l[index].left, depth + 1);
    l[index].data = p[ind];
    ind++;
    if (l[index].right != -1)
        dfs(l[index].right, depth + 1);
}

int main()
{
    ind = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> l[i].left >> l[i].right;
    for (int i = 0; i < N; i++)
        cin >> p[i];
    sort(p, p + N);
    dfs(0, 0);
    v[0].push_back(0);
    for (int i = 0; i <= maxDepth; i++)
        for (int j = 0; j < v[i].size(); j++)
        {
            if (i != 0)
                cout << " " << l[v[i][j]].data;
            else
                cout << l[v[i][j]].data;
            if (l[v[i][j]].left != -1)
                v[i + 1].push_back(l[v[i][j]].left);
            if (l[v[i][j]].right != -1)
                v[i + 1].push_back(l[v[i][j]].right);
        }
    cout << endl;
    system("pause");
    return 0;
}