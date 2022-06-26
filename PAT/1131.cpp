#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void build(unordered_map<int, int> &mapLine, unordered_map<int, vector<int>> &tran)
    {
    }

    pair<int, vector<pair<int, int>>> findPath(int source, int dest)
    {
        pair<int, vector<pair<int, int>>> res;
        return res;
    }
};

int main()
{
    unordered_map<int, int> mapLine;
    unordered_map<int, vector<int>> tran;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        int idx;
        for (int j = 0; j < M; j++)
        {
            cin >> idx;
            if (mapLine.find(idx) == mapLine.end())
                mapLine[idx] = i;
            else
            {
                if (tran.find(idx) == tran.end())
                {
                    tran[idx] = {};
                    tran[idx].push_back(i);
                    tran[idx].push_back(mapLine[idx]);
                }
                else
                    tran[idx].push_back(i);
            }
        }
    }
    Solution solution;
    solution.build(mapLine, tran);
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, vector<pair<int, int>>> res = solution.findPath(a, b);
        cout << res.first << endl;
        int pre = a;
        for (int j = 0; j < res.second.size(); j++)
            printf("Take Line#%d from %04d to %04d.\n", res.second[j].first + 1, pre, res.second[j].second);
    }
    system("pause");
    return 0;
}