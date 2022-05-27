#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double avgCount(int s, int n)
    {
        double result = 0.0;
        int start = s > n ? s : n;
        int maxX = 1000;
        for (int x = start; x <= maxX; x++)
        {
            result += x * (1 / pow(n, n)) * (1 / pow(s, s));
        }
        return result;
    }
};

int main()
{
    int s, n;
    cin >> s >> n;
    Solution solution;
    double res = solution.avgCount(s, n);
    cout << res << endl;
    system("pause");
    return 0;
}