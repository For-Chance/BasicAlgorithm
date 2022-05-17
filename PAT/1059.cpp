#include <iostream>
using namespace std;
#include <map>
#include <algorithm>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    long N;
    cin >> N;
    long n = N;
    map<int, int> s;
    for (int i = 2; i < N; i++)
    {
        if (N % i == 0 && isPrime(i))
        {
            N = N / i;
            cout << N << " " << i << endl;
            // map<int, int>::iterator pos = s.find(i);
            // if (pos != s.end())
            //     s.insert(make_pair(i, 1));
            // else
            //     pos->second++;
        }
    }
    cout << n << "=";
    for (map<int, int>::iterator it = s.begin(); it != s.end(); it++)
    {
        if (it != s.begin())
            cout << "*";
        if (it->second != 1)
            cout << it->first << "^" << it->second;
        else
            cout << it->first;
    }

    system("pause");
    return 0;
}