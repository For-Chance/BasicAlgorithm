#include <bits/stdc++.h>
using namespace std;

struct req
{
    int s, f;
};

class Solution
{
public:
    static bool cmp(req a, req b) { return a.f < b.f; };

    int getMaxReq(vector<req> &rs)
    {
        int n = rs.size();
        if (n == 0)
            return 0;
        sort(rs.begin(), rs.end(), cmp);
        int k = 0, cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (rs[i].s >= rs[k].f)
            {
                k = i;
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    // 贪心
    int N;
    cin >> N;
    vector<req> requests(N);
    for (int i = 0; i < N; i++)
    {
        int h1, m1, s1;
        int h2, m2, s2;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        requests[i].s = h1 * 3600 + m1 * 60 + s1;
        requests[i].f = h2 * 3600 + m2 * 60 + s2;
    }
    Solution solution;
    cout << solution.getMaxReq(requests) << endl;
    system("pause");
    return 0;
}