#include <iostream>
using namespace std;
#include <vector>
int N, maxdepth;
bool v[1010][1010], visit[1010]; // v[a][b] == true 表示，a follows b
vector<int> res;

void dfs(int node, int depth)
{
    if (depth > maxdepth)
        return;
    visit[node] = true;
    res.push_back(node);
    for (int i = 1; i <= N; i++)
        if (v[i][node] == true && visit[i] == false)
            dfs(i, depth + 1);
}

int main()
{
    cin >> N >> maxdepth;
    int k, c;
    for (int i = 1; i <= N; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> c;
            v[i][c] = true;
        }
    }
    int K, C;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        fill(visit, visit + 1010, false);
        cin >> C;
        visit[C] = true;
        res.clear();
        for (int j = 1; j <= N; j++)
            if (v[j][C] == true && visit[j] == false)
                dfs(j, 1);
        cout << res.size() << endl;
    }
    system("pause");
    return 0;
}