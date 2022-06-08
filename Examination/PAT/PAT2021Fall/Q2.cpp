#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getHats(vector<int> &hats, vector<int> &weights)
    {
        int N = hats.size();
        vector<int> result(N);
        vector<int> h(hats);
        vector<int> w(weights);
        sort(h.begin(), h.end());
        sort(w.begin(), w.end());
        unordered_map<int, int> hashtable;
        for (int i = 0; i < N; i++)
            hashtable[hats[i]] = weights[i];
        unordered_map<int, int> hashtable2;
        for (int i = 0; i < N; i++)
            hashtable2[weights[i]] = i;
        for (int i = 0; i < N; i++)
        {
            int wg = hashtable[hats[i]];
            int ind = hashtable2[wg];
            result[ind] = i + 1;
        }
        return result;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> hats(N);
    vector<int> weights(N);
    for (int i = 0; i < N; i++)
        cin >> hats[i];
    for (int i = 0; i < N; i++)
        cin >> weights[i];
    Solution solution;
    vector<int> result = solution.getHats(hats, weights);
    if (result.size() > 0)
    {
        cout << result[0];
        for (int i = 1; i < N; i++)
            cout << " " << result[i];
    }
    system("pause");
    return 0;
}