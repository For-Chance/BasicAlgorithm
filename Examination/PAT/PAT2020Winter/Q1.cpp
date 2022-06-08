#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getF(int N)
    {
        int f1 = 0, f2 = 1;
        while (1)
        {
            int t = f1 + f2;
            f1 = f2;
            f2 = t;
            if (f2 > N)
                return f1;
        }
    }
};

int main()
{
    int N;
    cin >> N;
    Solution solution;
    cout << solution.getF(N) << endl;
    system("pause");
    return 0;
}