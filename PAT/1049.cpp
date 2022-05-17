#include <iostream>
using namespace std;
#include <math.h>

int countOnes(string n)
{
    long long sum = 0;
    if (n.size() == 1)
    {
        int a = n[0] - '0';
        if (a >= 1)
            sum++;
    }
    else
    {
        for (int i = 0; i < n.size(); i++)
        {
            int a = n[i] - '0';
            if (a == 0)
                continue;
            else if (a == 1)
                if (i != n.size() - 1)
                    sum += stoi(n.substr(i + 1)) + 1;
                else
                    sum++;
            else
                sum += pow(10, n.size() - i - 1);
            if (i != 0)
                sum += stoi(n.substr(0, i));
        }
    }
    return sum;
}

int main()
{
    string n;
    cin >> n;
    cout << countOnes(n) << endl;
    system("pause");
    return 0;
}