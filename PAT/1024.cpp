#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string add(string n)
{
    string m = n;
    reverse(m.begin(), m.end());
    int s = 0, d;
    string res = "";
    for (int i = n.size() - 1; i >= 0; i--)
    {
        d = (n[i] - '0') + (m[i] - '0') + s;
        s = d / 10;
        res.append(to_string(d % 10));
    }
    if (s != 0)
        res.append(to_string(s));
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string N;
    int K, i;
    cin >> N >> K;
    for (i = 1; i <= K; i++)
    {
        N = add(N);
        string M = N;
        reverse(M.begin(), M.end());
        if (N == M || i == K)
            break;
    }
    cout << N << endl
         << i << endl;
    system("pause");
    return 0;
}