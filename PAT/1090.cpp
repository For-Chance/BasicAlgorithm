#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
double P, r;
int maxdepth = -1, count = 0;

vector<int> v[100000];

void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth > maxdepth)
        {
            maxdepth = depth;
            count = 1;
        }
        else if (depth == maxdepth)
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
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int k, begin;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k == -1)
            begin = i;
        else
            v[k].push_back(i);
    }
    bfs(begin, 0);
    printf("%.2f %d\n", P * pow(r, maxdepth), count);
    system("pause");
    return 0;
}