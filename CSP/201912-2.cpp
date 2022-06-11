#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
};

int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> set;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        set.insert(make_pair(x, y));
    }
    vector<int> map(5, 0);
    for (auto it = set.begin(); it != set.end(); it++)
    {
        int x = it->first, y = it->second;
        int cnt = 0;
        if (set.find(make_pair(x, y - 1)) != set.end() && set.find(make_pair(x - 1, y)) != set.end() && set.find(make_pair(x, y + 1)) != set.end() && set.find(make_pair(x + 1, y)) != set.end())
        {
            if (set.find(make_pair(x - 1, y - 1)) != set.end())
                cnt++;
            if (set.find(make_pair(x + 1, y - 1)) != set.end())
                cnt++;
            if (set.find(make_pair(x + 1, y + 1)) != set.end())
                cnt++;
            if (set.find(make_pair(x - 1, y + 1)) != set.end())
                cnt++;
            map[cnt]++;
        }
    }
    for (int i = 0; i < 5; i++)
        cout << map[i] << endl;
    system("pause");
    return 0;
}

/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1

2
0 0
-100000 10

11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11

*/