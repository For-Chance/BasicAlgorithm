#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, bool> used;
    unordered_map<int, vector<unordered_set<int>>> &equations;

    bool cmp(unordered_set<int> a, unordered_set<int> b)
    {
        int n1 = a.size(), n2 = b.size();
        auto it1 = a.begin();
        auto it2 = b.begin();
        while (it1 != a.end() && it2 != b.end())
        {
            if (*it1 == *it2)
            {
                it1++;
                it2++;
                continue;
            }
            return *it1 < *it2;
        }
    };

    void prepare(vector<int> &reacts, unordered_map<int, vector<unordered_set<int>>> &eq)
    {
        int N = reacts.size();
        for (int i = 0; i < N; i++)
            used[reacts[i]] = false;
        equations = eq;
        for (int i = 0; i < equations.size(); i++)
            sort(equations[i].begin(), equations[i].end(), cmp);
    };

    vector<int> findSolution(int r){};
};

int main()
{
    int N;
    cin >> N;
    vector<int> reacts(N);
    unordered_map<int, vector<unordered_set<int>>> equations;
    for (int i = 0; i < N; i++)
    {
        cin >> reacts[i];
        equations[reacts[i]] = {{reacts[i]}};
    }

    int M;
    cin >> M;
    vector<int> products(M);
    for (int i = 0; i < M; i++)
        cin >> products[i];

    int K;
    scanf("%d\n", &K);
    for (int i = 0; i < K; i++)
    {
        string s;
        getline(cin, s);
        int p = stoi(s.substr(s.length() - 2, 2));
        unordered_set<int> r;
        for (int j = 0; j < s.length() - 5;)
            if (s[j] == ' ')
                j += 3;
            else
            {
                int x = stoi(s.substr(j, 2));
                r.insert(x);
                j += 2;
            }
        reverse(r.begin(), r.end());
        if (equations.find(p) == equations.end())
            equations[p] = {};
        equations[p].push_back(r);
    }

    Solution solution;
    solution.prepare(reacts, equations);
    for (int i = 0; i < M; i++)
    {
        vector<int> result = solution.findSolution(products[i]);
        cout << result[1];
        for (int i = 1; i < result.size(); i++)
            cout << " + " << result[i];
        cout << " -> " << result[0];
    }
    system("pause");
    return 0;
}