#include <bits/stdc++.h>
using namespace std;
int n, X, Y;

double getdis(int x1, int y1, int x2, int y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }

bool cmp(vector<int> a, vector<int> b)
{
    return getdis(a[0], a[1], X, Y) == getdis(b[0], b[1], X, Y) ? a[2] < b[2] : getdis(a[0], a[1], X, Y) < getdis(b[0], b[1], X, Y);
}

int main()
{
    cin >> n >> X >> Y;
    vector<vector<int>> loc(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> loc[i][0] >> loc[i][1];
        loc[i][2] = i + 1;
    }
    sort(loc.begin(), loc.end(), cmp);
    for (int i = 0; i < 3 && i < loc.size(); i++)
        cout << loc[i][2] << endl;
    system("pause");
    return 0;
}

// 16m,太慢了,应该10m解决