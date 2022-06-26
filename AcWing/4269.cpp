#include <bits/stdc++.h>
using namespace std;

int getBirth(string id)
{
    return stoi(id.substr(6, 8));
}

int main()
{
    int N;
    cin >> N;
    unordered_set<string> friends;
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        friends.insert(a);
    }
    int M;
    cin >> M;
    vector<string> guests(M);
    int cnt = 0;
    int i_f = -1;
    int i_g = -1;
    int minf = 99999999, ming = 99999999;
    for (int i = 0; i < M; i++)
    {
        cin >> guests[i];
        int b = getBirth(guests[i]);
        if (friends.find(guests[i]) != friends.end())
        {
            if (minf > b)
            {
                minf = b;
                i_f = i;
            }
            cnt++;
        }
        if (ming > b)
        {
            ming = b;
            i_g = i;
        }
    }
    cout << cnt << endl;
    if (i_f == -1)
        cout << guests[i_g] << endl;
    else
        cout << guests[i_f] << endl;
    system("pause");
    return 0;
}