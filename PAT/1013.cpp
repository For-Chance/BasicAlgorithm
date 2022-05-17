#include <iostream>
using namespace std;
bool v[1001][1001], visit[1001];
int N, M, K;

// node表示当前开始dfs的节点
void dfs(int node)
{
    visit[node] = true;
    for (int i = 1; i <= N; i++)
        if (v[node][i] == true && visit[i] == false) // 尚未访问过,并且直接链接的点
            dfs(i);
}

int main()
{
    cin >> N >> M >> K;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v[a][b] = v[b][a] = true; // 注意这里没有填对角线上的，不过应该可以通过visit过滤掉这些
    }
    for (int i = 0; i < K; i++)
    {
        fill(visit, visit + 1000, false);
        cin >> a;
        int count = 0;
        visit[a] = true;
        for (int j = 1; j <= N; j++)
            if (visit[j] == false)
            {
                dfs(j);
                count++;
            }
        // 图的性质：a个非连通图之间只需要a-1个通路即可全部联通
        cout << count - 1 << endl;
    }
    system("pause");
    return 0;
}