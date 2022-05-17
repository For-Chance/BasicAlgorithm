#include <iostream>
using namespace std;
#include <vector>

vector<int> v[100];
int book[100] = {0}, maxdepth = -1; // book标记每一层有多少个叶子节点，maxdepth记录最大的深度，方便之后的输出

void dfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
    }
    else
        for (int i = 0; i < v[index].size(); i++)
            dfs(v[index][i], depth + 1);
}

int main()
{
    int N, M;
    cin >> N >> M;
    int nodeID, k, c;
    for (int i = 0; i < M; i++)
    {
        cin >> nodeID >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            v[nodeID].push_back(c);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= maxdepth; i++)
        if (i != 0)
            cout << " " << book[i];
        else
            cout << book[i];
    cout << endl;
    system("pause");
    return 0;
}