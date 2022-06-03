#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findLonely(vector<vector<int>> &cps, vector<int> &guests)
    {
        int n = cps.size(), m = guests.size();
        unordered_map<int, int> hashtable;
        for (int i = 0; i < n; i++)
        {
            hashtable[cps[i][0]] = cps[i][1];
            hashtable[cps[i][1]] = cps[i][0];
        }
        vector<int> result;
        for (int i = 0; i < m; i++)
        {
            auto pos = hashtable.find(guests[i]);
            if (pos == hashtable.end())
                result.push_back(guests[i]);
            else if (find(guests.begin(), guests.end(), pos->second) == guests.end())
                result.push_back(guests[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> cps(N, vector<int>(2));
    for (int i = 0; i < N; i++)
        cin >> cps[i][0] >> cps[i][1];
    int M;
    cin >> M;
    vector<int> guests(M);
    for (int i = 0; i < M; i++)
        cin >> guests[i];
    Solution solution;
    vector<int> result = solution.findLonely(cps, guests);
    int x = result.size();
    cout << x << endl;
    if (x != 0)
    {
        printf("%05d", result[0]);
        for (int i = 1; i < x; i++)
            printf(" %05d", result[i]);
        cout << endl;
    }
    system("pause");
    return 0;
}