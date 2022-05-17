#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int N;
    cin >> N;
    vector<int> v(N), dp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int maxdp = -1, start, end, maxstart, maxend;
    dp[0] = v[0];
    for (int i = 1; i < N; i++)
    {
        if (v[i] < dp[i - 1] + v[i])
        {
            dp[i] = dp[i - 1] + v[i];
            end = i;
        }
        else
        {
            dp[i] = v[i];
            start = i;
        }
        if (dp[i] > maxdp)
        {
            maxdp = dp[i];
            maxstart = start;
            maxend = end;
        }
    }
    if (maxdp < 0)
        cout << 0 << " " << 0 << " " << N - 1 << endl;
    else
        cout << maxdp << " " << maxstart << " " << maxend << endl;
    system("pause");
    return 0;
}