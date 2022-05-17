#include <iostream>
using namespace std;
#include <vector>

int main()
{
    cout << "�������еĸ�����" << endl;
    int N;
    cin >> N;
    cout << "������һ�����У��ո������" << endl;
    vector<int> v(N), dp(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    int maxdp = -1;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (v[i] > v[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[i] + 1;
        maxdp = max(maxdp, dp[i]);
    }
    cout << "������еĸ�����:\n"
         << maxdp << endl;
    system("pause");
    return 0;
}