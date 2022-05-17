#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    string n, m = "", x;
    cin >> n;
    string c = n;
    int s = 0, d, flag = 1;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        d = (n[i] - '0') * 2 + s;
        s = d / 10;
        x = to_string(d % 10);
        if (flag == 0 || c.find(x) == string::npos)
            flag = 0;
        else
            c[c.find(x)] = ' ';
        m.append(x);
    }
    if (s != 0)
        m.append(to_string(s));
    reverse(m.begin(), m.end());
    if (flag == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << m << endl;
    system("pause");
    return 0;
}