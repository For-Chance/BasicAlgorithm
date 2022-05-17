#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int N;

void pluszero(string &a)
{
    int x = a.length();
    if (x < N)
        for (int i = 0; i < (N - x); i++)
            a.append("0");
}

int getk(string &a)
{
    int pos = a.find('.');
    if (pos == string::npos)
    {
        int x = a.length();
        pluszero(a);
        return x;
    }
    else
    {
        if (a[0] == '0' && a[1] == '.')
        {
            int count0 = 0;
            for (int i = 2;; i++)
                if (a[i] != '0')
                    break;
                else
                    count0++;
            if (count0 != a.length() - 2)
            {
                a = a.substr(2 + count0);
                pluszero(a);
            }
            else // 相当于为0.0000
            {
                a = a.substr(2);
                pluszero(a);
                return 0;
            }
            return -count0;
        }
        else
        {
            string s1 = a.substr(0, pos);
            s1.append(a.substr(pos + 1));
            a = s1;
            pluszero(a);
            return pos;
        }
    }
}

int main()
{
    cin >> N;
    string A, B;
    cin >> A >> B;
    int k1, k2;
    k1 = getk(A);
    k2 = getk(B);
    int flag = 1;
    if (k1 == k2)
    {
        for (int i = 0; i < N; i++)
        {
            if (A[i] == B[i])
                continue;
            else if (A[i] != B[i])
            {
                flag = 0;
                cout << "NO"
                     << " "
                     << "0." << A.substr(0, N) << "*10^" << k1 << " "
                     << "0." << B.substr(0, N) << "*10^" << k2 << endl;
                break;
            }
        }
        if (flag == 1)
            cout << "YES"
                 << " "
                 << "0." << A.substr(0, N) << "*10^" << k1 << endl;
    }
    else
    {
        cout << "NO"
             << " "
             << "0." << A.substr(0, N) << "*10^" << k1 << " "
             << "0." << B.substr(0, N) << "*10^" << k2 << endl;
    }
    system("pause");
    return 0;
}