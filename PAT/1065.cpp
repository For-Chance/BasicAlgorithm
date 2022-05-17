#include <iostream>
using namespace std;

int main()
{
    long long A, B, C;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A >> B >> C;
        cout << "Case #" << i << ": ";
        long long sum = A + B;
        if (A > 0 && B > 0 && sum < 0)
            cout << "true" << endl;
        else if (A < 0 && B < 0 && sum >= 0)
            cout << "false" << endl;
        else
        {
            if (sum > C)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }
    system("pause");
    return 0;
}