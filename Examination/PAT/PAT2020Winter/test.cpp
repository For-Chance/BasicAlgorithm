#include <iostream>
using namespace std;

int main()
{
    string s[3];
    for (int i = 0; i < 3; i++)
        getline(cin, s[i]);
    for (int i = 0; i < 3; i++)
        cout << s[i] << endl;
    system("pause");
    return 0;
}