#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isPrime(int m)
{
    if (m <= 1)
        return false;
    for (int i = 2; i < m; i++)
        if (m % i == 0)
            return false;
    return true;
}

int main()
{
    int MS, N;
    cin >> MS >> N;
    int a, x;
    if (isPrime(MS) == false)
        for (; isPrime(MS) == false; MS++)
            ;
    vector<int> s(MS, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        x = a % MS;
        if (s[x] < 0)
        {
            s[x] = a;
            cout << x;
        }
        else
        {
            int flag = 0;
            for (int j = 1; j < MS - 1; j++)
                if (s[(a + j * j) % MS] < 0)
                {
                    s[(a + j * j) % MS] = a;
                    cout << (a + j * j) % MS;
                    flag = 1;
                    break;
                }
            if (flag == 0)
                cout << "-";
        }
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}