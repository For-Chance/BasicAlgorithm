#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> nums(n * m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            nums[a]++;
        }
    if (nums.size() > 0)
    {
        cout << nums[0];
        for (int i = 1; i < L; i++)
            cout << " " << nums[i];
    }
    system("pause");
    return 0;
}