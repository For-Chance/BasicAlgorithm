#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> mapLine;
    unordered_map<int, vector<int>> tran;
    unordered_map<int, vector<int>> Lines;
    vector<vector<int>> e;
    void build(unordered_map<int, int> &mapLine, unordered_map<int, vector<int>> &tran, unordered_map<int, vector<int>> &Lines)
    {
        mapLine = mapLine;
        tran = tran;
        Lines = Lines;
        // 建图
        int n = Lines.size();
        e = vector<vector<int>>(10000, vector<int>(10000));
        for (auto it = tran.begin(); it != tran.end(); it++)
        {
        }
    }

    pair<int, vector<pair<int, int>>> findPath(int source, int dest)
    {
        pair<int, vector<pair<int, int>>> res;
        // 赋
        return res;
    }
};

int main()
{
    unordered_map<int, int> mapLine;
    unordered_map<int, vector<int>> tran;
    unordered_map<int, vector<int>> Lines;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        int idx;
        Lines[i] = {};
        for (int j = 0; j < M; j++)
        {
            cin >> idx;
            Lines[i].push_back(idx);
            if (mapLine.find(idx) == mapLine.end())
                mapLine[idx] = i;
            else
            {
                if (mapLine[idx] == i)
                    continue;
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
    solution.build(mapLine, tran, Lines);
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