#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    string s, v;
    cin >> s >> v;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        int pos = v.find(s[i]);
        if (pos == string::npos && res.find(s[i]) == string::npos)
            res += s[i];
    }

    cout << res << endl;
    system("pause");
    return 0;
}