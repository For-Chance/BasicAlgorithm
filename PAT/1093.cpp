#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    string s;
    cin >> s;
    long long count = 0, cP = 0, cA = 0, cT = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P')
            cP++;
        else if (s[i] == 'A')
            cA++;
        else
            cT++;
    long long iP = 0, iT = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'P')
            iP++;
        else if (s[i] == 'T')
            iT++;
        else
            count = (count + iP * (cT - iT)) % 1000000007;
    cout << count << endl;
    system("pause");
    return 0;
}