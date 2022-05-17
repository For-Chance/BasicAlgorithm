#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n, e;
    cin >> n;
    int d[100];
    int s = 0, cost = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        cost += ((s < e) ? (6 * (e - s)) : (4 * (s - e))) + 5;
        s = e;
    }
    cout << cost << endl;
    system("pause");
    return 0;
}