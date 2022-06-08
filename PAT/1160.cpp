#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getSolution(unordered_map<int, vector<int>> &map, int r1, int r2)
    {
        int x1 = r1, x2 = r2;
        int L1 = 0, L2 = 0;
        while (x1 != -1)
        {
            L1++;
            x1 = map[x1][1];
        }
        while (x2 != -1)
        {
            L2++;
            x2 = map[x2][1];
        }
        if (L1 >= 2 * L2)
        {
            int last = reverse_list(map, r2);
        }
        else if (L2 >= 2 * L1)
        {
        }
    }

    int reverse_list(unordered_map<int, vector<int>> &map, int r2)
    {
        int pre_r = r2;
        vector<vector<int>> res;
        while (r2 != -1)
        {
            vector<int> temp = map[r2];
            res.push_back({temp[0], temp[1], r2});
            map.erase(r2);
            r2 = temp[0];
        }
    }
};

int main()
{
    int root1, root2, N;
    cin >> root1 >> root2 >> N;
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a] = {b, c};
    }
    Solution solution;
    vector<int> result = solution.getSolution(map, root1, root2);
    for (int i = 0; i < N; i++)
        printf("%05d %d %05d\n", result[i], map[result[i]][0], map[result[i]][1]);
    system("pause");
    return 0;
}