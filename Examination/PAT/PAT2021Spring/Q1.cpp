#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isPrime;
    vector<int> getPrimeArr(int N, int M)
    {
        isPrime = vector<bool>(M + 1, true);
        for (int i = 2; i <= M; i++)
            for (int j = 2; j <= M; j++)
                if ((i * j) <= M)
                    isPrime[i * j] = false;
        isPrime[0] = isPrime[1] = false;

        int diff = (M - 2) / N + 1;
        vector<int> NowPrime;
        vector<int> result;

        bool flag = false;
        int index = M;
        return result;
    }

    vector<int> isCanbe(int index, int diff, int N)
    {
        vector<int> res(N);
        for (int i = 0; i < N; i++)
            if (isPrime[index - i * diff] == true)
                res[N - 1 - i] = index - i * diff;
            else
                return {};
        return res;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    Solution solution;
    vector<int> result = solution.getPrimeArr(N, M);
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < result.size(); i++)
            cout << " " << result[i];
        cout << endl;
    }
    system("pause");
    return 0;
}