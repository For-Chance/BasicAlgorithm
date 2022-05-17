#include <iostream>
using namespace std;
#include <string.h>

int main()
{
    string s;
    cin >> s;
    int N = s.length();
    int n1 = (N + 2) / 3;
    int n3 = n1, n2 = (N + 2) - 2 * n1;
    char c[30][30];
    memset(c, ' ', sizeof(c));
    int i = 0;
    for (int j = 0; j < n1; j++)
    {
        c[j][0] = s[i];
        i++;
    }
    for (int j = 1; j < n2 - 1; j++)
    {
        c[n1 - 1][j] = s[i];
        i++;
    }
    for (int j = n3 - 1; j >= 0; j--)
    {
        c[j][n2 - 1] = s[i];
        i++;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
            cout << c[i][j];
        cout << endl;
    }

    system("pause");
    return 0;
}