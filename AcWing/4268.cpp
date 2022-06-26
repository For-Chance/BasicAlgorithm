#include <bits/stdc++.h>
using namespace std;

bool isPrime(int N)
{
    if (N < 2)
        return false;
    for (int i = 2; i <= int(sqrt(N)); i++)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}

int isSexPrime(int N)
{
    if (isPrime(N) == false)
        return -1;
    if (isPrime(N - 6) == true)
    {
        return N - 6;
    }
    else if (isPrime(N + 6) == true)
    {
        return N + 6;
    }
    return -1;
}

int main()
{
    int N;
    cin >> N;
    int res = isSexPrime(N);
    if (res == -1)
    {
        cout << "No" << endl;
        int i = N + 1;
        while (isSexPrime(i) == -1)
        {
            i++;
        }
        cout << i << endl;
    }
    else
        cout << "Yes" << endl
             << res << endl;
    system("pause");
    return 0;
}