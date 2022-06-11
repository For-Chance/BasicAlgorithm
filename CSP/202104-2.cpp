#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
};

int main()
{
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    vector<vector<int>> graph(n + 2 * r, vector<int>(n + 2 * r, t));
    int start = r, end = n + r - 1;
    for (int i = start; i <= end; i++)
        for (int j = start; j <= end; j++)
            cin >> graph[i][j];

    Solution solution;
    system("pause");
    return 0;
}