#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
};

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    unordered_map<int, int> map;
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x] = y;
    }
    long long sum = 0;
    for (int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;
        auto pos = map.find(x);
        if (pos != map.end())
            sum += y * pos->second;
    }
    cout << sum;
    Solution solution;
    system("pause");
    return 0;
}

// 10 3 4
// 4 5
// 7 -3
// 10 1
// 1 10
// 4 20
// 5 30
// 7 40