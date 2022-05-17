#include <iostream>
using namespace std;

int main()
{
    string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string s2[13] = {"XXX", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++)
    {
        string a;
        getline(cin, a);
        if (isdigit(a[0]))
        {
            int n = stoi(a);
            int n2 = n / 13, n1 = n % 13;
            if (n <= 12)
                cout << s1[n1] << endl;
            else
            {
                cout << s2[n2];
                if (n1 != 0)
                    cout << " " << s1[n1];
                cout << endl;
            }
        }
        else
        {
            if (a.length() > 5)
            {
                string a2 = a.substr(0, 3), a1 = a.substr(4, 3); // 不会有tret
                int num = 0;
                for (int j = 0; j < 13; j++)
                {
                    if (s2[j] == a2)
                        num += j * 13;
                    if (s1[j] == a1)
                        num += j;
                }
                cout << num << endl;
            }
            else
            {
                for (int j = 0; j < 13; j++)
                    if (s1[j] == a)
                    {
                        cout << j << endl;
                        break;
                    }
                    else if (s2[j] == a)
                    {
                        cout << j * 13 << endl;
                        break;
                    }
            }
        }
    }
    system("pause");
    return 0;
}