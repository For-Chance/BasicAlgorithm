#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <math.h>

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    int n, m = sqrt(N) + 1;
    for (; m <= N; m++)
        if (N % m == 0)
        {
            n = N / m;
            break;
        }
    vector<vector<int>> result(m, vector<int>(n));
    int k = m, z = n;
    int row = 0, col = 0, i = 0, level = m / 2 + m % 2;
    for (int j = 0; j < level; j++)
    {

        while (col < n - 1 - j && N != i)
        {
            result[row][col++] = v[i++];
        }
        while (row < m - 1 - j && N != i)
        {
            result[row++][col] = v[i++];
        }
        while (col > j && N != i)
        {
            result[row][col--] = v[i++];
        }
        while (row > j && N != i)
        {
            result[row--][col] = v[i++];
        }
        row++;
        col++;
    }
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < z; y++)
            if (y != z - 1)
                cout << result[x][y] << " ";
            else
                cout << result[x][y] << endl;
    }
    system("pause");
    return 0;
}