#include <iostream>
using namespace std;
const int inf = 99999999;
int dis[510], cost[510], pre[510], e[510][510][2];
bool visit[510];
int N, M, S, D;

void getPath(int index)
{
    if (index != S)
        getPath(pre[index]);
    cout << index << " ";
}

int main()
{
    cin >> N >> M >> S >> D;
    int a, b, c, d;
    fill(e[0][0], e[0][0] + 510 * 510 * 2, inf);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c >> d;
        e[a][b][0] = e[b][a][0] = c;
        e[a][b][1] = e[b][a][1] = d;
    }
    fill(dis, dis + 510, inf);
    fill(cost, cost + 510, inf);
    dis[S] = 0;
    cost[S] = 0;
    for (int i = 0; i < N; i++)
    {
        int min = -1, mindis = inf;
        for (int j = 0; j < N; j++)
            if (dis[j] < mindis && visit[j] == false)
            {
                min = j;
                mindis = dis[j];
            }
        if (min == -1)
            break;
        visit[min] = true;
        for (int j = 0; j < N; j++)
            if (visit[j] == false && e[min][j][0] != inf)
            {
                if (dis[j] > dis[min] + e[min][j][0])
                {
                    dis[j] = dis[min] + e[min][j][0];
                    cost[j] = cost[min] + e[min][j][1];
                    pre[j] = min;
                }
                else if (dis[j] == dis[min] + e[min][j][0])
                    if (cost[j] > cost[min] + e[min][j][1])
                    {
                        cost[j] = cost[min] + e[min][j][1];
                        pre[j] = min;
                    }
            }
    }
    getPath(D);
    cout << dis[D] << " " << cost[D] << endl;
    system("pause");
    return 0;
}