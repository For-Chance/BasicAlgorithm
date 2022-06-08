#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> Raffle(vector<string> &names, int &M, int &N, int &S)
    {
        vector<string> winners;
        while (S <= M)
        {
            if (find(winners.begin(), winners.end(), names[S - 1]) != winners.end())
            {
                S++;
                continue;
            }
            winners.push_back(names[S - 1]);
            S += N;
        };
        if (winners.size() == 0)
            winners.push_back("Keep going...");
        return winners;
    }
};

int main()
{
    int M, N, S;
    cin >> M >> N >> S;
    vector<string> names(M);
    for (int i = 0; i < M; i++)
        cin >> names[i];
    Solution solution;
    vector<string> result = solution.Raffle(names, M, N, S);
    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << endl;
    system("pause");
    return 0;
}