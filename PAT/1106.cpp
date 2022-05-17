#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
int minDepth = 1000000, count = 0;

vector<int> v[100000];

void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth < minDepth)
        {
            minDepth = depth;
            count = 1;
        }
        else if (depth == minDepth)
            count++;
        return;
    }
    else
        for (int i = 0; i < v[index].size(); i++)
            bfs(v[index][i], depth + 1);
}

int main()
{
    int N;
    double P, r;
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int k, c;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            v[i].push_back(c);
        }
    }
    bfs(0, 0);
    printf("%.4f %d\n", pow(r, minDepth) * P, count);
    system("pause");
    return 0;
}