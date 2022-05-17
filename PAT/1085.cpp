#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
    int d[10000];
    int N, p;
    cin >> N >> p;
    for (int i = 0; i < N; i++)
        cin >> d[i];
    sort(d, d + N);

    int dis = 0, temp = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + dis; j < N; j++)
            if (d[j] <= d[i] * p)
            {
                temp = j - i + 1;
                if (temp > dis)
                    dis = temp;
            }
            else
                break;

    cout << dis << endl;
    system("pause");
    return 0;
}