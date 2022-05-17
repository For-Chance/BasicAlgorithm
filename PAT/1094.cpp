#include <iostream>
using namespace std;
#include <vector>
int count[100];

vector<int> v[101];

void bfs(int index, int depth)
{
    if (count[depth] == -1)
        count[depth] = 0;
    else
        count[depth]++;
    if (v[index].size() == 0)
        return;
    else
        for (int i = 0; i < v[index].size(); i++)
            bfs(v[index][i], depth + 1);
}

int main()
{
    int N, M;
    cin >> N >> M;
    int index, k, c;
    for (int i = 0; i < M; i++)
    {
        cin >> index >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            v[index].push_back(c);
        }
    }
    bfs(1, 1);
    int ix, maxGen = -1;
    for (int i = 1; count[i] != 0; i++)
        if (count[i] > maxGen)
        {
            ix = i;
            maxGen = count[i];
        }
    cout << maxGen << " " << ix << endl;
    system("pause");
    return 0;
}