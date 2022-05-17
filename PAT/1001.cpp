#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        cout << s[i];
        if ((len - i - 1) % 3 == 0 && len - i - 1 != 0 && s[i] != '-')
            cout << ',';
    }
    cout << "\n";
    system("pause");
    return 0;
}