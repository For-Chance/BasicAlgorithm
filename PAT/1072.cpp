#include <iostream>
using namespace std;
#include <string>
#include <vector>
const int inf = 99999999;
int N, M, K, Ds, NM;
int dis[1100], e[1100][1100];
double avg[11], minloc[11];
bool visit[1100];

void Dijstra(int node)
{
    fill(dis, dis + 1100, inf);
    fill(visit, visit + 1100, false);
    dis[node] = 0;
    for (int i = 1; i <= NM; i++)
    {
        int min = -1, mindis = inf;
        for (int j = 1; j <= NM; j++)
            if (visit[j] == false && dis[j] < mindis)
            {
                min = j;
                mindis = dis[j];
            }
        if (min == -1)
            break;
        visit[min] = true;
        for (int j = 1; j <= NM; j++)
            if (visit[j] == false && e[min][j] != inf)
                if ((dis[min] + e[min][j]) < dis[j])
                    dis[j] = dis[min] + e[min][j];
    }
    int mindis = inf;
    int sum = 0;
    int flag = 1;
    for (int i = 1; i <= N; i++)
    {
        if (dis[i] > Ds)
        {
            flag = 0;
            break;
        }
        if (dis[i] < mindis)
            mindis = dis[i];
        sum += dis[i];
    }
    if (flag)
    {
        avg[node - N] = double(sum) / N;
        minloc[node - N] = double(mindis);
    }
    else
    {
        avg[node - N] = inf;
        minloc[node - N] = -1;
    }
}

int main()
{
    cin >> N >> M >> K >> Ds;
    NM = N + M;
    string s1, s2;
    int a, b;
    int d;
    fill(e[0], e[0] + 1100 * 1100, inf);
    // 1-N house N+1-M location
    for (int i = 0; i < K; i++)
    {
        cin >> s1 >> s2 >> d;
        if (isdigit(s1[0]))
            a = stoi(s1);
        else
            a = N + stoi(s1.substr(1));
        if (isdigit(s2[0]))
            b = stoi(s2);
        else
            b = N + stoi(s2.substr(1));
        e[a][b] = e[b][a] = d;
    }
    for (int i = 1; i <= M; i++)
        Dijstra(N + i);
    // minloc 越大越好，avg越小越好，所以
    vector<int> bestloc;
    int maxmin = -1;
    for (int i = 1; i < M; i++)
        if (minloc[i] > maxmin)
        {
            maxmin = minloc[i];
            bestloc.clear();
            bestloc.push_back(i);
        }
        else if (minloc[i] == maxmin)
            bestloc.push_back(i);
    if (bestloc.size() == 0)
        cout << "No Solution" << endl;
    else
    {
        int best = -1, minavg = inf;
        for (int i = 1; i <= bestloc.size(); i++)
            if (minavg > avg[i])
            {
                minavg = avg[i];
                best = i;
            }
        cout << "G" << best << endl;
        printf("%.1f %.1f", minloc[best], avg[best] + 0.05);
    }
    system("pause");
    return 0;
}