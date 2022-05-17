#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
double P, r;
double price = 0;

vector<int> v[100000];
vector<int> retailsPrice(100000);

void bfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        price += pow(r, depth) * P * retailsPrice[index];
        return;
    }
    else
    {
        for (int i = 0; i < v[index].size(); i++)
            bfs(v[index][i], depth + 1);
    }
}

int main()
{
    int N;
    cin >> N >> P >> r;
    r = r / 100 + 1;
    int k, c;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (k != 0)
            for (int j = 0; j < k; j++)
            {
                cin >> c;
                v[i].push_back(c);
            }
        else
            cin >> retailsPrice[i];
    }
    bfs(0, 0);
    printf("%.1f\n", price);
    system("pause");
    return 0;
}