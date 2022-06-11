#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int x, y;
};

class Solution
{
public:
    int x1, x2, y1, y2;
    void build(int x1, int y1, int x2, int y2)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }

    vector<int> getSolution(vector<vector<node>> &loc, int k)
    {
        int cnt1 = 0, cnt2 = 0;
        int n = loc.size();
        int t = loc[0].size();
        int f1 = 0; // 1 表示经过，2表示逗留
        for (int i = 0; i < n; i++)
        {
            int nowcnt = 0;
            for (int j = 0; j < t; j++)
            {
                if (isin(loc[i][j]))
                {
                    f1 = 1;
                    nowcnt++;
                }
                else
                    nowcnt = 0;
                if (nowcnt == k)
                {
                    f1 = 2;
                    break;
                }
            }
            if (f1 == 1)
                cnt1++;
            else if (f1 == 2)
                cnt2++;
        }
        return {cnt1, cnt2};
    }

    bool isin(node a)
    {
        return a.x >= x1 && a.x <= x2 && a.y >= y1 && a.y <= y2;
    }
};

int main()
{
    int n, k, t, xl, yd, xr, yu;
    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);
    vector<vector<node>> loc(n, vector<node>(t));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < t; j++)
            cin >> loc[i][j].x >> loc[i][j].y;
    Solution solution;
    solution.build(xl, yd, xr, yu);
    vector<int> result = solution.getSolution(loc, k);
    cout << result[0] << endl
         << result[1];
    system("pause");
    return 0;
}