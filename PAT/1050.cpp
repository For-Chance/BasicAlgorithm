#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int s1_size = s1.size();
    int s2_size = s2.size();
    for (int i = 0; i < s1_size; i++)
        if (s2.find(s1[i]) == string::npos)
            cout << s1[i];
    cout << endl;
    system("pause");
    return 0;
}