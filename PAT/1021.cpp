#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int N;
bool v[10001][10001], visit[10001];
vector<int> dr;

// 注意题目说了图是无环的；
void dfs(int node)
{
    visit[node] = true;
    int flag = 0;
    for (int i = 1; i <= N; i++)
        if (visit[i] == false && v[node][i] == true)
        {
            flag = 1;
            dfs(i);
        }
    if (!flag)
        dr.push_back(node);
}

int main()
{
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        v[a][b] = v[b][a] = true;
    }
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        visit[i] = true;
        int flag = 0;
        for (int j = 1; j <= N; j++)
            if (visit[j] == false && v[i][j] == true)
            {
                dfs(j);
                flag = 1;
            }
        if (flag == 1)
            count++;
    }
    if (count > 1)
        printf("Error: %d components\n", count);
    else
    {
        sort(dr.begin(), dr.end());
        for (int i = 0; i < dr.size(); i++)
            cout << dr[i] << endl;
    }
    system("pause");
    return 0;
}