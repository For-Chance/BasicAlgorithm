#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <math.h>

string transfrom(int N, int D)
{
    string m = "";
    while (N >= D)
    {
        m.append(to_string(N % D));
        N = N / D;
    }
    m.append(to_string(N));
    return m;
}

bool isPrime(string n, int D)
{
    int num = 0;
    for (int i = 0; i < n.size(); i++)
        num += (n[i] - '0') * pow(D, n.size() - 1 - i);
    if (num == 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main()
{
    int N, D;
    while (1)
    {
        cin >> N;
        if (N < 0)
            break;
        cin >> D;
        int flag = 1;
        string resN_D = transfrom(N, D);
        string N_D = resN_D;
        reverse(N_D.begin(), N_D.end());
        if (isPrime(N_D, D) && isPrime(resN_D, D))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    system("pause");
    return 0;
}