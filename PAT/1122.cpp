#include <bits/stdc++.h>
using namespace std;
bool e[210][210];

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = true;
    }
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int K;
        cin >> K;
        vector<int> v(K);
        set<int> s;
        int flag1 = 1, flag2 = 1;
    }

    system("pause");
    return 0;
}