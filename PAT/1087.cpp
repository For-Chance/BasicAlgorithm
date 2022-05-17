#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
const int inf = 99999;
struct node
{
    string name;
    int happiness, distance;
    int total_happiness;
};

vector<node> v(210);
int e[210][210], pre[210];
bool visit[210];
string result;
int length;

void dfs(int j)
{
    if (j == 0)
    {
        result += v[0].name;
        return;
    }
    dfs(pre[j]);
    result += "->" + v[j].name;
    length++;
}

int main()
{
    int N, K;
    cin >> N >> K >> v[0].name;
    v[0].happiness = 0;
    v[0].distance = 0;
    v[0].total_happiness = 0;
    int dest, count = 1;
    for (int i = 1; i < N; i++)
    {
        cin >> v[i].name >> v[i].happiness;
        v[i].distance = inf;
        v[i].total_happiness = v[i].total_happiness;
        if (v[i].name == "ROM")
            dest = i;
    }
    fill(e[0], e[0] + 210 * 210, inf);
    for (int i = 0; i < N; i++)
    {
        string str1, str2;
        int c;
        cin >> str1 >> str2 >> c;

        // e[a][b] = e[b][a] = c;
    }
    fill(pre, pre + 210, 0);
    // dijkstra
    for (int i = 0; i < N; i++)
    {
        int minj = -1, mindis = inf;
        for (int j = 0; j < N; j++)
        {
            if (mindis > v[j].distance && visit[j] == false)
            {
                minj = j;
                mindis = v[j].distance;
            }
        }
        if (minj == -1)
            break;
        visit[minj] = true;
        for (int j = 0; j < N; j++)
        {
            if (e[minj][j] != inf && visit[j] == false)
            {
                if (v[j].distance > v[minj].distance + e[minj][j])
                {
                    v[j].distance = v[minj].distance + e[minj][j];
                    pre[j] = minj;
                    v[j].total_happiness = v[j].happiness + v[minj].total_happiness;
                    if (j == dest)
                        count = 1;
                }
                else if (v[j].distance == v[minj].distance + e[minj][j])
                {
                    if (v[j].total_happiness < v[j].happiness + v[minj].total_happiness)
                    {
                        pre[j] = minj;
                        v[j].total_happiness = v[j].happiness + v[minj].total_happiness;
                        if (j == dest)
                            count++;
                    }
                }
            }
        }
    }
    cout << count << " " << v[dest].distance << " " << v[dest].distance << " ";
    result = "";
    length = 0;
    dfs(dest);
    cout << length << endl
         << result << endl;
    system("pause");
    return 0;
}