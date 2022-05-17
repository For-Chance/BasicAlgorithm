#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        d[a] = i;
    }
    int count = 0;
    int i = 1;
    while (1)
        if (d[0] != 0)
        {
            int temp = d[0];
            d[0] = d[d[0]];
            d[temp] = temp;
            count++;
        }
        else
        {
            while (d[i] == i && i < N)
                i++;
            if (i == N)
                break;
            int temp = d[0];
            d[0] = d[i];
            d[i] = temp;
            count++;
        }
    cout << count << endl;
    system("pause");
    return 0;
}